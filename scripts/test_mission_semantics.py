"""Compare mission helper C with original ARM/Thumb execution on boundary inputs.

Requires Unicorn and host gcc. Only the two global pointer expressions are
redirected to host buffers; field accesses and function control flow are kept.
This checks local behavior, not global ABI or whole-game equivalence.
"""
from pathlib import Path
import ctypes
import json
import random
import subprocess
import tempfile

from unicorn import Uc, UC_ARCH_ARM, UC_MODE_ARM
from unicorn.arm_const import (
    UC_ARM_REG_CPSR, UC_ARM_REG_LR, UC_ARM_REG_PC, UC_ARM_REG_R0, UC_ARM_REG_SP,
)

ROOT = Path(__file__).resolve().parents[1]
ENTRIES = [
    (0x020adbc4, 'GetCurrentMissionLevelStage'),
    (0x020adbe4, 'GetCurrentMissionLevel'),
    (0x020b2f18, 'GetCurrentMissionLevelStage_0'),
    (0x020b2f38, 'GetCurrentMissionLevel_0'),
    (0x020cc598, 'GetCurrentMissionStage'),
    (0x020cc5b8, 'GetCurrentMissionLevel_1'),
    (0x021054d0, 'IsInBossMissionStage'),
    (0x020b2f58, 'IsCurrentMission_Boss6OrBoss7_from_thumb'),
    (0x020b4d9c, 'GetCurrentPlayerRacerId'),
    (0x0203f2b4, 'IsRacerFinishStatus4'),
]


def main():
    uc = Uc(UC_ARCH_ARM, UC_MODE_ARM)
    uc.mem_map(0x02000000, 0x400000)
    manifest = json.loads((ROOT / 'baseline/manifest.json').read_text())
    module = next(m for m in manifest['modules'] if m['name'] == 'arm9')
    for section in module['sections']:
        start = section['base'] & ~4095
        end = (section['base'] + section['size'] + 4095) & ~4095
        if not 0x02000000 <= start < end <= 0x02400000:
            uc.mem_map(start, end - start)
        uc.mem_write(section['base'],
                     (ROOT / 'baseline/binaries' / section['file']).read_bytes())
    state, racers, stop = 0x02300000, 0x02310000, 0x023ff000
    uc.mem_write(0x021759c0, state.to_bytes(4, 'little'))
    uc.mem_write(0x0217561c, racers.to_bytes(4, 'little'))
    config_buffer = ctypes.create_string_buffer(0x100)
    racer_buffer = ctypes.create_string_buffer(8 * 0x8c)
    rng = random.Random(27)
    counts = {name: 0 for _, name in ENTRIES}
    addresses = dict((name, address) for address, name in ENTRIES)

    def put(offset, value, size=1, racer=False):
        data = (value & ((1 << (size * 8)) - 1)).to_bytes(size, 'little')
        uc.mem_write((racers if racer else state) + offset, data)
        target = racer_buffer if racer else config_buffer
        ctypes.memmove(ctypes.addressof(target) + offset, data, size)

    with tempfile.TemporaryDirectory() as directory:
        tmp = Path(directory)
        sources = []
        for address, name in ENTRIES:
            source = ROOT / 'src/arm9' / f'{address:08x}_{name}.c'
            text = source.read_text()
            text = text.replace('*(RaceConfig **)0x021759c0', 'test_config')
            text = text.replace('*(Racer **)0x0217561c', 'test_racers')
            prepared = tmp / source.name
            prepared.write_text('extern void *test_config, *test_racers;\n' + text)
            sources.append(str(prepared))
        shim = tmp / 'shim.c'
        shim.write_text('void *test_config, *test_racers;\n')
        library = tmp / 'mission.so'
        subprocess.run(['gcc', '-std=c11', '-O2', '-Wall', '-Wextra', '-Werror',
                        '-shared', '-fPIC', *sources, str(shim), '-o', str(library)],
                       check=True)
        dll = ctypes.CDLL(str(library))
        ctypes.c_void_p.in_dll(dll, 'test_config').value = ctypes.addressof(config_buffer)
        ctypes.c_void_p.in_dll(dll, 'test_racers').value = ctypes.addressof(racer_buffer)
        for _, name in ENTRIES:
            function = getattr(dll, name)
            function.restype = (ctypes.c_ushort if name == 'GetCurrentPlayerRacerId'
                                else ctypes.c_uint32)
            function.argtypes = [ctypes.c_int] if name == 'IsRacerFinishStatus4' else []

        def compare(name, *args):
            address = addresses[name]
            thumb = name.endswith('_from_thumb')
            uc.reg_write(UC_ARM_REG_CPSR, 0x10 | (rng.getrandbits(4) << 28))
            uc.reg_write(UC_ARM_REG_SP, 0x023fe000)
            uc.reg_write(UC_ARM_REG_LR, stop)
            uc.reg_write(UC_ARM_REG_R0, args[0] if args else rng.getrandbits(32))
            uc.emu_start(address | int(thumb), stop, count=200)
            assert uc.reg_read(UC_ARM_REG_PC) == stop, name + ' did not return'
            expected = uc.reg_read(UC_ARM_REG_R0)
            actual = getattr(dll, name)(*args)
            assert actual == expected, (name, args, actual, expected)
            counts[name] += 1

        for mode in [0, 1, 3, 4, 5, 0x7fffffff, 0xffffffff]:
            put(8, mode, 4)
            for raw in range(256):
                put(0x54, raw)
                put(0x55, raw)
                for _, name in ENTRIES[:8]:
                    compare(name)
                # Separate level and stage values exercise both short-circuit arms.
                for level, stage in [(6, raw), (7, raw), (raw, 9)]:
                    put(0x54, level)
                    put(0x55, stage)
                    compare('IsCurrentMission_Boss6OrBoss7_from_thumb')
        for mode in [0, 1, 2, 0xffffffff]:
            put(0xc, mode, 4)
            for raw in range(256):
                put(0x62, raw)
                put(0x63, 255 - raw)
                compare('GetCurrentPlayerRacerId')
        for slot in range(8):
            for value in [0, 1, 3, 4, 5, 0x7fffffff, 0xffffffff]:
                put(slot * 0x8c + 0x14, value, 4, racer=True)
                compare('IsRacerFinishStatus4', slot)
    summary = dict(passed=sum(counts.values()), cases=counts,
                   method='Original ARM/Thumb in Unicorn versus host-compiled current C; global pointers redirected only',
                   full_rom_link_verified=False)
    (ROOT / 'verification/mission-semantics.json').write_text(
        json.dumps(summary, indent=2) + '\n')
    print(json.dumps(summary))


if __name__ == '__main__':
    main()
