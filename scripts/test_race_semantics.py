"""Compare reconstructed C with original ARM execution and RAM read traces.
Requires unicorn; host gcc. Local semantics only, not byte-exact matching.
"""
from pathlib import Path
import ctypes, hashlib, json, random, struct, subprocess, tempfile
from unicorn import Uc, UC_ARCH_ARM, UC_MODE_ARM, UC_HOOK_MEM_READ
from unicorn.arm_const import UC_ARM_REG_R0, UC_ARM_REG_LR, UC_ARM_REG_CPSR, UC_ARM_REG_PC

root = Path(__file__).resolve().parents[1]
manifest = json.loads((root/'baseline/manifest.json').read_text())
module = next(m for m in manifest['modules'] if m['name'] == 'arm9')
uc = Uc(UC_ARCH_ARM, UC_MODE_ARM)
uc.mem_map(0x02000000, 0x400000)
for section in module['sections']:
    start = section['base'] & ~4095
    end = (section['base'] + section['size'] + 4095) & ~4095
    if not 0x02000000 <= start < end <= 0x02400000:
        uc.mem_map(start, end-start)
    uc.mem_write(section['base'], (root/'baseline/binaries'/section['file']).read_bytes())
STOP = 0x023ff000
arm_trace, c_trace = [], []
uc.hook_add(UC_HOOK_MEM_READ, lambda u, access, addr, size, value, data: arm_trace.append([addr, size]))
read_type = ctypes.CFUNCTYPE(ctypes.c_uint32, ctypes.c_uint32, ctypes.c_uint32)
@read_type
def read_memory(addr, size):
    c_trace.append([addr, size])
    return int.from_bytes(uc.mem_read(addr, size), 'little')

def put(addr, value, size=4):
    uc.mem_write(addr, (value & ((1 << (size*8))-1)).to_bytes(size, 'little'))

sources = [root/'src/arm9/0203c8dc_GetDriverPlace.c', root/'src/arm9/02044618_GetCurrentLapCount.c']
rng = random.Random(0x4d4b4453)
counts = {'GetDriverPlace': 0, 'GetCurrentLapCount': 0}
with tempfile.TemporaryDirectory() as directory:
    tmp = Path(directory)
    header = tmp/'reads.h'
    header.write_text('''#include <stdint.h>
extern uint32_t (*test_read)(uint32_t, uint32_t);
#define READ8(a) ((uint8_t)test_read((uint32_t)(a), 1))
#define READ16(a) ((uint16_t)test_read((uint32_t)(a), 2))
#define READ32(a) test_read((uint32_t)(a), 4)
union TestPacked { uint8_t raw; struct { unsigned char flags:1; unsigned char place:7; } fields; };
union TestNormal { uint16_t raw; struct { unsigned short place:4; unsigned short flags:12; } fields; };
#define READ_PACKED_PLACE(a) ((union TestPacked){.raw=(uint8_t)test_read((uint32_t)(a),1)}.fields.place)
#define READ_NORMAL_PLACE(a) ((union TestNormal){.raw=(uint16_t)test_read((uint32_t)(a),2)}.fields.place)
''')
    shim = tmp/'shim.c'
    shim.write_text('#include <stdint.h>\nuint32_t (*test_read)(uint32_t, uint32_t);\n')
    library = tmp/'race.so'
    subprocess.run(['gcc', '-std=c11', '-O2', '-Wall', '-Wextra', '-Werror', '-shared', '-fPIC', '-include', str(header), *map(str, sources), str(shim), '-o', str(library)], check=True)
    dll = ctypes.CDLL(str(library))
    ctypes.c_void_p.in_dll(dll, 'test_read').value = ctypes.cast(read_memory, ctypes.c_void_p).value
    dll.GetDriverPlace.argtypes = [ctypes.c_uint32]
    dll.GetCurrentLapCount.argtypes = []
    dll.GetDriverPlace.restype = dll.GetCurrentLapCount.restype = ctypes.c_uint32
    def compare(name, address, args, code_size):
        arm_trace.clear(); c_trace.clear()
        uc.reg_write(UC_ARM_REG_CPSR, 0x10 | (rng.getrandbits(4) << 28))
        uc.reg_write(UC_ARM_REG_R0, args[0] if args else rng.getrandbits(32))
        uc.reg_write(UC_ARM_REG_LR, STOP)
        uc.emu_start(address, STOP, count=100)
        assert uc.reg_read(UC_ARM_REG_PC) == STOP, 'Original did not return'
        expected = uc.reg_read(UC_ARM_REG_R0)
        actual = getattr(dll, name)(*args)
        # Pool reads fetch constants; C embeds the independently checked constants.
        data_trace = [item for item in arm_trace if not address <= item[0] < address+code_size]
        assert actual == expected, (name, args, actual, expected)
        assert c_trace == data_trace, (name, c_trace, data_trace)
        counts[name] += 1
    state, mapping, racers, normal, owner, settings = (0x02180000, 0x02181000, 0x02200000, 0x02220000, 0x02182000, 0x02183000)
    put(0x021759c0, state); put(0x0217aa18, mapping); put(0x0217aa14, racers)
    put(0x0217561c, normal); put(0x02175620, owner); put(owner+0x18, settings)
    # All 256 signed mapping values crossed with all 256 packed place bytes.
    put(state+8, 5)
    for slot_byte in range(256):
        signed_slot = slot_byte if slot_byte < 128 else slot_byte-256
        for packed in range(256):
            driver = rng.getrandbits(32)
            put(mapping+(driver & 255), slot_byte, 1)
            put(racers+signed_slot*0x88+0x18a, packed, 1)
            compare('GetDriverPlace', 0x0203c8dc, [driver], 0x74)
    # Driver range of an eight-player race, every possible 16-bit field.
    for field in range(65536):
        driver = field % 8
        put(state+8, [0, 1, 2, 3, 4, 6, 0xffffffff][field % 7])
        put(normal+driver*0x8c+0x50, field, 2)
        compare('GetDriverPlace', 0x0203c8dc, [driver], 0x74)
    # Signed lap boundary and all fallback values, plus forced one-lap mode.
    for value in range(256):
        put(state+0x64, value, 1)
        for mode in [0, 1, 2, 5, 0xffffffff]:
            put(state+8, mode); put(settings+2, rng.getrandbits(16), 2)
            compare('GetCurrentLapCount', 0x02044618, [], 0x44)
    put(state+8, 0)
    for fallback in range(65536):
        put(state+0x64, [0, 128, 255][fallback % 3], 1)
        put(settings+2, fallback, 2)
        compare('GetCurrentLapCount', 0x02044618, [], 0x44)

result = {'scope': 'Local original ARM execution versus host C results and RAM read traces; not whole-game or byte matching', 'cases': counts, 'total_cases': sum(counts.values()), 'seed': '0x4d4b4453', 'source_sha256': {str(p.relative_to(root)): hashlib.sha256(p.read_bytes()).hexdigest() for p in sources}, 'status': 'PASS'}
out = root/'verification/semantic-race/results.json'
out.parent.mkdir(parents=True, exist_ok=True)
out.write_text(json.dumps(result, indent=2)+'\n')
print(json.dumps(result, indent=2))
