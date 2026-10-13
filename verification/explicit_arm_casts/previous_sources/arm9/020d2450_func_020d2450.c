/* Decompiled C draft; module arm9; ROM address 020d2450. No matching claim. */
#include "types.h"
#include "deps/020d2450_func_020d2450.h"

void func_020d2450(int param_1)

{
  int iVar1;
  undefined1 auStack_28 [12];
  undefined1 auStack_1c [20];
  
  iVar1 = func_01ffdee4(param_1 + 4,0,0,0xa000,8,0xfffffffe,0,auStack_28,0,0,0,0,0,0);
  if (iVar1 != 0) {
    func_020d7b88(auStack_28,auStack_1c);
    func_01ffccd0(param_1 + 0x28,auStack_1c);
    return;
  }
  return;
}

