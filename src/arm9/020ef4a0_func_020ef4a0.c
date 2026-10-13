/* Decompiled C draft; module arm9; ROM address 020ef4a0. No matching claim. */
#include "types.h"
#include "deps/020ef4a0_func_020ef4a0.h"

void func_020ef4a0(uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar1 = param_1 + 0x14 & 3;
  uVar8 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
  uVar9 = uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0xc & 3;
  uVar8 = *(uint *)(param_1 + 0xc & 0xfffffffc);
  uVar7 = uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20;
  uVar1 = uVar9 + 0x70 & 3;
  uVar6 = *(uint *)(uVar9 + 0x70 & 0xfffffffc);
  func_020ef65c(param_1,uVar9 + 0x50,param_1 + 0xa8);
  uVar8 = uVar9 + 0x11c & 3;
  uVar2 = *(uint *)(uVar9 + 0x11c & 0xfffffffc);
  if ((0xc < (int)(uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20)) &&
     (uVar8 = uVar9 + 0x44 & 3, uVar2 = *(uint *)(uVar9 + 0x44 & 0xfffffffc),
     uVar8 = (uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20) * 0xa8 +
             (*(uint *)(uRam020ef63c & 0xfffffffc) >> (uRam020ef63c & 3) * 8 |
             *(uint *)(uRam020ef63c & 0xfffffffc) << (uRam020ef63c & 3) * -8 + 0x20) + 0x70,
     uVar2 = uVar8 & 3, uVar8 = *(uint *)(uVar8 & 0xfffffffc),
     iVar3 = func_020fa0b8(uVar9,uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20,uRam020ef640),
     iVar3 != 0)) {
    uVar8 = param_1 + 0x84 & 3;
    uVar4 = *(uint *)(param_1 + 0x84 & 0xfffffffc);
    uVar2 = param_1 + 0x88 & 3;
    uVar5 = *(uint *)(param_1 + 0x88 & 0xfffffffc);
    func_020f9f08(uVar9,uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20,
                  uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20);
  }
  if ((((int)(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) < iRam020ef644) &&
      (uVar1 = uVar9 + 0x70 & 3, uVar8 = *(uint *)(uVar9 + 0x70 & 0xfffffffc),
      iRam020ef644 <= (int)(uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20))) &&
     ((uint)*(ushort *)(param_1 + 0x28) ==
      (int)*(char *)((*(uint *)(uRam020ef648 & 0xfffffffc) >> (uRam020ef648 & 3) * 8 |
                     *(uint *)(uRam020ef648 & 0xfffffffc) << (uRam020ef648 & 3) * -8 + 0x20) + 0x62)
     )) {
    uVar1 = uVar7 + 0x1fc & 3;
    uVar8 = *(uint *)(uVar7 + 0x1fc & 0xfffffffc);
    func_020719bc(uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20,0xe7);
  }
  if ((((*(ushort *)(uVar7 + 0x1ec) & 0x284) == 0x284) &&
      ((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
       *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) != 0xf)) &&
     (uVar1 = param_1 + 0x24 & 3, uVar8 = *(uint *)(param_1 + 0x24 & 0xfffffffc),
     uVar8 >> uVar1 * 8 == 0 && uVar8 << uVar1 * -8 + 0x20 == 0)) {
    func_020efa60(param_1,1);
  }
  uVar1 = param_1 + 0x170 & 3;
  uVar8 = *(uint *)(param_1 + 0x170 & 0xfffffffc);
  if (uVar8 >> uVar1 * 8 != 0 || uVar8 << uVar1 * -8 + 0x20 != 0) {
    *(undefined4 *)(uVar7 + 0x14) = 0x13;
    uVar1 = uVar7 + 0x200 & 3;
    uVar8 = *(uint *)(uVar7 + 0x200 & 0xfffffffc);
    if ((*(ushort *)(iRam020ef64c + (uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20) * 0x5c) & 0x40
        ) != 0) {
      *(ushort *)(uVar7 + 0x1ec) = *(ushort *)(uVar7 + 0x1ec) | *puRam020ef650;
    }
    uVar1 = uVar7 + 0x200 & 3;
    uVar8 = *(uint *)(uVar7 + 0x200 & 0xfffffffc);
    if ((*(ushort *)(iRam020ef64c + (uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20) * 0x5c) & 0x80
        ) != 0) {
      *(ushort *)(uVar7 + 0x1ec) = *(ushort *)(uVar7 + 0x1ec) | *puRam020ef654;
    }
    func_020efa60(param_1,1);
  }
  *(ushort *)(uVar7 + 0x1ec) = *(ushort *)(uVar7 + 0x1ec) | *puRam020ef658;
  return;
}

