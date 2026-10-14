/* Decompiled C draft; module arm9; ROM address 020f7104. No matching claim. */
#include "types.h"
#include "deps/020f7104_func_020f7104.h"

void func_020f7104(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = param_1 + 0x74U & 3;
  uVar3 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0x8000000) == 0) {
    func_020f7184(param_1,0,0);
    return;
  }
  iVar2 = func_020f7184(param_1,0,0);
  if (iVar2 == 0) {
    if (param_2 != 0) {
      uVar1 = param_1 + 0x44U & 3;
      uVar3 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
      func_020fe7a0(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,0,8,
                    (int)*(short *)(param_1 + 0x4e));
      return;
    }
    return;
  }
  return;
}

