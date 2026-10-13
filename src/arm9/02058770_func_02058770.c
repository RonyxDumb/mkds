/* Decompiled C draft; module arm9; ROM address 02058770. No matching claim. */
#include "types.h"
#include "deps/02058770_func_02058770.h"

void func_02058770(void)

{
  int *piVar1;
  uint uVar2;
  
  piVar1 = (int *)*piRam020587bc;
  if (*piVar1 == 2) {
    uVar2 = (uint)*(ushort *)((int)piVar1 + iRam020587c0);
  }
  else {
    uVar2 = 0;
  }
  StructTK_SomeFn_from_thumb((int)piVar1 + iRam020587c8 * uVar2 + iRam020587c4);
  piVar1 = piRam020587bc;
  *(byte *)(*piRam020587bc + iRam020587cc) = *(byte *)(*piRam020587bc + iRam020587cc) | 1;
  *(undefined1 *)(*piVar1 + iRam020587d0) = 0;
  *(undefined2 *)(*piVar1 + iRam020587d4) = 0;
  return;
}

