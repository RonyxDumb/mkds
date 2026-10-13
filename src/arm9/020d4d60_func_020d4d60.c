/* Decompiled C draft; module arm9; ROM address 020d4d60. No matching claim. */
#include "types.h"
#include "deps/020d4d60_func_020d4d60.h"

bool func_020d4d60(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar5 = param_1 + 0x70U & 3;
  uVar4 = *(uint *)(param_1 + 0x70U & 0xfffffffc);
  if ((int)(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) < param_2) {
    return true;
  }
  uVar5 = param_1 + 0x98U & 3;
  uVar4 = *(uint *)(param_1 + 0x98U & 0xfffffffc);
  uVar4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar7 = param_1 + 8U & 3;
  uVar8 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar2 = iRam020d4dd8 + 0xcU & 3;
  uVar6 = *(uint *)(iRam020d4dd8 + 0xcU & 0xfffffffc);
  uVar5 = uVar4 + 0x3c;
  uVar3 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  iVar1 = (int)((uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20) -
               (uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20)) >> 0xc;
  if (((int)(uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) <= iVar1) &&
     (uVar4 = uVar4 + 0x38, uVar5 = uVar4 & 3, uVar4 = *(uint *)(uVar4 & 0xfffffffc),
     iVar1 <= (int)(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20))) {
    uVar4 = func_0207a780();
    uVar5 = param_1 + 0x74U & 3;
    uVar7 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
    return ((uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) & uVar4) != 0;
  }
  return true;
}

