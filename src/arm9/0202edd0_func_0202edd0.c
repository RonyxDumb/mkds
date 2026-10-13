/* Decompiled C draft; module arm9; ROM address 0202edd0. No matching claim. */
#include "types.h"
#include "deps/0202edd0_func_0202edd0.h"

void func_0202edd0(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *piRam0202edf8;
  iVar1 = func_0202edfc();
  *(undefined2 *)(*(int *)(iVar2 + 8) + (uint)*(ushort *)(iVar2 + 0x2c) * 0x40 + 0xe) =
       *(undefined2 *)(*(int *)(iVar2 + 8) + ((uint)**(ushort **)(iVar2 + 4) + iVar1) * 0x40 + 0xe);
  return;
}

