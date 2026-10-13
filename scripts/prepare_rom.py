"""Extract initialized ARM sections from the exact reference ROM, without changing metadata."""
from pathlib import Path
import argparse,hashlib,subprocess,sys,json
root=Path(__file__).resolve().parents[1]
def main():
 p=argparse.ArgumentParser(description=__doc__);p.add_argument('rom',type=Path);args=p.parse_args()
 rom=args.rom.resolve();expected='ce97d9b43f0d3ca0d48b781983e8a16f6393378f'
 digest=hashlib.sha1(rom.read_bytes()).hexdigest()
 if digest!=expected:p.error(f'Wrong ROM SHA-1: {digest}; expected {expected}')
 base=root/'baseline';(base/'binaries').mkdir(exist_ok=True)
 # The initial exporter writes manifests and block metadata; preserve the versioned inventory.
 files=[base/'manifest.json',*list((base/'symbols').glob('*.blocks.tsv'))];saved={f:f.read_bytes() for f in files}
 try:
  subprocess.run([sys.executable,str(base/'scripts/extract.py'),str(rom)],check=True)
  current=json.loads((base/'manifest.json').read_text());original=json.loads(saved[base/'manifest.json'])
  assert current==original,'Extracted module inventory differs from reference'
 finally:
  for f,data in saved.items():f.write_bytes(data)
 print('Reference ROM verified; initialized sections extracted to',base/'binaries')
if __name__=='__main__':main()
