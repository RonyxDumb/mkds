/* Decompiled C draft; module arm9; ROM address 0206ceb4. No matching claim. */
#include "types.h"
#include "deps/0206ceb4_func_0206ceb4.h"

void func_0206ceb4(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  
  *(short *)(param_2 + 0x238) = *(short *)(param_2 + 0x238) + -1;
  if (*(short *)(param_2 + 0x238) < 1) {
    uVar3 = param_2 + 0x48U & 3;
    uVar4 = *(uint *)(param_2 + 0x48U & 0xfffffffc);
    *(uint *)(param_2 + 0x48) = (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) & uRam0206d010;
    *(undefined2 *)(param_2 + 0x238) = 0;
    uVar3 = param_2 + 0x7cU & 3;
    uVar4 = *(uint *)(param_2 + 0x7cU & 0xfffffffc);
    if (((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) & 1) != 0) {
      uVar3 = param_2 + 0x4cU & 3;
      uVar4 = *(uint *)(param_2 + 0x4cU & 0xfffffffc);
      if (((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) & 0x10000000) == 0) {
        func_02074854();
      }
      func_02055c5c();
      return;
    }
    return;
  }
  *param_1 = 0x1000;
  uVar3 = param_2 + 0x7cU & 3;
  uVar4 = *(uint *)(param_2 + 0x7cU & 0xfffffffc);
  if (((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) & 1) != 0) {
    uVar3 = param_2 + 0x48U & 3;
    uVar4 = *(uint *)(param_2 + 0x48U & 0xfffffffc);
    if (((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) & 0x8000) == 0) {
      uVar5 = 0x9e;
    }
    else {
      uVar5 = 0xa0;
    }
    uVar1 = GetAED0PlayerUnk(*(undefined2 *)(param_2 + 0x74));
    func_0210ddf4(uRam0206d014,uVar1,uRam0206d018,param_2,uVar5);
  }
  uVar3 = param_2 + 0x48U & 3;
  uVar4 = *(uint *)(param_2 + 0x48U & 0xfffffffc);
  if (((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) & 0x20000000) == 0) {
    return;
  }
  func_021035ac(*(undefined2 *)(param_2 + 0x74));
  uVar3 = param_2 + 0x4cU & 3;
  uVar4 = *(uint *)(param_2 + 0x4cU & 0xfffffffc);
  uVar3 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  if ((uVar3 & 0x20000) != 0) {
    return;
  }
  if ((uVar3 & 0x8000000) != 0) {
    if (*(short *)(param_2 + iRam0206d01c + 0x1c) < 0x191) {
      *(undefined2 *)(param_2 + iRam0206d01c + 0x1c) = 400;
      uVar3 = param_2 + 0x4cU & 3;
      uVar4 = *(uint *)(param_2 + 0x4cU & 0xfffffffc);
      *(uint *)(param_2 + 0x4c) = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20 | 0x20000;
      uVar5 = func_0207a134();
      uVar1 = func_0207a11c();
      uVar2 = func_0207a104();
      uVar3 = param_2 + 0x590U & 3;
      uVar4 = *(uint *)(param_2 + 0x590U & 0xfffffffc);
      CharacterKartContext_SomeFn_1_0
                (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20,uVar5,uVar1,uVar2);
      return;
    }
    return;
  }
  return;
}

