/* Decompiled C draft; module arm9; ROM address 020a0f0c. No matching claim. */
#include "types.h"
#include "deps/020a0f0c_func_020a0f0c.h"

int func_020a0f0c(void)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar9;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar8;
  uint uVar10;
  
  uVar13 = *(uint *)(uRam020a0fe0 & 0xfffffffc) >> (uRam020a0fe0 & 3) * 8 |
           *(uint *)(uRam020a0fe0 & 0xfffffffc) << (uRam020a0fe0 & 3) * -8 + 0x20;
  iVar2 = uVar13 + iRam020a0fe4;
  uVar11 = iVar2 + 8U & 3;
  uVar7 = *(uint *)(iVar2 + 8U & 0xfffffffc);
  uVar8 = uVar7 >> uVar11 * 8 | uVar7 << uVar11 * -8 + 0x20;
  uVar11 = uVar13 + 0x47c & 3;
  uVar7 = *(uint *)(uVar13 + 0x47c & 0xfffffffc);
  uVar6 = uVar7 >> uVar11 * 8 | uVar7 << uVar11 * -8 + 0x20;
  uVar11 = iVar2 + 4U & 3;
  uVar3 = *(uint *)(iVar2 + 4U & 0xfffffffc);
  lVar1 = (ulonglong)uVar6 * (ulonglong)uVar8;
  uVar12 = (uint)lVar1;
  uVar7 = iVar2 + 0xcU & 3;
  uVar4 = *(uint *)(iVar2 + 0xcU & 0xfffffffc);
  uVar5 = iVar2 + 0x10U & 3;
  uVar9 = *(uint *)(iVar2 + 0x10U & 0xfffffffc);
  uVar10 = uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20;
  uVar5 = iVar2 + 0x14U & 3;
  uVar9 = *(uint *)(iVar2 + 0x14U & 0xfffffffc);
  *(uint *)(uVar13 + 0x47c) = uVar10 + uVar12;
  *(uint *)(iVar2 + 4) =
       (uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20) +
       (uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) * uVar6 +
       uVar8 * (uVar3 >> uVar11 * 8 | uVar3 << uVar11 * -8 + 0x20) + (int)((ulonglong)lVar1 >> 0x20)
       + (uint)CARRY4(uVar10,uVar12);
  uVar7 = uRam020a0fe8;
  uVar11 = iVar2 + 4U & 3;
  uVar3 = *(uint *)(iVar2 + 4U & 0xfffffffc);
  uVar5 = *(uint *)(uRam020a0fe8 & 0xfffffffc) >> (uRam020a0fe8 & 3) * 8 |
          *(uint *)(uRam020a0fe8 & 0xfffffffc) << (uRam020a0fe8 & 3) * -8 + 0x20;
  uVar11 = (uint)*(ushort *)(uVar5 + 0x3b8) +
           (int)((ulonglong)(uVar3 >> uVar11 * 8 | uVar3 << uVar11 * -8 + 0x20) * 5 >> 0x20) + 1;
  if (*(ushort *)
       ((*(uint *)(uRam020a0fec & 0xfffffffc) >> (uRam020a0fec & 3) * 8 |
        *(uint *)(uRam020a0fec & 0xfffffffc) << (uRam020a0fec & 3) * -8 + 0x20) + 0x88) <= uVar11) {
    uVar11 = 0;
  }
  *(short *)(uVar5 + 0x3b8) = (short)uVar11;
  uVar5 = uVar7 & 3;
  uVar3 = *(uint *)(uVar7 & 0xfffffffc);
  uVar11 = (*(uint *)(uRam020a0fec & 0xfffffffc) >> (uRam020a0fec & 3) * 8 |
           *(uint *)(uRam020a0fec & 0xfffffffc) << (uRam020a0fec & 3) * -8 + 0x20) + 0x84;
  uVar7 = uVar11 & 3;
  uVar11 = *(uint *)(uVar11 & 0xfffffffc);
  return (uint)*(ushort *)((uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) + 0x3b8) * 0x18 +
         (uVar11 >> uVar7 * 8 | uVar11 << uVar7 * -8 + 0x20);
}

