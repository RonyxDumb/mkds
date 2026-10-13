/* Decompiled C draft; module arm9; ROM address 020eff40. No matching claim. */
#include "types.h"
#include "deps/020eff40_func_020eff40.h"

/* WARNING: Removing unreachable block (ram,0x020efff8) */

void func_020eff40(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int unaff_r4;
  bool bVar4;
  
  uVar2 = param_1 + 0x1fc & 3;
  uVar3 = *(uint *)(param_1 + 0x1fc & 0xfffffffc);
  uVar3 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  uVar2 = (*(uint *)(uRam020f0040 & 0xfffffffc) >> (uRam020f0040 & 3) * 8 |
          *(uint *)(uRam020f0040 & 0xfffffffc) << (uRam020f0040 & 3) * -8 + 0x20) + 8;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  bVar4 = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 5;
  if (bVar4) {
    unaff_r4 = 1;
  }
  uVar2 = uVar3 + 0x7c;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (!bVar4) {
    unaff_r4 = 0;
  }
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x400) != 0) {
    return;
  }
  uVar3 = uVar3 + 0x29c;
  uVar2 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if ((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) - 2 < 2) {
    return;
  }
  if ((unaff_r4 != 0) &&
     (uVar2 = param_1 + 0x14 & 3, uVar3 = *(uint *)(param_1 + 0x14 & 0xfffffffc),
     (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) != 0x13)) {
    return;
  }
  uVar2 = param_1 + 0x30 & 3;
  uVar3 = *(uint *)(param_1 + 0x30 & 0xfffffffc);
  if (((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) != 0x13) &&
     (uVar2 = param_1 + 0x50 & 3, uVar3 = *(uint *)(param_1 + 0x50 & 0xfffffffc),
     uVar3 >> uVar2 * 8 == 0 && uVar3 << uVar2 * -8 + 0x20 == 0)) {
    CARD_func_0052(param_1 + 0x30);
  }
  if (unaff_r4 != 0) {
    return;
  }
  if (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 != 0 ||
      *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20 != 0) {
    func_020f81c0((undefined4 *)(uintptr_t)(param_1));
  }
  uVar2 = param_1 + 0x58 & 3;
  uVar3 = *(uint *)(param_1 + 0x58 & 0xfffffffc);
  if ((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) != 0xf) {
    uVar2 = param_1 + 0x7c & 3;
    uVar3 = *(uint *)(param_1 + 0x7c & 0xfffffffc);
    if (uVar3 >> uVar2 * 8 != 0 || uVar3 << uVar2 * -8 + 0x20 != 0) {
      return;
    }
    func_020edad8(param_1 + 0x58);
    return;
  }
  return;
}

