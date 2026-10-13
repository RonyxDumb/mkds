/* Decompiled C draft; module arm9_ov000; ROM address 0219d674. No matching claim. */
#include "types.h"
#include "deps/0219d674_FUN_0219d674.h"

void FUN_0219d674(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined1 auStack_220 [4];
  uint local_21c;
  undefined1 auStack_118 [264];
  
  if ((*(int *)(*DAT_0219d6c0 + 0x34) != 0) && (iVar1 = FUN_0219d5e4(*param_2), iVar1 != -1)) {
    FUN_0218ec44(param_1,param_2[2],auStack_220);
    (**(code **)(*DAT_0219d6c0 + 0x34))
              (iVar1,local_21c & 0xff,auStack_118,*(undefined4 *)(*DAT_0219d6c0 + 0x38));
  }
  return;
}

