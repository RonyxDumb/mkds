/* Decompiled C draft; module arm9; ROM address 02081ab8. No matching claim. */
#include "types.h"
#include "deps/02081ab8_func_02081ab8.h"

void func_02081ab8(int param_1,int param_2)

{
  uint uVar1;
  byte bVar2;
  undefined4 uVar3;
  uint uVar4;
  
  if (param_2 != 0) {
    return;
  }
  bVar2 = *(byte *)(param_1 + 0x9a);
  uVar3 = GetDriverEntry(*(undefined1 *)(param_1 + 0x9b));
  uVar1 = param_1 + 0x94U & 3;
  uVar4 = *(uint *)(param_1 + 0x94U & 0xfffffffc);
  func_02081ca0(param_1,uVar3,uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
  if (bVar2 < *(byte *)(param_1 + 0x99)) {
    *(byte *)(param_1 + 0x9a) = bVar2 + 1;
    return;
  }
  if (bVar2 == *(byte *)(param_1 + 0x99)) {
    uVar1 = param_1 + 0x24U & 3;
    uVar4 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
    *(uint *)(param_1 + 0x24) = (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) & 0xfffffffe | 1;
  }
  return;
}

