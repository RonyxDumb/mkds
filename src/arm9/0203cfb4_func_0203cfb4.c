/* Decompiled C draft; module arm9; ROM address 0203cfb4. No matching claim. */
#include "types.h"
#include "deps/0203cfb4_func_0203cfb4.h"

bool func_0203cfb4(void)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  
  uVar8 = *(uint *)(uRam0203d070 & 0xfffffffc) >> (uRam0203d070 & 3) * 8 |
          *(uint *)(uRam0203d070 & 0xfffffffc) << (uRam0203d070 & 3) * -8 + 0x20;
  uVar4 = uVar8 + 0x4cc;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  bVar2 = uVar4 >> uVar5 * 8 == 0;
  bVar3 = uVar4 << uVar5 * -8 + 0x20 == 0;
  bVar9 = bVar2 && bVar3;
  if (!bVar2 || !bVar3) {
    return bVar9;
  }
  uVar7 = *(uint *)(uRam0203d074 & 0xfffffffc) >> (uRam0203d074 & 3) * 8 |
          *(uint *)(uRam0203d074 & 0xfffffffc) << (uRam0203d074 & 3) * -8 + 0x20;
  uVar4 = uVar7 + 8 & 3;
  uVar5 = *(uint *)(uVar7 + 8 & 0xfffffffc);
  if ((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) != 2) {
    return false;
  }
  iVar6 = 0;
  uVar4 = 0;
  if (*(char *)(uVar7 + 0x3d0) == '\0') {
    return bVar9;
  }
  while ((uVar5 = uVar4 * 0x8c + uVar8 + 0x14, uVar1 = uVar5 & 3,
         uVar5 = *(uint *)(uVar5 & 0xfffffffc),
         uVar5 >> uVar1 * 8 != 0 || uVar5 << uVar1 * -8 + 0x20 != 0 ||
         (iVar6 = iVar6 + 1, iVar6 < 1))) {
    uVar4 = uVar4 + 1 & 0xffff;
    if (*(byte *)(uVar7 + 0x3d0) <= uVar4) {
      return bVar9;
    }
  }
  return false;
}

