/* Decompiled C draft; module arm9; ROM address 02004518. No matching claim. */
#include "types.h"
#include "deps/02004518_Fs_Archive_HandleNextOperation.h"

uint Fs_Archive_HandleNextOperation(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar7;
  undefined1 auStack_68 [8];
  int local_60;
  uint uVar6;
  
  uVar1 = Os_DisableIrq();
  uVar6 = param_1 + 0x1cU & 3;
  uVar3 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
  if (((uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) & 0x20) != 0) {
    uVar6 = param_1 + 0x1cU & 3;
    uVar3 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
    *(uint *)(param_1 + 0x1c) = (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) & 0xffffffdf;
    uVar6 = param_1 + 0x24U & 3;
    uVar3 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
    uVar6 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
    while (uVar3 = uVar6, uVar3 != 0) {
      uVar2 = uVar3 + 0xc & 3;
      uVar4 = *(uint *)(uVar3 + 0xc & 0xfffffffc);
      uVar6 = uVar3 + 4 & 3;
      uVar5 = *(uint *)(uVar3 + 4 & 0xfffffffc);
      uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
      if (((uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) & 2) != 0) {
        uVar2 = param_1 + 0x24U & 3;
        uVar4 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
        if ((uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) == uVar3) {
          *(uint *)(param_1 + 0x24) = uVar6;
        }
        Fs_File_ReleaseOperation((undefined4 *)(uintptr_t)(uVar3),3);
        if (uVar6 == 0) {
          uVar6 = param_1 + 0x24U & 3;
          uVar3 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
          uVar6 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
        }
      }
    }
  }
  uVar6 = param_1 + 0x1cU & 3;
  uVar3 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
  if (((((uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) & 0x40) == 0) &&
      (uVar6 = param_1 + 0x1cU & 3, uVar3 = *(uint *)(param_1 + 0x1cU & 0xfffffffc),
      ((uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) & 8) == 0)) &&
     (uVar6 = param_1 + 0x24U & 3, uVar3 = *(uint *)(param_1 + 0x24U & 0xfffffffc),
     uVar6 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20, uVar6 != 0)) {
    uVar3 = param_1 + 0x1cU & 3;
    uVar2 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
    bVar7 = ((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 0x10) == 0;
    if (bVar7) {
      uVar3 = param_1 + 0x1cU & 3;
      uVar2 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
      *(uint *)(param_1 + 0x1c) = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20 | 0x10;
    }
    Os_RestoreIrq(uVar1);
    if ((bVar7) &&
       (uVar3 = param_1 + 0x58U & 3, uVar2 = *(uint *)(param_1 + 0x58U & 0xfffffffc),
       ((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 0x200) != 0)) {
      uVar3 = param_1 + 0x54U & 3;
      uVar2 = *(uint *)(param_1 + 0x54U & 0xfffffffc);
      (*(code *)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20))(uVar6,9);
    }
    uVar1 = Os_DisableIrq();
    uVar3 = uVar6 + 0xc & 3;
    uVar2 = *(uint *)(uVar6 + 0xc & 0xfffffffc);
    *(uint *)(uVar6 + 0xc) = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20 | 0x40;
    uVar3 = uVar6 + 0xc & 3;
    uVar2 = *(uint *)(uVar6 + 0xc & 0xfffffffc);
    if (((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 4) != 0) {
      Os_Thread_WakeUp((uint *)(uintptr_t)(uVar6 + 0x18));
      Os_RestoreIrq(uVar1);
      return 0;
    }
    Os_RestoreIrq(uVar1);
    return uVar6;
  }
  uVar6 = param_1 + 0x1cU & 3;
  uVar3 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
  if ((((uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) & 0x10) != 0) &&
     (uVar6 = param_1 + 0x1cU & 3, uVar3 = *(uint *)(param_1 + 0x1cU & 0xfffffffc),
     *(uint *)(param_1 + 0x1c) = (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) & 0xffffffef,
     uVar6 = param_1 + 0x58U & 3, uVar3 = *(uint *)(param_1 + 0x58U & 0xfffffffc),
     ((uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) & 0x400) != 0)) {
    Fs_File_Initialize((undefined4 *)(void *)(auStack_68));
    uVar6 = param_1 + 0x54U & 3;
    uVar3 = *(uint *)(param_1 + 0x54U & 0xfffffffc);
    local_60 = param_1;
    (*(code *)(uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20))(auStack_68,10);
  }
  uVar6 = param_1 + 0x1cU & 3;
  uVar3 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
  if (((uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) & 0x40) != 0) {
    uVar6 = param_1 + 0x1cU & 3;
    uVar3 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
    *(uint *)(param_1 + 0x1c) = (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) & 0xffffffbf;
    uVar6 = param_1 + 0x1cU & 3;
    uVar3 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
    *(uint *)(param_1 + 0x1c) = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20 | 8;
    Os_Thread_WakeUp((uint *)(uintptr_t)(param_1 + 0x14));
  }
  Os_RestoreIrq(uVar1);
  return 0;
}

