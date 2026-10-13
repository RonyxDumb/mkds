/* Decompiled C draft; module arm9; ROM address 0210a724. No matching claim. */
#include "types.h"
#include "deps/0210a724_func_0210a724.h"

void func_0210a724(int param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar2 = 0;
  if ((((*(byte *)(param_2 + 0x19) & 0x10) == 0) &&
      (uVar1 = param_1 + 0x484U & 3, uVar3 = *(uint *)(param_1 + 0x484U & 0xfffffffc),
      (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 1 <
      (*(uint *)(uRam0210a768 & 0xfffffffc) >> (uRam0210a768 & 3) * 8 |
      *(uint *)(uRam0210a768 & 0xfffffffc) << (uRam0210a768 & 3) * -8 + 0x20))) &&
     (uVar2 = 0x180, (*(byte *)(param_2 + 0x19) & 0x80) != 0)) {
    uVar2 = 0x280;
  }
  func_0210a880(param_1,param_2,uVar2);
  return;
}

