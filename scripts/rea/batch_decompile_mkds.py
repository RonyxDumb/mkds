#!/usr/bin/env python3
"""Analyze one bounded, same-ISA MKDS group through one persistent REA session.

This exports analysis drafts only. It does not alter matching proofs or replace
source files. --one-shot runs equivalent CLI calls for a timing comparison.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import queue
import subprocess
import threading
import time
from decompile_mkds import ROOT, prepare


class ReaSession:
    def __init__(self, environment, log):
        self.log = log.open('w')
        self.process = subprocess.Popen(['sh', str(ROOT / 'scripts/rea/run.sh'), 'mcp'],
                                        stdin=subprocess.PIPE, stdout=subprocess.PIPE,
                                        stderr=self.log, text=True, bufsize=1, env=environment)
        self.responses = queue.Queue()
        self.serial = 0
        self.reader = threading.Thread(target=self.read, daemon=True)
        self.reader.start()
        self.initialized = False

    def initialize(self):
        self.request('initialize', {'protocolVersion': '2025-03-26', 'capabilities': {},
                                   'clientInfo': {'name': 'mkds-batch', 'version': '1'}})
        self.send({'jsonrpc': '2.0', 'method': 'notifications/initialized'})
        self.initialized = True

    def read(self):
        try:
            for line in self.process.stdout:
                self.responses.put(json.loads(line))
        except Exception as error:
            self.responses.put(error)
        finally:
            self.responses.put(EOFError('REA stdout closed'))

    def send(self, message):
        self.process.stdin.write(json.dumps(message) + '\n')
        self.process.stdin.flush()

    def request(self, method, params):
        self.serial += 1
        self.send({'jsonrpc': '2.0', 'id': self.serial, 'method': method, 'params': params})
        deadline = time.monotonic() + 240
        while True:
            result = self.responses.get(timeout=max(0.001, deadline-time.monotonic()))
            if isinstance(result, Exception):
                raise result
            if result.get('id') != self.serial:
                continue
            if 'error' in result:
                raise RuntimeError(str(result['error']))
            return result['result']

    def call(self, name, arguments):
        result = self.request('tools/call', {'name': name, 'arguments': arguments})
        if result.get('isError'):
            raise RuntimeError(json.dumps(result))
        structured = result.get('structuredContent')
        if structured is None:
            content = result.get('content', [])
            structured = next((json.loads(item['text']) for item in content if item.get('type') == 'text'), None)
        if structured is None:
            raise RuntimeError('REA returned no structured result')
        return structured

    def close(self):
        try:
            if self.initialized and self.process.poll() is None:
                self.call('close_binary', {})
        finally:
            if not self.process.stdin.closed:
                self.process.stdin.close()
            try:
                self.process.wait(timeout=20)
            except subprocess.TimeoutExpired:
                self.process.terminate()
                self.process.wait(timeout=10)
            self.log.close()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('module')
    parser.add_argument('addresses', nargs='+', type=lambda value: int(value, 0))
    parser.add_argument('--mode', choices=['arm', 'thumb'])
    parser.add_argument('--output', type=Path, help='Explicit run directory; default separates module, target hash and ISA')
    parser.add_argument('--one-shot', action='store_true')
    args = parser.parse_args()
    started = time.monotonic()
    targets = [prepare(args.module, address, args.mode)[1] for address in sorted(set(args.addresses))]
    if len({row['mode'] for row in targets}) != 1 or len({row['section'] for row in targets}) != 1:
        parser.error('A batch requires one module section and one entry ISA; split mixed groups')
    start = min(int(row['address'], 16) for row in targets)
    end = max(int(row['address'], 16) + row['bytes'] for row in targets)
    if end-start > 1024*1024:
        parser.error('Batch spans over 1 MiB; split into smaller groups')
    section = (ROOT / 'baseline/binaries' / targets[0]['section']).read_bytes()
    offset = targets[0]['section_offset']
    data = section[offset:offset+end-start]
    run_directory = args.output or ROOT / 'build/rea-batch' / (args.module + '_' + hashlib.sha256(data).hexdigest()[:16] + '_' + targets[0]['mode'])
    run_directory.mkdir(parents=True, exist_ok=True)
    output = run_directory.resolve()
    target = output / 'group.bin'
    seeds = output / 'seeds.tsv'
    target.write_bytes(data)
    seeds.write_text(''.join(f"{row['address']}\tfunction\t{row['name']}\n" for row in targets))
    environment = dict(os.environ, REA_ANALYSIS_PROVIDER='ghidra',
                       REA_GHIDRA_ARM_PROFILE=targets[0]['profile'], REA_GHIDRA_ARM_MODE=targets[0]['mode'],
                       REA_GHIDRA_SEED_FILE=str(seeds))
    session = None
    summary = {'mode': 'one-shot' if args.one_shot else 'persistent-mcp', 'module': args.module,
               'target_sha256': hashlib.sha256(data).hexdigest(), 'base_address': hex(start), 'bytes': len(data),
               'targets': targets, 'results': [], 'matching_claim': False,
               'limitations': ['Single initialized span only; external memory and callees remain incomplete.',
                              'Entry mode is explicit for the group; mixed ISA groups are rejected.']}
    try:
        if not args.one_shot:
            session = ReaSession(environment, output / 'stderr.log')
            session.initialize()
            # Resolve operations by exact contract names, never catalog ordering.
            tools = session.request('tools/list', {})
            available = {tool['name'] for tool in tools['tools']}
            if not {'open_binary', 'procedure_pseudo_code', 'close_binary'} <= available:
                raise RuntimeError('Required REA MCP contracts are unavailable')
            opened = session.call('open_binary', {'path': str(target), 'format': 'raw-binary',
                                                'architecture': 'arm', 'entry_point': hex(start), 'provider_id': 'ghidra'})
            (output / 'open-result.json').write_text(json.dumps(opened, indent=2)+'\n')
        for row in targets:
            before = time.monotonic()
            if session:
                evidence = session.call('procedure_pseudo_code', {'procedure': row['address']})
            else:
                result = subprocess.run(['sh', str(ROOT / 'scripts/rea/run.sh'), 'decompile', str(target), row['address'],
                                         '--provider', 'ghidra', '--target-format', 'raw-binary', '--architecture', 'arm',
                                         '--entry-point', hex(start), '--format', 'json'], env=environment,
                                        capture_output=True, text=True, timeout=240)
                if result.returncode:
                    raise RuntimeError(result.stderr or result.stdout)
                evidence = json.loads(result.stdout)
            parameters = evidence['analysis_profile']['parameters']
            if (evidence['subject']['digest']['sha256'] != summary['target_sha256'] or
                    parameters.get('arm_entry_mode') != row['mode'] or
                    parameters['language_id'] != ('ARM:LE:32:v4t' if args.module == 'arm7' else 'ARM:LE:32:v5t') or
                    int(parameters['entry_point'], 16) != start):
                raise RuntimeError('Evidence target/profile mismatch')
            if evidence['operation'] != 'procedure_pseudo_code' or evidence['parameters']['procedure'] != row['address']:
                raise RuntimeError('Evidence operation/selector mismatch')
            code = evidence.get('normalized_result')
            name = f"{int(row['address'],16):08x}"
            (output / (name+'.evidence.json')).write_text(json.dumps(evidence, separators=(',', ':'))+'\n')
            draft = output / (name+'.draft.c')
            if isinstance(code, str) and code.strip():
                draft.write_text(code)
            else:
                draft.unlink(missing_ok=True)
            summary['results'].append({'address': row['address'], 'seconds': time.monotonic()-before,
                                       'has_pseudocode': isinstance(code, str) and bool(code.strip()),
                                       'pseudocode_sha256': hashlib.sha256((code or '').encode()).hexdigest()})
            summary['seconds_before_close'] = time.monotonic()-started
            (output / 'summary.json').write_text(json.dumps(summary, indent=2)+'\n')
            print(json.dumps(summary['results'][-1]), flush=True)
    finally:
        if session:
            session.close()
    summary['seconds'] = time.monotonic()-started
    summary['provider_sessions'] = len(targets) if args.one_shot else 1
    (output / 'summary.json').write_text(json.dumps(summary, indent=2)+'\n')
    print(json.dumps({key: summary[key] for key in ['mode','seconds','provider_sessions']}), flush=True)


if __name__ == '__main__':
    main()
