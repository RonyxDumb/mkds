/* Decompiled C draft; module arm9_ov001; ROM address 0219c3bc. No matching claim. */
#include "types.h"
#include "deps/0219c3bc_FUN_0219c3bc.h"

void FUN_0219c3bc(void)

{
  int *piVar1;
  
  piVar1 = DAT_0219c3d0;
  *(undefined4 *)(*DAT_0219c3d0 + 0x4c) = 6;
  *(undefined4 *)(*piVar1 + 0x50) = 0;
                    /* WARNING: Could not recover jumptable at 0x0219c3cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_0219c3d4)();
  return;
}

