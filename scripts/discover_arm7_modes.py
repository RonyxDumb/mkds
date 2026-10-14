"""Recover missing ARM7 symbol modes from original control flow and interworking constants."""
from pathlib import Path
import csv
import hashlib
import json
import os
from collections import deque
from capstone import Cs, CS_ARCH_ARM, CS_MODE_ARM, CS_MODE_THUMB
from capstone.arm import *

root = Path(__file__).resolve().parents[1]
base = Path(os.environ.get('MKDS_BASELINE', root / 'baseline'))
manifest = json.loads((base / 'manifest.json').read_text())
module = next(m for m in manifest['modules'] if m['name'] == 'arm7')
sections = [(s['base'], (base / 'binaries' / s['file']).read_bytes()) for s in module['sections']]
rows = {int(r['address'], 16): r for r in csv.DictReader((base / 'pseudocode/arm7/index.tsv').open(), delimiter='\t')}
starts = sorted(rows)

def read(address, size):
    for start, data in sections:
        if start <= address and address + size <= start + len(data): return data[address-start:address-start+size]
    return None

decoders = {}
for mode, flag in [('arm', CS_MODE_ARM), ('thumb', CS_MODE_THUMB)]:
    md = Cs(CS_ARCH_ARM, flag); md.detail = True; decoders[mode] = md
modes = {}; certificates = {}; conflicts = set(); pending = deque()

def record(address, mode, evidence):
    if address not in rows: return
    if address in modes:
        if modes[address] != mode: conflicts.add(address)
        return
    modes[address] = mode; certificates[address] = evidence; pending.append(address)

record(module['entry'], 'arm', {'kind': 'imported_ARM_entry', 'address': module['entry']})
for address in starts:
    if address % 4 == 2:
        record(address, 'thumb', {'kind': 'indexed_entry_requires_halfword_ISA', 'address': address})
    else:
        raw = read(address, 4)
        if raw is None or int.from_bytes(raw, 'little') >> 16 != 0xe92d: continue
        arm = next(decoders['arm'].disasm(raw, address, count=1), None)
        first = next(decoders['thumb'].disasm(raw, address, count=1), None)
        second = next(decoders['thumb'].disasm(read(address+2, 4) or b'', address+2, count=1), None)
        # A C stack-save prologue executes the second halfword. E92D there
        # is a Thumb-2 encoding unavailable on ARM7TDMI, not a Thumb-1 op.
        if (arm and arm.id == ARM_INS_PUSH and first and first.size == 2
                and first.id not in [ARM_INS_B, ARM_INS_BX, ARM_INS_BL, ARM_INS_BLX, ARM_INS_SVC]
                and not any(o.type == ARM_OP_REG and o.reg == ARM_REG_PC for o in first.operands)
                and (second is None or second.size == 4)):
            record(address, 'arm', {'kind': 'ARM_stack_save_excludes_Thumb1', 'address': address,
                                   'instruction_hex': raw.hex()})

