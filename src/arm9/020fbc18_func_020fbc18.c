/* Decompiled C draft; module arm9; ROM address 020fbc18. No matching claim. */
#include "types.h"
#include "deps/020fbc18_func_020fbc18.h"

void func_020fbc18(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = param_1 + 0x228U & 3;
  uVar2 = *(uint *)(param_1 + 0x228U & 0xfffffffc);
  uVar5 = param_1 + 0x74U & 3;
  uVar1 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  uVar4 = (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) + 0x1fc;
  uVar2 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  iVar3 = 0x800;
  if ((((uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20) & 0x10000000) != 0) &&
     (uVar4 = (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) + 0x7c, uVar5 = uVar4 & 3,
     uVar4 = *(uint *)(uVar4 & 0xfffffffc),
     ((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 1) != 0)) {
    iVar3 = iRam020fbd44 + 0x800;
  }
  uVar4 = param_1 + 0x27cU & 3;
  uVar5 = *(uint *)(param_1 + 0x27cU & 0xfffffffc);
  uVar4 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  if ((int)uVar4 < 0xd001) {
    *(uint *)(param_1 + 0x27c) = uVar4 + iRam020fbd48;
  }
  else {
    *(uint *)(param_1 + 0x27c) = uVar4 - iRam020fbd48;
  }
  uVar4 = param_1 + 0x27cU & 3;
  uVar2 = *(uint *)(param_1 + 0x27cU & 0xfffffffc);
  uVar5 = param_1 + 0x284U & 3;
  uVar1 = *(uint *)(param_1 + 0x284U & 0xfffffffc);
  func_020fcedc(param_1,iVar3,uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20,
                uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20);
  uVar4 = param_1 + 0x74U & 3;
  uVar5 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 1) == 0) {
    uVar4 = param_1 + 0xd4U & 3;
    uVar5 = *(uint *)(param_1 + 0xd4U & 0xfffffffc);
    func_0210b7ec((undefined4 *)(uintptr_t)(param_1 + 0x300),(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 0x3fffffe0);
    uVar4 = param_1 + 0x270U & 3;
    uVar5 = *(uint *)(param_1 + 0x270U & 0xfffffffc);
    uVar4 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
    if (uVar4 != 1) {
      func_02109078(param_1,uVar4,0x7f,0);
    }
  }
  uVar4 = param_1 + 0x240U & 3;
  uVar5 = *(uint *)(param_1 + 0x240U & 0xfffffffc);
  uVar2 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  uVar4 = param_1 + 0x238U & 3;
  uVar5 = *(uint *)(param_1 + 0x238U & 0xfffffffc);
  uVar4 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  if ((longlong)(int)uVar4 * (longlong)(int)uVar4 + (longlong)(int)uVar2 * (longlong)(int)uVar2 <
      0x1900000000) {
    *(undefined2 *)(param_1 + 0x2f8) = 4;
    *(undefined2 *)(param_1 + 0x2fa) = 1;
  }
  func_020fc654(param_1);
  func_020fc2e8(param_1,param_1 + 0x5c,1);
  return;
}

