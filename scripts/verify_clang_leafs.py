"""Extend local proofs only with identical whole-function bytes, no relocations.
Reuses the existing bounded straight-line candidate reconstruction. Preserves
all historical proofs; candidates that fail verification never replace sources.
"""
from pathlib import Path
import csv, hashlib, importlib.util, io, json, subprocess
from elftools.elf.elffile import ELFFile

root = Path(__file__).resolve().parents[1]
generator = (root/'scripts/verify_leafs.py').read_text().split("print('Candidates'")[0]
generator = generator.replace("if module=='arm7':continue", "if False:continue").replace('if size>48', 'if size>96').replace('stop>7', 'stop>16')
namespace = {'__file__': str(root/'scripts/verify_leafs.py')}
exec(compile(generator, 'leaf-candidate-generator', 'exec'), namespace)
# Small comparison leaves reconstructed directly from the ARM instructions.
templates = {
    0x0200e070: ('unsigned int', 'unsigned int p0', 'return *(const unsigned int *)(p0 + 0x64u) == 2u;'),
    0x0201694c: ('unsigned int', 'unsigned int p0', 'return *(const unsigned short *)(p0 + 0xcu) == 0u;'),
    0x02016960: ('unsigned int', 'unsigned int p0', 'return *(const unsigned short *)(p0 + 0xcu) == *(const unsigned int *)(p0 + 4u);'),
    0x020204b4: ('unsigned int', 'unsigned int p0', 'return p0 == 255u ? 254u : p0;'),
    0x0204a650: ('unsigned int', 'unsigned int p0', 'return *(const unsigned int *)(p0 + 8u) == 3u;'),
    0x01ff9c9c: ('void', 'unsigned int p0, unsigned int p1', 'p1 &= 0x1000000u; if (p1 != *(const unsigned int *)(p0 + 0x4c0u)) *(unsigned int *)(p0 + 0x4c0u) = p1;'),
    0x02010998: ('void', 'unsigned int p0, unsigned int p1, unsigned int p2', 'if (p1) *(unsigned int *)(p0 + 8u) = p1; if (p2) *(unsigned int *)(p0 + 0x18u) = p2;'),
}
for item in csv.DictReader((root/'baseline/pseudocode/arm9/index.tsv').open(), delimiter='\t'):
    address = int(item['address'], 16)
    if address not in templates:
        continue
    ret, params, body = templates[address]
    size = int(item['bytes'])
    original = namespace['target_bytes']('arm9', address, size)
    namespace['funcs'].append(dict(module='arm9', name=item['name'], mode='arm', address=address, size=size, original=original, source=f"{ret} {item['name']}({params})\n{{\n    {body}\n}}\n", kind='conditional_leaf'))
proof_path = root/'verification/local-byte-exact.tsv'
with proof_path.open() as f:
    reader = csv.DictReader(f, delimiter='\t')
    fields, proofs = reader.fieldnames, list(reader)
known = {(r['module'], int(r['address'],16)) for r in proofs}
zig = Path(importlib.util.find_spec('ziglang').origin).parent/'zig'
out = root/'build/clang-leafs'; out.mkdir(parents=True, exist_ok=True)
evidence = root/'verification/clang-leafs'; evidence.mkdir(parents=True, exist_ok=True)
accepted, tested = [], 0
history_path = evidence/'results.json'
history = json.loads(history_path.read_text()) if history_path.exists() else {'functions': []}
for candidate in namespace['funcs']:
    if (candidate['module'], candidate['address']) in known:
        continue
    tested += 1
    tag = candidate['module']+'_'+format(candidate['address'], '08x')
    source, obj = out/(tag+'.c'), out/(tag+'.o')
    source.write_text(candidate['source'])
    for optimize in ['-O1', '-O2', '-Oz']:
        cpu = 'arm7tdmi' if candidate['module']=='arm7' else 'arm946e_s'
        flags = ['-target','arm-freestanding-eabi','-mcpu='+cpu,'-std=gnu11',optimize,'-fno-builtin','-mthumb' if candidate['mode']=='thumb' else '-marm']
        result = subprocess.run([str(zig),'cc',*flags,'-c',str(source),'-o',str(obj)],capture_output=True,timeout=60)
        if result.returncode:
            continue
        elf = ELFFile(io.BytesIO(obj.read_bytes()))
        symbols = elf.get_section_by_name('.symtab')
        symbol = next((s for s in symbols.iter_symbols() if s.name==candidate['name']),None)
        if symbol is None or not isinstance(symbol['st_shndx'],int):
            continue
        section_id = symbol['st_shndx']; section = elf.get_section(section_id)
        start, size = symbol['st_value'] & ~1, symbol['st_size']
        relocations = [r for s in elf.iter_sections() if s['sh_type'] in ['SHT_REL','SHT_RELA'] and s['sh_info']==section_id for r in s.iter_relocations()]
        code = section.data()
        # Require the entire text section, symbol and inventory function to agree.
        if relocations or start != 0 or size != len(code) or code != candidate['original']:
            continue
        dest = root/'src'/candidate['module']/f"{candidate['address']:08x}_{candidate['name']}.c"
        if not dest.is_file():
            break
        backup = evidence/'previous'/candidate['module']; backup.mkdir(parents=True,exist_ok=True)
        (backup/dest.name).write_bytes(dest.read_bytes())
        dest.write_text('/* High-level C; whole-function bytes verified with Zig 0.14.1 Clang.\n * Zero relocations; whole-ROM linking remains unverified. */\n'+candidate['source'])
        (root/'verification/leafs'/(tag+'.original.hex')).write_text(code.hex()+'\n')
        (evidence/(tag+'.o')).write_bytes(obj.read_bytes())
        row = {key:candidate[key] for key in ['module','name','mode','size','kind']}
        row.update(address=f"0x{candidate['address']:08x}",sha256=hashlib.sha256(code).hexdigest(),source_sha256=hashlib.sha256(dest.read_bytes()).hexdigest(),relocations=0,status='EXACT_LOCAL_BYTES')
        proofs.append(row)
        accepted.append(dict(row, compiler='Zig 0.14.1 bundled Clang',flags=flags,object_sha256=hashlib.sha256(obj.read_bytes()).hexdigest()))
        break
    if tested%25 == 0:
        print('Tested',tested,'new exact',len(accepted),flush=True)
with proof_path.open('w',newline='') as f:
    writer = csv.DictWriter(f,fieldnames=fields,delimiter='\t'); writer.writeheader(); writer.writerows(proofs)
all_accepted = history['functions'] + accepted
report = {'tested_candidates_this_run':tested,'accepted_this_run':len(accepted),'accepted':len(all_accepted),'added_bytes':sum(r['size'] for r in all_accepted),'functions':all_accepted,'whole_rom_verified':False}
(evidence/'results.json').write_text(json.dumps(report,indent=2)+'\n')
print(json.dumps({k:v for k,v in report.items() if k!='functions'}),flush=True)
