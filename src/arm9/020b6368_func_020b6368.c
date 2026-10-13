/* Decompiled C draft; module arm9; ROM address 020b6368. No matching claim. */
#include "types.h"
#include "deps/020b6368_func_020b6368.h"

uint func_020b6368(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar6 = 0;
  iVar1 = func_020b1dbc();
  if (iVar1 == 1) {
    iVar1 = GetCurrentRaceMode_2();
    if (iVar1 == 2) {
      iVar1 = GetGlobalHD4();
    }
    else {
      iVar1 = GetGlobalHD5();
    }
    uVar6 = iVar1 + 0x50U & 3;
    uVar2 = *(uint *)(iVar1 + 0x50U & 0xfffffffc);
    uVar4 = iVar1 + 0x38U & 3;
    uVar5 = *(uint *)(iVar1 + 0x38U & 0xfffffffc);
    iVar3 = FX_Atan2(uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20,
                     uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20);
    iVar1 = 0x14000 - iVar3 >> 0x1f;
    *(undefined4 *)
     ((*(uint *)(uRam020b6428 & 0xfffffffc) >> (uRam020b6428 & 3) * 8 |
      *(uint *)(uRam020b6428 & 0xfffffffc) << (uRam020b6428 & 3) * -8 + 0x20) + 0x8c) = 0;
    uVar6 = ((uint)((0x14000 - iVar3) * 0x10000 + iVar1) >> 0x10) - iVar1 & 0xffff;
  }
  else if ((iVar1 != 2) && (iVar1 == 3)) {
    iVar1 = func_020b57e4();
    uVar6 = iVar1 + 0x10U & 3;
    uVar4 = *(uint *)(iVar1 + 0x10U & 0xfffffffc);
    iVar1 = func_020b5250(uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20);
    uVar6 = (((int)((ulonglong)((longlong)iRam020b642c * (longlong)(iVar1 << 0x10)) >> 0x20) +
              iVar1 * 0x10000 >> 8) - ((iVar1 << 0x10) >> 0x1f)) + 0x8000U & 0xffff;
  }
  return uVar6;
}

