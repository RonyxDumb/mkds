/* Decompiled C draft; module arm9; ROM address 02131ce8. No matching claim. */
#include "types.h"
#include "deps/02131ce8_FUN_02131ce8.h"

uint FUN_02131ce8(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint *puVar1;
  uint uVar2;
  bool bVar3;
  
  if (((0xffdfffff < param_2 * 2) && ((param_2 * 2 != 0xffe00000 || (param_1 != 0)))) ||
     ((0xffdfffff < param_4 * 2 && (((param_4 & 0x7fffffff) != 0x7ff00000 || (param_3 != 0)))))) {
    puVar1 = (uint *)GetAlphaFlagsRef();
    uVar2 = *(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
            *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20;
    if ((uVar2 & 0x100) == 0) {
      *puVar1 = uVar2 | 1;
      return 0;
    }
    uVar2 = func_02134008(param_1,param_2,param_3,param_4,uRam021321fc);
    return uVar2;
  }
  if (-1 < (int)(param_4 | param_2)) {
    bVar3 = param_4 <= param_2;
    if (param_2 == param_4) {
      bVar3 = param_3 <= param_1;
    }
    return (uint)!bVar3;
  }
  if ((param_1 == 0 && ((param_4 | param_2) & 0x7fffffff) == 0) && param_3 == 0) {
    return 0;
  }
  bVar3 = param_2 <= param_4;
  if (param_4 == param_2) {
    bVar3 = param_1 <= param_3;
  }
  return (uint)!bVar3;
}

