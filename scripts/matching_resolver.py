"""Reusable complete-function relocation resolver; no scan or writes on import."""
from pathlib import Path
import re, json, csv, io
from elftools.elf.elffile import ELFFile
from capstone import Cs, CS_ARCH_ARM, CS_MODE_THUMB, CS_MODE_ARM

class MatchingContext:
    def __init__(self, root, base):
        root, base = Path(root), Path(base)
        manifest = json.loads((base/'manifest.json').read_text())
        sections={m['name']:[(s['base'],(base/'binaries'/s['file']).read_bytes()) for s in m['sections']] for m in manifest['modules']}
        local={};allsyms={};inventory={}
        for sf in (base/'symbols').glob('*.txt'):
         mod=sf.stem;local[mod]={}
         for line in sf.read_text().splitlines():
          m=re.match(r'^(\S+).* addr:0x([0-9a-fA-F]+)',line)
          if not m:continue
          name,a=m.groups();a=int(a,16);thumb='function(thumb,' in line
          local[mod][name]=(a,thumb);allsyms.setdefault(name,set()).add((a,thumb))
          f=re.search(r'kind:function\((arm|thumb),size=0x([0-9a-fA-F]+)\)',line)
          if f:inventory[(mod,a)]=(name,f[1],int(f[2],16))
        from supplemental_symbols import augment
        augment(root, base, sections, local, allsyms, inventory)
        extra_symbols=root/'verification/sdk-extra-symbols.tsv'
        if extra_symbols.exists():
         for item in csv.DictReader(extra_symbols.open(),delimiter='\t'):
          mod=item['module'];name=item['name'];value=(int(item['address'],16),item['thumb']=='1')
          if name in local[mod] and local[mod][name]!=value:raise ValueError('SDK data symbol conflict')
          local[mod][name]=value;allsyms.setdefault(name,set()).add(value)
        self.sections, self.local, self.allsyms, self.inventory = sections, local, allsyms, inventory
        self.data_symbols = {}
        for module, table in local.items():
            selected = {}
            for name, (address, thumb) in sorted(table.items(), key=lambda item: (item[0].startswith('SDK_'), item[0]), reverse=True):
                if not thumb and re.fullmatch(r'(?:data_|SDK_data_)[0-9a-f]{8}', name):
                    selected[address] = name
            self.data_symbols[module] = selected


    def resolve(self,mod,name):
     local,allsyms=self.local,self.allsyms
     # MW appends a deterministic scope suffix to function-local static data.
     if re.fullmatch(r'SDK_data_[0-9a-f]{8}\$[0-9]+',name):name=name.rsplit('$',1)[0]
     if name in local[mod]:return local[mod][name]
     choices=allsyms.get(name,set())
     if len(choices)!=1:raise ValueError('unresolved or ambiguous symbol '+name)
     return next(iter(choices))

    def linked(self,data,mod,name,addr):
     elf=ELFFile(io.BytesIO(data));sym=next(s for s in elf.get_section_by_name('.symtab').iter_symbols() if s.name==name);idx=sym['st_shndx'];start=sym['st_value']&~1;n=sym['st_size'];code=bytearray(elf.get_section(idx).data()[start:start+n]);records=[]
     for sec in elf.iter_sections():
      if sec['sh_type'] not in ['SHT_RELA','SHT_REL'] or sec['sh_info']!=idx:continue
      symbols=elf.get_section(sec['sh_link'])
      for r in sec.iter_relocations():
       off=r['r_offset']-start
       if not 0<=off<n:continue
       if sec['sh_type']!='SHT_RELA' or off+4>n:raise ValueError('unsupported relocation')
       symbol=symbols.get_symbol(r['r_info_sym']);target,thumb=self.resolve(mod,symbol.name);word=int.from_bytes(code[off:off+4],'little');add=r['r_addend'];typ=r['r_info_type']
       if typ==1:
        if (word&0x0e000000)!=0x0a000000:raise ValueError('branch type')
        delta=target+add-(addr+off)
        if thumb:
         if (word&0xff000000) not in [0xeb000000,0xfa000000,0xfb000000]:raise ValueError('interworking requires unconditional call')
         if delta%2 or not -(1<<25)<=delta<(1<<25):raise ValueError('BLX range')
         value=0xfa000000|((delta>>2)&0xffffff)|((delta&2)<<23)
         decoded=list(Cs(CS_ARCH_ARM,CS_MODE_ARM).disasm(value.to_bytes(4,'little'),addr+off))
         if len(decoded)!=1 or decoded[0].mnemonic!='blx' or int(decoded[0].op_str.lstrip('#'),0)!=target:raise ValueError('independent ARM BLX target check')
        else:
         if delta%4 or not -(1<<25)<=delta<(1<<25):raise ValueError('branch range')
         value=(word&0xff000000)|((delta>>2)&0xffffff)
       elif typ==10:
        hi=word&0xffff;lo=word>>16
        if hi&0xf800!=0xf000 or lo&0xf800 not in [0xf800,0xe800]:raise ValueError('not Thumb BL/BLX')
        delta=target+add-(addr+off) if thumb else target+add+4-((addr+off+4)&~3)
        if delta%2 or not -(1<<22)<=delta<(1<<22):raise ValueError('Thumb call range')
        if not thumb and target%4:raise ValueError('unaligned ARM call target')
        value=(0xf000|((delta>>12)&0x7ff))|(((0xf800 if thumb else 0xe800)|((delta>>1)&0x7ff))<<16)
        decoded=list(Cs(CS_ARCH_ARM,CS_MODE_THUMB).disasm(value.to_bytes(4,'little'),addr+off))
        if len(decoded)!=1 or decoded[0].mnemonic!=('bl' if thumb else 'blx') or int(decoded[0].op_str.lstrip('#'),0)!=target:raise ValueError('independent Thumb target check')
       elif typ==2:value=(target+(1 if thumb else 0)+add)&0xffffffff
       else:raise ValueError('relocation type '+str(typ))
       code[off:off+4]=value.to_bytes(4,'little');records.append(dict(offset=off,type=typ,symbol=symbol.name,target=target,thumb=thumb,addend=add,value=value))
     return bytes(code),records

    def original(self, module, address, size):
        for start, data in self.sections[module]:
            if start <= address and address + size <= start + len(data):
                return data[address-start:address-start+size]
        raise ValueError('Function span outside initialized sections')
