"""Reconstruct SDK C candidates; accept only freshly compiled, fully resolved exact bytes.

Preliminary relocation-slot signature filtering is only a search accelerator.
Every installed source is compiled again, and every relocated byte is checked.
"""
from pathlib import Path
import csv, hashlib, io, json, os, re, subprocess
from capstone import Cs, CS_ARCH_ARM, CS_MODE_ARM, CS_MODE_THUMB
from elftools.elf.elffile import ELFFile

root = Path(__file__).resolve().parents[1]
donor = Path(os.environ['MKDS_SDK_DONOR']).resolve()
config_path = os.environ.get('MKDS_DONOR_CONFIG')
config = json.loads(Path(config_path).read_text()) if config_path else {}
donor_commit = subprocess.check_output(['git', '-C', str(donor), 'rev-parse', 'HEAD'], text=True).strip()
donor_repository = subprocess.check_output(['git', '-C', str(donor), 'remote', 'get-url', 'origin'], text=True).strip()
namespace = {'__file__': str(root / 'scripts/verify_resolved_calls.py')}
exec(compile((root / 'scripts/verify_resolved_calls.py').read_text().split("out=root/'verification/resolved-calls'")[0], 'sdk-resolver', 'exec'), namespace)
inventory, original, resolve_link = namespace['inventory'], namespace['original'], namespace['linked']
up = root / 'verification/local-byte-exact.tsv'
lp = root / 'verification/local-linked-byte-exact.tsv'
u = list(csv.DictReader(up.open(), delimiter='\t'))
l = list(csv.DictReader(lp.open(), delimiter='\t'))
known = {(r['module'], int(r['address'], 16)) for r in u + l}
by_size = {}
for (module, address), (name, mode, size) in inventory.items():
    if (module, address) not in known and size >= 16:
        by_size.setdefault(size, []).append((module, address, name, mode, original(module, address, size)))
proof_path = root / 'verification/sdk-source-proofs.json'
proofs = json.loads(proof_path.read_text()) if proof_path.exists() else {}
extra_path = root / 'verification/sdk-extra-symbols.tsv'
extras = list(csv.DictReader(extra_path.open(), delimiter='\t')) if extra_path.exists() else []
out = root / 'build/sdk-source-candidates'; out.mkdir(parents=True, exist_ok=True)
flags = '-O4,p -enum int -lang c99 -char signed -interworking -proc arm946e -gccext,on -inline on,noauto -gccinc -fp soft'.split()
for directory in ['include-mw', 'arm9/lib/MSL_C/include', 'arm9/lib/libnns/include', 'arm9/lib/NitroSDK/include']:
    flags += ['-ir', 'vendor/pokediamond/' + directory]
flags = config.get('flags', flags)
object_manifest = config.get('objects', {})

def function_source(text, name):
    # Preserve source positions while ignoring braces in comments and strings.
    clean = re.sub(r'/\*.*?\*/|//[^\n]*|"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'',
                   lambda m: ''.join('\n' if c == '\n' else ' ' for c in m.group()), text, flags=re.S)
    match = re.search(r'\b' + re.escape(name) + r'\s*\([^;{}]*\)\s*\{', clean)
    if not match: return None
    start = clean.rfind('\n', 0, match.start()) + 1
    opening = clean.index('{', match.start()); end = opening + 1; depth = 1
    while end < len(clean) and depth:
        depth += (clean[end] == '{') - (clean[end] == '}'); end += 1
    if depth: return None
    source = text[start:end]
    if re.search(r'\b(?:asm|__asm|__asm__)\b', source): return None
    source = re.sub(r'^\s*static\s+', '', source)
    return source

def save_registry(path, rows):
    tmp = path.with_suffix('.tmp')
    with tmp.open('w', newline='') as stream:
        writer = csv.DictWriter(stream, fieldnames=list(rows[0]), delimiter='\t'); writer.writeheader(); writer.writerows(rows)
    tmp.replace(path)

