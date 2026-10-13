/* Decompiled C draft; module arm9; ROM address 020faa78. No matching claim. */
#include "types.h"
#include "deps/020faa78_func_020faa78.h"

undefined4 func_020faa78(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar9;
  int iVar10;
  uint uVar8;
  
  uVar1 = uRam020fab30;
  iVar9 = param_1 * 0x1c +
          (*(uint *)(uRam020fab28 & 0xfffffffc) >> (uRam020fab28 & 3) * 8 |
          *(uint *)(uRam020fab28 & 0xfffffffc) << (uRam020fab28 & 3) * -8 + 0x20);
  uVar7 = iVar9 + 8;
  uVar4 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar8 = uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20;
  iVar10 = uVar8 * 0x44 +
           (*(uint *)(uRam020fab2c & 0xfffffffc) >> (uRam020fab2c & 3) * 8 |
           *(uint *)(uRam020fab2c & 0xfffffffc) << (uRam020fab2c & 3) * -8 + 0x20);
  uVar4 = iVar10 + 0xcU & 3;
  uVar6 = *(uint *)(iVar10 + 0xcU & 0xfffffffc);
  uVar3 = iVar10 + 0x1cU & 3;
  uVar2 = *(uint *)(iVar10 + 0x1cU & 0xfffffffc);
  uVar7 = iVar9 + 0xc;
  uVar5 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar7 = uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20;
  if ((int)((uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) -
           (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20)) < (int)uVar7) {
    do {
      uVar4 = uVar1 & 3;
      uVar3 = *(uint *)(uVar1 & 0xfffffffc);
      uVar4 = uVar8 * 0xa8 + (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 4;
      uVar3 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      if ((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) == 1) {
        return 0;
      }
      iVar9 = func_020f03bc(iVar10);
      if (iVar9 == 0) {
        return 0;
      }
      uVar4 = iVar10 + 0xcU & 3;
      uVar2 = *(uint *)(iVar10 + 0xcU & 0xfffffffc);
      uVar3 = iVar10 + 0x1cU & 3;
      uVar5 = *(uint *)(iVar10 + 0x1cU & 0xfffffffc);
    } while ((int)((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) -
                  (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20)) < (int)uVar7);
  }
  return 1;
}

