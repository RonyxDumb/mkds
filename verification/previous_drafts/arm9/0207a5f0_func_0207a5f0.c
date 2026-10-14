/* Decompiled C draft; module arm9; ROM address 0207a5f0. No matching claim. */
#include "types.h"
#include "deps/0207a5f0_func_0207a5f0.h"

void func_0207a5f0(undefined4 param_1)

{
  ushort *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar6;
  int iVar7;
  uint uVar5;
  
  iVar2 = iRam0207a688;
  puVar1 = puRam0207a680;
  uVar6 = *(uint *)(uRam0207a684 & 0xfffffffc) >> (uRam0207a684 & 3) * 8 |
          *(uint *)(uRam0207a684 & 0xfffffffc) << (uRam0207a684 & 3) * -8 + 0x20;
  iVar7 = 0;
  if (*puRam0207a680 == 0) {
    return;
  }
  do {
    uVar3 = uVar6 + 0x590 & 3;
    uVar4 = *(uint *)(uVar6 + 0x590 & 0xfffffffc);
    uVar5 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
    uVar3 = uVar5 + 0x14 & 3;
    uVar4 = *(uint *)(uVar5 + 0x14 & 0xfffffffc);
    uVar3 = (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) + 4;
    uVar4 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    Maybe_helper_013044(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20,param_1);
    uVar3 = uVar5 + 0x10 & 3;
    uVar4 = *(uint *)(uVar5 + 0x10 & 0xfffffffc);
    uVar3 = (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) + 4;
    uVar4 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    Maybe_helper_013044(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20,param_1);
    uVar3 = uVar5 + 0x18 & 3;
    uVar4 = *(uint *)(uVar5 + 0x18 & 0xfffffffc);
    uVar3 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
    if (uVar3 != 0) {
      uVar3 = uVar3 + 4;
      uVar4 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      Maybe_helper_013044(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20,param_1);
    }
    iVar7 = iVar7 + 1;
    uVar6 = uVar6 + iVar2;
  } while (iVar7 < (int)(uint)*puVar1);
  return;
}

