/* Decompiled C draft; module arm9; ROM address 0206f574. No matching claim. */
#include "types.h"
#include "deps/0206f574_func_0206f574.h"

void func_0206f574(int param_1,uint param_2,undefined4 *param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  func_020d59f8(uRam0206f688);
  func_0206f04c(param_1,param_3);
  uVar2 = param_1 + 0x44U & 3;
  uVar1 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  *(uint *)(param_1 + 0x44) = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20 | 0x80;
  uVar3 = param_3[1];
  uVar4 = param_3[2];
  *(undefined4 *)(param_1 + 0x250) = *param_3;
  *(undefined4 *)(param_1 + 0x254) = uVar3;
  *(undefined4 *)(param_1 + 600) = uVar4;
  uVar2 = param_1 + 0x180U & 3;
  uVar1 = *(uint *)(param_1 + 0x180U & 0xfffffffc);
  if ((((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) == 6) &&
      (uVar2 = (uint)(param_3 + 1) & 3, uVar1 = *(uint *)((uint)(param_3 + 1) & 0xfffffffc),
      (int)(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) < -0x800)) &&
     (uVar2 = param_1 + 0x260U & 3, uVar1 = *(uint *)(param_1 + 0x260U & 0xfffffffc),
     uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20, 0 < (int)uVar2)) {
    *(uint *)(param_1 + 0x260) = -uVar2;
  }
  uVar2 = (uint)(param_3 + 1) & 3;
  uVar1 = *(uint *)((uint)(param_3 + 1) & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if ((int)uVar2 < 1) {
    uVar2 = -uVar2;
  }
  if (1000 < (int)uVar2) {
    uVar2 = param_1 + 0x44U & 3;
    uVar1 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    *(uint *)(param_1 + 0x44) = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20 | 0x40000000;
  }
  if ((param_2 & 0x2000000) == 0) {
    return;
  }
  if (*(uint *)(uRam0206f690 & 0xfffffffc) >> (uRam0206f690 & 3) * 8 == 0 &&
      *(uint *)(uRam0206f690 & 0xfffffffc) << (uRam0206f690 & 3) * -8 + 0x20 == 0) {
    return;
  }
  if ((param_2 & 0x10000) != 0) {
    uVar2 = param_1 + 0x44U & 3;
    uVar1 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    *(uint *)(param_1 + 0x44) = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20 | 0x4000000;
  }
  return;
}

