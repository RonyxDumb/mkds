/* Decompiled C draft; module arm9; ROM address 021322c8. No matching claim. */
#include "types.h"
#include "deps/021322c8_func_021322c8.h"

ulonglong func_021322c8(uint param_1)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  undefined4 in_lr;
  ulonglong uVar6;
  
  uVar3 = param_1 & 0x7fffffff;
  puVar5 = (uint *)(0x9e - (uVar3 >> 0x17));
  if (puVar5 == (uint *)0x0 || 0x9e < uVar3 >> 0x17) {
    if (param_1 != 0xcf000000) {
      puVar5 = (uint *)GetAlphaFlagsRef();
      uVar3 = *(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
              *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20;
      if ((uVar3 & 0x100) != 0) {
        uVar6 = func_02134238(param_1,uRam021323bc,puVar5,uVar3,in_lr);
        return uVar6;
      }
      *puVar5 = uVar3 | 1;
    }
    return CONCAT44(param_1,~((int)param_1 >> 0x1f) + 0x80000000) & 0x7fffffffffffffff;
  }
  if ((int)puVar5 < 0x20) {
    uVar4 = uVar3 << 8 | 0x80000000;
    uVar3 = uVar4 >> ((uint)puVar5 & 0xff);
    if ((int)param_1 < 0) {
      uVar3 = -uVar3;
    }
    iVar1 = uVar4 << (0x20U - (int)puVar5 & 0xff);
    if (iVar1 == 0) {
      return (ulonglong)uVar3;
    }
    puVar5 = (uint *)GetAlphaFlagsRef();
    uVar4 = *(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
            *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20;
    if ((uVar4 & 0x1000) == 0) {
      *puVar5 = uVar4 | 0x10;
      return CONCAT44(iVar1,uVar3);
    }
  }
  else {
    if (uVar3 == 0) {
      return CONCAT44(param_1,param_1) & 0x7fffffff7fffffff;
    }
    puVar2 = (uint *)GetAlphaFlagsRef();
    uVar3 = 0;
    uVar4 = *(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
            *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20;
    if ((uVar4 & 0x1000) == 0) {
      *puVar2 = uVar4 | 0x10;
      return ZEXT48(puVar2) << 0x20;
    }
  }
  uVar6 = func_02134238(uVar3,uRam021323c0,puVar5,uVar4,in_lr);
  return uVar6;
}

