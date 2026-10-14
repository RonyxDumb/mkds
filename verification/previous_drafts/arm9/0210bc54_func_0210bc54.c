/* Decompiled C draft; module arm9; ROM address 0210bc54. No matching claim. */
#include "types.h"
#include "deps/0210bc54_func_0210bc54.h"

void func_0210bc54(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  IntrusiveListWrapper_RemoveItem();
  param_2 = param_2 + (uint)*(ushort *)(param_1 + 10);
  uVar2 = param_2 + 8;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
    *(undefined4 *)(param_2 + 8) = 0;
  }
  return;
}

