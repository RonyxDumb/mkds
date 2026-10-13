/* Decompiled C draft; module arm9_ov000; ROM address 021aedd8. No matching claim. */
#include "types.h"
#include "deps/021aedd8_FUN_021aedd8.h"

undefined4 FUN_021aedd8(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = FUN_021af090();
  if (iVar1 != 0) {
    if (*(char *)(iVar1 + 8) == '\x01') {
      FUN_021aee38(param_1,param_2);
    }
    else if ((byte)(*(char *)(iVar1 + 8) - 3U) < 2) {
      *(int *)(iVar1 + 0x28) = *(int *)(iVar1 + 0x28) + -1;
      FUN_021aee38(param_1,param_2);
    }
    else {
      FUN_021aeed8(param_1,param_2,param_3,(ushort)*(byte *)(param_1 + 5) * 0x100 + 3);
    }
    return 1;
  }
  return 0;
}

