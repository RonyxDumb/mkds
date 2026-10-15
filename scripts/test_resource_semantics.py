"""Compare original ARM resource helpers with current host C on synthetic data.

Checks return values and the complete buffer after each call. Fixtures contain
valid aligned dictionaries with eight entries; this is not malformed-file or
whole-game validation. Requires Unicorn and gcc.
"""
from pathlib import Path
import ctypes
import json
import random
import struct
import subprocess
import tempfile

from unicorn import Uc, UC_ARCH_ARM, UC_MODE_ARM
from unicorn.arm_const import (
    UC_ARM_REG_CPSR, UC_ARM_REG_LR, UC_ARM_REG_PC, UC_ARM_REG_R0,
    UC_ARM_REG_R1, UC_ARM_REG_R2, UC_ARM_REG_SP,
)

ROOT = Path(__file__).resolve().parents[1]
POINTERS = [0x02013a4c, 0x02013a88, 0x02013ac4, 0x02013b00, 0x02013bf8]
GETTERS = [0x02013314, 0x02013344, 0x02013378, 0x020133ac]
SETTERS = [0x020133e0, 0x02013424, 0x02013468, 0x020134b0, 0x020134f8,
           0x02013540, 0x02013588, 0x020135d0, 0x02013618, 0x02013660, 0x020136a8]


def main():
    rng = random.Random(28)
    uc = Uc(UC_ARCH_ARM, UC_MODE_ARM)
    uc.mem_map(0x02000000, 0x400000)
    uc.mem_map(0x02400000, 0x1000)
    manifest = json.loads((ROOT / 'baseline/manifest.json').read_text())
    module = next(m for m in manifest['modules'] if m['name'] == 'arm9')
    for section in module['sections']:
        start = section['base'] & ~4095
        end = (section['base'] + section['size'] + 4095) & ~4095
        if not 0x02000000 <= start < end <= 0x02400000:
            uc.mem_map(start, end - start)
        uc.mem_write(section['base'],
                     (ROOT / 'baseline/binaries' / section['file']).read_bytes())
    data_address, stop = 0x02400000, 0x023ff000
    buffer = ctypes.create_string_buffer(4096)
    sources, counts = [], {}
    for address in POINTERS + GETTERS + SETTERS:
        paths = list((ROOT / 'src/arm9').glob(f'{address:08x}_*.c'))
        assert len(paths) == 1
        name = paths[0].stem[9:]
        sources.append((address, name, paths[0]))
        counts[name] = 0
    with tempfile.TemporaryDirectory() as directory:
        library = Path(directory) / 'resources.so'
        subprocess.run(['gcc', '-std=c11', '-O2', '-Wall', '-Wextra', '-Werror',
                        '-shared', '-fPIC', *[str(s) for _, _, s in sources],
                        '-o', str(library)], check=True)
        dll = ctypes.CDLL(str(library))
        for address, name, _ in sources:
            function = getattr(dll, name)
            setter = address in SETTERS
            pointer = address in POINTERS
            function.argtypes = [ctypes.c_void_p, ctypes.c_uint]
            if setter:
                function.argtypes.append(ctypes.c_uint)
            function.restype = None if setter else ctypes.c_void_p if pointer else ctypes.c_uint
            for index in range(8):
                for sample in range(256):
                    data = bytearray(rng.randbytes(4096))
                    # Animation headers embed a dictionary at +8; model material
                    # blocks are reached through the offset at header +8.
                    block = 0 if pointer else 0x80
                    if pointer:
                        struct.pack_into('<H', data, 14, 0x40)
                        table = 8 + 0x40
                    else:
                        struct.pack_into('<I', data, 8, block)
                        struct.pack_into('<H', data, block + 10, 0x40)
                        table = block + 4 + 0x40
                    struct.pack_into('<H', data, table, 16)
                    for slot in range(8):
                        struct.pack_into('<I', data, table + slot * 16 + 4,
                                         0x200 + slot * 0x20)
                    value = ([0, 1, 0xffffffff, 0x80000000][sample]
                             if sample < 4 else rng.getrandbits(32))
                    uc.mem_write(data_address, bytes(data))
                    ctypes.memmove(ctypes.addressof(buffer), bytes(data), len(data))
                    uc.reg_write(UC_ARM_REG_CPSR, 0x10 | (rng.getrandbits(4) << 28))
                    uc.reg_write(UC_ARM_REG_SP, 0x023fe000)
                    uc.reg_write(UC_ARM_REG_LR, stop)
                    uc.reg_write(UC_ARM_REG_R0, data_address)
                    uc.reg_write(UC_ARM_REG_R1, index)
                    uc.reg_write(UC_ARM_REG_R2, value)
                    uc.emu_start(address, stop, count=100)
                    assert uc.reg_read(UC_ARM_REG_PC) == stop, name
                    args = [ctypes.addressof(buffer), index] + ([value] if setter else [])
                    result = function(*args)
                    if not setter:
                        expected = uc.reg_read(UC_ARM_REG_R0)
                        if pointer:
                            result = result - ctypes.addressof(buffer) + data_address
                        assert result == expected, (name, index, sample, result, expected)
                    assert buffer.raw == bytes(uc.mem_read(data_address, 4096)), (name, index, sample)
                    counts[name] += 1
    summary = dict(passed=sum(counts.values()), cases=counts,
                   method='Original ARM versus current host C; return values and complete 4096-byte buffers',
                   scope='Valid aligned synthetic dictionaries, eight entries; no global ABI or whole-ROM equivalence',
                   full_rom_link_verified=False)
    (ROOT / 'verification/resource-semantics.json').write_text(json.dumps(summary, indent=2) + '\n')
    print(json.dumps(summary))


if __name__ == '__main__':
    main()
