/* Decompiled C draft; module arm9; ROM address 0212cad8. No matching claim. */
#include "types.h"
#include "deps/0212cad8_func_0212cad8.h"

void func_0212cad8(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = uRam0212cb74;
  if (*(uint *)(uRam0212cb74 & 0xfffffffc) >> (uRam0212cb74 & 3) * 8 != 0 ||
      *(uint *)(uRam0212cb74 & 0xfffffffc) << (uRam0212cb74 & 3) * -8 + 0x20 != 0) {
    *(undefined4 *)(uRam0212cb74 + 0x1c) = 0;
    uVar1 = uVar4 + 0xc & 3;
    uVar3 = *(uint *)(uVar4 + 0xc & 0xfffffffc);
    uVar2 = uVar4 + 0x14 & 3;
    uVar5 = *(uint *)(uVar4 + 0x14 & 0xfffffffc);
    MIi_CpuClear32(0,uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,
                   uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20);
    uVar1 = uVar4 + 0x10 & 3;
    uVar3 = *(uint *)(uVar4 + 0x10 & 0xfffffffc);
    uVar2 = uVar4 + 0x14 & 3;
    uVar5 = *(uint *)(uVar4 + 0x14 & 0xfffffffc);
    MIi_CpuClear32(0,uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,
                   uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20);
    uVar1 = uVar4 + 0xc & 3;
    uVar3 = *(uint *)(uVar4 + 0xc & 0xfffffffc);
    uVar2 = uVar4 + 0x14 & 3;
    uVar5 = *(uint *)(uVar4 + 0x14 & 0xfffffffc);
    Arm_FlushRange(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,
                   uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20);
    uVar1 = uVar4 + 0x10 & 3;
    uVar3 = *(uint *)(uVar4 + 0x10 & 0xfffffffc);
    uVar2 = uVar4 + 0x14 & 3;
    uVar5 = *(uint *)(uVar4 + 0x14 & 0xfffffffc);
    Arm_FlushRange(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,
                   uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20);
    uVar1 = uVar4 + 0x24 & 3;
    uVar3 = *(uint *)(uVar4 + 0x24 & 0xfffffffc);
    uVar2 = uVar4 + 0x28 & 3;
    uVar4 = *(uint *)(uVar4 + 0x28 & 0xfffffffc);
    SND_StartTimer(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,
                   uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20);
    return;
  }
  return;
}

