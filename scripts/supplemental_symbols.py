"""Load separately recorded ARM7 ISA evidence without changing the function-byte inventory."""
from pathlib import Path
import hashlib
import json

def augment(root, base, sections, local, allsyms, inventory):
    path = Path(root) / 'verification/arm7-mode-evidence.json'
    if not path.exists(): return
    evidence = json.loads(path.read_text())
    for filename, digest in evidence['section_sha256'].items():
        assert hashlib.sha256((Path(base)/'binaries'/filename).read_bytes()).hexdigest() == digest
    for row in evidence['functions']:
        module, address = row['module'], int(row['address'], 16)
        if (module, address) in inventory: continue
        size = row['inventory_size']
        code = next(b[address-a:address-a+size] for a,b in sections[module] if a <= address and address+size <= a+len(b))
        assert hashlib.sha256(code).hexdigest() == row['original_sha256']
        name, thumb = row['name'], row['mode'] == 'thumb'
        if name in local[module] and local[module][name] != (address, thumb):
            # Ghidra can give two veneers the same thunk name. Do not
            # overwrite the established address or guess a call binding.
            continue
        local[module][name] = (address, thumb); allsyms.setdefault(name, set()).add((address, thumb))
        inventory[(module, address)] = (name, row['mode'], size)
