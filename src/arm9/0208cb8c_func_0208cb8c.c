/* Decompiled C draft; module arm9; ROM address 0208cb8c. No matching claim. */
#include "types.h"
#include "deps/0208cb8c_func_0208cb8c.h"

void func_0208cb8c(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = param_1 + 0x34U & 3;
  uVar3 = *(uint *)(param_1 + 0x34U & 0xfffffffc);
  if ((uVar3 >> uVar1 * 8 != 0 || uVar3 << uVar1 * -8 + 0x20 != 0) &&
     (*(short *)(param_1 + 0x30) = *(short *)(param_1 + 0x30) + 1, 10 < *(short *)(param_1 + 0x30)))
  {
    uVar1 = param_1 + 0x38U & 3;
    uVar3 = *(uint *)(param_1 + 0x38U & 0xfffffffc);
    if (uVar3 >> uVar1 * 8 != 0 || uVar3 << uVar1 * -8 + 0x20 != 0) {
      uVar1 = param_1 + 0x74U & 3;
      uVar3 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
      (*(code *)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20))();
    }
    *(undefined4 *)(param_1 + 0x38) = 0;
    *(undefined2 *)(param_1 + 0x30) = 0;
    *(undefined4 *)(param_1 + 0x34) = 0;
    *(undefined2 *)(param_1 + 0x62) = 0;
    *(undefined4 *)(param_1 + 100) = 0;
  }
  uVar1 = param_2 + 0x44U & 3;
  uVar3 = *(uint *)(param_2 + 0x44U & 0xfffffffc);
  if (((((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 8) != 0) &&
      (uVar1 = param_1 + 100U & 3, uVar3 = *(uint *)(param_1 + 100U & 0xfffffffc),
      uVar3 >> uVar1 * 8 != 0 || uVar3 << uVar1 * -8 + 0x20 != 0)) &&
     (*(short *)(param_1 + 0x62) = *(short *)(param_1 + 0x62) + 1, 10 < *(ushort *)(param_1 + 0x62))
     ) {
    uVar1 = param_1 + 0x38U & 3;
    uVar3 = *(uint *)(param_1 + 0x38U & 0xfffffffc);
    if (uVar3 >> uVar1 * 8 != 0 || uVar3 << uVar1 * -8 + 0x20 != 0) {
      uVar1 = param_1 + 0x74U & 3;
      uVar3 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
      (*(code *)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20))(param_1);
    }
    *(undefined4 *)(param_1 + 0x38) = 0;
    *(undefined2 *)(param_1 + 0x30) = 0;
    *(undefined4 *)(param_1 + 0x34) = 0;
    *(undefined2 *)(param_1 + 0x62) = 0;
    *(undefined4 *)(param_1 + 100) = 0;
    uVar1 = param_1 + 0x68U & 3;
    uVar3 = *(uint *)(param_1 + 0x68U & 0xfffffffc);
    (*(code *)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20))(param_1);
    *(undefined4 *)(param_1 + 0x38) = 1;
    *(undefined2 *)(param_1 + 0x62) = 0;
    *(undefined4 *)(param_1 + 100) = 0;
  }
  uVar1 = param_1 + 0x38U & 3;
  uVar3 = *(uint *)(param_1 + 0x38U & 0xfffffffc);
  if (uVar3 >> uVar1 * 8 == 0 && uVar3 << uVar1 * -8 + 0x20 == 0) {
    return;
  }
  iVar2 = func_020846a8(*(undefined2 *)(param_2 + 0x74));
  uVar1 = param_1 + 0x84U & 3;
  uVar3 = *(uint *)(param_1 + 0x84U & 0xfffffffc);
  (*(code *)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20))(param_1,iVar2 + 0x4c,iVar2 + 0x34);
  uVar1 = param_2 + 0x44U & 3;
  uVar3 = *(uint *)(param_2 + 0x44U & 0xfffffffc);
  if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0x10) == 0) {
    uVar1 = param_1 + 0x6cU & 3;
    uVar3 = *(uint *)(param_1 + 0x6cU & 0xfffffffc);
    (*(code *)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20))(param_1);
    return;
  }
  uVar1 = param_1 + 0x34U & 3;
  uVar3 = *(uint *)(param_1 + 0x34U & 0xfffffffc);
  if (uVar3 >> uVar1 * 8 == 0 && uVar3 << uVar1 * -8 + 0x20 == 0) {
    uVar1 = param_1 + 0x70U & 3;
    uVar3 = *(uint *)(param_1 + 0x70U & 0xfffffffc);
    (*(code *)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20))(param_1);
    return;
  }
  return;
}

