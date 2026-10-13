/* Decompiled C draft; module arm9; ROM address 0201873c. No matching claim. */
#include "types.h"
#include "deps/0201873c_func_0201873c.h"

void func_0201873c(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar5;
  uint uVar4;
  uint uVar6;
  
  uVar6 = param_1 + 4U & 3;
  uVar5 = *(uint *)(param_1 + 4U & 0xfffffffc);
  uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  if (uVar6 != 0) {
    do {
      uVar5 = uVar6 + 0x24 & 3;
      uVar3 = *(uint *)(uVar6 + 0x24 & 0xfffffffc);
      uVar4 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
      uVar5 = uVar6 + 0x20 & 3;
      uVar3 = *(uint *)(uVar6 + 0x20 & 0xfffffffc);
      uVar3 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
      uVar5 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      uVar5 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
      uVar3 = *(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
              *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20;
      if ((-1 < (int)(uVar4 << 0x1b)) && (*(ushort *)(uVar5 + 0x32) <= *(ushort *)(uVar6 + 0x4c))) {
        *(uint *)(uVar6 + 0x24) = uVar4 | 0x10;
        *(undefined2 *)(uVar6 + 0x4c) = 0;
      }
      uVar4 = uVar6 + 0x24 & 3;
      uVar1 = *(uint *)(uVar6 + 0x24 & 0xfffffffc);
      if ((-1 < (int)((uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20) << 0x1d)) &&
         ((uVar4 = uVar6 + 0x80 & 3, uVar1 = *(uint *)(uVar6 + 0x80 & 0xfffffffc),
          uVar4 = ((uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20) << 0xd) >> 0x1d, uVar4 == 0 ||
          ((uint)*(ushort *)(param_1 + 0x48) == uVar4 - 1)))) {
        func_020192e0(param_1,uVar6);
      }
      if (((((((int)((*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
                     *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) << 0x11) < 0) &&
             (*(ushort *)(uVar5 + 0x3c) != 0)) &&
            (uVar4 = uVar6 + 0x24 & 3, uVar1 = *(uint *)(uVar6 + 0x24 & 0xfffffffc),
            (int)((uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20) << 0x1b) < 0)) &&
           (*(ushort *)(uVar5 + 0x3c) < *(ushort *)(uVar6 + 0x4c))) ||
          (uVar5 = uVar6 + 0x24 & 3, uVar4 = *(uint *)(uVar6 + 0x24 & 0xfffffffc),
          (int)((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) << 0x1f) < 0)) &&
         ((uVar5 = uVar6 + 0xc & 3, uVar4 = *(uint *)(uVar6 + 0xc & 0xfffffffc),
          uVar4 >> uVar5 * 8 == 0 && uVar4 << uVar5 * -8 + 0x20 == 0 &&
          (uVar5 = uVar6 + 0x18 & 3, uVar4 = *(uint *)(uVar6 + 0x18 & 0xfffffffc),
          uVar4 >> uVar5 * 8 == 0 && uVar4 << uVar5 * -8 + 0x20 == 0)))) {
        uVar2 = func_0201e3c8((uint *)(uintptr_t)(param_1 + 4),uVar6);
        func_0201e494((undefined4 *)(uintptr_t)(param_1 + 0x10),(uint *)(uintptr_t)(uVar2));
      }
      uVar6 = uVar3;
    } while (uVar3 != 0);
  }
  *(short *)(param_1 + 0x48) = *(short *)(param_1 + 0x48) + 1;
  if (1 < *(ushort *)(param_1 + 0x48)) {
    *(undefined2 *)(param_1 + 0x48) = 0;
  }
  return;
}

