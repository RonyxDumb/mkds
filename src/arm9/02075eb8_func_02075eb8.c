/* Decompiled C draft; module arm9; ROM address 02075eb8. No matching claim. */
#include "types.h"
#include "deps/02075eb8_func_02075eb8.h"

void func_02075eb8(void)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar9;
  
  uVar12 = *(uint *)(uRam02075fcc & 0xfffffffc) >> (uRam02075fcc & 3) * 8 |
           *(uint *)(uRam02075fcc & 0xfffffffc) << (uRam02075fcc & 3) * -8 + 0x20;
  uVar10 = (*(uint *)(uRam02075fc8 & 0xfffffffc) >> (uRam02075fc8 & 3) * 8 |
           *(uint *)(uRam02075fc8 & 0xfffffffc) << (uRam02075fc8 & 3) * -8 + 0x20) + 0xcc;
  uVar2 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  uVar10 = uVar10 >> uVar2 * 8 | uVar10 << uVar2 * -8 + 0x20;
  if (uVar10 != 0) {
    *(undefined4 *)(uVar12 + 0x228) = 1;
    *(uint *)(uVar12 + 0x218) = uVar10;
    *(undefined4 *)(uVar12 + 0x240) = 0;
    *(undefined2 *)(uVar12 + 0x68) = *(undefined2 *)(uVar10 + 0x32);
    *(undefined2 *)(uVar12 + 0x6a) = *(undefined2 *)(uVar10 + 0x34);
    *(undefined1 *)(uVar12 + 0x130) = *(undefined1 *)(uVar10 + 0x4b);
    if ((*(short *)(uVar10 + 0x40) != -1) &&
       (StructVC_SomeFnLinkedRouteRelated(uVar12 + 0x194,uVar10),
       uVar2 = (*(uint *)(uRam02075fd0 & 0xfffffffc) >> (uRam02075fd0 & 3) * 8 |
               *(uint *)(uRam02075fd0 & 0xfffffffc) << (uRam02075fd0 & 3) * -8 + 0x20) + 8,
       uVar4 = uVar2 & 3, uVar2 = *(uint *)(uVar2 & 0xfffffffc),
       (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) == 2)) {
      func_0207bd6c(uVar12 + 0x1d0,uVar10);
    }
    iVar3 = GetDriverEntry((int)*(char *)((*(uint *)(uRam02075fd0 & 0xfffffffc) >>
                                           (uRam02075fd0 & 3) * 8 |
                                          *(uint *)(uRam02075fd0 & 0xfffffffc) <<
                                          (uRam02075fd0 & 3) * -8 + 0x20) + 0x62));
    iVar3 = IsRacerFinishedRace(*(undefined2 *)(iVar3 + 0x74));
    if (iVar3 != 0) {
      uVar13 = *(uint *)(uRam02075fd4 & 0xfffffffc) >> (uRam02075fd4 & 3) * 8 |
               *(uint *)(uRam02075fd4 & 0xfffffffc) << (uRam02075fd4 & 3) * -8 + 0x20;
      iVar3 = uVar13 + iRam02075fd8;
      uVar10 = iVar3 + 8U & 3;
      uVar2 = *(uint *)(iVar3 + 8U & 0xfffffffc);
      uVar7 = uVar2 >> uVar10 * 8 | uVar2 << uVar10 * -8 + 0x20;
      uVar10 = uVar13 + 0x498 & 3;
      uVar2 = *(uint *)(uVar13 + 0x498 & 0xfffffffc);
      uVar6 = uVar2 >> uVar10 * 8 | uVar2 << uVar10 * -8 + 0x20;
      uVar10 = iVar3 + 4U & 3;
      uVar4 = *(uint *)(iVar3 + 4U & 0xfffffffc);
      lVar1 = (ulonglong)uVar6 * (ulonglong)uVar7;
      uVar11 = (uint)lVar1;
      uVar2 = iVar3 + 0xcU & 3;
      uVar5 = *(uint *)(iVar3 + 0xcU & 0xfffffffc);
      uVar12 = iVar3 + 0x10U & 3;
      uVar8 = *(uint *)(iVar3 + 0x10U & 0xfffffffc);
      uVar9 = uVar8 >> uVar12 * 8 | uVar8 << uVar12 * -8 + 0x20;
      uVar12 = iVar3 + 0x14U & 3;
      uVar8 = *(uint *)(iVar3 + 0x14U & 0xfffffffc);
      *(uint *)(uVar13 + 0x498) = uVar9 + uVar11;
      *(uint *)(iVar3 + 4) =
           (uVar8 >> uVar12 * 8 | uVar8 << uVar12 * -8 + 0x20) +
           (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) * uVar6 +
           uVar7 * (uVar4 >> uVar10 * 8 | uVar4 << uVar10 * -8 + 0x20) +
           (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar9,uVar11);
    }
    *puRam02075fdc = 1;
    return;
  }
  return;
}

