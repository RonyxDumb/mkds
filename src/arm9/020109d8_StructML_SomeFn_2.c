/* Decompiled C draft; module arm9; ROM address 020109d8. No matching claim. */
#include "types.h"
#include "deps/020109d8_StructML_SomeFn_2.h"

void StructML_SomeFn_2(uint *param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = func_02010a40(param_1 + 2);
  if (((iVar1 == 0) && (iVar1 = func_02010a40(param_1 + 4,param_2), iVar1 == 0)) &&
     (iVar1 = func_02010a40(param_1 + 6,param_2), iVar1 == 0)) {
    return;
  }
  *param_1 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
             *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20 | 0x10;
  return;
}

