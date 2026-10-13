/* Decompiled C draft; module arm9_ov001; ROM address 02196eb0. No matching claim. */
#include "types.h"
#include "deps/02196eb0_FUN_02196eb0.h"

void FUN_02196eb0(void)

{
  int *piVar1;
  
  piVar1 = DAT_02196ec4;
  *(undefined4 *)(*DAT_02196ec4 + 0x54) = 10;
  *(undefined4 *)(*piVar1 + 0x58) = 0;
                    /* WARNING: Could not recover jumptable at 0x02196ec2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_02196ec8)(0,0xb);
  return;
}

