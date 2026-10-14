/* Decompiled C draft; module arm9; ROM address 02004270. No matching claim. */
#include "types.h"
#include "deps/02004270_Fs_File_SendOperation.h"

undefined4 Fs_File_SendOperation(uint *param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar8;
  uint uVar7;
  
  uVar2 = (uint)(param_1 + 2) & 3;
  uVar6 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
  uVar7 = uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20;
  param_1[4] = param_2;
  param_1[5] = 2;
  uVar2 = (uint)(param_1 + 3) & 3;
  uVar6 = *(uint *)((uint)(param_1 + 3) & 0xfffffffc);
  param_1[3] = uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20 | 1;
  uVar1 = Os_DisableIrq();
  uVar2 = uVar7 + 0x1c & 3;
  uVar6 = *(uint *)(uVar7 + 0x1c & 0xfffffffc);
  if (((uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20) & 0x80) != 0) {
    Fs_File_ReleaseOperation(param_1,3);
    Os_RestoreIrq(uVar1);
    return 0;
  }
  uVar2 = 1 << (param_2 & 0xff) & 0x1fc;
  bVar8 = uVar2 != 0;
  if (bVar8) {
    uVar2 = (uint)(param_1 + 3) & 3;
    uVar6 = *(uint *)((uint)(param_1 + 3) & 0xfffffffc);
    uVar2 = uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20;
  }
  if (bVar8) {
    param_1[3] = uVar2 | 4;
  }
  uVar5 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  uVar2 = (uint)(param_1 + 1) & 3;
  uVar6 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  puVar3 = (uint *)(uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20);
  if (uVar5 != 0) {
    *(uint **)(uVar5 + 4) = puVar3;
  }
  if (puVar3 != (uint *)0x0) {
    *puVar3 = uVar5;
  }
  uVar2 = uVar7 + 0x24 & 3;
  uVar5 = *(uint *)(uVar7 + 0x24 & 0xfffffffc);
  uVar6 = uVar7 + 0x20;
  uVar2 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
  while (uVar2 != 0) {
    uVar5 = uVar2 + 4 & 3;
    uVar4 = *(uint *)(uVar2 + 4 & 0xfffffffc);
    uVar6 = uVar2;
    uVar2 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  }
  *(uint **)(uVar6 + 4) = param_1;
  *param_1 = uVar6;
  param_1[1] = 0;
  uVar2 = uVar7 + 0x1c & 3;
  uVar6 = *(uint *)(uVar7 + 0x1c & 0xfffffffc);
  if ((((uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20) & 8) == 0) &&
     (uVar2 = uVar7 + 0x1c & 3, uVar6 = *(uint *)(uVar7 + 0x1c & 0xfffffffc),
     ((uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20) & 0x10) == 0)) {
    uVar2 = uVar7 + 0x1c & 3;
    uVar6 = *(uint *)(uVar7 + 0x1c & 0xfffffffc);
    *(uint *)(uVar7 + 0x1c) = uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20 | 0x10;
    Os_RestoreIrq(uVar1);
    uVar2 = uVar7 + 0x58 & 3;
    uVar6 = *(uint *)(uVar7 + 0x58 & 0xfffffffc);
    if (((uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20) & 0x200) != 0) {
      uVar2 = uVar7 + 0x54 & 3;
      uVar6 = *(uint *)(uVar7 + 0x54 & 0xfffffffc);
      (*(code *)(uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20))(param_1,9);
    }
    Os_DisableIrq();
    uVar2 = (uint)(param_1 + 3) & 3;
    uVar6 = *(uint *)((uint)(param_1 + 3) & 0xfffffffc);
    param_1[3] = uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20 | 0x40;
    uVar2 = (uint)(param_1 + 3) & 3;
    uVar6 = *(uint *)((uint)(param_1 + 3) & 0xfffffffc);
    if (((uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20) & 4) == 0) {
      Os_RestoreIrq();
      Fs_File_ExecuteAsyncOperation((int)(uintptr_t)(param_1));
      return 1;
    }
    Os_RestoreIrq();
  }
  else {
    uVar2 = (uint)(param_1 + 3) & 3;
    uVar6 = *(uint *)((uint)(param_1 + 3) & 0xfffffffc);
    if (((uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20) & 4) == 0) {
      Os_RestoreIrq(uVar1);
      return 1;
    }
    do {
      Os_Thread_Sleep((int)(uintptr_t)(param_1 + 6));
      uVar2 = (uint)(param_1 + 3) & 3;
      uVar6 = *(uint *)((uint)(param_1 + 3) & 0xfffffffc);
    } while (((uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20) & 0x40) == 0);
    Os_RestoreIrq(uVar1);
  }
  uVar1 = Fs_File_ExecuteSyncOperation((int)(uintptr_t)(param_1));
  return uVar1;
}

