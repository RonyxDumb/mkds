#include "Main/Unknown/code_02108b78.h"
#include "code_0212c6ac.h"

// non-matching: 0x64 bytes, original 0x50; 27 instructions differ; first at +0x0: original `stmdb sp!, {lr}`, ours
// `stmdb sp!, {r4, lr}`
void func_02108bb4(void) {
    func_0212c6f0((Unk0212c400 **) ((u32) &data_0217c788), 1);
    if (*(u32 *) (((u32) &data_0217c788)) >> (((u32) &data_0217c788) & 3) * 8 != 0 ||
        *(u32 *) (((u32) &data_0217c788)) << (((u32) &data_0217c788) & 3) * -8 + 0x20 != 0) {
        func_0212c6f0((Unk0212c400 **) ((u32) &data_0217c788), 0);
    }
    func_0212ecc0((const void *) (((u32) &data_0217c788)), (u32) (0), (u32) (((u32) 0x00000202u)));
    return;
}

void func_02108b78(void) {
    func_0212c6f0((Unk0212c400 **) ((u32) &data_0217c788), 1);
    func_0212ecc0((const void *) (((u32) &data_0217d068)), (u32) (0), (u32) (((u32) 0x00000203u)));
    return;
}