while pending:
    entry = pending.popleft(); mode = modes[entry]; md = decoders[mode]
    end = next((a for a in starts if a > entry), entry + int(rows[entry]['bytes']) + 32)
    states = {}; work = deque([(entry, {})]); steps = 0
    while work and steps < 10000:
        pc, regs = work.popleft(); steps += 1
        if pc in states:
            joined = {r: v for r, v in states[pc].items() if regs.get(r) == v}
            if joined == states[pc]: continue
            regs = joined
        states[pc] = dict(regs)
        raw = read(pc, 4)
        if raw is None: continue
        ins = next(md.disasm(raw, pc, count=1), None)
        if ins is None: continue
        # ARM7TDMI does not implement Thumb-2 or BLX.
        if mode == 'thumb' and ins.size == 4 and ins.id != ARM_INS_BL: continue
        if ins.id == ARM_INS_BLX: continue
        ops = ins.operands; conditional = ins.cc not in [ARM_CC_AL, ARM_CC_INVALID]
        def value(op):
            if op.type == ARM_OP_IMM: return op.imm & 0xffffffff
            if op.type != ARM_OP_REG: return None
            if op.reg == ARM_REG_PC: return pc + 8 if mode == 'arm' else (pc + 4) & ~3
            return regs.get(op.reg)
        target = None; transfer_mode = mode; stop = False
        if ins.id in [ARM_INS_B, ARM_INS_BL] and ops and ops[0].type == ARM_OP_IMM:
            target = ops[0].imm; stop = ins.id == ARM_INS_B
        elif ins.id == ARM_INS_BX and ops:
            pointer = value(ops[0]); stop = True
            if pointer is not None:
                target = pointer & ~1; transfer_mode = 'thumb' if pointer & 1 else 'arm'
        elif ops and ops[0].type == ARM_OP_REG and ops[0].reg == ARM_REG_PC:
            if ins.id == ARM_INS_MOV and len(ops) > 1: target = value(ops[1])
            elif ins.id == ARM_INS_LDR and len(ops) > 1 and ops[1].type == ARM_OP_MEM:
                mem = ops[1].mem; b = pc + 8 if mem.base == ARM_REG_PC else regs.get(mem.base)
                data = read(b + mem.disp, 4) if b is not None and not mem.index else None
                if data is not None: target = int.from_bytes(data, 'little') & ~3
            stop = True
        elif ins.id in [ARM_INS_POP, ARM_INS_LDM] and any(o.type == ARM_OP_REG and o.reg == ARM_REG_PC for o in ops):
            stop = True
        if target is not None:
            evidence = {'kind': 'constant_interworking_transfer' if ins.id == ARM_INS_BX else 'direct_transfer',
                        'source_function': entry, 'source_mode': mode, 'instruction': pc,
                        'instruction_hex': ins.bytes.hex(), 'target': target}
            if target in rows and target != entry:
                record(target, transfer_mode, evidence)
            elif entry <= target < end:
                work.append((target, dict(regs)))
        if ins.id == ARM_INS_BL:
            # Do not assume a not-yet-reconstructed callee obeys a C ABI.
            regs.clear()
        else:
            _, written = ins.regs_access(); new = None; dst = ops[0].reg if ops and ops[0].type == ARM_OP_REG else None
            if ins.id == ARM_INS_MOV and len(ops) > 1 and not ops[1].shift.type: new = value(ops[1])
            elif ins.id in [ARM_INS_ADD, ARM_INS_SUB] and len(ops) == 3 and not any(o.shift.type for o in ops):
                x, y = value(ops[1]), value(ops[2])
                if x is not None and y is not None: new = (x + y if ins.id == ARM_INS_ADD else x - y) & 0xffffffff
            elif ins.id == ARM_INS_LDR and len(ops) > 1 and ops[1].type == ARM_OP_MEM and not ins.writeback:
                mem = ops[1].mem
                b = (pc + 8 if mode == 'arm' else (pc + 4) & ~3) if mem.base == ARM_REG_PC else regs.get(mem.base)
                data = read(b + mem.disp, 4) if b is not None and not mem.index else None
                if data is not None: new = int.from_bytes(data, 'little')
            for r in written: regs.pop(r, None)
            if dst is not None and new is not None and not conditional: regs[dst] = new
        if not stop or conditional:
            if pc + ins.size < end: work.append((pc + ins.size, dict(regs)))

functions = []
for address, mode in sorted(modes.items()):
    if address in conflicts: continue
    row = rows[address]; size = int(row['bytes']); code = read(address, size)
    if code is None: continue
    functions.append(dict(module='arm7', address=f'0x{address:08x}', name=row['name'], mode=mode,
                          inventory_size=size, original_sha256=hashlib.sha256(code).hexdigest(), evidence=certificates[address]))
result = dict(reference_rom_sha1=manifest['sha1'], indexed_functions=len(rows), resolved=len(functions),
              conflicts=[hex(a) for a in sorted(conflicts)], functions=functions,
              section_sha256={s['file']: hashlib.sha256((base/'binaries'/s['file']).read_bytes()).hexdigest() for s in module['sections']})
(root / 'verification/arm7-mode-evidence.json').write_text(json.dumps(result, indent=2)+'\n')
print(json.dumps({k: v for k, v in result.items() if k not in ['functions', 'section_sha256']}))
