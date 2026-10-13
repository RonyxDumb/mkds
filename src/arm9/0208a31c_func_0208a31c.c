/* Decompiled C draft; module arm9; ROM address 0208a31c. No matching claim. */
#include "types.h"
#include "deps/0208a31c_func_0208a31c.h"

void func_0208a31c(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined2 unaff_r9;
  
  uVar4 = uRam0208a45c;
  uVar3 = *(uint *)(uRam0208a45c & 0xfffffffc) >> (uRam0208a45c & 3) * 8 |
          *(uint *)(uRam0208a45c & 0xfffffffc) << (uRam0208a45c & 3) * -8 + 0x20;
  uVar1 = uVar3 + param_1 * 4;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  *(uint *)(uVar3 + 0x20) = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  uVar1 = uVar4 & 3;
  uVar2 = *(uint *)(uVar4 & 0xfffffffc);
  uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  uVar1 = uVar2 + 0x20 & 3;
  uVar4 = *(uint *)(uVar2 + 0x20 & 0xfffffffc);
  uVar1 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  if (uVar1 == 0) {
    *(undefined4 *)(uVar2 + 0x73c) = 9;
    return;
  }
  *(int *)(uVar2 + 0x73c) = param_1;
  uVar2 = 0;
  if (*(short *)(uVar1 + 0x10) == 0) {
    return;
  }
  do {
    uVar4 = uVar1 + 4 & 3;
    uVar3 = *(uint *)(uVar1 + 4 & 0xfffffffc);
    uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    if (uVar4 != 0) {
      Animation_SetAt(uVar2 * 0x38 + uVar4,0);
    }
    uVar4 = uVar1 + 8 & 3;
    uVar3 = *(uint *)(uVar1 + 8 & 0xfffffffc);
    uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    if (uVar4 != 0) {
      Animation_SetAt(uVar2 * 0x38 + uVar4,0);
    }
    if ((param_1 == 0) || (param_1 == 2)) {
      if (param_1 == 2) {
        unaff_r9 = 5;
      }
      uVar4 = uVar1 + 0xc & 3;
      uVar3 = *(uint *)(uVar1 + 0xc & 0xfffffffc);
      if (param_1 != 2) {
        unaff_r9 = 3;
      }
      Animation_SetAt(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20,param_1 == 2);
      uVar4 = uVar1 + 4 & 3;
      uVar3 = *(uint *)(uVar1 + 4 & 0xfffffffc);
      uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
      if (uVar4 != 0) {
        *(undefined2 *)(uVar4 + uVar2 * 0x38) = 2;
        *(undefined2 *)(uVar4 + uVar2 * 0x38 + 0x12) = unaff_r9;
      }
      uVar4 = uVar1 + 8 & 3;
      uVar3 = *(uint *)(uVar1 + 8 & 0xfffffffc);
      uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
      if (uVar4 != 0) {
        *(undefined2 *)(uVar4 + uVar2 * 0x38) = 2;
        *(undefined2 *)(uVar4 + uVar2 * 0x38 + 0x12) = unaff_r9;
      }
    }
    uVar2 = uVar2 + 1 & 0xffff;
  } while (uVar2 < *(ushort *)(uVar1 + 0x10));
  return;
}

