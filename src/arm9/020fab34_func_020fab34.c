/* Decompiled C draft; module arm9; ROM address 020fab34. No matching claim. */
#include "types.h"
#include "deps/020fab34_func_020fab34.h"

undefined4 func_020fab34(undefined4 *param_1)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  
  uVar12 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
           *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  if (uVar12 != 0x13) {
    uVar4 = (*(uint *)(uRam020fac94 & 0xfffffffc) >> (uRam020fac94 & 3) * 8 |
            *(uint *)(uRam020fac94 & 0xfffffffc) << (uRam020fac94 & 3) * -8 + 0x20) + 8;
    uVar2 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    if ((uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) == 5) {
      iVar5 = (*(uint *)(uRam020fac98 & 0xfffffffc) >> (uRam020fac98 & 3) * 8 |
              *(uint *)(uRam020fac98 & 0xfffffffc) << (uRam020fac98 & 3) * -8 + 0x20) +
              uVar12 * 0x1c;
      uVar4 = iVar5 + 0xc;
      uVar2 = uVar4 & 3;
      uVar13 = *(uint *)(uVar4 & 0xfffffffc);
      uVar4 = iVar5 + 8;
      uVar3 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      iVar5 = func_020fa0e8(uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20,0);
      if (uVar12 == 0x13) {
        bVar1 = false;
      }
      else {
        iVar11 = (*(uint *)(uRam020fac98 & 0xfffffffc) >> (uRam020fac98 & 3) * 8 |
                 *(uint *)(uRam020fac98 & 0xfffffffc) << (uRam020fac98 & 3) * -8 + 0x20) +
                 uVar12 * 0x1c;
        uVar12 = iVar11 + 8;
        uVar4 = uVar12 & 3;
        uVar12 = *(uint *)(uVar12 & 0xfffffffc);
        iVar7 = (uVar12 >> uVar4 * 8 | uVar12 << uVar4 * -8 + 0x20) * 0x44 +
                (*(uint *)(uRam020fac9c & 0xfffffffc) >> (uRam020fac9c & 3) * 8 |
                *(uint *)(uRam020fac9c & 0xfffffffc) << (uRam020fac9c & 3) * -8 + 0x20);
        uVar12 = iVar7 + 0xc;
        uVar4 = uVar12 & 3;
        uVar10 = *(uint *)(uVar12 & 0xfffffffc);
        uVar12 = iVar7 + 0x1c;
        uVar3 = uVar12 & 3;
        uVar8 = *(uint *)(uVar12 & 0xfffffffc);
        uVar12 = iVar11 + 0xc;
        uVar9 = uVar12 & 3;
        uVar12 = *(uint *)(uVar12 & 0xfffffffc);
        bVar1 = (int)(uVar12 >> uVar9 * 8 | uVar12 << uVar9 * -8 + 0x20) <=
                (int)((uVar10 >> uVar4 * 8 | uVar10 << uVar4 * -8 + 0x20) -
                     (uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20));
      }
      if ((bVar1) &&
         ((int)((uVar13 >> uVar2 * 8 | uVar13 << uVar2 * -8 + 0x20) * iVar5) <=
          (int)(uint)*(ushort *)
                      ((*(uint *)(uRam020faca0 & 0xfffffffc) >> (uRam020faca0 & 3) * 8 |
                       *(uint *)(uRam020faca0 & 0xfffffffc) << (uRam020faca0 & 3) * -8 + 0x20) +
                      0x724))) {
        return 0;
      }
    }
    else {
      if (uVar12 == 0x13) {
        bVar1 = false;
      }
      else {
        iVar7 = uVar12 * 0x1c +
                (*(uint *)(uRam020fac98 & 0xfffffffc) >> (uRam020fac98 & 3) * 8 |
                *(uint *)(uRam020fac98 & 0xfffffffc) << (uRam020fac98 & 3) * -8 + 0x20);
        uVar12 = iVar7 + 8;
        uVar4 = uVar12 & 3;
        uVar12 = *(uint *)(uVar12 & 0xfffffffc);
        iVar5 = (uVar12 >> uVar4 * 8 | uVar12 << uVar4 * -8 + 0x20) * 0x44 +
                (*(uint *)(uRam020fac9c & 0xfffffffc) >> (uRam020fac9c & 3) * 8 |
                *(uint *)(uRam020fac9c & 0xfffffffc) << (uRam020fac9c & 3) * -8 + 0x20);
        uVar12 = iVar5 + 0xc;
        uVar4 = uVar12 & 3;
        uVar9 = *(uint *)(uVar12 & 0xfffffffc);
        uVar12 = iVar5 + 0x1c;
        uVar2 = uVar12 & 3;
        uVar13 = *(uint *)(uVar12 & 0xfffffffc);
        uVar12 = iVar7 + 0xc;
        uVar3 = uVar12 & 3;
        uVar12 = *(uint *)(uVar12 & 0xfffffffc);
        bVar1 = (int)(uVar12 >> uVar3 * 8 | uVar12 << uVar3 * -8 + 0x20) <=
                (int)((uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20) -
                     (uVar13 >> uVar2 * 8 | uVar13 << uVar2 * -8 + 0x20));
      }
      if (bVar1) {
        return 0;
      }
    }
  }
  uVar12 = (*(uint *)(uRam020fac94 & 0xfffffffc) >> (uRam020fac94 & 3) * 8 |
           *(uint *)(uRam020fac94 & 0xfffffffc) << (uRam020fac94 & 3) * -8 + 0x20) + 8;
  uVar4 = uVar12 & 3;
  uVar12 = *(uint *)(uVar12 & 0xfffffffc);
  if ((uVar12 >> uVar4 * 8 | uVar12 << uVar4 * -8 + 0x20) == 5) {
    uVar6 = 4;
  }
  else {
    uVar6 = 2;
  }
  *param_1 = uVar6;
  return 1;
}

