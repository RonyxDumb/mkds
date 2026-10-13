/* Decompiled C draft; module arm9; ROM address 02104118. No matching claim. */
#include "types.h"
#include "deps/02104118_func_02104118.h"

void func_02104118(void)

{
  undefined4 uVar1;
  
  uVar1 = uRam0210413c;
  if (*(uint *)(uRam02104134 & 0xfffffffc) >> (uRam02104134 & 3) * 8 == 0 &&
      *(uint *)(uRam02104134 & 0xfffffffc) << (uRam02104134 & 3) * -8 + 0x20 == 0) {
    uVar1 = uRam02104140;
  }
                    /* WARNING: Could not recover jumptable at 0x02104130. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02104138)(uVar1);
  return;
}

