/* Decompiled C draft; module arm9; ROM address 020fd9d8. No matching claim. */
#include "types.h"
#include "deps/020fd9d8_func_020fd9d8.h"

void func_020fd9d8(int param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  func_020f8e78();
  uVar1 = param_1 + 0x130U & 3;
  uVar2 = *(uint *)(param_1 + 0x130U & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 == 0 && uVar2 << uVar1 * -8 + 0x20 == 0) {
    uVar3 = 2;
  }
  else {
    uVar3 = 3;
  }
  func_020f2d98(param_1,uVar3);
  StateDualHandler_Create(param_1 + 0x184,uRam020fda4c,4,param_1);
  uVar1 = param_1 + 0x74U & 3;
  uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x10000000) != 0) {
    uVar1 = param_1 + 0x130U & 3;
    uVar2 = *(uint *)(param_1 + 0x130U & 0xfffffffc);
    if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
      DriverContext_MaybeQueuePlaySfx(param_1,0xda,0x7f,0);
      return;
    }
    return;
  }
  return;
}

