/* Decompiled C draft; module arm9; ROM address 02111adc. No matching claim. */
#include "types.h"
#include "deps/02111adc_func_02111adc.h"

void func_02111adc(void)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = func_0211146c();
  uVar1 = uRam02111b2c;
  if (iVar2 == 0xc) {
    *puRam02111b28 = *puRam02111b28 & uRam02111b2c | uRam02111b30;
    *puRam02111b34 = *puRam02111b34 & uVar1 | uRam02111b38;
    return;
  }
  *puRam02111b28 =
       *puRam02111b28 & uRam02111b2c | ((*puRam02111b28 & uRam02111b3c) >> 8 | 0x13) << 8;
  return;
}

