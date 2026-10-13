/* Decompiled C draft; module arm9; ROM address 020f4884. No matching claim. */
#include "types.h"
#include "deps/020f4884_func_020f4884.h"

void func_020f4884(undefined4 *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  func_020f49bc();
  uVar2 = (uint)(param_1 + 3) & 3;
  uVar1 = *(uint *)((uint)(param_1 + 3) & 0xfffffffc);
  if (uVar1 >> uVar2 * 8 == 0 && uVar1 << uVar2 * -8 + 0x20 == 0) {
    return;
  }
  if (*(short *)(param_1 + 4) == 0) {
    return;
  }
  uVar2 = (uint)(param_1 + 8) & 3;
  uVar1 = *(uint *)((uint)(param_1 + 8) & 0xfffffffc);
  if (uVar1 >> uVar2 * 8 != 0 || uVar1 << uVar2 * -8 + 0x20 != 0) {
    return;
  }
  *(short *)(param_1 + 4) = *(short *)(param_1 + 4) + -1;
  if (*(short *)(param_1 + 4) == 0) {
    uVar3 = *(uint *)(uRam020f49b0 & 0xfffffffc) >> (uRam020f49b0 & 3) * 8 |
            *(uint *)(uRam020f49b0 & 0xfffffffc) << (uRam020f49b0 & 3) * -8 + 0x20;
    uVar2 = uVar3 + 8;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 5) &&
       (uVar2 = (uint)(param_1 + 1) & 3, uVar1 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc),
       (int)*(char *)(uVar3 + 0x62) ==
       (uint)*(ushort *)((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + 0x1f8))) {
      uVar2 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
              *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) * 0x1c +
              (*(uint *)(uRam020f49b4 & 0xfffffffc) >> (uRam020f49b4 & 3) * 8 |
              *(uint *)(uRam020f49b4 & 0xfffffffc) << (uRam020f49b4 & 3) * -8 + 0x20) + 8;
      uVar1 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      func_020fe958(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
    }
    uVar1 = uRam020f49b4;
    uVar2 = (uint)(param_1 + 2) & 3;
    uVar3 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
    param_1[2] = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) - 1;
    uVar2 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    uVar2 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
            *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) * 0x1c +
            (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + 8;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    iVar4 = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) * 0x44 +
            (*(uint *)(uRam020f49b8 & 0xfffffffc) >> (uRam020f49b8 & 3) * 8 |
            *(uint *)(uRam020f49b8 & 0xfffffffc) << (uRam020f49b8 & 3) * -8 + 0x20);
    uVar2 = iVar4 + 0x1c;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    *(uint *)(iVar4 + 0x1c) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) - 1;
    uVar2 = (uint)(param_1 + 2) & 3;
    uVar1 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
    if (uVar1 >> uVar2 * 8 == 0 && uVar1 << uVar2 * -8 + 0x20 == 0) {
      *param_1 = 0x13;
      param_1[2] = 0;
      param_1[8] = 0;
      param_1[3] = 0;
      *(undefined2 *)(param_1 + 4) = 0;
      *(undefined2 *)((int)param_1 + 0x12) = 0;
      iVar4 = 0;
      do {
        iVar5 = iVar4 + 1;
        param_1[iVar4 + 5] = 0;
        iVar4 = iVar5;
      } while (iVar5 < 3);
      return;
    }
    return;
  }
  return;
}

