#!/usr/bin/env python3
"""Resumable, bounded parallel MWCC search. Candidates never become proofs implicitly.

All inputs that affect comparison are content-addressed. Successful cached objects
are relinked and compared again; failed compilations and mismatches can be skipped.
Searches produce reviewable exact candidates; acceptance is a separate fresh audit.
"""
import argparse
import concurrent.futures
import csv
import hashlib
import fcntl
import importlib.metadata
import json
import os
from pathlib import Path
import re
import resource
import subprocess
import sys
import tempfile
import time
from dataclasses import dataclass
from capstone import Cs, CS_ARCH_ARM, CS_MODE_ARM, CS_MODE_THUMB
from capstone.arm import ARM_OP_MEM, ARM_REG_PC
from elftools.elf.elffile import ELFFile
from arm_load_model import simplify_word_reads, parenthesized
from matching_resolver import MatchingContext
from sdk_signatures import recover_sdk_calls

ROOT = Path(__file__).resolve().parents[1]
PREAMBLE = '''typedef unsigned char uint8_t; typedef unsigned short uint16_t; typedef unsigned int uint32_t; typedef unsigned long long uint64_t;
typedef signed char int8_t; typedef short int16_t; typedef int int32_t; typedef long long int64_t; typedef unsigned int uintptr_t; typedef int intptr_t;
#define bool _Bool
#define true 1
#define false 0
#define UINT32_MAX 0xffffffffU
#define INT32_MAX 0x7fffffff
#define INT32_MIN (-2147483647-1)
#define __attribute__(x)
extern int __builtin_clz(unsigned int);
'''


def digest(data):
    return hashlib.sha256(data).hexdigest()


def canonical(value):
    return json.dumps(value, sort_keys=True, separators=(',', ':')).encode()


def atomic_json(path, value):
    path.parent.mkdir(parents=True, exist_ok=True)
    temporary = path.with_suffix('.tmp')
    temporary.write_bytes(canonical(value) + b'\n')
    temporary.replace(path)


def clean(text):
    return re.sub(r'^#(?:include|pragma).*$', '', text, flags=re.M)


@dataclass(frozen=True)
class Candidate:
    module: str
    name: str
    mode: str
    address: int
    size: int
    variant: str
    source: str
    original: bytes

    @property
    def tag(self):
        return f'{self.module}_{self.address:08x}'


def variants(context, module, address, original, body, declarations):
    """Preserve raw drafts and derive independently byte-checked load candidates."""
    yield 'draft', body, declarations
    decoder = Cs(CS_ARCH_ARM, CS_MODE_THUMB if context.inventory[module, address][1] == 'thumb' else CS_MODE_ARM)
    decoder.detail = True
    slots = set()
    for ins in decoder.disasm(original, address):
        if ins.mnemonic == 'ldr' and len(ins.operands) == 2:
            op = ins.operands[1]
            if op.type == ARM_OP_MEM and op.mem.base == ARM_REG_PC:
                pc = ins.address + 8 if decoder.mode == CS_MODE_ARM else (ins.address + 4) & ~3
                slots.add(pc + op.mem.disp)
    for variable in sorted(set(re.findall(r'\b[A-Za-z]+Ram[0-9a-fA-F]{8}\b', body))):
        location = int(variable[-8:], 16)
        if location not in slots:
            continue
        try:
            literal = int.from_bytes(context.original(module, location, 4), 'little')
        except ValueError:
            continue
        declaration = re.search(r'^#define ' + variable + r'\s+\(\*\((.*?)\)\(uintptr_t\)', declarations, re.M)
        if not declaration or not declaration[1].strip().endswith('*'):
            continue
        typ = declaration[1].strip()[:-1].strip()
        if typ in ['float', 'double']:
            continue
        body = re.sub(r'\b' + variable + r'\b', f'(({typ})0x{literal:08x}u)', body)
        declarations = re.sub(r'^#define ' + variable + r'\b.*$', '', declarations, flags=re.M)
    body, _ = simplify_word_reads(body)
    yield 'native-loads', body, declarations
    typed_declarations, typed_body, changed_calls = recover_sdk_calls(ROOT, module, declarations, body)
    if changed_calls:
        yield 'typed-sdk-calls', typed_body, typed_declarations
    # Replacing constant memory lvalues by actual data symbols preserves aliasing
    # information the compiler loses when the global address is a local integer.
    globals_ = []
    replacements = []
    for match in re.finditer(r'\*\s*\(\s*(uint|int|undefined4|byte|ushort|undefined2)\s*\*\s*\)', body):
        parsed = parenthesized(body, match.end())
        if parsed is None:
            continue
        expression, finish = parsed
        simplified = re.sub(r'\b(?:uint|uintptr_t)\b', '', expression)
        simplified = re.sub(r'[()\s]', '', simplified)
        value = re.fullmatch(r'0x([0-9a-fA-F]{8})[uU]?', simplified)
        if value is None:
            continue
        address_value = int(value[1], 16)
        name = context.data_symbols[module].get(address_value)
        if name is None:
            continue
        globals_.append(f'extern {match[1]} {name};')
        replacements.append((match.start(), finish, name))
    symbolic = body
    for start, finish, replacement in reversed(replacements):
        symbolic = symbolic[:start] + replacement + symbolic[finish:]

    if globals_:
        yield 'symbolic-globals', symbolic, declarations + '\n' + '\n'.join(sorted(set(globals_))) + '\n'
        typed_declarations, typed_body, changed_calls = recover_sdk_calls(ROOT, module, declarations, symbolic)
        if changed_calls:
            yield 'typed-sdk-globals', typed_body, typed_declarations + '\n' + '\n'.join(sorted(set(globals_))) + '\n'


