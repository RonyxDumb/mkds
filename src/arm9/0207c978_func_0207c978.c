/* Decompiled C draft; module arm9; ROM address 0207c978. No matching claim. */
#include "types.h"
#include "deps/0207c978_func_0207c978.h"

void func_0207c978(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = param_1 + 0x10U & 3;
  uVar2 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  uVar4 = (uint)*(ushort *)(param_2 + 4) * 0x210 +
          (*(uint *)(uRam0207ca14 & 0xfffffffc) >> (uRam0207ca14 & 3) * 8 |
          *(uint *)(uRam0207ca14 & 0xfffffffc) << (uRam0207ca14 & 3) * -8 + 0x20) + 0x30;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if (uVar2 >> uVar3 * 8 == 0 && uVar2 << uVar3 * -8 + 0x20 == 0) {
    func_0207d194();
    return;
  }
  if ((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) != 0x13) {
    *(undefined4 *)(param_1 + 0xc) = 1;
  }
  uVar4 = param_1 + 0xcU & 3;
  uVar3 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  if (uVar3 >> uVar4 * 8 == 0 && uVar3 << uVar4 * -8 + 0x20 == 0) {
    return;
  }
  *(short *)(param_1 + 2) = *(short *)(param_1 + 2) + -1;
  if (0 < *(short *)(param_1 + 2)) {
    return;
  }
  *(undefined2 *)(param_1 + 2) = 0;
  func_0207d194();
  return;
}

