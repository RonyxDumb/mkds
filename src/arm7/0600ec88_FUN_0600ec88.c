/* Decompiled C draft; module arm7; ROM address 0600ec88. No matching claim. */
#include "types.h"
#include "deps/0600ec88_FUN_0600ec88.h"

void FUN_0600ec88(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = *(undefined2 *)(param_1 + 2);
  iVar2 = FUN_0600e808(uVar1);
  uVar3 = thunk_FUN_037f8850(0x1000000);
  if ((*(short *)((*(uint *)(DAT_0600ecf0 & 0xfffffffc) >> (DAT_0600ecf0 & 3) * 8 |
                  *(uint *)(DAT_0600ecf0 & 0xfffffffc) << (DAT_0600ecf0 & 3) * -8 + 0x20) + 0x350)
       == 1) && (*(short *)(iVar2 + 0x16) == 1)) {
    FUN_0600e69c(uVar1);
  }
  *(short *)(iVar2 + 0x16) = *(short *)(iVar2 + 0x16) + -1;
  thunk_FUN_037f888c(uVar3);
  return;
}

