/* Decompiled C draft; module arm9; ROM address 02131b74. No matching claim. */
#include "types.h"
#include "deps/02131b74_FUN_02131b74.h"

uint FUN_02131b74(int param_1,uint param_2,int param_3,uint param_4)

{
  uint *puVar1;
  uint uVar2;
  
  if ((param_2 * 2 < 0xffe00000) || ((param_2 * 2 == 0xffe00000 && (param_1 == 0)))) {
    if ((param_4 * 2 < 0xffe00000) || (((param_4 & 0x7fffffff) == 0x7ff00000 && (param_3 == 0)))) {
      if (-1 < (int)(param_4 | param_2)) {
        return (uint)(param_2 != param_4 || param_1 != param_3);
      }
      if ((param_1 != 0 || ((param_4 | param_2) & 0x7fffffff) != 0) || param_3 != 0) {
        return (uint)(param_4 != param_2 || param_3 != param_1);
      }
      return 0;
    }
  }
  else {
    if ((param_2 & 0x80000) == 0) goto code_r0x02132078;
    if (param_4 * 2 < 0xffe00000) {
      return 1;
    }
    if ((param_4 * 2 == 0xffe00000) && (param_3 == 0)) {
      return 1;
    }
  }
  if ((param_4 & 0x80000) != 0) {
    return 1;
  }
code_r0x02132078:
  puVar1 = (uint *)GetAlphaFlagsRef();
  uVar2 = *(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
          *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20;
  if ((uVar2 & 0x100) != 0) {
    uVar2 = func_02134008(param_1,param_2,param_3,param_4,uRam021321fc);
    return uVar2;
  }
  *puVar1 = uVar2 | 1;
  return 1;
}

