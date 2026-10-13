/* Decompiled C draft; module arm9; ROM address 021433b0. No matching claim. */
#include "types.h"
#include "deps/021433b0_func_021433b0.h"

int func_021433b0(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int unaff_r5;
  bool bVar6;
  
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
    DC_InvalidateRangeNoClean(uVar5 + 0x184,2);
    uVar4 = iVar1 + 4U & 3;
    uVar3 = *(uint *)(iVar1 + 4U & 0xfffffffc);
    uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    bVar6 = *(short *)(uVar4 + 0x184) == 0;
    if (bVar6) {
      unaff_r5 = 1;
    }
    if (!bVar6) {
      unaff_r5 = 0;
    }
    DC_InvalidateRangeNoClean(uVar4 + 400,2);
    uVar4 = iVar1 + 4U & 3;
    uVar3 = *(uint *)(iVar1 + 4U & 0xfffffffc);
    uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    uVar3 = (uint)*(ushort *)(uVar4 + 400);
    if (unaff_r5 == 1) {
      DC_InvalidateRangeNoClean(uVar4 + 0xf4,2);
      uVar4 = iVar1 + 4U & 3;
      uVar5 = *(uint *)(iVar1 + 4U & 0xfffffffc);
      return ((uVar3 + 0xc) *
              (uint)*(ushort *)((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) + 0xf4) + 0x29 &
             0xffffffe0) << 1;
    }
    return (uVar3 + 0x51 & 0xffffffe0) << 1;
  }
  return 0;
}

