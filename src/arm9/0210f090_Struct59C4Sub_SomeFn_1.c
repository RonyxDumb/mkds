/* Decompiled C draft; module arm9; ROM address 0210f090. No matching claim. */
#include "types.h"
#include "deps/0210f090_Struct59C4Sub_SomeFn_1.h"

undefined4 Struct59C4Sub_SomeFn_1(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_1 + 0x41cU & 3;
  uVar2 = *(uint *)(param_1 + 0x41cU & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if (uVar3 != 0) {
    if ((int)uVar3 < 0x1e) {
      *(uint *)(param_1 + 0x41c) = uVar3 + 1;
    }
    else {
      *(undefined4 *)(param_1 + 0x41c) = 0;
    }
    return 0;
  }
  uVar1 = func_0201ec30();
  return uVar1;
}

