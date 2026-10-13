/* Decompiled C draft; module arm9; ROM address 020f65c4. No matching claim. */
#include "types.h"
#include "deps/020f65c4_func_020f65c4.h"

void func_020f65c4(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = uRam020f6624;
  uVar2 = param_1 + 0x74U & 3;
  uVar1 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  *(uint *)(param_1 + 0x74) = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0xffff7fff;
  uVar2 = param_1 + 0x74U & 3;
  uVar1 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  *(uint *)(param_1 + 0x74) = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20 | 0x4000;
  uVar2 = param_1 + 0x44U & 3;
  uVar4 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar2 = (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) * 0xa8 +
          (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0x44;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 == 0 && uVar2 << uVar1 * -8 + 0x20 == 0) &&
     (uVar2 = param_1 + 0x74U & 3, uVar1 = *(uint *)(param_1 + 0x74U & 0xfffffffc),
     ((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0x180000) == 0)) {
    *(undefined4 *)(param_1 + 0x120) = uRam020f6628;
  }
  *(undefined4 *)(param_1 + 0x124) = uRam020f662c;
  uVar2 = param_1 + 0x74U & 3;
  uVar1 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  *(uint *)(param_1 + 0x74) = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0xf8ffffff;
  return;
}

