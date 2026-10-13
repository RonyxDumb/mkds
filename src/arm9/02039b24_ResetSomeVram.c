/* Decompiled C draft; module arm9; ROM address 02039b24. No matching claim. */
#include "types.h"
#include "deps/02039b24_ResetSomeVram.h"

void ResetSomeVram(void)

{
  func_02148e6c();
  func_02148e58();
  func_02148e34();
  func_02148e10();
  func_02148dfc();
  GX_DisableBankForTexPltt();
  GX_DisableBankForClearImage();
  GX_DisableBankForSubBG();
  GX_DisableBankForSubOBJ();
  GX_DisableBankForBGExtPltt();
  GX_DisableBankForOBJExtPltt();
  GX_DisableBankForLCDC();
  switch(*(uint *)(DAT_02039b90 & 0xfffffffc) >> (DAT_02039b90 & 3) * 8 |
         *(uint *)(DAT_02039b90 & 0xfffffffc) << (DAT_02039b90 & 3) * -8 + 0x20) {
  case 0:
    break;
  case 1:
    goto LAB_02039b80;
  case 2:
    break;
  case 3:
LAB_02039b80:
    GX_DisableBankForARM7();
  }
  return;
}

