/* Decompiled C draft; module arm9_ov000; ROM address 02181ff0. No matching claim. */
#include "types.h"
#include "deps/02181ff0_FUN_02181ff0.h"

void FUN_02181ff0(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = DAT_02182068;
  uVar2 = DAT_02182064;
  *DAT_02182060 = *DAT_02182060 & DAT_02182068 | ((*DAT_02182060 & DAT_02182064) >> 8 | 4) << 8;
  *DAT_0218206c = *DAT_0218206c & uVar1 | ((*DAT_0218206c & uVar2) >> 8 | 9) << 8;
  func_0x0214a40c(DAT_02182070,0,2,6,10);
  uVar2 = -(int)*(short *)(*DAT_02182074 + 0x18);
  if (*(short *)(*DAT_02182074 + 0x18) == 0x100 || (int)uVar2 < -0x100) {
    uVar2 = 0xffffff00;
  }
  if ((int)DAT_02182078 <= (int)uVar2) {
    uVar2 = DAT_02182078;
  }
  *DAT_02182080 = uVar2 & DAT_0218207c;
  return;
}

