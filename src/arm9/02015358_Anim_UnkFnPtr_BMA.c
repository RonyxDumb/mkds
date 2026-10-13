/* Decompiled C draft; module arm9; ROM address 02015358. No matching claim. */
#include "types.h"
#include "deps/02015358_Anim_UnkFnPtr_BMA.h"

void Anim_UnkFnPtr_BMA(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  uVar2 = param_2 + 8 & 3;
  uVar6 = *(uint *)(param_2 + 8 & 0xfffffffc);
  uVar7 = uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20;
  iVar5 = (uint)*(ushort *)(uVar7 + 8 + (uint)*(ushort *)(uVar7 + 0xe)) * (param_3 & 0xffff);
  iVar4 = uVar7 + 8 + (uint)*(ushort *)(uVar7 + 0xe) + 4;
  iVar1 = (int)(*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
               *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) >> 0xc;
  uVar2 = iVar4 + iVar5;
  uVar6 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  iVar4 = iVar4 + iVar5;
  uVar6 = func_020155d8(uVar7,uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20,iVar1);
  uVar2 = iVar4 + 4U & 3;
  uVar3 = *(uint *)(iVar4 + 4U & 0xfffffffc);
  iVar5 = func_020155d8(uVar7,uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20,iVar1);
  uVar2 = param_1 + 4U & 3;
  uVar3 = *(uint *)(param_1 + 4U & 0xfffffffc);
  *(uint *)(param_1 + 4) =
       (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) & 0x8000 | uVar6 | iVar5 << 0x10;
  uVar2 = iVar4 + 0xcU & 3;
  uVar6 = *(uint *)(iVar4 + 0xcU & 0xfffffffc);
  iVar5 = func_020155d8(uVar7,uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20,iVar1);
  uVar2 = iVar4 + 8U & 3;
  uVar6 = *(uint *)(iVar4 + 8U & 0xfffffffc);
  uVar6 = func_020155d8(uVar7,uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20,iVar1);
  uVar2 = param_1 + 8U & 3;
  uVar3 = *(uint *)(param_1 + 8U & 0xfffffffc);
  *(uint *)(param_1 + 8) =
       (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) & 0x8000 | uVar6 | iVar5 << 0x10;
  uVar2 = iVar4 + 0x10U & 3;
  uVar6 = *(uint *)(iVar4 + 0x10U & 0xfffffffc);
  iVar1 = func_020154e4(uVar7,uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20,iVar1);
  uVar2 = param_1 + 0xcU & 3;
  uVar6 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  *(uint *)(param_1 + 0xc) =
       (uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20) & 0xffe0ffff | iVar1 << 0x10;
  return;
}

