from pathlib import Path
import csv,re
root=Path(__file__).resolve().parents[1]
operations=set();normal=[]
for p in sorted((root/'src').iterdir()):
 if not p.is_dir():continue
 rows=list(csv.DictReader((p/'index.tsv').open(),delimiter='\t'));names={r['name'] for r in rows};protos={}
 for line in (p/'prototypes.h').read_text().splitlines():
  matches=set(re.findall(r'\b([A-Za-z_]\w*)\s*\(',line))&names
  if line.endswith(';') and len(matches)==1:protos[next(iter(matches))]=line
 for r in rows:
  if r['status']!='OK':continue
  f=p/r['file'];text=f.read_text();used=set(re.findall(r'\b[A-Za-z_]\w*\b',text));decls=[protos[n] for n in sorted(used&protos.keys())]
  (p/'deps'/f.name.replace('.c','.h')).write_text('#pragma once\n/* Function-specific inferred declarations. */\n'+'\n'.join(decls)+'\n'+(p/'deps'/f.name.replace('.c','.globals.h')).read_text())
  operations.update(re.findall(r'\b(CONCAT\d\d|SUB\d\d|ZEXT\d\d|SEXT\d\d)\s*\(',text))
  text,n=re.subn(r'\b([A-Za-z_]\w*)\._(\d+)_(1|2|4|8)_\b',lambda m:f'MKDS_SLICE_{m[3]}({m[1]},{m[2]})',text)
  if n:f.write_text(text);normal.append({'file':str(f.relative_to(root)),'replacements':n})
header=root/'src/ghidra_compat.h';text=header.read_text()
for op in sorted(operations):
 a=int(op[-2]);b=int(op[-1]);out=a+b if op.startswith('CONCAT') else b;typ='uint32_t' if out<=4 else 'uint64_t'
 if op.startswith('CONCAT'):
  text+=f'#define {op}(hi,lo) (({typ})((((uint64_t)(hi)&0x{(1<<(8*a))-1:x}ULL)<<{8*b})|((uint64_t)(lo)&0x{(1<<(8*b))-1:x}ULL)))\n'
 elif op.startswith('SUB'):text+=f'#define {op}(v,n) (({typ})((uint64_t)(v)>>(8u*(n))))\n'
 elif op.startswith('ZEXT') and a in [1,2,4,8]:text+=f'#define {op}(v) (({typ})(uint{8*a}_t)(v))\n'
for n in [1,2,4,8]:text+=f'typedef uint{8*n}_t mkds_alias_u{8*n} __attribute__((may_alias,aligned(1)));\n#define MKDS_SLICE_{n}(obj,n) (*(mkds_alias_u{8*n} *)((uint8_t *)&(obj)+(n)))\n'
header.write_text(text)
with (root/'checks/slice-normalization.tsv').open('w',newline='') as f:
 w=csv.DictWriter(f,fieldnames=['file','replacements'],delimiter='\t');w.writeheader();w.writerows(normal)
print('Prepared',sum(len(list(p.glob('*.c'))) for p in (root/'src').iterdir() if p.is_dir()),'C files')
