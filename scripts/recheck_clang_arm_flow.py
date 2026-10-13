"""Recompile Clang ARM flow proofs and compare entire text against ROM sections."""
import csv
import hashlib
import importlib.util
import io
import json
import os
from pathlib import Path
import subprocess
from elftools.elf.elffile import ELFFile

root = Path(__file__).resolve().parents[1]
base = Path(os.environ.get('MKDS_BASELINE', str(root / 'baseline')))
manifest = json.loads((base / 'manifest.json').read_text())
sections = {m['name']: [(s['base'], (base / 'binaries' / s['file']).read_bytes())
                        for s in m['sections']] for m in manifest['modules']}
zig = Path(importlib.util.find_spec('ziglang').origin).parent / 'zig'
rows = [r for r in csv.DictReader((root / 'verification/local-byte-exact.tsv').open(), delimiter='\t')
        if r['kind'] in ['clang_arm_control_flow', 'clang_multiple_transfers']]
out = root / 'build/clang-arm-flow-recheck'
out.mkdir(parents=True, exist_ok=True)
results = []
for r in rows:
    address, size = int(r['address'], 16), int(r['size'])
    tag = f"{r['module']}_{address:08x}"
    source = root / 'src' / r['module'] / f"{address:08x}_{r['name']}.c"
    assert hashlib.sha256(source.read_bytes()).hexdigest() == r['source_sha256']
    original = next(data[address-start:address-start+size] for start, data in sections[r['module']]
                    if start <= address and address + size <= start + len(data))
    flags = ['-target', 'arm-freestanding-eabi',
             '-mcpu=' + ('arm7tdmi' if r['module'] == 'arm7' else 'arm946e_s'),
             r['optimization'], '-std=gnu11', '-fno-builtin', '-mthumb' if r['mode']=='thumb' else '-marm']
    obj = out / (tag + '.o')
    subprocess.run([str(zig), 'cc', *flags, '-c', str(source), '-o', str(obj)], check=True)
    elf = ELFFile(io.BytesIO(obj.read_bytes()))
    symbol = next(s for s in elf.get_section_by_name('.symtab').iter_symbols() if s.name == r['name'])
    index = symbol['st_shndx']
    code = elf.get_section(index).data()
    assert (symbol['st_value'] & ~1) == 0 and symbol['st_size'] == len(code) == size
    assert not any(s['sh_type'] in ['SHT_REL', 'SHT_RELA'] and s['sh_info'] == index and s['sh_size']
                   for s in elf.iter_sections())
    assert code == original == bytes.fromhex((root / 'verification/leafs' / (tag + '.original.hex')).read_text())
    assert hashlib.sha256(code).hexdigest() == r['sha256']
    results.append(dict(module=r['module'], address=r['address'], size=size, flags=flags,
                        source_sha256=r['source_sha256'], object_sha256=hashlib.sha256(obj.read_bytes()).hexdigest()))
report = dict(compiler='Zig 0.14.1 bundled Clang', tested=len(rows), passed=len(rows),
              bytes=sum(int(r['size']) for r in rows), functions=results,
              verification='Fresh compilation; whole text equals extracted original; zero text relocations.',
              full_rom_link_verified=False)
(root / 'verification/clang-arm-flow-recheck.json').write_text(json.dumps(report, indent=2) + '\n')
print(json.dumps({k: v for k, v in report.items() if k != 'functions'}))
