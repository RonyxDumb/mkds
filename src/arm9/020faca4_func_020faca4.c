/* Decompiled C draft; module arm9; ROM address 020faca4. No matching claim. */
#include "types.h"
#include "deps/020faca4_func_020faca4.h"

bool func_020faca4(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  
  if (param_1 == 0x13) {
    return false;
  }
  iVar8 = param_1 * 0x1c +
          (*(uint *)(uRam020facf8 & 0xfffffffc) >> (uRam020facf8 & 3) * 8 |
          *(uint *)(uRam020facf8 & 0xfffffffc) << (uRam020facf8 & 3) * -8 + 0x20);
  uVar7 = iVar8 + 8;
  uVar1 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  iVar4 = (uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20) * 0x44 +
          (*(uint *)(uRam020facfc & 0xfffffffc) >> (uRam020facfc & 3) * 8 |
          *(uint *)(uRam020facfc & 0xfffffffc) << (uRam020facfc & 3) * -8 + 0x20);
  uVar7 = iVar4 + 0xc;
  uVar1 = uVar7 & 3;
  uVar6 = *(uint *)(uVar7 & 0xfffffffc);
  uVar7 = iVar4 + 0x1c;
  uVar2 = uVar7 & 3;
  uVar5 = *(uint *)(uVar7 & 0xfffffffc);
  uVar7 = iVar8 + 0xc;
  uVar3 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  return (int)(uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) <=
         (int)((uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) -
              (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20));
}

