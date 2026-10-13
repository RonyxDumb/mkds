"""Recompile every new Clang proof, then verify full unrelocated text bytes."""
from pathlib import Path
import hashlib, importlib.util, json, subprocess, sys
sys.path.insert(0, str(Path(__file__).resolve().parent))
root = Path(__file__).resolve().parents[1]
zig = Path(importlib.util.find_spec('ziglang').origin).parent/'zig'
report = json.loads((root/'verification/clang-leafs/results.json').read_text())
from elftools.elf.elffile import ELFFile
import io
out = root/'build/clang-proof-recheck'; out.mkdir(parents=True, exist_ok=True)
for row in report['functions']:
    source = root/'src'/row['module']/(row['address'][2:]+'_'+row['name']+'.c')
    assert hashlib.sha256(source.read_bytes()).hexdigest() == row['source_sha256']
    obj = out/(row['module']+'_'+row['address'][2:]+'.o')
    subprocess.run([str(zig),'cc',*row['flags'],'-c',str(source),'-o',str(obj)], check=True)
    elf = ELFFile(io.BytesIO(obj.read_bytes()))
    texts = [(i,s.data()) for i,s in enumerate(elf.iter_sections()) if s.name.startswith('.text') and s['sh_size']]
    assert len(texts) == 1
    text_index, code = texts[0]
    assert not any(s['sh_type'] in ['SHT_REL','SHT_RELA'] and s['sh_info']==text_index and s['sh_size'] for s in elf.iter_sections())
    expected = bytes.fromhex((root/'verification/leafs'/(row['module']+'_'+row['address'][2:]+'.original.hex')).read_text())
    assert code == expected and len(code) == row['size']
    assert hashlib.sha256(code).hexdigest() == row['sha256']
result = {'tested':len(report['functions']), 'status':'PASS', 'verification':'Fresh compilation; entire text byte equality, zero text relocations. Unwind metadata is outside local code proof.'}
(root/'verification/clang-leafs/recheck.json').write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps(result))
