/* Decompiled C draft; module arm9; ROM address 0204e4d8. No matching claim. */
#include "types.h"
#include "deps/0204e4d8_func_0204e4d8.h"

void func_0204e4d8(void)

{
  int *piVar1;
  byte local_20 [32];
  
  piVar1 = piRam0204e550;
  *(undefined4 *)(*piRam0204e550 + 0xc) = 0x1c;
  *(undefined4 *)(*piVar1 + 0x10) = 1;
  local_20[1] = 10;
  local_20[0] = *(byte *)(*piRam0204e554 + 0x40) & 0xf | 0x90;
  Mem_CpuCopy8((ushort *)(uintptr_t)(*(int *)*puRam0204e558 + 0xc),(uint *)(void *)(local_20 + 2),0x14);
  piVar1 = piRam0204e550;
  *(undefined1 *)(*piRam0204e550 + iRam0204e55c) = 0xff;
  func_0200bb98(*(undefined4 *)(*piVar1 + iRam0204e560),(undefined4)(uintptr_t)(local_20));
  func_0200ba84(uRam0204e564);
  *(undefined4 *)(*piRam0204e550 + 0x10) = 0;
  return;
}

