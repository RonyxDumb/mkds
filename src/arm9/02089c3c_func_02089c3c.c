/* Decompiled C draft; module arm9; ROM address 02089c3c. No matching claim. */
#include "types.h"
#include "deps/02089c3c_func_02089c3c.h"

void func_02089c3c(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = func_02061f90();
  if (*(ushort *)(param_2 + 4) == uVar1) {
    *(undefined4 *)(param_1 + 0xc) = 0;
    uVar1 = (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
            *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) + 0xcc;
    uVar3 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    uVar1 = uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20;
    if (0xa000 < (int)uVar1) {
      uVar1 = 0xa000;
    }
    func_02089b4c(param_1,param_2,uVar1);
    uVar3 = param_1 + 0x10U & 3;
    uVar2 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
    uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    if ((int)uVar3 < (int)uVar1) {
      uVar1 = uVar3;
    }
    if (0xa000 < (int)uVar1) {
      uVar1 = 0xa000;
    }
    *(uint *)(param_1 + 4) = uVar1;
    uVar1 = param_2 + 0xa4 & 3;
    uVar3 = *(uint *)(param_2 + 0xa4 & 0xfffffffc);
    uVar1 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
    if ((uVar1 != 0) &&
       (uVar3 = param_1 + 4U & 3, uVar2 = *(uint *)(param_1 + 4U & 0xfffffffc),
       (int)uVar1 < (int)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20))) {
      *(uint *)(param_1 + 4) = uVar1;
    }
  }
  uVar2 = *(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
          *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20;
  uVar1 = uVar2 + 0x180 & 3;
  uVar3 = *(uint *)(uVar2 + 0x180 & 0xfffffffc);
  if (uVar3 >> uVar1 * 8 == 0 && uVar3 << uVar1 * -8 + 0x20 == 0) {
    uVar1 = uVar2 + 0x48 & 3;
    uVar3 = *(uint *)(uVar2 + 0x48 & 0xfffffffc);
    if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & uRam02089ce0) == 0) {
      uVar1 = param_1 + 4U & 3;
      uVar3 = *(uint *)(param_1 + 4U & 0xfffffffc);
      *(uint *)(uVar2 + 0xcc) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
    }
    return;
  }
  return;
}

