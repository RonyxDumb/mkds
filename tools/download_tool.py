#!/usr/bin/env python3
"""Downloads a third-party build tool into tools/."""
import argparse
import hashlib
import io
import stat
import sys
import urllib.request
import zipfile
from pathlib import Path

URLS = {
    "wibo": "https://github.com/decompals/wibo/releases/download/{tag}/wibo-x86_64",
    "objdiff": "https://github.com/encounter/objdiff/releases/download/{tag}/objdiff-cli-linux-x86_64",
    # Metrowerks CodeWarrior compilers: DS 1.2 and 2.0 builds, DSi 1.1 and 1.2 builds
    "mwccarm": "http://decomp.aetias.com/files/mwccarm.zip",
    "dsd": "https://github.com/AetiasHax/ds-decomp/releases/download/{tag}/dsd-linux-x86_64",
}
# The compiler bundle is only published as "latest", so the files the build runs are pinned by hash (paths are
# relative to --path, where the zip's mwccarm/ folder lands): the game's compiler and linker, and the assembler.
SHA256 = {
    "mwccarm/1.2/base/mwccarm.exe": "87b4f748825ded418355e4ae35e032ce8b27c083cc4c60598ce2a75d346e4399",
    "mwccarm/1.2/base/mwldarm.exe": "2fcfacd7b33f364affb99f6dcdc541c65c70c866bec2dfcded6084709a4429a3",
    "mwccarm/2.0/sp2p3/mwasmarm.exe": "f68e9567fc966c03e1cd6b1f5b0aa85db9a239996ee1824960b45192beaca6e2",
}
# Single-file downloads pinned by hash (the release named by configure.py).
BINARY_SHA256 = {
    "dsd": "256edde804dd8e5d7bc4c0e4187f85244ee4cd1f42bb427502e01fda6af43ceb",
}

parser = argparse.ArgumentParser()
parser.add_argument("tool", choices=URLS)
parser.add_argument("tag")
parser.add_argument("--path", type=Path, required=True, help="output file, or extraction dir for zips")
parser.add_argument("--outputs", type=Path, nargs="*", default=[],
                    help="files the build needs from this tool; if all exist already, nothing is downloaded")
args = parser.parse_args()


def verify(root: Path) -> list[str]:
    bad = []
    for rel, digest in SHA256.items():
        f = root / rel
        if not f.is_file() or hashlib.sha256(f.read_bytes()).hexdigest() != digest:
            bad.append(str(f))
    return bad


# Ninja reruns this edge whenever .ninja_log has no entry for it (a new checkout or build copy), so tools that are
# already in place are kept rather than fetched again.
if args.outputs and all(p.is_file() for p in args.outputs):
    if args.tool == "mwccarm" and (bad := verify(args.path)):
        sys.exit(f"{', '.join(bad)}: missing or not the pinned compiler build (SHA-256)")
    sys.exit(0)

url = URLS[args.tool].format(tag=args.tag)
print(f"Downloading {args.tool} {args.tag} from {url}")
with urllib.request.urlopen(url) as resp:
    data = resp.read()

if url.endswith(".zip"):
    zipfile.ZipFile(io.BytesIO(data)).extractall(args.path)
    if args.tool == "mwccarm" and (bad := verify(args.path)):
        sys.exit(f"{', '.join(bad)}: missing from the download or not the pinned compiler build (SHA-256)")
else:
    if args.tool in BINARY_SHA256 and hashlib.sha256(data).hexdigest() != BINARY_SHA256[args.tool]:
        sys.exit(f"{url}: not the pinned {args.tool} build (SHA-256)")
    args.path.parent.mkdir(parents=True, exist_ok=True)
    args.path.write_bytes(data)
    args.path.chmod(args.path.stat().st_mode | stat.S_IEXEC)
