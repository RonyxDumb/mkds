/* Decompiled C draft; module arm9; ROM address 020f7600. No matching claim. */
#include "types.h"
#include "deps/020f7600_func_020f7600.h"

void func_020f7600(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 + 0x74U & 3;
  uVar1 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0x180000) != 0) {
    return;
  }
  uVar2 = param_1 + 0x44U & 3;
  uVar1 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  uVar2 = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) * 0xa8 +
          (*(uint *)(uRam020f764c & 0xfffffffc) >> (uRam020f764c & 3) * 8 |
          *(uint *)(uRam020f764c & 0xfffffffc) << (uRam020f764c & 3) * -8 + 0x20) + 0x40;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 == 0 && uVar2 << uVar1 * -8 + 0x20 == 0) {
    *(undefined4 *)(param_1 + 0x120) = uRam020f7650;
  }
  uVar2 = param_1 + 0x74U & 3;
  uVar1 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  *(uint *)(param_1 + 0x74) = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20 | uRam020f7654;
  return;
}

