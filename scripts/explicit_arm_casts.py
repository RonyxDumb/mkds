"""Make existing ARM32 word/pointer argument reinterpretations explicit.
Does not infer or certify the ABI; never changes the called function or its argument count.
Only object pointers and integer words <=32 bits are accepted, with uintptr_t as bridge.
"""
from pathlib import Path
import re,json,hashlib
root=Path(__file__).resolve().parents[1];out=root/'verification/explicit_arm_casts';out.mkdir(exist_ok=True)
ints={'int','uint','undefined4','uint32_t','int32_t','long','ulong','unsigned int','unsigned long','uintptr_t','intptr_t','unsigned char','char','byte','undefined','undefined1','undefined2','short','ushort','unsigned short','uint8_t','uint16_t','int8_t','int16_t','bool'}
word={'int','uint','undefined4','uint32_t','int32_t','long','ulong','unsigned int','unsigned long','uintptr_t','intptr_t'}
def pointer(t):return bool(re.fullmatch(r'(?:const\s+)?(?:struct\s+)?[A-Za-z_]\w*(?:\s+[A-Za-z_]\w*)*\s*(?:\*\s*(?:const\s*)?)+',t)) and not re.search(r'\bcode\b',t)
def arguments(text):
 result=[]
 for m in re.finditer(r'\b[A-Za-z_]\w*\s*\(',text):
  if m[0].split('(')[0].strip() in ['if','while','for','switch','sizeof']:continue
  start=m.end();i=start;stack=[')'];parts=[]
  while i<len(text) and stack:
   c=text[i]
   if c in '([{':stack.append({'(':')','[':']','{':'}'}[c])
   elif c in ')]}':
    if c!=stack[-1]:break
    stack.pop()
    if not stack:parts.append((start,i));break
   elif c==',' and len(stack)==1:parts.append((start,i));start=i+1
   i+=1
  if not stack:
   result.extend(parts)
 return result
changes=[]
for log in sorted((root/'checks/errors').glob('*.txt')):
 edits={}
 for m in re.finditer(r'^C-WORK/(src/[^:\n]+\.c):(\d+):(\d+): error: (.*)$',log.read_text(),re.M):
  rel,line,col,diag=m.groups();f=root/rel
  if not f.exists():continue
  match=re.search(r"(?:incompatible (?:integer to pointer|pointer to integer) conversion|incompatible pointer types) passing '([^']+)'(?: \(aka '[^']+'\))? to parameter of type '([^']+)'",diag)
  if not match:continue
  src,dst=match.groups();kind=''
  if src in ints and pointer(dst):kind='integer_to_pointer'
  elif ('*' in src or '[' in src) and dst in word:kind='pointer_to_word'
  elif ('*' in src or '[' in src) and pointer(dst):kind='object_pointer_cast'
  else:continue
  text=f.read_text();lines=text.splitlines(keepends=True);pos=sum(map(len,lines[:int(line)-1]))+int(col)-1
  spans=[(a,b) for a,b in arguments(text) if a<=pos<b]
  if not spans:continue
  a,b=min(spans,key=lambda s:s[1]-s[0]);expr=text[a:b];trim=expr.strip()
  if not trim or re.search(r'\b(?:code|longlong|ulonglong|undefined8)\b',src):continue
  # No discarded expression or changed evaluation count; all original expression bytes remain.
  bridge='void *' if kind=='object_pointer_cast' else 'uintptr_t'
  replacement=f'({dst})({bridge})({trim})'
  replacement=expr[:len(expr)-len(expr.lstrip())]+replacement+expr[len(expr.rstrip()):]
  edits.setdefault(f,{})[(a,b)]=(replacement,dict(file=rel,line=int(line),column=int(col),source_type=src,target_type=dst,kind=kind,original=trim,replacement=replacement.strip(),diagnostic=diag))
 for f,items in edits.items():
  text=f.read_text();accepted=[];last=len(text)+1
  for (a,b),(replacement,row) in sorted(items.items(),reverse=True):
   if b>last:continue
   text=text[:a]+replacement+text[b:];last=a;accepted.append(row)
  if not accepted:continue
  backup=out/'previous_sources'/f.parent.name;backup.mkdir(parents=True,exist_ok=True)
  if not (backup/f.name).exists():(backup/f.name).write_text(f.read_text())
  f.write_text(text);changes.extend(accepted)
old=json.loads((out/'changes.json').read_text()) if (out/'changes.json').exists() else []
(out/'changes.json').write_text(json.dumps(old+changes,indent=2)+'\n');print('Explicit conversions',len(changes),'files',len({r['file'] for r in changes}))
