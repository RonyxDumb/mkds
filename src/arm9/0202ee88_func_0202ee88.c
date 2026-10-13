/* Decompiled C draft; module arm9; ROM address 0202ee88. No matching claim. */
#include "types.h"
#include "deps/0202ee88_func_0202ee88.h"

void func_0202ee88(void)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = *piRam0202eebc;
  iVar4 = (uint)*(ushort *)(iVar2 + 0x2e) * 0x40;
  iVar3 = *(int *)(iVar2 + 8);
  if (*(int *)(iVar3 + iVar4) != 0) {
    uVar1 = _s32_div_f((*(int *)(iVar2 + 0x40) - *(int *)(iVar2 + 0x44)) * *(int *)(iVar2 + 0x30),
                       *(int *)(iVar2 + 0x34) + -5);
    *(undefined2 *)(iVar3 + iVar4 + 6) = uVar1;
  }
  return;
}

