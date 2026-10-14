/* Decompiled C draft; module arm9; ROM address 020031a0. No matching claim. */
#include "types.h"
#include "deps/020031a0_Fs_File_ReleaseOperation.h"

void Fs_File_ReleaseOperation(undefined4 *param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar5;
  uint *puVar4;
  
  uVar2 = Os_DisableIrq();
  uVar5 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  uVar1 = (uint)(param_1 + 1) & 3;
  uVar3 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  puVar4 = (uint *)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  if (uVar5 != 0) {
    *(uint **)(uVar5 + 4) = puVar4;
  }
  if (puVar4 != (uint *)0x0) {
    *puVar4 = uVar5;
  }
  *param_1 = 0;
  param_1[1] = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
               *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  uVar1 = (uint)(param_1 + 3) & 3;
  uVar3 = *(uint *)((uint)(param_1 + 3) & 0xfffffffc);
  param_1[3] = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0xffffffb0;
  param_1[5] = param_2;
  Os_Thread_WakeUp(param_1 + 6);
  Os_RestoreIrq(uVar2);
  return;
}

