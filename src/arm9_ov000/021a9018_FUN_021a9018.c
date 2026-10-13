/* Decompiled C draft; module arm9_ov000; ROM address 021a9018. No matching claim. */
#include "types.h"
#include "deps/021a9018_FUN_021a9018.h"

void FUN_021a9018(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5)

{
  uint uVar1;
  uint uVar2;
  
  if (param_5 == 0) {
    uVar1 = 0;
    uVar2 = 0;
  }
  else {
    uVar1 = (int)(uint)*(ushort *)(param_5 + 2) >> 8 |
            (uint)*(ushort *)(param_5 + 2) << 8 & DAT_021a907c & 0xffff;
    uVar2 = *(uint *)(param_5 + 4);
    uVar2 = uVar2 << 0x18 & DAT_021a9080 |
            uVar2 << 8 & DAT_021a9084 | uVar2 >> 0x18 | uVar2 >> 8 & DAT_021a907c;
  }
  FUN_021a8268(param_1,param_2,param_3,uVar1,uVar2,param_4);
  return;
}

