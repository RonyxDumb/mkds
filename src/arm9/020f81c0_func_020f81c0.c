/* Decompiled C draft; module arm9; ROM address 020f81c0. No matching claim. */
#include "types.h"
#include "deps/020f81c0_func_020f81c0.h"

void func_020f81c0(undefined4 *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  uVar3 = (uint)(param_1 + 6) & 3;
  uVar2 = *(uint *)((uint)(param_1 + 6) & 0xfffffffc);
  if ((uint)*(ushort *)((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 0x1f8) ==
      (int)*(char *)((*(uint *)(uRam020f824c & 0xfffffffc) >> (uRam020f824c & 3) * 8 |
                     *(uint *)(uRam020f824c & 0xfffffffc) << (uRam020f824c & 3) * -8 + 0x20) + 0x62)
     ) {
    func_020bb5cc();
  }
  uVar3 = (uint)(param_1 + 4) & 3;
  uVar2 = *(uint *)((uint)(param_1 + 4) & 0xfffffffc);
  iVar6 = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) * 0x1c +
          (*(uint *)(uRam020f8250 & 0xfffffffc) >> (uRam020f8250 & 3) * 8 |
          *(uint *)(uRam020f8250 & 0xfffffffc) << (uRam020f8250 & 3) * -8 + 0x20);
  uVar3 = iVar6 + 8;
  uVar2 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  iVar5 = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) * 0x44 +
          (*(uint *)(uRam020f8254 & 0xfffffffc) >> (uRam020f8254 & 3) * 8 |
          *(uint *)(uRam020f8254 & 0xfffffffc) << (uRam020f8254 & 3) * -8 + 0x20);
  uVar3 = iVar5 + 0x1c;
  uVar2 = uVar3 & 3;
  uVar4 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = iVar6 + 0xc;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  *(uint *)(iVar5 + 0x1c) =
       (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) -
       (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  *param_1 = 0;
  param_1[1] = 0;
  param_1[3] = 0x13;
  param_1[4] = 0x13;
  param_1[5] = 0x13;
  param_1[8] = 0;
  return;
}

