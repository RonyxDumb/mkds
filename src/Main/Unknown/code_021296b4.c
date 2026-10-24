#include "Main/Unknown/code_021296b4.h"

#pragma thumb on

// non-matching: 27 instructions differ; first at +0x6: original `ldr r0, [pc, #0xc0] (->0xc8)`, ours `ldr r6, [pc,
// #0xc0] (->0xc8)`
void func_021296b4(void) {
    u8 bVar1;
    int *piVar2;
    int iVar3;
    int iVar4;
    int iVar5;
    iVar5 = 0;
    *(u32 *) (*((int *) ((u32) (&data_0217d400))) + 0x1c) = 0;
    iVar3 = ((u16) func_020ab748());
    piVar2 = ((int *) ((u32) (&data_0217d400)));
    if (0 < iVar3) {
        iVar3 = 0;
        do {
            iVar4 = ((u32) func_020ab798());
            if (*(unsigned short *) (iVar4 + iVar3) != 0x20) {
                iVar4 = ((u32) func_020ab798());
                if (*(u16 *) (iVar4 + iVar3) != ((u32) 0x00003000u)) {
                    *(u32 *) (*piVar2 + 0x1c) = 1;
                }
            }
            iVar3 = iVar3 + 2;
            iVar5 = iVar5 + 1;
            iVar4 = ((u16) func_020ab748());
        } while (iVar5 < iVar4);
    }
    bVar1 = *(u8 *) (((int) (u32) ((unsigned char *) &data_0215d0e0)) + 1);
    iVar3 = ((u16) func_020ab748());
    if (bVar1 - 1 == iVar3) {
        iVar5 = (u32) bVar1 * 2;
        iVar3 = ((u32) func_020ab798());
        if (*(unsigned short *) (iVar3 + iVar5 + -2) != 0x20) {
            iVar3 = ((u32) func_020ab798());
            if (*(u16 *) (iVar3 + iVar5 + -2) != ((u32) 0x00003000u)) {
                iVar3 = ((u32) func_020ab798());
                if (*(unsigned short *) (iVar3 + iVar5 + -2) != 0) {
                    *(u32 *) (*((int *) ((u32) (&data_0217d400))) + 0x1c) = 1;
                }
            }
        }
    }
    iVar3 = func_020ab8c4();
    if (iVar3 == 1) {
        *(u32 *) (*((int *) ((u32) (&data_0217d400))) + 0x14) = 1;
    } else {
        *(u32 *) (*((int *) ((u32) (&data_0217d400))) + 0x14) = 0;
    }
    iVar3 = func_020ab8c4();
    if (iVar3 == 2) {
        *(u32 *) (*((int *) ((u32) (&data_0217d400))) + 0x18) = 1;
        return;
    }
    *(u32 *) (*((int *) ((u32) (&data_0217d400))) + 0x18) = 0;
    return;
}

#pragma thumb off
