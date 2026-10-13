"""Recover pinned matching tools into ignored tools/, checking archive and executable hashes."""
from pathlib import Path
import hashlib
import urllib.request
import zipfile

root = Path(__file__).resolve().parents[1]
out = root / 'tools'
out.mkdir(exist_ok=True)

def download(url, path, digest):
    if not path.exists() or hashlib.sha256(path.read_bytes()).hexdigest() != digest:
        temporary = path.with_suffix('.download')
        with urllib.request.urlopen(url, timeout=60) as response:
            temporary.write_bytes(response.read())
        assert hashlib.sha256(temporary.read_bytes()).hexdigest() == digest, 'Download hash mismatch'
        temporary.replace(path)
    return path

archive = download('https://github.com/decompme/compilers/releases/download/compilers/mwccarm.zip',
                   out / 'mwccarm.zip', 'dc386e37b2176e960954a733de928337d9b7e7620b9e94228008c31774339ace')
with zipfile.ZipFile(archive) as package:
    for name in package.namelist():
        if name.startswith('mwccarm/1.2/sp2p3/') and not name.endswith('/'):
            package.extract(name, out)
compiler = out / 'mwccarm/1.2/sp2p3/mwccarm.exe'
assert hashlib.sha256(compiler.read_bytes()).hexdigest() == 'a0db9f5dd49ceb619dbc64993660b39f96cca10821a698a9859824e2d4ae2a81'
wibo = download('https://github.com/decompals/wibo/releases/download/1.2.0/wibo-x86_64',
                out / 'wibo', '13f86a2d618f0dbe67179d349625345eabf9b46450295cb4c904e49f6aff85af')
wibo.chmod(0o755)
print('Linux x86_64 matching toolchain ready. Set:')
print('MWCCARM=' + str(compiler))
print('WIBO=' + str(wibo))
print('MKDS_BASELINE=' + str(root / 'baseline'))
