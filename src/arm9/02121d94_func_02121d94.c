/* Decompiled C draft; module arm9; ROM address 02121d94. No matching claim. */
#include "types.h"
#include "deps/02121d94_func_02121d94.h"

uint func_02121d94(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = GetGlobalCA_from_thumb();
  uVar3 = iVar1 + 0xd0U & 3;
  uVar2 = *(uint *)(iVar1 + 0xd0U & 0xfffffffc);
  if (uVar2 >> uVar3 * 8 == 0 && uVar2 << uVar3 * -8 + 0x20 == 0) {
    iVar1 = func_0x0219bb50();
    uVar3 = iVar1 * 0x44 +
            (*(uint *)(uRam02121de8 & 0xfffffffc) >> (uRam02121de8 & 3) * 8 |
            *(uint *)(uRam02121de8 & 0xfffffffc) << (uRam02121de8 & 3) * -8 + 0x20) + 0x1e48;
    uVar2 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    return uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  }
  iVar1 = GetGlobalCA_from_thumb();
  uVar3 = iVar1 + 0xd0U & 3;
  uVar2 = *(uint *)(iVar1 + 0xd0U & 0xfffffffc);
  return uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
}

