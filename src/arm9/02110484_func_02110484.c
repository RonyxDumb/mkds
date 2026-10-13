/* Decompiled C draft; module arm9; ROM address 02110484. No matching claim. */
#include "types.h"
#include "deps/02110484_func_02110484.h"

void func_02110484(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = FX_Div(((*(uint *)(uRam021104cc & 0xfffffffc) >> (uRam021104cc & 3) * 8 |
                  *(uint *)(uRam021104cc & 0xfffffffc) << (uRam021104cc & 3) * -8 + 0x20) - 0x14) *
                 0x1000,uRam021104d0);
  uVar2 = uRam021104d0;
  *puRam021104d4 = uVar1;
  uVar2 = FX_Div(0x61000,uVar2);
  *puRam021104d8 = uVar2;
  return;
}

