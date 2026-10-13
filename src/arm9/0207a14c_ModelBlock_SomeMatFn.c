/* Decompiled C draft; module arm9; ROM address 0207a14c. No matching claim. */
#include "types.h"
#include "deps/0207a14c_ModelBlock_SomeMatFn.h"

void ModelBlock_SomeMatFn(undefined4 param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint unaff_r5;
  uint unaff_r6;
  uint unaff_r7;
  ushort *puVar3;
  
  switch(param_2) {
  case 0:
    uVar2 = (*(uint *)(DAT_0207a204 & 0xfffffffc) >> (DAT_0207a204 & 3) * 8 |
            *(uint *)(DAT_0207a204 & 0xfffffffc) << (DAT_0207a204 & 3) * -8 + 0x20) + 4;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    puVar3 = (ushort *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
    param_2 = (uint)*puVar3;
    unaff_r7 = (uint)puVar3[1];
    unaff_r6 = (uint)puVar3[2];
    unaff_r5 = (uint)puVar3[3];
    break;
  case 1:
    unaff_r6 = 0;
    param_2 = DAT_0207a210;
    unaff_r5 = DAT_0207a208;
    unaff_r7 = DAT_0207a214;
    break;
  case 2:
    unaff_r6 = 0;
    unaff_r5 = 0;
    param_2 = DAT_0207a208;
    unaff_r7 = 0;
    break;
  case 3:
    unaff_r6 = 0;
    param_2 = DAT_0207a208;
    unaff_r5 = DAT_0207a20c;
    unaff_r7 = 0;
  }
  ModelBlock_SomeMatFn_0(param_1,param_2);
  ModelBlock_SomeMatFn_1(param_1,unaff_r7);
  ModelBlock_SomeMatFn_2(param_1,unaff_r6);
  ModelBlock_SetEmi(param_1,unaff_r5);
  return;
}

