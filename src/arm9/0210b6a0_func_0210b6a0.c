/* Decompiled C draft; module arm9; ROM address 0210b6a0. No matching claim. */
#include "types.h"
#include "deps/0210b6a0_func_0210b6a0.h"

void func_0210b6a0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar3 = FX_Div(0x384000,uRam0210b6f0);
  uVar4 = uRam0210b6f0;
  *puRam0210b6f4 = uVar3;
  uVar4 = FX_Div(uRam0210b6f8,uVar4);
  puVar2 = puRam0210b704;
  puVar1 = puRam0210b700;
  *puRam0210b6fc = uVar4;
  *puVar1 = 0;
  *puVar2 = 0;
  return;
}

