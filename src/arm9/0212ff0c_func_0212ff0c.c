/* Decompiled C draft; module arm9; ROM address 0212ff0c. No matching claim. */
#include "types.h"
#include "deps/0212ff0c_func_0212ff0c.h"

undefined4 func_0212ff0c(undefined4 param_1,undefined4 param_2)

{
  uint *puVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 in_lr;
  
  puVar1 = (uint *)GetAlphaFlagsRef();
  uVar3 = *(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
          *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20;
  if ((uVar3 & 0x100) == 0) {
    *puVar1 = uVar3 | 1;
    return 0x7fffffff;
  }
  uVar2 = func_021341e0(param_1,param_2,uRam02130190,uVar3,in_lr);
  return uVar2;
}

