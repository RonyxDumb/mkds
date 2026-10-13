/* Decompiled C draft; module arm9; ROM address 0200ee08. No matching claim. */
#include "types.h"
#include "deps/0200ee08_DC_FlushAll.h"

void DC_FlushAll(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 in_cr7;
  undefined4 in_cr14;
  
  uVar2 = 0;
  do {
    uVar1 = 0;
    do {
      coproc_moveto_Data_Synchronization(0);
      coprocessor_moveto(0xf,0,2,uVar2 | uVar1,in_cr7,in_cr14);
      uVar1 = uVar1 + 0x20;
    } while ((int)uVar1 < 0x400);
    uVar2 = uVar2 + 0x40000000;
  } while (uVar2 != 0);
  return;
}

