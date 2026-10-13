/* Decompiled C draft; module arm9; ROM address 020e0448. No matching claim. */
#include "types.h"
#include "deps/020e0448_func_020e0448.h"

uint func_020e0448(uint param_1)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  short *psVar4;
  int iVar5;
  uint uVar6;
  uint uVar8;
  bool bVar10;
  uint uVar7;
  uint uVar9;
  
  psVar4 = (short *)(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                    *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20);
  uVar7 = (uint)(psVar4 + 0x9c) & 3;
  uVar6 = *(uint *)((uint)(psVar4 + 0x9c) & 0xfffffffc);
  uVar7 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
  if ((uVar7 != 0) && (*psVar4 == 0xcb)) {
    uVar7 = param_1 + 0xc & 3;
    uVar6 = *(uint *)(param_1 + 0xc & 0xfffffffc);
    uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    uVar7 = (uint)(psVar4 + 0xaa) & 3;
    uVar8 = *(uint *)((uint)(psVar4 + 0xaa) & 0xfffffffc);
    uVar9 = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    uVar7 = param_1 + 4 & 3;
    uVar8 = *(uint *)(param_1 + 4 & 0xfffffffc);
    uVar7 = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    lVar2 = (longlong)(int)uVar9 * (longlong)(int)uVar9;
    iVar3 = (int)((ulonglong)lVar2 >> 0x20);
    lVar1 = (longlong)(int)uVar7 * (longlong)(int)uVar7 +
            (longlong)(int)uVar6 * (longlong)(int)uVar6;
    iVar5 = (int)((ulonglong)lVar1 >> 0x20);
    bVar10 = (uint)lVar1 < (uint)lVar2;
    return (uint)((int)(iVar5 - (iVar3 + (uint)bVar10)) < 0 ==
                 (SBORROW4(iVar5,iVar3) != SBORROW4(iVar5 - iVar3,(uint)bVar10)));
  }
  return uVar7;
}

