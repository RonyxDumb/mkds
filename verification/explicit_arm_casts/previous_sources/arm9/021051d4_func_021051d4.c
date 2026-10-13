/* Decompiled C draft; module arm9; ROM address 021051d4. No matching claim. */
#include "types.h"
#include "deps/021051d4_func_021051d4.h"

void func_021051d4(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_2 + 4U & 3;
  uVar2 = *(uint *)(param_2 + 4U & 0xfffffffc);
  uVar1 = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0x1fc;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  StructMQRacerEntry_SomeFn_42(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20);
  func_020f4754(param_2,1);
  uVar1 = param_1 + 0xcU & 3;
  uVar2 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  func_020f81b8(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,0xe);
  return;
}

