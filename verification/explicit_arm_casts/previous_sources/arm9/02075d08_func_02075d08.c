/* Decompiled C draft; module arm9; ROM address 02075d08. No matching claim. */
#include "types.h"
#include "deps/02075d08_func_02075d08.h"

void func_02075d08(int param_1)

{
  short sVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  undefined1 *puVar15;
  undefined1 auStack_18 [12];
  uint uVar6;
  uint uVar10;
  
  uVar11 = *(uint *)(uRam02075ea0 & 0xfffffffc) >> (uRam02075ea0 & 3) * 8 |
           *(uint *)(uRam02075ea0 & 0xfffffffc) << (uRam02075ea0 & 3) * -8 + 0x20;
  uVar6 = uVar11 + 0x218 & 3;
  uVar5 = *(uint *)(uVar11 + 0x218 & 0xfffffffc);
  uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  if (uVar6 == 0) {
    return;
  }
  if (((param_1 != 0) && (sVar1 = *(short *)(uVar6 + 0x3e), sVar1 != 5)) && (sVar1 != 6)) {
    return;
  }
  puVar15 = auStack_18;
  if (param_1 == 0) {
    puVar15 = &stack0xfffffff4;
  }
  *(int *)(uVar11 + 0x230) = param_1;
  if (param_1 == 0) {
    return;
  }
  uVar6 = uVar11 + 0x228 & 3;
  uVar5 = *(uint *)(uVar11 + 0x228 & 0xfffffffc);
  if (uVar5 >> uVar6 * 8 == 0 && uVar5 << uVar6 * -8 + 0x20 == 0) {
    return;
  }
  *(undefined4 *)(uVar11 + 0x228) = 0;
  GetDriverMaybeSfxPosition(puVar15,*(undefined2 *)(uVar11 + 0x210));
  uVar6 = func_020411e4(puVar15);
  if (-1 < (int)uVar6) {
    uVar5 = (*(uint *)(uRam02075ea4 & 0xfffffffc) >> (uRam02075ea4 & 3) * 8 |
            *(uint *)(uRam02075ea4 & 0xfffffffc) << (uRam02075ea4 & 3) * -8 + 0x20) + 0x7c;
    uVar3 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    iVar13 = (uVar6 & 0xffff) * 0x4c + (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20);
    *(int *)(uVar11 + 0x218) = iVar13;
    *(undefined4 *)(uVar11 + 0x240) = 0;
    *(undefined2 *)(uVar11 + 0x68) = *(undefined2 *)(iVar13 + 0x32);
    *(undefined2 *)(uVar11 + 0x6a) = *(undefined2 *)(iVar13 + 0x34);
    *(undefined1 *)(uVar11 + 0x130) = *(undefined1 *)(iVar13 + 0x4b);
    if ((*(short *)(iVar13 + 0x40) != -1) &&
       (StructVC_SomeFnLinkedRouteRelated(uVar11 + 0x194,iVar13),
       uVar6 = (*(uint *)(uRam02075ea8 & 0xfffffffc) >> (uRam02075ea8 & 3) * 8 |
               *(uint *)(uRam02075ea8 & 0xfffffffc) << (uRam02075ea8 & 3) * -8 + 0x20) + 8,
       uVar5 = uVar6 & 3, uVar6 = *(uint *)(uVar6 & 0xfffffffc),
       (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) == 2)) {
      func_0207bd6c(uVar11 + 0x1d0,iVar13);
    }
    iVar13 = GetDriverEntry((int)*(char *)((*(uint *)(uRam02075ea8 & 0xfffffffc) >>
                                            (uRam02075ea8 & 3) * 8 |
                                           *(uint *)(uRam02075ea8 & 0xfffffffc) <<
                                           (uRam02075ea8 & 3) * -8 + 0x20) + 0x62));
    iVar13 = IsRacerFinishedRace(*(undefined2 *)(iVar13 + 0x74));
    if (iVar13 != 0) {
      uVar14 = *(uint *)(uRam02075eac & 0xfffffffc) >> (uRam02075eac & 3) * 8 |
               *(uint *)(uRam02075eac & 0xfffffffc) << (uRam02075eac & 3) * -8 + 0x20;
      iVar13 = uVar14 + iRam02075eb0;
      uVar6 = iVar13 + 8U & 3;
      uVar5 = *(uint *)(iVar13 + 8U & 0xfffffffc);
      uVar8 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
      uVar6 = uVar14 + 0x498 & 3;
      uVar5 = *(uint *)(uVar14 + 0x498 & 0xfffffffc);
      uVar7 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
      uVar6 = iVar13 + 4U & 3;
      uVar3 = *(uint *)(iVar13 + 4U & 0xfffffffc);
      lVar2 = (ulonglong)uVar7 * (ulonglong)uVar8;
      uVar12 = (uint)lVar2;
      uVar5 = iVar13 + 0xcU & 3;
      uVar4 = *(uint *)(iVar13 + 0xcU & 0xfffffffc);
      uVar11 = iVar13 + 0x10U & 3;
      uVar9 = *(uint *)(iVar13 + 0x10U & 0xfffffffc);
      uVar10 = uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20;
      uVar11 = iVar13 + 0x14U & 3;
      uVar9 = *(uint *)(iVar13 + 0x14U & 0xfffffffc);
      *(uint *)(uVar14 + 0x498) = uVar10 + uVar12;
      *(uint *)(iVar13 + 4) =
           (uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20) +
           (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) * uVar7 +
           uVar8 * (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) +
           (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar10,uVar12);
    }
    *puRam02075eb4 = 1;
    return;
  }
  return;
}

