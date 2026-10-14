/* Decompiled C draft; module arm9; ROM address 02129e78. No matching claim. */
#include "types.h"
#include "deps/02129e78_func_02129e78.h"

void func_02129e78(void)

{
  int iVar1;
  
  iVar1 = *(int *)(*piRam02129ea0 + *(int *)(*piRam02129ea0 + 4) * 4 + 0xb4);
  AllocateReserveTEQSub(0x1b,0,iVar1 + 0xc,*(undefined4 *)(iVar1 + 8));
  return;
}

