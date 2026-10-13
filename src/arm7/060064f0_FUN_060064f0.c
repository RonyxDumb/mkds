/* Decompiled C draft; module arm7; ROM address 060064f0. No matching claim. */
#include "types.h"
#include "deps/060064f0_FUN_060064f0.h"

void FUN_060064f0(void)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar4;
  
  iVar2 = FUN_06000680();
  uVar5 = iVar2 + 0x154cU & 3;
  uVar3 = *(uint *)(iVar2 + 0x154cU & 0xfffffffc);
  uVar4 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
  uVar6 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
          *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
  uVar5 = uVar6 + 0xcc;
  uVar3 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  *(uint *)(uVar6 + 0xcc) = (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) << 6;
  iVar2 = DAT_060065f4;
  uVar1 = *DAT_060065e4;
  if (*DAT_060065e0 < *DAT_060065e0) {
    uVar1 = *DAT_060065e4;
  }
  uVar3 = DAT_060065ec &
          (DAT_060065f0 - (uint)*DAT_060065e8) * 0x7f +
          (CONCAT22(uVar1,*DAT_060065e0) & DAT_060065ec) * 2 >> 1;
  uVar7 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
          *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
  uVar5 = uVar7 + 0xcc & 3;
  uVar6 = *(uint *)(uVar7 + 0xcc & 0xfffffffc);
  if (uVar3 < (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20)) {
    *(undefined4 *)(uVar7 + 0xd4) = 0;
  }
  else {
    for (iVar8 = 1; iVar8 < 0x1e; iVar8 = iVar8 + 1) {
      uVar5 = uVar7 + 0xcc & 3;
      uVar6 = *(uint *)(uVar7 + 0xcc & 0xfffffffc);
      *(uint *)(uVar7 + 0xcc) = (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) + iVar2;
      uVar7 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
              *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
      uVar5 = uVar7 + 0xcc & 3;
      uVar6 = *(uint *)(uVar7 + 0xcc & 0xfffffffc);
      uVar5 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
      if (uVar3 < uVar5) {
        *(uint *)(uVar7 + 0xd4) = uVar5 - uVar3;
        uVar4 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
        uVar5 = uVar4 + 0xd4;
        uVar3 = uVar5 & 3;
        uVar5 = *(uint *)(uVar5 & 0xfffffffc);
        if ((uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) <= DAT_060065f8) {
          return;
        }
        *(undefined4 *)(uVar4 + 0xd4) = 0;
        return;
      }
    }
    *(undefined4 *)(uVar7 + 0xd4) = 0;
  }
  return;
}

