/* Decompiled C draft; module arm9; ROM address 02058130. No matching claim. */
#include "types.h"
#include "deps/02058130_func_02058130.h"

void func_02058130(void)

{
  int *piVar1;
  uint uVar2;
  
  piVar1 = piRam0205817c;
  uVar2 = 0;
  *(undefined1 *)(*piRam0205817c + iRam02058180) = 0;
  piVar1 = (int *)*piVar1;
  if (*piVar1 == 2) {
    uVar2 = (uint)*(ushort *)((int)piVar1 + iRam02058184);
  }
  Mem_CpuCopy8(*(int *)*puRam02058188 + 0x20,(int)piVar1 + iRam02058190 * uVar2 + iRam0205818c,4);
  *(byte *)(*piRam0205817c + iRam02058194) = *(byte *)(*piRam0205817c + iRam02058194) | 1;
  return;
}

