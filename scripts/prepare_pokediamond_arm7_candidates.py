"""Prepare older ARM7 audio/OS C sources; byte acceptance is a separate step."""
from pathlib import Path
import argparse,hashlib,json,subprocess
ROOT=Path(__file__).resolve().parents[1]
p=argparse.ArgumentParser(description=__doc__);p.add_argument('donor',type=Path);a=p.parse_args();donor=a.donor.resolve()
assert subprocess.check_output(['git','-C',str(donor),'rev-parse','HEAD'],text=True).strip()=='b623abef1b4dfe204ca50aab42447ac00c134290'
assert not subprocess.check_output(['git','-C',str(donor),'status','--porcelain'],text=True).strip()
for source in (donor/'arm7/lib/include').rglob('*.h'):
 dest=ROOT/'vendor/pokediamond'/source.relative_to(donor);dest.parent.mkdir(parents=True,exist_ok=True)
 if dest.exists():assert dest.read_bytes()==source.read_bytes()
 else:dest.write_bytes(source.read_bytes())
manifest=ROOT/'verification/sdk-header-manifest.json';headers=json.loads(manifest.read_text())
for source in (ROOT/'vendor/pokediamond/arm7').rglob('*.h'):
 relative=str(source.relative_to(ROOT));digest=hashlib.sha256(source.read_bytes()).hexdigest()
 if relative in headers:assert headers[relative]==digest
 headers[relative]=digest
manifest.write_text(json.dumps(headers,indent=2)+'\n')
objects={}
for source in (donor/'arm7/lib/src').glob('*.c'):
 for opt in ['-O4,p','-O4,s','-O2']:
  flags=[opt,'-enum','int','-lang','c99','-char','signed','-interworking','-proc','arm7tdmi','-gccext,on','-inline','on,noauto','-gccinc','-fp','soft','-DFS_IMPLEMENT']
  for include in ['vendor/pokediamond/arm7/lib/include','vendor/pokediamond/include-mw','vendor/pokediamond/arm9/lib/MSL_C/include']:flags+=['-ir',include]
  objects[str(len(objects))+'.o']=dict(source=str(source.relative_to(donor)),flags=flags)
out=ROOT/'build/pokediamond-arm7';out.mkdir(parents=True,exist_ok=True)
(out/'input.json').write_text(json.dumps(dict(objects=objects,complete_translation_unit=True,target_modules=['arm7'],extend_literal_spans=True),indent=2)+'\n')
print('Prepared',len(objects),'ARM7 compilation profiles; no matching claim.')
