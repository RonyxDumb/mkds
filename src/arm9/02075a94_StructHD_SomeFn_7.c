/* Decompiled C draft; module arm9; ROM address 02075a94. No matching claim. */
#include "types.h"
#include "deps/02075a94_StructHD_SomeFn_7.h"

bool StructHD_SomeFn_7(int param_1)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar14;
  undefined1 auStack_20 [16];
  uint uVar13;
  
  *(undefined4 *)(param_1 + 0x134) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(param_1 + 0x138) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(param_1 + 0x13c) = *(undefined4 *)(param_1 + 0x2c);
  uVar4 = uRam02075cd8 & 3;
  uVar3 = *(uint *)(uRam02075cd8 & 0xfffffffc);
  *puRam02075cdc = 1;
  uVar4 = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0xc;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if ((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) == 6) {
    StructHD_SomeFn_13(param_1);
    return true;
  }
  uVar4 = param_1 + 0x230U & 3;
  uVar3 = *(uint *)(param_1 + 0x230U & 0xfffffffc);
  if ((uVar3 >> uVar4 * 8 == 0 && uVar3 << uVar4 * -8 + 0x20 == 0) &&
     (uVar4 = param_1 + 0x234U & 3, uVar3 = *(uint *)(param_1 + 0x234U & 0xfffffffc),
     uVar3 >> uVar4 * 8 == 0 && uVar3 << uVar4 * -8 + 0x20 == 0)) {
    *(undefined4 *)(param_1 + 0x134) = *(undefined4 *)(param_1 + 0x24);
    *(undefined4 *)(param_1 + 0x138) = *(undefined4 *)(param_1 + 0x28);
    *(undefined4 *)(param_1 + 0x13c) = *(undefined4 *)(param_1 + 0x2c);
    uVar4 = param_1 + 0x238U & 3;
    uVar3 = *(uint *)(param_1 + 0x238U & 0xfffffffc);
    if (uVar3 >> uVar4 * 8 != 0 || uVar3 << uVar4 * -8 + 0x20 != 0) {
      StructHD_SomeFn_12(param_1);
      return true;
    }
    GetDriverMaybeSfxPosition((undefined4 *)(void *)(auStack_20),*(undefined2 *)(param_1 + 0x210));
    uVar3 = func_020411e4((undefined4)(uintptr_t)(auStack_20));
    uVar4 = param_1 + 0x228U & 3;
    uVar5 = *(uint *)(param_1 + 0x228U & 0xfffffffc);
    if (uVar5 >> uVar4 * 8 != 0 || uVar5 << uVar4 * -8 + 0x20 != 0) {
      uVar4 = (*(uint *)(uRam02075cd8 & 0xfffffffc) >> (uRam02075cd8 & 3) * 8 |
              *(uint *)(uRam02075cd8 & 0xfffffffc) << (uRam02075cd8 & 3) * -8 + 0x20) + 8;
      uVar5 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      if ((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) == 2) {
        StructHD_SomeFn_1(param_1);
        return true;
      }
      *(short *)(param_1 + 0x22c) = *(short *)(param_1 + 0x22c) + 1;
      if (299 < *(ushort *)(param_1 + 0x22c)) {
        *(undefined4 *)(param_1 + 0x228) = 0;
      }
    }
    if (uVar3 != 0xffffffff) {
      uVar5 = param_1 + 0x214U & 3;
      uVar8 = *(uint *)(param_1 + 0x214U & 0xfffffffc);
      uVar4 = (*(uint *)(uRam02075ce0 & 0xfffffffc) >> (uRam02075ce0 & 3) * 8 |
              *(uint *)(uRam02075ce0 & 0xfffffffc) << (uRam02075ce0 & 3) * -8 + 0x20) + 0x7c;
      uVar1 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      iVar10 = (uVar3 & 0xffff) * 0x4c + (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
      if ((uVar3 != (uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20)) &&
         (*(uint *)(param_1 + 0x214) = uVar3, uVar4 = param_1 + 0x228U & 3,
         uVar5 = *(uint *)(param_1 + 0x228U & 0xfffffffc),
         uVar5 >> uVar4 * 8 == 0 && uVar5 << uVar4 * -8 + 0x20 == 0)) {
        *(int *)(param_1 + 0x218) = iVar10;
        *(undefined4 *)(param_1 + 0x240) = 0;
        *(undefined2 *)(param_1 + 0x68) = *(undefined2 *)(iVar10 + 0x32);
        *(undefined2 *)(param_1 + 0x6a) = *(undefined2 *)(iVar10 + 0x34);
        *(undefined1 *)(param_1 + 0x130) = *(undefined1 *)(iVar10 + 0x4b);
        if ((*(short *)(iVar10 + 0x40) != -1) &&
           (StructVC_SomeFnLinkedRouteRelated(param_1 + 0x194,iVar10),
           uVar4 = (*(uint *)(uRam02075cd8 & 0xfffffffc) >> (uRam02075cd8 & 3) * 8 |
                   *(uint *)(uRam02075cd8 & 0xfffffffc) << (uRam02075cd8 & 3) * -8 + 0x20) + 8,
           uVar5 = uVar4 & 3, uVar4 = *(uint *)(uVar4 & 0xfffffffc),
           (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) == 2)) {
          func_0207bd6c(param_1 + 0x1d0,iVar10);
        }
        iVar10 = GetDriverEntry((int)*(char *)((*(uint *)(uRam02075cd8 & 0xfffffffc) >>
                                                (uRam02075cd8 & 3) * 8 |
                                               *(uint *)(uRam02075cd8 & 0xfffffffc) <<
                                               (uRam02075cd8 & 3) * -8 + 0x20) + 0x62));
        iVar10 = IsRacerFinishedRace(*(undefined2 *)(iVar10 + 0x74));
        if (iVar10 != 0) {
          uVar8 = *(uint *)(uRam02075ce4 & 0xfffffffc) >> (uRam02075ce4 & 3) * 8 |
                  *(uint *)(uRam02075ce4 & 0xfffffffc) << (uRam02075ce4 & 3) * -8 + 0x20;
          iVar10 = uVar8 + iRam02075ce8;
          uVar4 = iVar10 + 8U & 3;
          uVar5 = *(uint *)(iVar10 + 8U & 0xfffffffc);
          uVar11 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
          uVar4 = uVar8 + 0x498 & 3;
          uVar5 = *(uint *)(uVar8 + 0x498 & 0xfffffffc);
          uVar9 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
          uVar4 = iVar10 + 4U & 3;
          uVar6 = *(uint *)(iVar10 + 4U & 0xfffffffc);
          lVar2 = (ulonglong)uVar9 * (ulonglong)uVar11;
          uVar14 = (uint)lVar2;
          uVar5 = iVar10 + 0xcU & 3;
          uVar7 = *(uint *)(iVar10 + 0xcU & 0xfffffffc);
          uVar1 = iVar10 + 0x10U & 3;
          uVar12 = *(uint *)(iVar10 + 0x10U & 0xfffffffc);
          uVar13 = uVar12 >> uVar1 * 8 | uVar12 << uVar1 * -8 + 0x20;
          uVar1 = iVar10 + 0x14U & 3;
          uVar12 = *(uint *)(iVar10 + 0x14U & 0xfffffffc);
          *(uint *)(uVar8 + 0x498) = uVar13 + uVar14;
          *(uint *)(iVar10 + 4) =
               (uVar12 >> uVar1 * 8 | uVar12 << uVar1 * -8 + 0x20) +
               (uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) * uVar9 +
               uVar11 * (uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) +
               (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar13,uVar14);
        }
        *puRam02075cec = 1;
      }
      StructHD_SomeFn_1(param_1);
    }
    return uVar3 != 0xffffffff;
  }
  return false;
}