def candidates(context, include_known=False, modules=None, minimum=1, maximum=32768):
    known = set()
    if not include_known:
        for name in ['local-byte-exact.tsv', 'local-linked-byte-exact.tsv']:
            known.update((r['module'], int(r['address'], 16)) for r in csv.DictReader((ROOT / 'verification' / name).open(), delimiter='\t'))
    compat = clean((ROOT / 'src/ghidra_compat.h').read_text())
    types = {}
    for (module, address), (name, mode, size) in sorted(context.inventory.items()):
        if (module, address) in known or (modules and module not in modules) or not minimum <= size <= maximum:
            continue
        src = ROOT / 'src' / module / f'{address:08x}_{name}.c'
        if not src.exists():
            continue
        if module not in types:
            types[module] = clean((ROOT / 'src' / module / 'types.h').read_text())
        deps = src.parent / 'deps' / (src.stem + '.h')
        declarations = clean(deps.read_text()) if deps.exists() else ''
        original = context.original(module, address, size)
        body = clean(src.read_text())
        seen = set()
        for variant, transformed, decls in variants(context, module, address, original, body, declarations):
            source = PREAMBLE + compat + types[module] + decls + transformed
            key = digest(source.encode())
            if key in seen:
                continue
            seen.add(key)
            yield Candidate(module, name, mode, address, size, variant, source, original)


