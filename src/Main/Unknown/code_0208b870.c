#include "Main/Unknown/code_0208b870.h"

// non-matching: 0x84 bytes, original 0x6c; 12 instructions differ; first at +0x8: original `ldr r0, [pc, #0x4c]
// (->0xb4)`, ours `ldr r0, [pc, #0x64] (->0x74)`
void func_0208b8c8(void) {
    UnkFunc *pcVar1;
    pcVar1 = (UnkFunc *) (*(u32 *) (((u32) ((u32) (&data_0217b054)))));
    if (pcVar1 != (UnkFunc *) 0x0) {
        (*pcVar1)();
    }
    func_0201873c(*(u32 *) (((u32) ((u32) (&data_0217b044)))));
    func_0201873c(*(u32 *) (((u32) ((u32) (&data_0217b04c)))));
    if (*(u32 *) (((u32) ((u32) (&data_0217b03c)))) >> (((u32) ((u32) (&data_0217b03c))) & 3) * 8 != 0 ||
        *(u32 *) (((u32) ((u32) (&data_0217b03c)))) << (((u32) ((u32) (&data_0217b03c))) & 3) * -8 + 0x20 != 0) {
        func_0201873c();
        return;
    }
    return;
}

// non-matching: 0xac bytes, original 0x58; 29 instructions differ; first at +0x4: original `ldr r1, [pc, #0x40]
// (->0x4c)`, ours `ldr r1, [pc, #0x94] (->0xa0)`
void func_0208b870(u32 param_1) {
    u32 uVar1;
    func_02018674(
        (int) (*(u32 *) (((u32) (&data_0217b044)) & 0xfffffffc) >> (((u32) (&data_0217b044)) & 3) * 8 |
               *(u32 *) (((u32) (&data_0217b044)) & 0xfffffffc) << (((u32) (&data_0217b044)) & 3) * -8 + 0x20),
        (u32) (param_1));
    func_02018674(
        (int) (*(u32 *) (((u32) (&data_0217b04c)) & 0xfffffffc) >> (((u32) (&data_0217b04c)) & 3) * 8 |
               *(u32 *) (((u32) (&data_0217b04c)) & 0xfffffffc) << (((u32) (&data_0217b04c)) & 3) * -8 + 0x20),
        (u32) (param_1));
    uVar1 = *(u32 *) (((u32) (&data_0217b03c)) & 0xfffffffc) >> (((u32) (&data_0217b03c)) & 3) * 8 |
            *(u32 *) (((u32) (&data_0217b03c)) & 0xfffffffc) << (((u32) (&data_0217b03c)) & 3) * -8 + 0x20;
    if (uVar1 != 0) {
        func_02018674((int) (uVar1), (u32) (param_1));
        return;
    }
    return;
}
