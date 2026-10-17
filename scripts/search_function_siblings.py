"""Reuse verified C for same-shaped siblings; every result still needs fresh acceptance."""
from batch_matching import *
from collections import defaultdict

def main():
 ctx=MatchingContext(ROOT,ROOT/'baseline');known={}
 for p in ['local-byte-exact.tsv','local-linked-byte-exact.tsv']:
  for r in csv.DictReader((ROOT/'verification'/p).open(),delimiter='\t'):known[r['module'],int(r['address'],16)]=r
 def shape(mod,a,mode,size):
  b=ctx.original(mod,a,size);mask=bytearray(b);slots={};pools=set();step=2 if mode=='thumb' else 4
  for off in range(0,len(b)-step+1,step):
   w=int.from_bytes(b[off:off+step],'little');loc=None
   if mode=='thumb' and w&0xf800==0x4800:loc=(((a+off+4)&~3)+(w&255)*4)-a
   elif mode=='arm' and w&0x0f7f0000==0x051f0000:loc=off+8+((w&4095) if w&0x800000 else -(w&4095))
   if loc is not None and 0<=loc<=len(b)-4:pools.update(range(loc,loc+4));slots['literal',loc]=int.from_bytes(b[loc:loc+4],'little')
  for off in range(0,len(b)-step+1,step):
   if off in pools:continue
   w=int.from_bytes(b[off:off+step],'little')
   call=(mode=='arm' and (w&0x0f000000==0x0b000000 or w&0xfe000000==0xfa000000)) or (mode=='thumb' and w&0xf800==0xf000 and off+4<=len(b) and int.from_bytes(b[off+2:off+4],'little')&0xe800==0xe800)
   if call:
    ins=list(Cs(CS_ARCH_ARM,CS_MODE_THUMB if mode=='thumb' else CS_MODE_ARM).disasm(b[off:off+4],a+off))
    if len(ins)==1 and ins[0].mnemonic in ['bl','blx']:
     slots['call',off]=int(ins[0].op_str.lstrip('#'),0);mask[off:off+4]=b'\0'*4
  # Same instruction/register shape with different field offsets or constants.
  for off in range(0,len(b)-step+1,step):
   if off in pools or ('call',off) in slots:continue
   w=int.from_bytes(b[off:off+step],'little');bits=0;value=None
   if mode=='thumb':
    if w&0xe000==0x2000:bits=255;value=w&255
    elif w&0xe000==0x6000:bits=0x7c0;value=((w>>6)&31)*(1 if w&0x1000 else 4)
    elif w&0xf000==0x8000:bits=0x7c0;value=((w>>6)&31)*2
    elif w&0xf800==0x1800 and w&0x400:bits=0x1c0;value=(w>>6)&7
   elif w&0x0e000000==0x02000000:
    bits=4095;imm=w&255;rot=((w>>8)&15)*2;value=((imm>>rot)|(imm<<(32-rot)))&0xffffffff if rot else imm
   elif w&0x0e000000==0x04000000 and not w&0x02000000:
    bits=4095;value=w&4095
   if bits:
    slots['immediate',off]=value
    mask[off:off+step]=(int.from_bytes(mask[off:off+step],'little')&~bits).to_bytes(step,'little')
  for off in pools:mask[off]=0
  return (mode,size,bytes(mask)),slots
 groups=defaultdict(list)
 for (mod,a),r in known.items():
  mode=r['mode'];size=int(r['size'])
  if size<24 or size>8192:continue
  key,slots=shape(mod,a,mode,size);groups[key].append((mod,a,r['name'],slots))
 reverse={mod:defaultdict(list) for mod in ctx.local}
 for mod,table in ctx.local.items():
  for n,(a,t) in table.items():reverse[mod][a].append(n)
 runner=Search(ctx,ROOT/'tools/mwccarm/1.2/sp2p3/mwccarm.exe',ROOT/'tools/wibo',ROOT/'build/siblings-immediates41',['-O4,p','-O4,s','-O2','-O3','-O1']);out={'exact':[],'near_misses':[]};attempts=0
 for (mod,a),(name,mode,size) in ctx.inventory.items():
  if (mod,a) in known or size<24 or size>8192:continue
  key,slots=shape(mod,a,mode,size)
  for smod,sa,sname,ss in groups.get(key,[])[:12]:
   source=ROOT/'src'/smod/f'{sa:08x}_{sname}.c'
   if not source.exists():continue
   text=source.read_text()
   if re.search(r'^\s*#\s*include',text,re.M):continue
   names={sname:name};values={};bad=False
   for k,old in ss.items():
    new=slots.get(k)
    if new==old:continue
    if new is None or old in values and values[old]!=new:bad=True;break
    values[old]=new
    if old in reverse[smod] and new in reverse[mod]:
     newname=sorted(reverse[mod][new],key=lambda n:n.startswith('SDK_'))[0]
     for oldname in reverse[smod][old]:names[oldname]=newname
   if bad:continue
   text=re.sub(r'\b(?:'+ '|'.join(re.escape(n) for n in sorted(names,key=len,reverse=True))+r')\b',lambda m:names[m[0]],text)
   def number(m):
    raw=m[0];base=raw.rstrip('uUlL')
    try:v=int(base,0) if base.lower().startswith('0x') else int(base)
    except:return raw
    if v in values:return hex(values[v])+raw[len(base):]
    return raw
   text=re.sub(r'\b(?:0x[0-9a-fA-F]+|[0-9]+)[uUlL]*\b',number,text)
   ca=Candidate(mod,name,mode,a,size,'verified-sibling',text,ctx.original(mod,a,size));_,rs=runner.run(ca);attempts+=1
   ex=next((r for r in rs if r['outcome']=='exact'),None)
   if ex:
    out['exact'].append(dict(module=mod,address=hex(a),name=name,mode=mode,size=size,variant=ca.variant,source=ex['source'],optimization=ex['optimization']));print('EXACT',ca.tag,size,flush=True);break
  atomic_json(ROOT/'build/siblings-immediates41.json',out)
 print('Attempts',attempts,'exact',len(out['exact']),flush=True)

if __name__=='__main__':main()
