#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/code_020f1104.h"

void func_020f1150(int arg0, int arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2;
    u32 value3;
    u32 value12;
    value3 = ((u32) &data_027e00c8);
    value2 = 0x210u;
    value12 = (u32) * (const u32 *) ((value3) + (0));
    value3 = 0u;
    value2 = (value1) * (value2) + (value12);
    *(u32 *) ((value0) + (552)) = (u32) value2;
    *(u32 *) ((value0) + (556)) = (u32) value3;
    *(u32 *) ((value0) + (560)) = (u32) value3;
    *(u32 *) ((value0) + (564)) = (u32) value3;
    *(u32 *) ((value0) + (568)) = (u32) value3;
    return;
}

void func_020f112c(int arg0, int arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2;
    u32 value3;
    u32 value12;
    value3 = ((u32) &data_027e00c8);
    value2 = 0x210u;
    value12 = (u32) * (const u32 *) ((value3) + (0));
    value3 = 0u;
    value2 = (value1) * (value2) + (value12);
    *(u32 *) ((value0) + (552)) = (u32) value2;
    *(u32 *) ((value0) + (568)) = (u32) value3;
    return;
}

void func_020f1104(int param_1) {
    func_02148504((u32) (param_1 + 0x22c), (u32) (param_1 + 0x5c), (int *) ((int *) (u32) (param_1 + 0x5c)));
    func_020f29e8((int) (param_1));
    return;
}
