/* Decompiled C draft; module arm9; ROM address 02093910. No matching claim. */
#include "types.h"
#include "deps/02093910_func_02093910.h"

void func_02093910(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar1 = func_0207a780();
  uVar2 = param_2 + 0x74U & 3;
  uVar4 = *(uint *)(param_2 + 0x74U & 0xfffffffc);
  if (((uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) & uVar1) == 0) {
    *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) & 0xfffd;
  }
  else {
    *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) | *puRam02093a44;
  }
  uVar2 = param_2 + 0xa4U & 3;
  uVar1 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (uVar2 == 0) {
    uVar2 = param_2 + 0xa0U & 3;
    uVar1 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
    uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    *(uint *)(param_2 + 0xa0) = uVar2 - 1;
    if ((int)uVar2 < 1) {
      func_020d2398(param_2);
      return;
    }
    if (((*(ushort *)(param_2 + 2) & 2) == 0) &&
       (uVar2 = param_2 + 0x78U & 3, uVar1 = *(uint *)(param_2 + 0x78U & 0xfffffffc),
       uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20, (uVar2 & 8) != 0)) {
      uVar1 = param_2 + 0xa8U & 3;
      uVar4 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
      func_0210b7ec((undefined4 *)(uintptr_t)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20),uVar2 & 0x3fffffe0);
    }
    else {
      uVar3 = func_020d4ef4(param_2 + 4);
      uVar2 = param_2 + 0xa8U & 3;
      uVar1 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
      func_0210b7ec((undefined4 *)(uintptr_t)(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20),uVar3);
    }
    VecFx32_Add(param_2 + 4,param_2 + 0x10,(int *)(uintptr_t)(param_2 + 4));
    uVar2 = param_2 + 0xa0U & 3;
    uVar1 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
    if (iRam02093a48 <= (int)(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20)) {
      return;
    }
    func_020d275c(param_2,uRam02093a4c);
    return;
  }
  if (uVar2 != 1) {
    return;
  }
  uVar2 = param_2 + 0xa0U & 3;
  uVar1 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  *(uint *)(param_2 + 0xa0) = uVar2 - 1;
  if (0 < (int)uVar2) {
    uVar2 = param_2 + 0x14U & 3;
    uVar1 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
    *(uint *)(param_2 + 0x14) = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) - 0x400;
    VecFx32_Add(param_2 + 4,param_2 + 0x10,(int *)(uintptr_t)(param_2 + 4));
    return;
  }
  func_020d2398(param_2);
  return;
}

