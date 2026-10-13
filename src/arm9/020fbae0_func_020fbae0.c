/* Decompiled C draft; module arm9; ROM address 020fbae0. No matching claim. */
#include "types.h"
#include "deps/020fbae0_func_020fbae0.h"

void func_020fbae0(int param_1)

{
  uint uVar1;
  uint uVar3;
  int iVar4;
  uint uVar2;
  
  uVar2 = param_1 + 0x27cU & 3;
  uVar1 = *(uint *)(param_1 + 0x27cU & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if ((int)uVar2 < 0xd001) {
    *(uint *)(param_1 + 0x27c) = uVar2 + iRam020fbc14;
  }
  else {
    *(uint *)(param_1 + 0x27c) = uVar2 - iRam020fbc14;
  }
  uVar2 = param_1 + 0x27cU & 3;
  uVar1 = *(uint *)(param_1 + 0x27cU & 0xfffffffc);
  func_020ec918(param_1,uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20,0x21,
                *(undefined2 *)(param_1 + 0x276),1);
  uVar2 = param_1 + 0x74U & 3;
  uVar1 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 1) == 0) {
    uVar2 = param_1 + 0xd4U & 3;
    uVar1 = *(uint *)(param_1 + 0xd4U & 0xfffffffc);
    func_0210b7ec((undefined4 *)(uintptr_t)(param_1 + 0x300),(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0x3fffffe0);
    uVar2 = param_1 + 0x270U & 3;
    uVar1 = *(uint *)(param_1 + 0x270U & 0xfffffffc);
    uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    if (uVar2 != 1) {
      func_02109078(param_1,uVar2,0x7f,0);
    }
  }
  uVar2 = param_1 + 0x74U & 3;
  uVar1 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 1) == 0) {
    func_020fc654(param_1);
    func_020fc2e8(param_1,param_1 + 0x5c,1);
    uVar2 = param_1 + 0x228U & 3;
    uVar1 = *(uint *)(param_1 + 0x228U & 0xfffffffc);
    iVar4 = 0;
    uVar2 = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + 0x1f0;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
    do {
      uVar1 = param_1 + 0x168U & 3;
      uVar3 = *(uint *)(param_1 + 0x168U & 0xfffffffc);
      iVar4 = iVar4 + 1;
      if (uVar2 == (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20)) {
        *(undefined2 *)(param_1 + 0x2f8) = 3;
        *(undefined2 *)(param_1 + 0x2fa) = 1;
      }
      uVar2 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
              *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
    } while (iVar4 < 4);
    return;
  }
  return;
}

