/* Decompiled C draft; module arm9; ROM address 0214d79c. No matching claim. */
#include "types.h"
#include "deps/0214d79c_Fifo_IsHandlerReady.h"

bool Fifo_IsHandlerReady(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = iRam0214d7c0 + param_2 * 4 + 0x388;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return (1 << (param_1 & 0xff) & (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20)) != 0;
}

