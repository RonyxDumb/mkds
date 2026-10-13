/* Decompiled C draft; module arm9; ROM address 02075390. No matching claim. */
#include "types.h"
#include "deps/02075390_StructHD_SomeFn_3.h"

void StructHD_SomeFn_3(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = param_1 + 0x218U & 3;
  uVar3 = *(uint *)(param_1 + 0x218U & 0xfffffffc);
  StructHD_SomeFn_11(param_1,(int)*(short *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) +
                                            0x42));
  uVar1 = (*(uint *)(uRam02075420 & 0xfffffffc) >> (uRam02075420 & 3) * 8 |
          *(uint *)(uRam02075420 & 0xfffffffc) << (uRam02075420 & 3) * -8 + 0x20) + 0xc;
  uVar3 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  if ((uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) == 5) {
    uVar1 = param_1 + 0x218U & 3;
    uVar3 = *(uint *)(param_1 + 0x218U & 0xfffffffc);
    uVar1 = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0x2c;
    uVar3 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    *(short *)(param_1 + 0x210) =
         (short)((int)(uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) >> 0xc) + -1;
    GetDriverMaybeSfxPosition(param_1 + 0x18,*(undefined2 *)(param_1 + 0x210));
    uVar1 = param_1 + 0x218U & 3;
    uVar2 = *(uint *)(param_1 + 0x218U & 0xfffffffc);
    uVar3 = param_1 + 0x1cU & 3;
    uVar4 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
    uVar1 = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0x1c;
    uVar2 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    *(uint *)(param_1 + 0x1c) =
         (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) +
         (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20);
  }
  else {
    GetDriverMaybeSfxPosition(param_1 + 0x18,*(undefined2 *)(param_1 + 0x210));
    uVar1 = param_1 + 0x1cU & 3;
    uVar3 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
    *(uint *)(param_1 + 0x1c) = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0x6000;
  }
  StructHD_SomeLookAt(param_1);
  return;
}

