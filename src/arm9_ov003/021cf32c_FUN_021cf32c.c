/* Decompiled C draft; module arm9_ov003; ROM address 021cf32c. No matching claim. */
#include "types.h"
#include "deps/021cf32c_FUN_021cf32c.h"

undefined2 FUN_021cf32c(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_021cf35c;
  iVar2 = *DAT_021cf358;
  *DAT_021cf35c = iVar2 + 2;
  piVar1[1] = iVar2 + 4;
  piVar1[2] = iVar2 + 6;
  piVar1[3] = iVar2 + 8;
  piVar1[4] = iVar2 + 10;
  piVar1[5] = iVar2 + 0xc;
  return *(undefined2 *)piVar1[param_1];
}