accepted = 0; tested = 0; errors = []
for obj in sorted((root / config.get('object_directory', 'build/sdk')).glob('*.o')):
    if object_manifest and obj.name not in object_manifest: continue
    paths = [donor / object_manifest[obj.name]['source']] if obj.name in object_manifest else [p for folder in ['arm9/lib/NitroSDK/src', 'arm9/lib/libnns/src', 'arm9/lib/syscall'] for p in (donor / folder).rglob(obj.stem + '.c')]
    if len(paths) != 1: continue
    donor_file = paths[0]; text = donor_file.read_text()
    for include in config.get('drop_includes', []):
        text = re.sub(r'^\s*#include\s*"' + re.escape(include) + r'"[^\n]*\n', '', text, flags=re.M)
    current_flags = object_manifest.get(obj.name, {}).get('flags', flags)
    elf = ELFFile(io.BytesIO(obj.read_bytes())); symtab = elf.get_section_by_name('.symtab')
    for symbol in symtab.iter_symbols():
        if symbol['st_info']['type'] != 'STT_FUNC' or not isinstance(symbol['st_shndx'], int): continue
        start, size = symbol['st_value'] & ~1, symbol['st_size']
        body = function_source(text, symbol.name)
        if body is None or size not in by_size: continue
        index = symbol['st_shndx']; code = elf.get_section(index).data()[start:start+size]
        relocations = []
        for section in elf.iter_sections():
            if section['sh_type'] not in ['SHT_REL', 'SHT_RELA'] or section['sh_info'] != index: continue
            if section['sh_type'] != 'SHT_RELA': continue
            for relocation in section.iter_relocations():
                if start <= relocation['r_offset'] < start + size:
                    relocations.append((relocation['r_offset'] - start, relocation['r_info_type'],
                                        elf.get_section(section['sh_link']).get_symbol(relocation['r_info_sym']).name,
                                        relocation['r_addend']))
        skipped = {j for off, typ, _, _ in relocations for j in range(off, off+4)}
        for module, address, name, mode, target in by_size[size]:
            if bool(symbol['st_value'] & 1) != (mode == 'thumb'): continue
            if (module, address) in known or any(code[j] != target[j] for j in range(size) if j not in skipped): continue
            bindings = {}; data_symbols = []; valid = True
            for off, typ, callee, addend in relocations:
                if typ in [1, 10]:
                    decoded = list(Cs(CS_ARCH_ARM, CS_MODE_ARM if mode == 'arm' else CS_MODE_THUMB).disasm(target[off:off+4], address+off))
                    if len(decoded) != 1 or decoded[0].mnemonic not in ['b','bl','blx']: valid = False; break
                    destination = int(decoded[0].op_str.lstrip('#'), 0)
                    entry = inventory.get((module, destination))
                    if entry is None: valid = False; break
                    replacement = entry[0]
                elif typ == 2:
                    destination = (int.from_bytes(target[off:off+4], 'little') - addend) & 0xffffffff
                    replacement = f'SDK_data_{destination:08x}'
                    data_symbols.append(dict(module=module, name=replacement, address=f'0x{destination:08x}', thumb='0'))
                else: valid = False; break
                if callee in bindings and bindings[callee] != replacement: valid = False; break
                bindings[callee] = replacement
            if not valid: continue
            bindings[symbol.name] = name
            if any(new in bindings and new!=old and bindings[new]!=new for old,new in bindings.items()):continue
            preamble = '\n'.join(f'#define {old} {new}' for old,new in bindings.items() if old != new) + '\n'
            includes = '\n'.join(re.findall(r'^\s*#include[^\n]+', text, flags=re.M))
            # File-local data needs an external typed declaration at the observed original address.
            declarations = []
            for old in bindings:
                if old == symbol.name: continue
                declaration = re.search(r'^[^#\n{};]*\b' + re.escape(old) + r'\s*(?:\[[^\]]*\]\s*)*(?=;|=)', text, flags=re.M)
                if declaration and '(' not in declaration.group():
                    value = re.sub(r'\b(?:static|extern)\s+', '', declaration.group()).strip()
                    declarations.append('extern ' + value + ';')
                helper = function_source(text, old)
                if helper:
                    declarations.append('extern ' + helper[:helper.index('{')].strip() + ';')
            source = '/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */\n' + preamble + includes + '\n' + '\n'.join(declarations) + '\n' + ('#pragma thumb on\n' if mode=='thumb' else '#pragma thumb off\n') + body + '\n'
            if config.get('complete_translation_unit'):
                clean = re.sub(r'/\*.*?\*/|//[^\n]*|"(?:\\.|[^"\\])*"', '', text, flags=re.S)
                if re.search(r'\b(?:asm|__asm|__asm__)\b', clean): continue
                source = '/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */\n' + preamble + text
                for old, replacement in config.get('include_rewrites', {}).items():
                    source = re.sub(r'(#\s*include\s*")' + re.escape(old) + r'(")',
                                    lambda m: m.group(1) + replacement + m.group(2), source)
            tag = f'{module}_{address:08x}'; src = out / (tag + '.c'); fresh = src.with_suffix('.o'); src.write_text(source); tested += 1
            result = subprocess.run([os.environ['WIBO'], os.environ['MWCCARM'], *current_flags, '-c', str(src), '-o', str(fresh)], cwd=root, capture_output=True, timeout=60)
            if result.returncode:
                errors.append(dict(tag=tag, error=result.stderr.decode(errors='replace')[:1200])); continue
            previous = {}
            for item in data_symbols:
                previous[item['name']] = namespace['local'][module].get(item['name'])
                namespace['local'][module][item['name']] = (int(item['address'],16), False)
            try: actual, applied = resolve_link(fresh.read_bytes(), module, name, address)
            except (ValueError, KeyError, StopIteration, TypeError, IndexError): actual = None
            for key, value in previous.items():
                if value is None: namespace['local'][module].pop(key, None)
                else: namespace['local'][module][key] = value
            if actual != target: continue
            dest = root / 'src' / module / f'{address:08x}_{name}.c'
            backup = root / 'verification/previous_drafts' / module / dest.name; backup.parent.mkdir(parents=True, exist_ok=True)
            if not backup.exists(): backup.write_bytes(dest.read_bytes())
            dest.write_text(source)
            for item in data_symbols:
                if item not in extras: extras.append(item)
            if extras: save_registry(extra_path, extras)
            row = dict(module=module, name=name, mode=mode, address=f'0x{address:08x}', size=size,
                       sha256=hashlib.sha256(actual).hexdigest(), source_sha256=hashlib.sha256(dest.read_bytes()).hexdigest(),
                       relocations=len(applied), optimization=next(f for f in current_flags if f.startswith('-O')), processor=current_flags[current_flags.index('-proc')+1],
                       status='EXACT_LOCAL_LINKED_BYTES' if applied else 'EXACT_LOCAL_BYTES')
            proofs[tag] = dict(flags=current_flags, donor_source=str(donor_file.relative_to(donor)), donor_function=symbol.name,
                               source_sha256=row['source_sha256'], bindings=bindings, donor_repository=donor_repository, donor_commit=donor_commit,
                               donor_source_sha256=hashlib.sha256(donor_file.read_bytes()).hexdigest())
            proofs[tag]['complete_translation_unit'] = bool(config.get('complete_translation_unit'))
            if config.get('drop_includes'): proofs[tag]['dropped_includes'] = config['drop_includes']
            proof_path.write_text(json.dumps(proofs, indent=2) + '\n')
            if applied:
                evidence = root / 'verification/resolved-calls'
                (evidence / (tag + '.linked.hex')).write_text(actual.hex() + '\n')
                (evidence / (tag + '.relocations.json')).write_text(json.dumps(applied, indent=2) + '\n')
                l.append(row); save_registry(lp, l)
            else:
                evidence = root / 'verification/leafs'
                (evidence / (tag + '.original.hex')).write_text(actual.hex() + '\n')
                (evidence / (tag + '.c')).write_text(source)
                row['kind'] = 'sdk_source'; u.append(row); save_registry(up, u)
            (evidence / (tag + '.o')).write_bytes(fresh.read_bytes())
            known.add((module,address)); accepted += 1
            print('SDK MATCH', tag, symbol.name, size, flush=True)
search_directory = root / config.get('object_directory', 'build/sdk')
search_directory.mkdir(parents=True, exist_ok=True)
(search_directory / 'source-search-errors.json').write_text(json.dumps(errors,indent=2)+'\n')
(search_directory / 'source-search-summary.json').write_text(json.dumps(dict(tested=tested, accepted=accepted), indent=2)+'\n')
print(json.dumps(dict(tested=tested, accepted=accepted)), flush=True)
