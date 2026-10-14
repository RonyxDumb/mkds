/* Decompiled C draft; module arm7; ROM address 06016560. No matching claim. */
#include "types.h"
#include "deps/06016560_FUN_06016560.h"

void FUN_06016560(int param_1)

{
  undefined2 uVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = *(uint *)(DAT_06016618 & 0xfffffffc) >> (DAT_06016618 & 3) * 8 |
          *(uint *)(DAT_06016618 & 0xfffffffc) << (DAT_06016618 & 3) * -8 + 0x20;
  uVar1 = *(undefined2 *)(param_1 + 2);
  sVar2 = *(short *)(uVar3 + 0x350);
  if (sVar2 == 1) {
    uVar3 = FUN_0600e918(uVar1);
    if (0x20 < uVar3) {
      FUN_0600ebbc(uVar1,0x20);
      FUN_0600fa04(param_1 + 0x1e,*(undefined2 *)(param_1 + 0x2c));
      FUN_060145f8(uVar1);
    }
  }
  else if ((((sVar2 == 2) || (sVar2 == 3)) && (0x20 < *(ushort *)(uVar3 + 0x34c))) &&
          (iVar4 = FUN_0600a578((short *)(uintptr_t)(param_1 + 0x1e),(short *)(uintptr_t)(uVar3 + 0x3c6)), iVar4 != 0)) {
    FUN_0600a970(0x20);
    FUN_0600aa54();
    FUN_0600fa04(param_1 + 0x1e,*(undefined2 *)(param_1 + 0x2c));
  }
  return;
}

