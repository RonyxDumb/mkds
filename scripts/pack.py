from pathlib import Path
import zipfile
root=Path(__file__).resolve().parents[1];dest=root.parent/'MarioKartDS-EUR-C-workspace.zip'
with zipfile.ZipFile(dest,'w',zipfile.ZIP_DEFLATED,compresslevel=6) as z:
 for p in sorted(root.rglob('*')):
  if p.is_file() and '__pycache__' not in p.parts and 'build_objects' not in p.parts:z.write(p,Path('MarioKartDS-EUR-C-workspace')/p.relative_to(root))
with zipfile.ZipFile(dest) as z:assert z.testzip() is None
print(dest,dest.stat().st_size)
