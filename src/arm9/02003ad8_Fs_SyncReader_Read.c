/* Decompiled C draft; module arm9; ROM address 02003ad8. No matching claim. */
#include "types.h"
#include "deps/02003ad8_Fs_SyncReader_Read.h"

void Fs_SyncReader_Read(uint param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar7 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  uVar1 = uVar7 + 0x1c & 3;
  uVar4 = *(uint *)(uVar7 + 0x1c & 0xfffffffc);
  *(uint *)(uVar7 + 0x1c) = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20 | 0x200;
  uVar1 = param_1 + 4 & 3;
  uVar5 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar4 = uVar7 + 0x50 & 3;
  uVar6 = *(uint *)(uVar7 + 0x50 & 0xfffffffc);
  iVar2 = (*(code *)(uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20))
                    (uVar7,param_2,uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20,param_3);
  if ((iVar2 == 0) || (iVar2 == 1)) {
    uVar1 = uVar7 + 0x1c & 3;
    uVar4 = *(uint *)(uVar7 + 0x1c & 0xfffffffc);
    *(uint *)(uVar7 + 0x1c) = (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) & 0xfffffdff;
  }
  else if (iVar2 == 6) {
    uVar3 = Os_DisableIrq();
    uVar1 = uVar7 + 0x1c & 3;
    uVar4 = *(uint *)(uVar7 + 0x1c & 0xfffffffc);
    if (((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) & 0x200) != 0) {
      do {
        Os_Thread_Sleep(uVar7 + 0xc);
        uVar1 = uVar7 + 0x1c & 3;
        uVar4 = *(uint *)(uVar7 + 0x1c & 0xfffffffc);
      } while (((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) & 0x200) != 0);
    }
    Os_RestoreIrq(uVar3);
  }
  uVar1 = param_1 + 4 & 3;
  uVar4 = *(uint *)(param_1 + 4 & 0xfffffffc);
  *(uint *)(param_1 + 4) = (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) + param_3;
  return;
}

