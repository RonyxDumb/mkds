"""Resolve explicitly recorded compiler variants, verifying executable hashes."""
from pathlib import Path
import hashlib
import os


def compiler_for(root, metadata=None):
    record = (metadata or {}).get('compiler')
    if record is None:
        return os.environ['MWCCARM']
    relative = Path(record['path'])
    if relative.is_absolute() or '..' in relative.parts:
        raise ValueError('Compiler path must be repository-relative')
    executable = root / relative
    if hashlib.sha256(executable.read_bytes()).hexdigest() != record['sha256']:
        raise ValueError('Compiler variant hash mismatch')
    return str(executable)


def compiler_record(root):
    executable = Path(os.environ['MWCCARM']).resolve()
    default = (root / 'tools/mwccarm/1.2/sp2p3/mwccarm.exe').resolve()
    if executable == default:
        return None
    relative = executable.relative_to(root.resolve())
    return dict(path=str(relative), sha256=hashlib.sha256(executable.read_bytes()).hexdigest())
