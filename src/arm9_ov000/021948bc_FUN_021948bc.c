/* Decompiled C draft; module arm9_ov000; ROM address 021948bc. No matching claim. */
#include "types.h"
#include "deps/021948bc_FUN_021948bc.h"

undefined4 FUN_021948bc(undefined4 param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(param_2 + 0xc);
  if (((puVar2 != (undefined4 *)0x0) && (iVar1 = func_0x0213a074(*param_3,*puVar2), iVar1 == 0)) &&
     (iVar1 = func_0x0213a074(param_3[1],puVar2[2]), iVar1 == 0)) {
    *(int *)param_3[2] = param_2;
    param_3[3] = 1;
    return 0;
  }
  return 1;
}

