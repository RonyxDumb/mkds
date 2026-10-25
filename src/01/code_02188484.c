#include "01/code_02188484.h"

void func_ov001_021888a4(Unk02188950 *param_1, s32 param_2, s32 param_3) {
    if (param_2 == 0) {
        param_1->mUnk_27c = 1;
    } else {
        param_1->mUnk_27c = 2;
    }
    param_1->mUnk_280 = param_1->mUnk_28c = 0;
    param_1->mUnk_284 = param_1->mUnk_290 = param_2;
    param_1->mUnk_288 = param_1->mUnk_294 = 0;
    param_1->mUnk_2b0 = 0;
    param_1->mUnk_298 = param_1->mUnk_2a4 = param_3;
    param_1->mUnk_29c = param_1->mUnk_2a8 = 0xa000;
    param_1->mUnk_2a0 = param_1->mUnk_2ac = param_3;
    param_1->mUnk_2b4 = 0;
}

void func_ov001_0218883c(int param_1, int param_2, u32 param_3, u32 param_4, u32 param_5) {
    if (param_2 == 0) {
        *(u32 *) (param_1 + ((int) 0x0000027cu)) = 1;
    } else {
        *(u32 *) (param_1 + ((int) 0x0000027cu)) = 2;
    }
    *(u32 *) (param_1 + ((int) 0x0000028cu)) = 0;
    *(int *) (param_1 + ((int) 0x00000290u)) = param_2;
    *(u32 *) (param_1 + ((int) 0x00000294u)) = 0;
    *(u32 *) (param_1 + ((int) 0x000002b0u)) = param_3;
    *(u32 *) (param_1 + ((int) 0x000002a4u)) = param_4;
    *(u32 *) (param_1 + ((int) 0x000002a8u)) = ((u32) 0x0000a000u);
    *(u32 *) (param_1 + ((int) 0x000002acu)) = param_4;
    *(u32 *) (param_1 + ((int) 0x000002b4u)) = param_5;
    return;
}

void func_ov001_0218875c(Unk02188950 *param_1, s32 param_2, s32 param_3, s32 param_4) {
    if (param_4 == 0) {
        param_1->mUnk_234 = 0;
    } else {
        param_1->mUnk_234 = 2;
    }
    param_1->mUnk_244 = param_1->mUnk_250 = 0;
    param_1->mUnk_248 = param_1->mUnk_254 = param_2;
    param_1->mUnk_24c = param_1->mUnk_258 = 0;
    param_1->mUnk_274 = 0;
    param_1->mUnk_25c = param_1->mUnk_268 = param_3;
    param_1->mUnk_260 = param_1->mUnk_26c = param_4;
    param_1->mUnk_264 = param_1->mUnk_270 = param_3;
    param_1->mUnk_278 = 0;
    param_1->mUnk_238.x = param_1->mUnk_004.x + param_1->mUnk_244;
    param_1->mUnk_238.y = param_1->mUnk_004.y + param_1->mUnk_248;
    param_1->mUnk_238.z = param_1->mUnk_004.z + param_1->mUnk_24c;
}

void func_ov001_021886f8(int param_1, u32 param_2, u32 param_3, u32 param_4, int param_5, u32 param_6) {
    if (param_5 == 0) {
        *(u32 *) (param_1 + ((int) 0x00000234u)) = 0;
    } else {
        *(u32 *) (param_1 + ((int) 0x00000234u)) = 2;
    }
    *(u32 *) (param_1 + ((int) 0x00000250u)) = 0;
    *(u32 *) (param_1 + ((int) 0x00000254u)) = param_2;
    *(u32 *) (param_1 + ((int) 0x00000258u)) = 0;
    *(u32 *) (param_1 + ((int) 0x00000274u)) = param_3;
    *(u32 *) (param_1 + ((int) 0x00000268u)) = param_4;
    *(int *) (param_1 + ((int) 0x0000026cu)) = param_5;
    *(u32 *) (param_1 + ((int) 0x00000270u)) = param_4;
    *(u32 *) (param_1 + ((int) 0x00000278u)) = param_6;
    return;
}

void func_ov001_02188644(int param_1, int param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7) {
    u32 *puVar1;
    int *piVar2;
    *(u32 *) (param_1 + ((int) 0x0000027cu)) = 0;
    if ((*(u16 *) (param_1 + 2) & ((u32) 0x00000400u)) != 0) {
        param_2 = -param_2;
    }
    piVar2 = (int *) (param_1 + ((int) 0x0000028cu));
    *piVar2 = param_2;
    *(int *) (param_1 + ((int) 0x00000280u)) = *piVar2;
    puVar1 = (u32 *) (param_1 + ((int) 0x00000290u));
    *puVar1 = param_3;
    *(u32 *) (param_1 + ((int) 0x00000284u)) = *puVar1;
    puVar1 = (u32 *) (param_1 + ((int) 0x00000294u));
    *puVar1 = param_4;
    *(u32 *) (param_1 + ((int) 0x00000288u)) = *puVar1;
    *(u32 *) (param_1 + ((int) 0x000002b0u)) = 0;
    puVar1 = (u32 *) (param_1 + ((int) 0x000002a4u));
    *puVar1 = param_5;
    *(u32 *) (param_1 + ((int) 0x00000298u)) = *puVar1;
    puVar1 = (u32 *) (param_1 + ((int) 0x000002a8u));
    *puVar1 = ((u32) 0x0000a000u);
    *(u32 *) (param_1 + ((int) 0x0000029cu)) = *puVar1;
    puVar1 = (u32 *) (param_1 + ((int) 0x000002acu));
    *puVar1 = param_7;
    *(u32 *) (param_1 + ((int) 0x000002a0u)) = *puVar1;
    *(u32 *) (param_1 + ((int) 0x000002b4u)) = 0;
    return;
}

