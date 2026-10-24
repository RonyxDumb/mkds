#include "Main/Unknown/code_020422c4.h"

#pragma thumb on

// non-matching: 2 instructions differ; first at +0x2: original nothing, ours `ldr r6, [pc, #0x40] (->0x44)`
void func_02042320(void) {
    int *piVar1;
    u16 sVar2;
    u16 uVar3;
    int iVar4;
    piVar1 = ((int *) ((u32) (&data_02175620)));
    sVar2 = 0;
    uVar3 = 0;
    iVar4 = *((int *) ((u32) (&data_02175620)));
    if (uVar3 < *(u16 *) (iVar4 + 0x78)) {
        do {
            iVar4 = ((int) func_020423fc((unsigned int) (uVar3)));
            if (*(unsigned char *) (iVar4 + 0x44) == '\x04') {
                sVar2 = sVar2 + 1;
            }
            uVar3 = uVar3 + 1;
            iVar4 = *piVar1;
        } while (uVar3 < *(u16 *) (iVar4 + 0x78));
    }
    *(unsigned short *) (iVar4 + ((int) 0x00000102u)) = sVar2;
    return;
}

// non-matching: 0x58 bytes, original 0x5c; 8 instructions differ; first at +0x2: original nothing, ours `ldr r6, [pc,
// #0x48] (->0x4c)`
void func_020422c4(void) {
    int *piVar1;
    u8 cVar2;
    u16 uVar3;
    int iVar4;
    piVar1 = ((int *) ((u32) (&data_02175620)));
    cVar2 = '\0';
    if (*(int *) (*((int *) ((u32) (&data_021759c0))) + 8) == 4) {
        uVar3 = 0;
        if (uVar3 < *(u16 *) (*piVar1 + 0x78)) {
            do {
                iVar4 = ((int) func_020423fc((unsigned int) (uVar3)));
                if (*(unsigned char *) (iVar4 + 0x44) == '\x02') {
                    cVar2 = cVar2 + '\x01';
                }
                uVar3 = uVar3 + 1;
            } while (uVar3 < *(u16 *) (*piVar1 + 0x78));
        }
    }
    *(unsigned char *) (*((int *) ((u32) (&data_02175620))) + ((int) 0x0000010fu)) = cVar2;
    return;
}

#pragma thumb off
