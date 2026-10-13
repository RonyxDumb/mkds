/* Decompiled C draft; module arm9; ROM address 020d2600. No matching claim. */
#include "types.h"
#include "deps/020d2600_func_020d2600.h"

void func_020d2600(undefined4 param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  int iStack_14;
  uint uVar2;
  
  iStack_14 = func_020d4ef4(param_2);
  if (param_3 == 2) {
    uVar2 = iRam020d2664 + 0x68U & 3;
    uVar1 = *(uint *)(iRam020d2664 + 0x68U & 0xfffffffc);
    uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  }
  else {
    uVar2 = iRam020d2664 + 0xb0U & 3;
    uVar1 = *(uint *)(iRam020d2664 + 0xb0U & 0xfffffffc);
    uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  }
  if (iStack_14 < (int)uVar2) {
    uStack_20 = param_1;
    uStack_1c = param_2;
    iStack_18 = param_3;
    func_0210b7a8((uint)(uintptr_t)(&uStack_20));
    return;
  }
  return;
}

