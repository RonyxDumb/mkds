/* Decompiled C draft; module arm9_ov000; ROM address 021ae100. No matching claim. */
#include "types.h"
#include "deps/021ae100_FUN_021ae100.h"

undefined4 FUN_021ae100(undefined2 *param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(DAT_021ae130 + 4) + 0xa4);
  if ((iVar1 != 0) && ((*(char *)(iVar1 + 8) == '\x04' || (*(char *)(iVar1 + 8) == '\n')))) {
    if (param_1 != (undefined2 *)0x0) {
      *param_1 = *(undefined2 *)(iVar1 + 0x18);
    }
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *(undefined4 *)(iVar1 + 0x14);
    }
    return *(undefined4 *)(iVar1 + 0x1c);
  }
  return 0;
}

