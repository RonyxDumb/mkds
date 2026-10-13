/* Decompiled C draft; module arm9; ROM address 020efd84. No matching claim. */
#include "types.h"
#include "deps/020efd84_func_020efd84.h"

bool func_020efd84(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = param_1 + 0x30;
  if (param_2 == 0x13) {
    return true;
  }
  uVar2 = param_1 + 0x14 & 3;
  uVar1 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
  if ((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) != 0x13) {
    *(undefined4 *)(param_1 + 0x14) = 0x13;
  }
  uVar2 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  if (uVar2 == 0) {
    if (((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
         *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) == 0x13) &&
       (uVar2 = param_1 + 0x38 & 3, uVar1 = *(uint *)(param_1 + 0x38 & 0xfffffffc),
       uVar1 >> uVar2 * 8 == 0 && uVar1 << uVar2 * -8 + 0x20 == 0)) {
      uVar2 = param_2 * 0x1c +
              (*(uint *)(uRam020efe9c & 0xfffffffc) >> (uRam020efe9c & 3) * 8 |
              *(uint *)(uRam020efe9c & 0xfffffffc) << (uRam020efe9c & 3) * -8 + 0x20) + 8;
      uVar1 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      iVar3 = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) * 0x44 +
              (*(uint *)(uRam020efea0 & 0xfffffffc) >> (uRam020efea0 & 3) * 8 |
              *(uint *)(uRam020efea0 & 0xfffffffc) << (uRam020efea0 & 3) * -8 + 0x20);
      uVar2 = iVar3 + 0x1c;
      uVar1 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      *(uint *)(iVar3 + 0x1c) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) - 1;
    }
  }
  else {
    if ((uVar2 == 1) &&
       (uVar2 = param_1 + 4 & 3, uVar1 = *(uint *)(param_1 + 4 & 0xfffffffc),
       (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) < 0x3c)) {
      uVar4 = param_2 * 0x1c +
              (*(uint *)(uRam020efe9c & 0xfffffffc) >> (uRam020efe9c & 3) * 8 |
              *(uint *)(uRam020efe9c & 0xfffffffc) << (uRam020efe9c & 3) * -8 + 0x20) + 8;
      uVar2 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      iVar3 = (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) * 0x44 +
              (*(uint *)(uRam020efea0 & 0xfffffffc) >> (uRam020efea0 & 3) * 8 |
              *(uint *)(uRam020efea0 & 0xfffffffc) << (uRam020efea0 & 3) * -8 + 0x20);
      uVar4 = iVar3 + 0x1c;
      uVar2 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      *(uint *)(iVar3 + 0x1c) = (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) - 1;
      return true;
    }
    func_020f8418();
    func_020f47e4((int *)(uintptr_t)(uVar4),param_2);
  }
  func_020f4754((undefined4 *)(uintptr_t)(uVar4),1);
  return (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
         *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) == 0x13;
}

