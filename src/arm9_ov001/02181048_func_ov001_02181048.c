/* Decompiled C draft; module arm9_ov001; ROM address 02181048. No matching claim. */
#include "types.h"
#include "deps/02181048_func_ov001_02181048.h"

void func_ov001_02181048(void)

{
  int *piVar1;
  
  piVar1 = piRam02181068;
  *(undefined4 *)(*piRam02181068 + 0x10) = 0;
  *(undefined4 *)(*piVar1 + 0xc) = 0;
  *(undefined4 *)(*piVar1 + 0x14) = 0;
  piVar1 = (int *)*piVar1;
                    /* WARNING: Could not recover jumptable at 0x02181066. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0218106c)(piVar1[8],piVar1[9],*piVar1 * *piVar1);
  return;
}

