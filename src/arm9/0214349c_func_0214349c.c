/* Decompiled C draft; module arm9; ROM address 0214349c. No matching claim. */
#include "types.h"
#include "deps/0214349c_func_0214349c.h"

uint func_0214349c(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  iVar1 = Wm_GetGlobal();
  iVar2 = func_02142988(2,7,8);
  if (iVar2 != 0) {
    return 0;
  }
  uVar4 = iVar1 + 4U & 3;
  uVar3 = *(uint *)(iVar1 + 4U & 0xfffffffc);
  DC_InvalidateRangeNoClean((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0xc,4);
  uVar4 = iVar1 + 4U & 3;
  uVar3 = *(uint *)(iVar1 + 4U & 0xfffffffc);
  uVar5 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  uVar4 = uVar5 + 0xc;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if ((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) != 1) {
    DC_InvalidateRangeNoClean(uVar5 + iRam0214351c,4);
    uVar4 = iVar1 + 4U & 3;
    uVar3 = *(uint *)(iVar1 + 4U & 0xfffffffc);
    return *(ushort *)((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0x18e) + 0x1f &
           0xffffffe0;
  }
  return 0;
}

