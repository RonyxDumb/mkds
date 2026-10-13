/* Decompiled C draft; module arm7; ROM address 060084c0. No matching claim. */
#include "types.h"
#include "deps/060084c0_FUN_060084c0.h"

void FUN_060084c0(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined2 *puVar3;
  uint uVar4;
  undefined1 auStack_208 [512];
  
  FUN_06000680();
  uVar1 = param_1 + 4U & 3;
  uVar4 = *(uint *)(param_1 + 4U & 0xfffffffc);
  iVar2 = FUN_06002214((undefined2 *)(void *)(auStack_208),(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) & 0xffff);
  if (*(short *)(iVar2 + 4) == 0) {
    puVar3 = (undefined2 *)thunk_FUN_03807424();
    *puVar3 = 0x24;
    puVar3[1] = 0;
    thunk_FUN_038074cc();
  }
  else {
    FUN_06008484(DAT_06008520);
  }
  return;
}