class Search:
    def __init__(self, context, compiler, wibo, cache, optimizations, stop_frontend_errors=True):
        self.context, self.compiler, self.wibo, self.cache = context, Path(compiler).resolve(), Path(wibo).resolve(), Path(cache)
        self.optimizations = optimizations
        self.stop_frontend_errors = stop_frontend_errors
        self.cache.mkdir(parents=True, exist_ok=True)
        self.fingerprint = digest(canonical({
            'version': 1, 'compiler': digest(self.compiler.read_bytes()), 'wibo': digest(self.wibo.read_bytes()),
            'python': sys.version, 'libraries': {name: importlib.metadata.version(name) for name in ['capstone', 'pyelftools']}, 'sources': {name: digest((ROOT / 'scripts' / name).read_bytes()) for name in ['batch_matching.py', 'matching_resolver.py', 'supplemental_symbols.py', 'arm_load_model.py']},
            'symbols': {mod: sorted(table.items()) for mod, table in context.local.items()},
            'all_symbols': {name: sorted(values) for name, values in context.allsyms.items()},
        }))

    def key(self, candidate, flags):
        return digest(canonical([self.fingerprint, candidate.module, candidate.name, candidate.mode, candidate.address,
                                 digest(candidate.original), digest(candidate.source.encode()), flags]))

    def compile(self, candidate, optimization, use_cache=True):
        processor = 'arm7tdmi' if candidate.module == 'arm7' else 'arm946e'
        flags = [optimization, '-enum', 'int', '-lang', 'c99', '-char', 'signed', '-interworking', '-proc', processor, '-gccext,on']
        if candidate.mode == 'thumb':
            flags.append('-thumb')
        key = self.key(candidate, flags)
        lock = self.cache / 'locks' / (key + '.lock')
        lock.parent.mkdir(parents=True, exist_ok=True)
        with lock.open('a') as stream:
            fcntl.flock(stream, fcntl.LOCK_EX)
            return self._compile_locked(candidate, optimization, flags, key, use_cache)

    def _compile_locked(self, candidate, optimization, flags, key, use_cache):
        directory = self.cache / key[:2] / key
        record = directory / 'result.json'
        obj = directory / 'candidate.o'
        if use_cache and record.exists():
            try:
                saved = json.loads(record.read_text())
            except (ValueError, OSError):
                saved = {}
            # Incomplete writes, timeouts and OS failures are never negative hits.
            if saved.get('key') == key and saved.get('outcome') in ['compile_error', 'mismatch', 'unresolved', 'exact']:
                if saved['outcome'] != 'exact':
                    return {**saved, 'cache_hit': True, 'compiles': 0}
                if obj.exists() and digest(obj.read_bytes()) == saved.get('object_sha256'):
                    code, relocs = self.context.linked(obj.read_bytes(), candidate.module, candidate.name, candidate.address)
                    if code == candidate.original:
                        return {**saved, 'cache_hit': True, 'compiles': 0, 'relocations': relocs, 'object': str(obj)}
        directory.mkdir(parents=True, exist_ok=True)
        src = self.cache / 'sources' / (digest(candidate.source.encode()) + '.c')
        src.parent.mkdir(parents=True, exist_ok=True)
        if not src.exists() or digest(src.read_bytes()) != digest(candidate.source.encode()):
            with tempfile.NamedTemporaryFile('w', dir=src.parent, prefix='.source-', delete=False) as stream:
                stream.write(candidate.source)
                temporary_source = Path(stream.name)
            temporary_source.replace(src)
        obj.unlink(missing_ok=True)
        started = time.monotonic()
        try:
            result = subprocess.run([str(self.wibo), str(self.compiler), *flags, '-c', str(src), '-o', str(obj)], capture_output=True, timeout=30)
        except subprocess.TimeoutExpired:
            return {'outcome': 'timeout', 'compiles': 1, 'cache_hit': False}
        diagnostics = (result.stderr + result.stdout).decode(errors='replace')
        deterministic_error = result.returncode > 0 and re.search(r'(?:#\s+Error:|\berror:)', diagnostics) is not None
        saved = {'key': key, 'source': str(src), 'optimization': optimization, 'flags': flags, 'compile_seconds': time.monotonic()-started,
                 'outcome': 'compile_error' if deterministic_error else 'compiler_failure', 'diagnostic': diagnostics[:1000],
                 'frontend_error': bool(deterministic_error and re.search(r"\billegal implicit conversion\b|\bundefined identifier\b|\bdeclaration syntax error\b|\bfunction call '[^\n]+' does not match\b", diagnostics))}
        if result.returncode == 0:
            try:
                code, relocs = self.context.linked(obj.read_bytes(), candidate.module, candidate.name, candidate.address)
                saved.update(outcome='exact' if code == candidate.original else 'mismatch', bytes=len(code),
                             differing_bytes=sum(a != b for a, b in zip(code, candidate.original)) + abs(len(code)-len(candidate.original)),
                             object_sha256=digest(obj.read_bytes()), relocations=relocs)
            except (ValueError, StopIteration, KeyError) as error:
                saved.update(outcome='unresolved', diagnostic=str(error))
        atomic_json(record, saved)
        return {**saved, 'cache_hit': False, 'compiles': 1, 'object': str(obj)}

    def run(self, candidate, use_cache=True):
        results = []
        for index, optimization in enumerate(self.optimizations):
            result = self.compile(candidate, optimization, use_cache)
            results.append(result)
            if result['outcome'] == 'exact':
                break
            if self.stop_frontend_errors and result.get('frontend_error'):
                result['skipped_optimizations'] = len(self.optimizations)-index-1
                break
        return candidate, results


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--workers', type=int, default=4)
    parser.add_argument('--limit', type=int, default=300, help='Candidate variants, not accepted matches')
    parser.add_argument('--min-bytes', type=int, default=1)
    parser.add_argument('--max-bytes', type=int, default=32768)
    parser.add_argument('--module', action='append')
    parser.add_argument('--variant', action='append', help='Select named candidate transformations')
    parser.add_argument('--optimization', action='append', default=None)
    parser.add_argument('--cache', type=Path, default=ROOT / 'build/matching-cache')
    parser.add_argument('--summary', type=Path, default=ROOT / 'build/batch-matching.json')
    parser.add_argument('--queue', type=Path, help='Prioritize near misses from an earlier summary')
    parser.add_argument('--exhaustive-errors', action='store_true', help='Retry all optimization flags even for recognized frontend type/syntax failures')
    parser.add_argument('--fresh', action='store_true')
    parser.add_argument('--include-known', action='store_true', help='Benchmark/audit; does not alter registries')
    args = parser.parse_args()
    if args.workers < 1 or args.workers > 32 or args.limit < 1:
        parser.error('workers must be 1..32 and limit must be positive')
    started = time.monotonic()
    context = MatchingContext(ROOT, Path(os.environ.get('MKDS_BASELINE', ROOT / 'baseline')))
    search = Search(context, os.environ.get('MWCCARM', ROOT / 'tools/mwccarm/1.2/sp2p3/mwccarm.exe'),
                    os.environ.get('WIBO', ROOT / 'tools/wibo'), args.cache, args.optimization or ['-O4,p', '-O2', '-O3', '-O4,s', '-O1', '-O0'], not args.exhaustive_errors)
    pool = list(candidates(context, args.include_known, args.module, args.min_bytes, args.max_bytes))
    if args.variant:
        pool = [candidate for candidate in pool if candidate.variant in args.variant]
    priority = {}
    if args.queue:
        priority = {(r['module'], int(r['address'], 16)): index for index, r in enumerate(json.loads(args.queue.read_text()).get('near_misses', []))}
    pool.sort(key=lambda c: (priority.get((c.module, c.address), len(priority)), -c.size, c.module, c.address, c.variant))
    selected = pool[:args.limit]
    summary = {'fingerprint': search.fingerprint, 'workers': args.workers, 'available_candidates': len(pool),
               'selected': len(selected), 'completed': 0, 'compiler_invocations': 0, 'cache_hits': 0, 'optimization_attempts_skipped': 0, 'exact': [], 'near_misses': [], 'outcomes': {},
               'full_rom_link_verified': False}
    print(json.dumps({k: summary[k] for k in ['workers', 'available_candidates', 'selected']}), flush=True)
    with concurrent.futures.ThreadPoolExecutor(max_workers=args.workers) as executor:
        futures = [executor.submit(search.run, c, not args.fresh) for c in selected]
        for future in concurrent.futures.as_completed(futures):
            candidate, results = future.result()
            summary['completed'] += 1
            for result in results:
                summary['compiler_invocations'] += result['compiles']
                summary['cache_hits'] += int(result['cache_hit'])
                summary['optimization_attempts_skipped'] += result.get('skipped_optimizations', 0)
                summary['outcomes'][result['outcome']] = summary['outcomes'].get(result['outcome'], 0) + 1
            mismatches = [r for r in results if r['outcome'] == 'mismatch']
            if mismatches:
                best = min(mismatches, key=lambda r: r['differing_bytes'])
                near = {'module': candidate.module, 'address': hex(candidate.address), 'name': candidate.name,
                        'size': candidate.size, 'variant': candidate.variant, 'differing_bytes': best['differing_bytes'],
                        'optimization': best['optimization'], 'source': best['source']}
                previous = [r for r in summary['near_misses'] if (r['module'], r['address']) == (near['module'], near['address'])]
                if not previous or best['differing_bytes'] < previous[0]['differing_bytes']:
                    summary['near_misses'] = [r for r in summary['near_misses'] if (r['module'], r['address']) != (near['module'], near['address'])]
                    summary['near_misses'].append(near)
                summary['near_misses'].sort(key=lambda r: (r['differing_bytes'], -r['size'], r['module'], r['address']))
                del summary['near_misses'][100:]
            exact = next((r for r in results if r['outcome'] == 'exact'), None)
            if exact:
                item = {'module': candidate.module, 'address': hex(candidate.address), 'name': candidate.name,
                        'mode': candidate.mode, 'size': candidate.size, 'variant': candidate.variant,
                        'source': exact['source'], **exact}
                summary['exact'].append(item)
                print('EXACT', candidate.tag, candidate.size, candidate.variant, exact['optimization'], flush=True)
            summary['seconds'] = time.monotonic() - started
            atomic_json(args.summary, summary)
            if summary['completed'] % 100 == 0:
                print('Completed', summary['completed'], 'exact candidates', len(summary['exact']), flush=True)
    summary['seconds'] = time.monotonic() - started
    own, children = resource.getrusage(resource.RUSAGE_SELF), resource.getrusage(resource.RUSAGE_CHILDREN)
    summary['cpu_seconds_self_and_children'] = own.ru_utime + own.ru_stime + children.ru_utime + children.ru_stime
    summary['peak_python_rss_kib'] = own.ru_maxrss
    summary['largest_child_rss_kib'] = children.ru_maxrss
    atomic_json(args.summary, summary)
    print(json.dumps({k: v for k, v in summary.items() if k not in ['exact', 'near_misses']}), flush=True)


if __name__ == '__main__':
    main()
