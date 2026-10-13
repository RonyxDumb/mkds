/* Decompiled C draft; module arm9; ROM address 020612b0. No matching claim. */
#include "types.h"
#include "deps/020612b0_func_020612b0.h"

void func_020612b0(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar5 = uRam02061350;
  uVar7 = uRam0206134c;
  uVar6 = uRam02061348;
  uVar3 = *(uint *)(uRam02061348 & 0xfffffffc) >> (uRam02061348 & 3) * 8 |
          *(uint *)(uRam02061348 & 0xfffffffc) << (uRam02061348 & 3) * -8 + 0x20;
  *(undefined1 *)(uVar3 + 0x1f54) = *(undefined1 *)(uVar3 + 0x1f52);
  uVar2 = uRam0206134c;
  uVar3 = uVar6 & 3;
  uVar4 = *(uint *)(uVar6 & 0xfffffffc);
  uVar6 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar7 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
  uVar6 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar8 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
  uVar1 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar6 = uVar8 + 0x48;
  uVar7 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  uVar6 = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) +
          (*(byte *)((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) + 0x1f54) - 1 & 0xff);
  uVar7 = (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + 3;
  if (uVar7 < uVar6) {
    uVar6 = uVar7;
  }
  *(uint *)(uVar8 + 0x48) = uVar6;
  uVar6 = uVar2 & 3;
  uVar7 = *(uint *)(uVar2 & 0xfffffffc);
  uVar7 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
  uVar6 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  WriteSaveDataSection_Header_from_thumb(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20);
  uVar6 = (*(uint *)(uRam02061354 & 0xfffffffc) >> (uRam02061354 & 3) * 8 |
          *(uint *)(uRam02061354 & 0xfffffffc) << (uRam02061354 & 3) * -8 + 0x20) + 0xc;
  uVar7 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  if (uVar6 >> uVar7 * 8 != 0 || uVar6 << uVar7 * -8 + 0x20 != 0) {
    func_02145d38();
    return;
  }
  return;
}

