/* Decompiled C draft; module arm7; ROM address 037fe1c8. No matching claim. */
#include "types.h"
#include "deps/037fe1c8_FUN_037fe1c8.h"

void FUN_037fe1c8(uint param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar3;
  uint uVar2;
  
  if (param_2 == 1) {
    *(undefined1 *)(param_1 + 0x22) = 0;
    FUN_037fcac8();
  }
  uVar2 = param_3 + 0x3cU & 3;
  uVar1 = *(uint *)(param_3 + 0x3cU & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (uVar2 == param_1) {
    uVar2 = param_1 + 0x50 & 3;
    uVar1 = *(uint *)(param_1 + 0x50 & 0xfffffffc);
    *(uint *)(param_3 + 0x3c) = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  }
  else {
    do {
      uVar3 = uVar2;
      uVar2 = uVar3 + 0x50;
      uVar1 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
      if (uVar2 == 0) {
        return;
      }
    } while (uVar2 != param_1);
    uVar2 = param_1 + 0x50 & 3;
    uVar1 = *(uint *)(param_1 + 0x50 & 0xfffffffc);
    *(uint *)(uVar3 + 0x50) = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  }
  return;
}

