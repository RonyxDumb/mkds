/* Decompiled C draft; module arm9; ROM address 02146868. No matching claim. */
#include "types.h"
#include "deps/02146868_Card_Request.h"

bool Card_Request(uint param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar4 = param_1 + 0x114 & 3;
  uVar1 = *(uint *)(param_1 + 0x114 & 0xfffffffc);
  if (((uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20) & 2) == 0) {
    uVar4 = param_1 + 0x114 & 3;
    uVar1 = *(uint *)(param_1 + 0x114 & 0xfffffffc);
    *(uint *)(param_1 + 0x114) = uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20 | 2;
    iVar2 = Fifo_IsHandlerReady(0xb,1);
    while (iVar2 == 0) {
      Os_SpinWait(100);
      iVar2 = Fifo_IsHandlerReady(0xb,1);
    }
    Card_Request(param_1,0,1);
  }
  Arm_FlushRange(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                 *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20,0x40);
  Mem_DcDrainWriteBuffer();
  do {
    *(int *)(param_1 + 4) = param_2;
    uVar4 = param_1 + 0x114 & 3;
    uVar1 = *(uint *)(param_1 + 0x114 & 0xfffffffc);
    *(uint *)(param_1 + 0x114) = uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20 | 0x20;
    do {
      iVar2 = Fifo_SendWord(0xb,param_2,1);
    } while (iVar2 < 0);
    if (param_2 == 0) {
      uVar4 = *(uint *)(param_1 & 0xfffffffc);
      do {
        iVar2 = Fifo_SendWord(0xb,uVar4 >> (param_1 & 3) * 8 | uVar4 << (param_1 & 3) * -8 + 0x20,1)
        ;
      } while (iVar2 < 0);
    }
    uVar3 = Os_DisableIrq();
    uVar4 = param_1 + 0x114 & 3;
    uVar1 = *(uint *)(param_1 + 0x114 & 0xfffffffc);
    for (uVar4 = uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20; (uVar4 & 0x20) != 0;
        uVar4 = uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20) {
      Os_Thread_Sleep(0);
      uVar4 = param_1 + 0x114 & 3;
      uVar1 = *(uint *)(param_1 + 0x114 & 0xfffffffc);
    }
    Os_RestoreIrq(uVar3);
    uVar1 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
            *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
    uVar4 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    uVar4 = uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20;
  } while ((uVar4 == 4) && (param_3 = param_3 + -1, 0 < param_3));
  return uVar4 == 0;
}

