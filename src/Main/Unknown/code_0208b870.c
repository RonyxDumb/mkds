#include "Main/Unknown/code_02018000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_0208b870.h"

// non-matching: 0x84 bytes, original 0x6c; 12 instructions differ; first at +0x8: original `ldr r0, [pc, #0x4c]
// (->0xb4)`, ours `ldr r0, [pc, #0x64] (->0x74)`
void func_0208b8c8(void) {
    UnkFunc *pcVar1;
    pcVar1 = (UnkFunc *) (*(u32 *) (((u32) ((u32) (&data_0217b054)))));
    if (pcVar1 != (UnkFunc *) 0x0) {
        (*pcVar1)();
    }
    func_0201873c((Unk020184e4 *) (*(u32 *) (((u32) ((u32) (&data_0217b044))))));
    func_0201873c((Unk020184e4 *) (*(u32 *) (((u32) ((u32) (&data_0217b04c))))));
    if (*(u32 *) (((u32) ((u32) (&data_0217b03c)))) >> (((u32) ((u32) (&data_0217b03c))) & 3) * 8 != 0 ||
        *(u32 *) (((u32) ((u32) (&data_0217b03c)))) << (((u32) ((u32) (&data_0217b03c))) & 3) * -8 + 0x20 != 0) {
        func_0201873c((Unk020184e4 *) (*(u32 *) (((u32) ((u32) (&data_0217b03c))))));
        return;
    }
    return;
}

void func_0208b870(u32 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value4;
    u32 compareLeft0;
    u32 compareRight0;
    value1 = (u32) &data_0217b044;
    value4 = value0;
    value0 = (u32) * (const u32 *) ((value1) + (0));
    value1 = value4;
    func_02018674((Unk020184e4 *) value0, (Unk02012f58 *) value1);
    value0 = (u32) &data_0217b04c;
    value1 = value4;
    value0 = (u32) * (const u32 *) ((value0) + (0));
    func_02018674((Unk020184e4 *) value0, (Unk02012f58 *) value1);
    value0 = (u32) &data_0217b03c;
    value0 = (u32) * (const u32 *) ((value0) + (0));
    compareLeft0 = value0;
    compareRight0 = 0u;
    if ((u32) compareLeft0 == (u32) compareRight0) {
    }
    if ((u32) compareLeft0 == (u32) compareRight0) {
        return;
    }
    value1 = value4;
    func_02018674((Unk020184e4 *) value0, (Unk02012f58 *) value1);
    return;
}
