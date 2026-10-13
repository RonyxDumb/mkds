/* Decompiled C draft; module arm7; ROM address 060175d0. No matching claim. */
#include "types.h"
#include "deps/060175d0_FUN_060175d0.h"

void FUN_060175d0(int param_1)

{
  undefined2 uVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = *(uint *)(DAT_060176bc & 0xfffffffc) >> (DAT_060176bc & 3) * 8 |
          *(uint *)(DAT_060176bc & 0xfffffffc) << (DAT_060176bc & 3) * -8 + 0x20;
  uVar1 = *(undefined2 *)(param_1 + 2);
  sVar2 = *(short *)(uVar3 + 0x350);
  if (sVar2 == 1) {
    iVar4 = FUN_0600e918(uVar1);
    if (iVar4 == 0x40) {
      FUN_0600ebbc(uVar1,0x30);
      FUN_0600f79c(param_1 + 0x1e,*(undefined2 *)(param_1 + 0x2c));
      FUN_060145f8(uVar1);
    }
    else {
      if (iVar4 == 0x30) {
        iVar4 = FUN_06013d2c(param_1 + 0x1e,7);
      }
      else {
        iVar4 = FUN_0601364c(param_1 + 0x1e,7);
      }
      if (iVar4 != 0) {
        FUN_060143ac();
      }
    }
  }
  else if ((((sVar2 == 2) || (sVar2 == 3)) && (*(short *)(uVar3 + 0x34c) == 0x40)) &&
          (iVar4 = FUN_0600a578((short *)(uintptr_t)(param_1 + 0x1e),(short *)(uintptr_t)(uVar3 + 0x3c6)), iVar4 != 0)) {
    FUN_0600a970(0x30);
    FUN_0600aa54();
    FUN_0600f79c(param_1 + 0x1e,*(undefined2 *)(param_1 + 0x2c));
  }
  return;
}

