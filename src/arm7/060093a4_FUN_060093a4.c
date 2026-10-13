/* Decompiled C draft; module arm7; ROM address 060093a4. No matching claim. */
#include "types.h"
#include "deps/060093a4_FUN_060093a4.h"

void FUN_060093a4(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = *(uint *)(DAT_060094a0 & 0xfffffffc) >> (DAT_060094a0 & 3) * 8 |
          *(uint *)(DAT_060094a0 & 0xfffffffc) << (DAT_060094a0 & 3) * -8 + 0x20;
  iVar3 = uVar2 + DAT_060094a4;
  if (*(short *)(uVar2 + 0x350) == 1) {
    iVar1 = FUN_0600953c(iVar3 + 0x78);
    if (iVar1 != 0) {
      FUN_060094f8();
      FUN_06013ebc();
    }
    iVar1 = FUN_0600953c(iVar3 + 0x28);
    if (iVar1 != 0) {
      FUN_060094ac((short *)(uintptr_t)(iVar3 + 0x28));
    }
  }
  else if (*(short *)(uVar2 + 0x350) == 2) {
    FUN_0600953c(iVar3 + 100);
    iVar1 = FUN_0600953c(iVar3 + 0x28);
    if (iVar1 != 0) {
      if (*(short *)(iVar3 + 0x28) != 0) {
        FUN_060094f8();
      }
      FUN_060135f8(*(undefined2 *)(uVar2 + 0x3ae));
      *(short *)(uVar2 + 0x3fc) = *(short *)(uVar2 + 0x3fc) + 1;
    }
  }
  iVar1 = FUN_0600953c(iVar3 + 0x14);
  if (iVar1 != 0) {
    FUN_060094ac((short *)(uintptr_t)(iVar3 + 0x14));
  }
  iVar1 = FUN_0600953c(iVar3);
  if (iVar1 != 0) {
    FUN_060094ac((short *)(uintptr_t)(iVar3));
  }
  if (*DAT_060094a8 == 0) {
    *DAT_060094a8 = 1;
  }
  return;
}

