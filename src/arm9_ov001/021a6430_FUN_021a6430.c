/* Decompiled C draft; module arm9_ov001; ROM address 021a6430. No matching claim. */
#include "types.h"
#include "deps/021a6430_FUN_021a6430.h"

void FUN_021a6430(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                 ushort param_6,int param_7)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  uVar2 = 0xe;
  if ((param_7 != 0) && (param_7 == 1)) {
    uVar2 = 0x1e;
  }
  puVar3 = (undefined4 *)*DAT_021a6494;
  func_0x02124748(*(undefined2 *)(DAT_021a6498 + param_1 * 2),puVar3[1],*puVar3,puVar3[3],param_7,
                  param_5,param_3,param_4);
  if (param_2 == 0) {
    uVar1 = 7;
  }
  else {
    uVar1 = (uint)*(ushort *)(DAT_021a649c + param_1 * 2);
  }
  func_0x02016468(uVar2,(uint)param_6 << 5,
                  *(int *)(*(int *)(*DAT_021a6494 + 8) + 0xc) + uVar1 * 0x20,0x20);
  return;
}

