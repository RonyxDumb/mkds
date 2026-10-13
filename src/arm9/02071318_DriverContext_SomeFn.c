/* Decompiled C draft; module arm9; ROM address 02071318. No matching claim. */
#include "types.h"
#include "deps/02071318_DriverContext_SomeFn.h"

void DriverContext_SomeFn(int param_1,int param_2)

{
  uint uVar1;
  bool bVar3;
  uint uVar2;
  
  uVar2 = param_1 + 0x180U & 3;
  uVar1 = *(uint *)(param_1 + 0x180U & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if ((uVar2 != 0) && (uVar2 != 6)) {
    return;
  }
  bVar3 = param_2 == 2;
  if (bVar3) {
    param_2 = param_1 + 0x300;
    uVar2 = 2;
  }
  if (bVar3) {
    *(short *)(param_2 + 0xfc) = (short)uVar2;
  }
  else {
    uVar2 = param_1 + 0x44U & 3;
    uVar1 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 2) == 0) {
      uVar2 = param_1 + 0x380U & 3;
      uVar1 = *(uint *)(param_1 + 0x380U & 0xfffffffc);
      if ((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) < 0xb) {
        *(undefined2 *)(param_1 + 0x3fc) = 0;
      }
      else {
        *(undefined2 *)(param_1 + 0x3fc) = 1;
      }
    }
    else {
      *(undefined2 *)(param_1 + 0x3fc) = 1;
    }
  }
  *(undefined2 *)(param_1 + 0x3fe) = 0;
  *(undefined2 *)(param_1 + 0x400) = 0xf;
  uVar2 = param_1 + 0x4cU & 3;
  uVar1 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  *(uint *)(param_1 + 0x4c) = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20 | 8;
  return;
}

