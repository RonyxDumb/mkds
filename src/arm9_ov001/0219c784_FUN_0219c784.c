/* Decompiled C draft; module arm9_ov001; ROM address 0219c784. No matching claim. */
#include "types.h"
#include "deps/0219c784_FUN_0219c784.h"

void FUN_0219c784(void)

{
  uint uVar1;
  
  uVar1 = DAT_0219c7e4;
  *DAT_0219c7e0 = *DAT_0219c7e0 & DAT_0219c7e4 | DAT_0219c7e8;
  *DAT_0219c7ec = *DAT_0219c7ec & uVar1 | DAT_0219c7f0;
  *DAT_0219c7f4 = *DAT_0219c7f4 & 0xfffc | 1;
  *DAT_0219c7f8 = 0;
  func_0x0214a40c((uint *)(uintptr_t)(DAT_0219c7fc),0,2,6,10);
  *DAT_0219c808 =
       (*(int *)(*DAT_0219c800 + 0x14) - *(int *)(*DAT_0219c800 + 0x1c)) * 0x10000 & DAT_0219c804;
  return;
}

