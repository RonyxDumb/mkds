/* Decompiled C draft; module arm9; ROM address 02076c50. No matching claim. */
#include "types.h"
#include "deps/02076c50_func_02076c50.h"

void func_02076c50(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  if (param_2 != 0) {
    uVar1 = param_1 + 0x8cU & 3;
    uVar7 = *(uint *)(param_1 + 0x8cU & 0xfffffffc);
    param_3 = uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20;
  }
  uVar1 = param_1 + 0x70U & 3;
  uVar7 = *(uint *)(param_1 + 0x70U & 0xfffffffc);
  if (param_2 == 0) {
    uVar2 = param_1 + 0x74U & 3;
    uVar8 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
    param_3 = uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20;
  }
  uVar2 = param_1 + 0x78U & 3;
  uVar5 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
  uVar8 = param_1 + 0x7cU & 3;
  uVar6 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  uVar3 = param_1 + 0x80U & 3;
  uVar9 = *(uint *)(param_1 + 0x80U & 0xfffffffc);
  uVar4 = param_1 + 0x84U & 3;
  uVar10 = *(uint *)(param_1 + 0x84U & 0xfffffffc);
  G3i_FrustumW_(uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20,
                uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20,
                uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20,
                uVar10 >> uVar4 * 8 | uVar10 << uVar4 * -8 + 0x20,
                uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20,param_3,0x1000,0,uRam02076cbc);
  uVar1 = iRam02076cc0 + 0xfcU & 3;
  uVar7 = *(uint *)(iRam02076cc0 + 0xfcU & 0xfffffffc);
  *(uint *)(iRam02076cc0 + 0xfc) = (uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20) & 0xffffffaf;
  return;
}

