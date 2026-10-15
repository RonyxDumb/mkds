"""Compare original menu helpers against host C using scripted callee results.

Only external callees are substituted at the function boundary. Checks call
order, option result, and complete emblem state buffers. Requires Unicorn/gcc.
"""
from pathlib import Path
import ctypes
import itertools
import json
import struct
import subprocess
import tempfile

from unicorn import Uc, UC_ARCH_ARM, UC_MODE_ARM, UC_HOOK_CODE
from unicorn.arm_const import (
    UC_ARM_REG_CPSR, UC_ARM_REG_LR, UC_ARM_REG_PC, UC_ARM_REG_R0, UC_ARM_REG_SP,
)

ROOT = Path(__file__).resolve().parents[1]
CALLEES = [
    (0x020b24e4, 'GetDisplayMode_0'), (0x020b2a4c, 'IsRaceEnded'),
    (0x020b252c, 'GetRaceMode'), (0x020b2d54, 'func_020b2d54'),
    (0x020c3db4, 'func_020c3db4'),
    (0x021a23c8, 'Menu_EmblemOverlayQuery_021a23c8'),
]


def main():
    uc = Uc(UC_ARCH_ARM, UC_MODE_ARM)
    uc.mem_map(0x02000000, 0x400000)
    manifest = json.loads((ROOT / 'baseline/manifest.json').read_text())
    section = next(s for m in manifest['modules'] if m['name'] == 'arm9'
                   for s in m['sections'] if s['file'] == 'arm9_0.bin')
    uc.mem_write(section['base'], (ROOT / 'baseline/binaries/arm9_0.bin').read_bytes())
    for address, _ in CALLEES:
        uc.mem_write(address, bytes.fromhex('7047') if address == 0x021a23c8
                     else bytes.fromhex('1eff2fe1'))
    scripted, calls = [], []
    ended_calls = 0
    by_address = {address: index for index, (address, _) in enumerate(CALLEES)}

    def hook(machine, address, size, data):
        nonlocal ended_calls
        if address not in by_address:
            return
        index = by_address[address]
        calls.append(index)
        slot = index
        if index == 1:
            slot = 1 if ended_calls == 0 else 6
            ended_calls += 1
        machine.reg_write(UC_ARM_REG_R0, scripted[slot] & 0xffffffff)

    uc.hook_add(UC_HOOK_CODE, hook)
    count = dict(option=0, emblem=0)
    with tempfile.TemporaryDirectory() as directory:
        tmp = Path(directory)
        shim = tmp / 'shim.c'
        text = 'int values[7], calls[16], call_count, ended_calls;\n'
        for index, (_, name) in enumerate(CALLEES):
            expression = '(ended_calls++ ? values[6] : values[1])' if index == 1 else f'values[{index}]'
            text += f'int {name}(void) {{ calls[call_count++]={index}; return {expression}; }}\n'
        shim.write_text(text)
        library = tmp / 'menus.so'
        sources = [ROOT / 'src/arm9/020b2d04_GetCurrentOptionMenuKind_from_thumb.c',
                   ROOT / 'src/arm9/0204a598_Scene_Emblem_Update.c']
        subprocess.run(['gcc', '-std=c11', '-O2', '-Wall', '-Wextra', '-Werror',
                        '-shared', '-fPIC', *map(str, sources), str(shim),
                        '-o', str(library)], check=True)
        dll = ctypes.CDLL(str(library))
        dll.GetCurrentOptionMenuKind_from_thumb.restype = ctypes.c_int
        dll.Scene_Emblem_Update.argtypes = [ctypes.c_void_p]
        dll.Scene_Emblem_Update.restype = None
        values = (ctypes.c_int * 7).in_dll(dll, 'values')
        host_calls = (ctypes.c_int * 16).in_dll(dll, 'calls')
        host_count = ctypes.c_int.in_dll(dll, 'call_count')
        host_ended = ctypes.c_int.in_dll(dll, 'ended_calls')

        def run(address, argument=0):
            nonlocal ended_calls
            ended_calls = 0
            calls.clear()
            host_count.value = host_ended.value = 0
            for index, value in enumerate(scripted):
                values[index] = value
            uc.reg_write(UC_ARM_REG_CPSR, 0x10)
            uc.reg_write(UC_ARM_REG_SP, 0x023fe000)
            uc.reg_write(UC_ARM_REG_LR, 0x023ff000)
            uc.reg_write(UC_ARM_REG_R0, argument)
            uc.emu_start(address, 0x023ff000, count=200)
            assert uc.reg_read(UC_ARM_REG_PC) == 0x023ff000

        for display, ended, second, mode, a, b in itertools.product(
                [-1, 0, 1, 2, 3], [-1, 0, 1], [-1, 0, 1], [0, 4, 5],
                [-1, 0, 1], [-1, 0, 1]):
            scripted[:] = [display, ended, mode, a, b, 0, second]
            run(0x020b2d05)
            result = dll.GetCurrentOptionMenuKind_from_thumb()
            assert result == uc.reg_read(UC_ARM_REG_R0)
            assert calls == list(host_calls[:host_count.value])
            count['option'] += 1
        for result, state, null in itertools.product(
                [-1, 0, 1], [-32768, -1, 0, 1, 6, 7, 8, 127, 255, 32767], [False, True]):
            scripted[:] = [0, 0, 0, 0, 0, result, 0]
            data = struct.pack('<hhhh', state, -222, 1234, -444)
            uc.mem_write(0x02300000, data)
            buffer = ctypes.create_string_buffer(data, len(data))
            run(0x0204a598, 0 if null else 0x02300000)
            dll.Scene_Emblem_Update(None if null else ctypes.addressof(buffer))
            assert buffer.raw == bytes(uc.mem_read(0x02300000, len(data)))
            assert calls == list(host_calls[:host_count.value])
            count['emblem'] += 1
    summary = dict(passed=sum(count.values()), cases=count,
                   method='Original helper instructions versus host C with scripted external callees; results, call order and complete emblem buffers',
                   full_rom_link_verified=False)
    (ROOT / 'verification/menu-helper-semantics.json').write_text(json.dumps(summary, indent=2) + '\n')
    print(json.dumps(summary))


if __name__ == '__main__':
    main()