void func_ov001_021885d4(int param_1, int param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7,
                         u32 param_8, u32 param_9) {
    *(u32 *) (param_1 + ((int) 0x0000027cu)) = 0;
    if ((*(u16 *) (param_1 + 2) & ((u32) 0x00000400u)) != 0) {
        param_2 = -param_2;
    }
    *(int *) (param_1 + ((int) 0x0000028cu)) = param_2;
    *(u32 *) (param_1 + ((int) 0x00000290u)) = param_3;
    *(u32 *) (param_1 + ((int) 0x00000294u)) = param_4;
    *(u32 *) (param_1 + ((int) 0x000002b0u)) = param_5;
    *(u32 *) (param_1 + ((int) 0x000002a4u)) = param_6;
    *(u32 *) (param_1 + ((int) 0x000002a8u)) = ((u32) 0x0000a000u);
    *(u32 *) (param_1 + ((int) 0x000002acu)) = param_8;
    *(u32 *) (param_1 + ((int) 0x000002b4u)) = param_9;
    return;
}

void func_ov001_021884f0(int param_1, int param_2, int param_3, int param_4, u32 param_5, u32 param_6, u32 param_7) {
    int *piVar1;
    int *piVar2;
    int *piVar3;
    int *piVar4;
    u32 *puVar5;
    *(u32 *) (param_1 + ((int) 0x00000234u)) = 1;
    if ((*(u16 *) (param_1 + 2) & ((u32) 0x00000400u)) != 0) {
        param_2 = -param_2;
    }
    piVar2 = (int *) (param_1 + ((int) 0x00000250u));
    *piVar2 = param_2;
    piVar1 = (int *) (param_1 + ((int) 0x00000244u));
    *piVar1 = *piVar2;
    piVar3 = (int *) (param_1 + ((int) 0x00000254u));
    *piVar3 = param_3;
    piVar2 = (int *) (param_1 + ((int) 0x00000248u));
    *piVar2 = *piVar3;
    piVar4 = (int *) (param_1 + ((int) 0x00000258u));
    *piVar4 = param_4;
    piVar3 = (int *) (param_1 + ((int) 0x0000024cu));
    *piVar3 = *piVar4;
    *(u32 *) (param_1 + ((int) 0x00000274u)) = 0;
    puVar5 = (u32 *) (param_1 + ((int) 0x00000268u));
    *puVar5 = param_5;
    *(u32 *) (param_1 + ((int) 0x0000025cu)) = *puVar5;
    puVar5 = (u32 *) (param_1 + ((int) 0x0000026cu));
    *puVar5 = param_6;
    *(u32 *) (param_1 + ((int) 0x00000260u)) = *puVar5;
    puVar5 = (u32 *) (param_1 + ((int) 0x00000270u));
    *puVar5 = param_7;
    *(u32 *) (param_1 + ((int) 0x00000264u)) = *puVar5;
    *(u32 *) (param_1 + ((int) 0x00000278u)) = 0;
    *(int *) (param_1 + ((int) 0x00000238u)) = *(int *) (param_1 + 4) + *piVar1;
    *(int *) (param_1 + ((int) 0x0000023cu)) = *(int *) (param_1 + 8) + *piVar2;
    *(int *) (param_1 + ((int) 0x00000240u)) = *(int *) (param_1 + 0xc) + *piVar3;
    return;
}

void func_ov001_02188484(int param_1, int param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7,
                         u32 param_8, u32 param_9) {
    *(u32 *) (param_1 + ((int) 0x00000234u)) = 1;
    if ((*(u16 *) (param_1 + 2) & ((u32) 0x00000400u)) != 0) {
        param_2 = -param_2;
    }
    *(int *) (param_1 + ((int) 0x00000250u)) = param_2;
    *(u32 *) (param_1 + ((int) 0x00000254u)) = param_3;
    *(u32 *) (param_1 + ((int) 0x00000258u)) = param_4;
    *(u32 *) (param_1 + ((int) 0x00000274u)) = param_5;
    *(u32 *) (param_1 + ((int) 0x00000268u)) = param_6;
    *(u32 *) (param_1 + ((int) 0x0000026cu)) = param_7;
    *(u32 *) (param_1 + ((int) 0x00000270u)) = param_8;
    *(u32 *) (param_1 + ((int) 0x00000278u)) = param_9;
    return;
}
