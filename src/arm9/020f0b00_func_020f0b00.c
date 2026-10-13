/* Decompiled C draft; module arm9; ROM address 020f0b00. No matching claim. */
#include "types.h"
#include "deps/020f0b00_func_020f0b00.h"

void func_020f0b00(uint param_1,int param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  ushort *puVar2;
  ushort uVar3;
  uint uVar4;
  code *pcVar5;
  uint uVar6;
  uint uVar8;
  uint uVar10;
  uint uVar12;
  uint uVar7;
  uint uVar9;
  uint uVar11;
  
  uVar10 = param_1 + 0x10 & 3;
  uVar8 = *(uint *)(param_1 + 0x10 & 0xfffffffc);
  uVar9 = uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20;
  *(uint *)(param_1 + 0x10) = uVar9 + 1;
  uVar10 = param_1 + 4 & 3;
  uVar8 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar10 = (uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20) + uVar9 * 4;
  uVar8 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  uVar11 = uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20;
  func_020f9054(uVar11,*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                       *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20);
  uVar10 = param_1 + 0x1c & 3;
  uVar8 = *(uint *)(param_1 + 0x1c & 0xfffffffc);
  *(uint *)(param_1 + 0x1c) = (uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20) + 1;
  uVar8 = uRam020f0cf8;
  uVar10 = param_1 + 0x14 & 3;
  uVar9 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
  uVar9 = uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20;
  uVar10 = param_1 + 0x10 & 3;
  uVar6 = *(uint *)(param_1 + 0x10 & 0xfffffffc);
  uVar7 = uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20;
  uVar10 = param_1 + 4 & 3;
  uVar6 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar6 = uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20;
  uVar10 = uVar9;
  while ((uVar12 = uVar7, (int)uVar10 < (int)uVar7 &&
         (uVar12 = uVar6 + uVar10 * 4, uVar1 = uVar12 & 3, uVar4 = *(uint *)(uVar12 & 0xfffffffc),
         uVar12 = uVar10, (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) != uVar11))) {
    uVar10 = uVar10 + 1;
  }
  if ((int)uVar9 < (int)uVar12) {
    uVar10 = uVar6 + uVar9 * 4;
    uVar9 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    *(uint *)(uVar6 + uVar12 * 4) = uVar10 >> uVar9 * 8 | uVar10 << uVar9 * -8 + 0x20;
    uVar10 = param_1 + 0x14 & 3;
    uVar9 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
    *(uint *)(uVar6 + (uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20) * 4) = uVar11;
  }
  uVar10 = param_1 + 0x14 & 3;
  uVar9 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
  *(uint *)(param_1 + 0x14) = (uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20) + 1;
  uVar10 = uVar11 + 0x74 & 3;
  uVar9 = *(uint *)(uVar11 + 0x74 & 0xfffffffc);
  *(uint *)(uVar11 + 0x74) = uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20 | 0x2000;
  uVar10 = uVar8 & 3;
  uVar8 = *(uint *)(uVar8 & 0xfffffffc);
  uVar10 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
           *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) * 0xa8 +
           (uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20) + 0x6c;
  uVar8 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  if (uVar10 >> uVar8 * 8 != 0 || uVar10 << uVar8 * -8 + 0x20 != 0) {
    func_020f9ca8(uVar11);
  }
  *(undefined4 *)(uVar11 + 0x11c) = 0;
  uVar10 = uVar11 + 0x44 & 3;
  uVar8 = *(uint *)(uVar11 + 0x44 & 0xfffffffc);
  uVar10 = (uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20) * 0xa8 +
           (*(uint *)(uRam020f0cf8 & 0xfffffffc) >> (uRam020f0cf8 & 3) * 8 |
           *(uint *)(uRam020f0cf8 & 0xfffffffc) << (uRam020f0cf8 & 3) * -8 + 0x20) + 0x1c;
  uVar8 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  pcVar5 = (code *)(uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20);
  if (pcVar5 != (code *)0x0) {
    (*pcVar5)(uVar11);
  }
  pcVar5 = pcRam020f0cfc;
  if (param_4 == 0) {
    uVar10 = uVar11 + 0x44 & 3;
    uVar8 = *(uint *)(uVar11 + 0x44 & 0xfffffffc);
    uVar10 = (uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20) * 0xa8 +
             (*(uint *)(uRam020f0cf8 & 0xfffffffc) >> (uRam020f0cf8 & 3) * 8 |
             *(uint *)(uRam020f0cf8 & 0xfffffffc) << (uRam020f0cf8 & 3) * -8 + 0x20) + 0x50;
    uVar8 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    pcVar5 = (code *)(uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20);
  }
  (*pcVar5)(uVar11);
  uVar10 = uVar11 + 0x74 & 3;
  uVar8 = *(uint *)(uVar11 + 0x74 & 0xfffffffc);
  *(uint *)(uVar11 + 0x74) = uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20 | 0x20000000;
  if (param_4 == 0) {
    uVar3 = *(ushort *)(uVar11 + 0x78);
    if ((uVar3 & 0x1000) == 0) {
      if ((uVar3 & 0x8000) == 0) {
        uVar3 = uVar3 & 0xff;
      }
      else {
        uVar3 = 8;
      }
      if (uVar3 != 8) {
        GetDriverEntry();
        DriverContext_SomeFn_0();
      }
    }
  }
  else {
    if ((*(ushort *)(uVar11 + 0x78) & 0x800) != 0) {
      CARD_func_0054__mkds_f70f0(uVar11);
    }
    if ((*(ushort *)(uVar11 + 0x78) & 0x400) != 0) {
      CARD_func_0054__mkds_f705c(uVar11);
    }
    if ((*(ushort *)(uVar11 + 0x78) & 0x200) != 0) {
      func_020f7600(uVar11);
    }
    if ((*(ushort *)(uVar11 + 0x78) & 0x100) != 0) {
      func_020f73fc(uVar11);
    }
  }
  puVar2 = puRam020f0d00;
  if (0 < param_2) {
    *(short *)(uVar11 + 0x7a) = (short)param_2;
    *(ushort *)(uVar11 + 0x7a) = *(ushort *)(uVar11 + 0x7a) | *puVar2;
    return;
  }
  return;
}

