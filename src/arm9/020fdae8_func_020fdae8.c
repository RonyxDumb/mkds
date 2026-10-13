/* Decompiled C draft; module arm9; ROM address 020fdae8. No matching claim. */
#include "types.h"
#include "deps/020fdae8_func_020fdae8.h"

void func_020fdae8(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = param_1 + 0x198U & 3;
  uVar3 = *(uint *)(param_1 + 0x198U & 0xfffffffc);
  if (uVar3 >> uVar1 * 8 != 0 || uVar3 << uVar1 * -8 + 0x20 != 0) {
    func_020fdc08(param_1,param_1);
    return;
  }
  StateDualHandler_Execute(param_1 + 0x184);
  uVar1 = param_1 + 0x74U & 3;
  uVar3 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if ((((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0x80000) != 0) ||
     (uVar1 = param_1 + 0x170U & 3, uVar3 = *(uint *)(param_1 + 0x170U & 0xfffffffc),
     (int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) < 0)) {
    func_020f7104(param_1,1);
  }
  uVar1 = param_1 + 0x170U & 3;
  uVar3 = *(uint *)(param_1 + 0x170U & 0xfffffffc);
  *(uint *)(param_1 + 0x170) = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) - 1;
  uVar1 = param_1 + 0x180U & 3;
  uVar3 = *(uint *)(param_1 + 0x180U & 0xfffffffc);
  uVar1 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  if ((0 < (int)uVar1) &&
     (*(uint *)(param_1 + 0x180) = uVar1 - 1, uVar1 = param_1 + 0x170U & 3,
     uVar3 = *(uint *)(param_1 + 0x170U & 0xfffffffc),
     uVar3 >> uVar1 * 8 == 0 && uVar3 << uVar1 * -8 + 0x20 == 0)) {
    *(undefined4 *)(param_1 + 0x170) = 0x10;
  }
  uVar1 = param_1 + 300U & 3;
  uVar3 = *(uint *)(param_1 + 300U & 0xfffffffc);
  uVar1 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  if (2 < (int)uVar1) {
    return;
  }
  uVar3 = param_1 + 0x130U & 3;
  uVar2 = *(uint *)(param_1 + 0x130U & 0xfffffffc);
  if ((uVar2 >> uVar3 * 8 == 0 && uVar2 << uVar3 * -8 + 0x20 == 0) && (1 < (int)uVar1)) {
    return;
  }
  if (((*(ushort *)(param_1 + 0x78) & 0x8000) == 0) &&
     (func_020fde18(param_1), uVar1 = param_1 + 0x180U & 3,
     uVar3 = *(uint *)(param_1 + 0x180U & 0xfffffffc),
     uVar3 >> uVar1 * 8 == 0 && uVar3 << uVar1 * -8 + 0x20 == 0)) {
    func_020fdd78(param_1);
  }
  uVar1 = param_1 + 0x170U & 3;
  uVar3 = *(uint *)(param_1 + 0x170U & 0xfffffffc);
  if ((int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) < 0xd2) {
    uVar1 = param_1 + 0x174U & 3;
    uVar3 = *(uint *)(param_1 + 0x174U & 0xfffffffc);
    *(uint *)(param_1 + 0x174) = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) - 1;
    uVar1 = param_1 + 0x174U & 3;
    uVar3 = *(uint *)(param_1 + 0x174U & 0xfffffffc);
    if ((int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) < 1) {
      uVar1 = param_1 + 0x170U & 3;
      uVar3 = *(uint *)(param_1 + 0x170U & 0xfffffffc);
      *(int *)(param_1 + 0x174) = (int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) >> 2;
      uVar1 = param_1 + 0x174U & 3;
      uVar3 = *(uint *)(param_1 + 0x174U & 0xfffffffc);
      if ((int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) < 8) {
        *(undefined4 *)(param_1 + 0x174) = 8;
      }
      return;
    }
    return;
  }
  return;
}

