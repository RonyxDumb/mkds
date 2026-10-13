/* Decompiled C draft; module arm9_ov000; ROM address 021ace90. No matching claim. */
#include "types.h"
#include "deps/021ace90_FUN_021ace90.h"

undefined4 FUN_021ace90(int param_1,int param_2)

{
  int iVar1;
  
  if ((*(ushort *)(param_1 + (param_2 + -1) * 2) & DAT_021acec4) != 0) {
    return 0xffffffff;
  }
  iVar1 = thunk_FUN_021acecc();
  if (iVar1 != 0) {
    return 1;
  }
  return 0;
}

