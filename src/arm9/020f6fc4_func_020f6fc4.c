/* Decompiled C draft; module arm9; ROM address 020f6fc4. No matching claim. */
#include "types.h"
#include "deps/020f6fc4_func_020f6fc4.h"

void func_020f6fc4(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = func_020f7184(param_1,0,0);
  if (iVar1 < 2) {
    uVar2 = param_1 + 0x44U & 3;
    uVar3 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    uVar2 = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) * 0xa8 +
            (*(uint *)(uRam020f7058 & 0xfffffffc) >> (uRam020f7058 & 3) * 8 |
            *(uint *)(uRam020f7058 & 0xfffffffc) << (uRam020f7058 & 3) * -8 + 0x20) + 0x94;
    uVar3 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    func_020f91fc(param_1,uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20);
  }
  if (iVar1 != 0) {
    return;
  }
  uVar2 = param_1 + 0x74U & 3;
  uVar3 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) & 0x8000000) == 0) {
    return;
  }
  if (param_2 != 0) {
    uVar2 = param_1 + 0x44U & 3;
    uVar3 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    uVar2 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
    if (uVar2 != 5) {
      func_020fe7a0(uVar2,2,8,(int)*(short *)(param_1 + 0x4e));
      return;
    }
    return;
  }
  return;
}

