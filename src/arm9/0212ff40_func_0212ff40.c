/* Decompiled C draft; module arm9; ROM address 0212ff40. No matching claim. */
#include "types.h"
#include "deps/0212ff40_func_0212ff40.h"

undefined8 func_0212ff40(uint param_1,int param_2,int param_3)

{
  uint uVar1;
  uint *puVar2;
  undefined4 in_lr;
  bool bVar3;
  undefined8 uVar4;
  
  uVar1 = GetAlphaFlagsRef();
  uVar1 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
  bVar3 = (uVar1 & 0x800) != 0;
  if (bVar3) {
    uVar4 = func_021341e0(param_1 & 0xe0000000,param_2 + 0xc000000,uRam0213018c,uVar1,in_lr);
    return uVar4;
  }
  if (bVar3) {
    return CONCAT44(param_2,param_3);
  }
  puVar2 = (uint *)GetAlphaFlagsRef();
  uVar1 = *(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
          *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20;
  if ((uVar1 & 0x1000) != 0) {
    uVar4 = func_02134238(param_3,uRam02130194,param_3,uVar1,in_lr);
    return uVar4;
  }
  *puVar2 = uVar1 | 0x18;
  if ((uVar1 & 0x800000) == 0) {
    if ((uVar1 & 0x400000) == 0) {
      return CONCAT44(param_2,param_3);
    }
    if (param_3 == 0) {
      param_3 = 1;
    }
    return CONCAT44(param_2,param_3);
  }
  if ((uVar1 & 0x400000) == 0) {
    param_3 = param_3 - (param_3 >> 0x1f);
  }
  return CONCAT44(param_2,param_3);
}

