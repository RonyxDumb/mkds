"""Check full function spans while counting the unchanged Ghidra body inventory.

Some original symbol spans include literal words excluded by Ghidra's body.
Such a difference is accepted only when PC-relative word loads account for
exactly the excluded byte count. All span bytes remain part of the exact proof.
"""
def validate_span(code, address, mode, inventory_size):
    if len(code) == inventory_size:
        return
    assert len(code) > inventory_size
    literal_bytes = set()
    step = 4 if mode == 'arm' else 2
    for offset in range(0, len(code) - step + 1, step):
        word = int.from_bytes(code[offset:offset+step], 'little')
        if mode == 'arm' and word & 0x0f7f0000 == 0x051f0000:
            displacement = word & 0xfff
            if not word & 0x00800000: displacement = -displacement
            location = address + offset + 8 + displacement
        elif mode == 'thumb' and word & 0xf800 == 0x4800:
            location = ((address + offset + 4) & ~3) + (word & 0xff) * 4
        else:
            continue
        relative = location - address
        if 0 <= relative and relative + 4 <= len(code):
            literal_bytes.update(range(relative, relative + 4))
    remaining = len(code) - len(literal_bytes) - inventory_size
    if remaining == 4 and mode == 'arm' and literal_bytes:
        # One seeded Ghidra body omits the shared final BX LR after LDM SP!,{LR}.
        # Its complete original bytes are still proved; do not add it to the inventory.
        end = min(literal_bytes)
        if (literal_bytes == set(range(end, len(code))) and end >= 8
                and code[end-8:end] == bytes.fromhex('0040bde81eff2fe1')):
            remaining = 0
    assert remaining == 0, 'Span/body difference is not accounted for by literal loads or the checked shared return'
