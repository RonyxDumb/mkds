"""Extend local proofs only with identical whole-function bytes, no relocations.
Reuses the existing bounded straight-line candidate reconstruction. Preserves
all historical proofs; candidates that fail verification never replace sources.
"""
from pathlib import Path
import csv, hashlib, importlib.util, io, json, subprocess
from elftools.elf.elffile import ELFFile

root = Path(__file__).resolve().parents[1]
generator = (root/'scripts/verify_multiple_transfers.py').read_text().split("print('Candidates'")[0]
namespace = {'__file__': str(root/'scripts/verify_multiple_transfers.py')}
exec(compile(generator, 'multiple-candidate-generator', 'exec'), namespace)
proof_path = root/'verification/local-byte-exact.tsv'
with proof_path.open() as f:
    reader = csv.DictReader(f, delimiter='\t')
    fields, proofs = reader.fieldnames, list(reader)
known = {(r['module'], int(r['address'],16)) for r in proofs}
zig = Path(importlib.util.find_spec('ziglang').origin).parent/'zig'
out = root/'build/clang-leafs'; out.mkdir(parents=True, exist_ok=True)
evidence = root/'verification/clang-multiple-transfers'; evidence.mkdir(parents=True, exist_ok=True)
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
    for optimize in ['-O1', '-O2', '-O3', '-Oz', '-O0']:
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
        row['kind']='clang_multiple_transfers'
        row['optimization']=optimize
        row['processor']=cpu
        row.update(address=f"0x{candidate['address']:08x}",sha256=hashlib.sha256(code).hexdigest(),source_sha256=hashlib.sha256(dest.read_bytes()).hexdigest(),relocations=0,status='EXACT_LOCAL_BYTES')
        proofs.append(row)
        with proof_path.open('w',newline='') as checkpoint:
            writer=csv.DictWriter(checkpoint,fieldnames=fields,delimiter='\t');writer.writeheader();writer.writerows(proofs)
        print('MATCH',tag,candidate['size'],optimize,flush=True)
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
