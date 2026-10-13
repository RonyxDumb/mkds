/* Decompiled C draft; module arm9_ov003; ROM address 021d2940. No matching claim. */
#include "types.h"
#include "deps/021d2940_FUN_021d2940.h"

undefined4 FUN_021d2940(undefined2 *param_1)

{
  int iVar1;
  
  iVar1 = *DAT_021d296c;
  if ((*(byte *)(iVar1 + 0x38) & 1) == 0) {
    *param_1 = *(undefined2 *)(iVar1 + 0x2c);
    param_1[1] = *(undefined2 *)(iVar1 + 0x2e);
    return 0;
  }
  *param_1 = *(undefined2 *)(iVar1 + 0x28);
  param_1[1] = *(undefined2 *)(iVar1 + 0x2a);
  return 1;
}

