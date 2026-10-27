#include "Main/Unknown/code_020883e4.h"

// non-matching: 0x50 bytes, original 0x4c; 16 instructions differ; first at +0x0: original `stmdb sp!, {lr}`, ours
// `stmdb sp!, {r4, lr}`
s8 *func_020883e4(void) {
    func_02135048(((char *) ((u32) (&data_0217af28))), 0x100, ((const char *) ((u32) (&data_02165ef0))),
                  *(u32 *) (((u32) ((u32) (&data_0217af24)))), *(u32 *) (((u32) ((u32) (&data_02165ac4)))));
    return ((s8 *) ((u32) (&data_0217af28)));
}
