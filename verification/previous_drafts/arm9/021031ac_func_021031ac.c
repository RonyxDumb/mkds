/* Decompiled C draft; module arm9; ROM address 021031ac. No matching claim. */
#include "types.h"
#include "deps/021031ac_func_021031ac.h"

void func_021031ac(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  *(undefined4 *)(param_1 + 300) = 0;
  do {
    iVar1 = param_1 + iVar2;
    iVar2 = iVar2 + 1;
    *(undefined1 *)(iVar1 + 0x130) = 0;
  } while (iVar2 < 8);
  *(undefined4 *)(param_1 + 0x138) = 0xffffffff;
  *(undefined2 *)(param_1 + 0xd8) = 0x1f;
  *(undefined4 *)(param_1 + 0x19c) = 0;
  *(undefined4 *)(param_1 + 0x160) = 0;
  return;
}

