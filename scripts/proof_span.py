"""Check full function spans while counting the unchanged Ghidra body inventory.

Some original symbol spans include literal words excluded by Ghidra's body.
Such a difference is accepted only when PC-relative word loads account for
exactly the excluded byte count. All span bytes remain part of the exact proof.
"""
def thumb_switch_bytes(code, address):
    """Recognize MW's bounded Thumb signed-halfword switch, including BX bit.

    Only this exact instruction idiom supplies a table length. Arbitrary data
    or an unexplained body/span difference never becomes an exclusion.
    """
    excluded=set()
    half=lambda p:int.from_bytes(code[p:p+2], 'little')
    for start in range(0,len(code)-16,2):
        reg=half(start)&7
        selector=(half(start)>>3)&7
        pattern=[0x1800|(selector<<6)|(selector<<3)|reg,0x4478|reg,
                 0x8900|(reg<<3)|reg,0x0400|(reg<<3)|reg,
                 0x1400|(reg<<3)|reg,0x4478|reg,0x4700|(reg<<3)]
        if [half(start+i*2) for i in range(7)]!=pattern:continue
        cmp_at=start-4
        if cmp_at>=0 and half(cmp_at)&0xff00==0x2800|(selector<<8) and half(start-2)&0xff00==0xd800:
            pass
        else:
            cmp_at=start-6
            if not (cmp_at>=0 and half(cmp_at)&0xff00==0x2800|(selector<<8)
                    and half(start-4)==0xd900 and half(start-2)&0xf800==0xe000):continue
        count=(half(cmp_at)&255)+1;table=start+14;end=table+count*2
        assert end<=len(code),'Truncated Thumb switch table'
        for p in range(table,end,2):
            delta=int.from_bytes(code[p:p+2],'little',signed=True)
            target=(table+delta)&~1
            assert delta&1 and end<=target<len(code),'Invalid Thumb switch destination'
        excluded.update(range(table,end))
    return excluded

def validate_span(code, address, mode, inventory_size):
    if len(code) == inventory_size:
        return
    assert len(code) > inventory_size
    literal_bytes = set()
    switch_bytes=thumb_switch_bytes(code,address) if mode=='thumb' else set()
    step = 4 if mode == 'arm' else 2
    for offset in range(0, len(code) - step + 1, step):
        if mode=='thumb' and (offset in literal_bytes or offset in switch_bytes):continue
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
    switch_bytes=thumb_switch_bytes(code,address) if mode=='thumb' else set()
    assert not switch_bytes & literal_bytes,'Switch table overlaps literal pool'
    excluded=literal_bytes|switch_bytes
    remaining = len(code) - len(excluded) - inventory_size
    if remaining==2 and mode=='thumb' and switch_bytes and literal_bytes:
        # MW's alignment NOP immediately before the terminal literal pool.
        end=min(literal_bytes)
        if literal_bytes==set(range(end,len(code))) and code[end-2:end]==bytes.fromhex('c046'):
            remaining=0
    if remaining == 4 and mode == 'arm' and literal_bytes:
        # One seeded Ghidra body omits the shared final BX LR after LDM SP!,{LR}.
        # Its complete original bytes are still proved; do not add it to the inventory.
        end = min(literal_bytes)
        if (literal_bytes == set(range(end, len(code))) and end >= 8
                and code[end-8:end] == bytes.fromhex('0040bde81eff2fe1')):
            remaining = 0
    if remaining != 0 and mode == 'thumb':
        # Embedded pools can themselves decode as LDR literals. Walk forward,
        # skipping already established data, so those false instructions cannot
        # invent exclusions inside later executable code.
        actual=set()
        for offset in range(0,len(code)-1,2):
            if offset in actual or offset in switch_bytes:continue
            word=int.from_bytes(code[offset:offset+2],'little')
            if word & 0xf800 != 0x4800:continue
            relative=(((address+offset+4)&~3)+(word&255)*4)-address
            if offset < relative and relative+4<=len(code):actual.update(range(relative,relative+4))
        pads=set()
        starts=[p for p in sorted(actual) if p-1 not in actual]
        for start in starts:
            if start<4 or code[start-2:start]!=bytes.fromhex('c046'):continue
            prev=int.from_bytes(code[start-4:start-2],'little')
            end=start
            while end in actual:end+=1
            # An unconditional B must skip precisely this pool, or BX returns
            # immediately before the final aligned pool. No arbitrary NOPs.
            if prev & 0xf800==0xe000:
                delta=prev&0x7ff
                if delta&0x400:delta-=0x800
                if start+delta*2==end:pads.update(range(start-2,start))
            elif prev & 0xff87==0x4700 and end==len(code):pads.update(range(start-2,start))
        if len(code)-len(actual|switch_bytes|pads)==inventory_size:
            remaining=0
    assert remaining == 0, 'Span/body difference is not accounted for by literal loads or the checked shared return'
