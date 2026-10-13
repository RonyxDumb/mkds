"""Atomically package the full recovery workspace with a SHA-256 manifest."""
from pathlib import Path
import hashlib, json, os, sys, zipfile
root = Path(__file__).resolve().parents[1]
dest = Path(sys.argv[1]).resolve() if len(sys.argv)>1 else root.parent/'MarioKartDS-EUR-checkpoint7-completo.zip'
if dest.is_relative_to(root):
    raise SystemExit('Choose an output outside the source workspace')
dest.parent.mkdir(parents=True,exist_ok=True)
files = [p for p in sorted(root.rglob('*')) if p.is_file() and not set(p.relative_to(root).parts)&{'build','build_objects','__pycache__','.git','.venv'}]
manifest = {str(p.relative_to(root)):hashlib.sha256(p.read_bytes()).hexdigest() for p in files}
temporary = dest.with_suffix('.zip.partial')
try:
    with zipfile.ZipFile(temporary,'w',zipfile.ZIP_DEFLATED,compresslevel=6) as z:
        for p in files:
            z.write(p,Path('MarioKartDS-EUR')/p.relative_to(root))
        z.writestr('MarioKartDS-EUR/ARCHIVE-SHA256.json',json.dumps(manifest,indent=2)+'\n')
    with zipfile.ZipFile(temporary) as z:
        assert z.testzip() is None
        for name,digest in manifest.items():
            assert hashlib.sha256(z.read('MarioKartDS-EUR/'+name)).hexdigest()==digest
    os.replace(temporary,dest)
finally:
    temporary.unlink(missing_ok=True)
print(json.dumps({'path':str(dest),'files':len(files),'size_bytes':dest.stat().st_size,'sha256':hashlib.sha256(dest.read_bytes()).hexdigest()}))
