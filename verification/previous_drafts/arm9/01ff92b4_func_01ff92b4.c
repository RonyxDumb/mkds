/* Decompiled C draft; module arm9; ROM address 01ff92b4. No matching claim. */
#include "types.h"
#include "deps/01ff92b4_func_01ff92b4.h"

uint func_01ff92b4(void)

{
  uint uVar1;
  uint uVar2;
  
  func_01ff9234();
  uVar1 = (uint)puRam01ff92dc & 3;
  uVar2 = *(uint *)((uint)puRam01ff92dc & 0xfffffffc);
  *puRam01ff92dc = 0;
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

