/* Decompiled C draft; module arm9; ROM address 020a0318. No matching claim. */
#include "types.h"
#include "deps/020a0318_func_020a0318.h"

void func_020a0318(undefined4 param_1,int param_2)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar15;
  uint uVar16;
  bool bVar17;
  uint local_38 [4];
  uint auStack_28 [5];
  uint uVar6;
  uint uVar14;
  
  uVar6 = param_2 + 0xc0U & 3;
  uVar5 = *(uint *)(param_2 + 0xc0U & 0xfffffffc);
  uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  *(uint *)(param_2 + 0xc0) = uVar6 - 1;
  if ((int)uVar6 < 1) {
    *(undefined4 *)(param_2 + 0xc0) = 0xf;
    uVar6 = param_2 + 0xa8U & 3;
    uVar5 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
    uVar11 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    iVar8 = (int)uVar11 / 2;
    iVar2 = GetDriverEntry((short)*(char *)((*(uint *)(uRam020a065c & 0xfffffffc) >>
                                             (uRam020a065c & 3) * 8 |
                                            *(uint *)(uRam020a065c & 0xfffffffc) <<
                                            (uRam020a065c & 3) * -8 + 0x20) + 0x62));
    uVar6 = iVar2 + 0x88U & 3;
    uVar10 = *(uint *)(iVar2 + 0x88U & 0xfffffffc);
    uVar5 = param_2 + 0xb4U & 3;
    uVar7 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
    uVar9 = iVar2 + 0x80U & 3;
    uVar15 = *(uint *)(iVar2 + 0x80U & 0xfffffffc);
    iVar2 = (uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20) -
            (uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20);
    uVar6 = param_2 + 0xacU & 3;
    uVar5 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
    iVar3 = (uVar15 >> uVar9 * 8 | uVar15 << uVar9 * -8 + 0x20) -
            (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20);
    lVar1 = (longlong)iVar3 * (longlong)iVar3 + (longlong)iVar2 * (longlong)iVar2;
    uVar6 = (uint)lVar1;
    iVar2 = (int)((ulonglong)lVar1 >> 0x20);
    lVar1 = (longlong)iVar8 * (longlong)iVar8;
    iVar8 = (int)((ulonglong)lVar1 >> 0x20);
    bVar17 = uVar6 < (uint)lVar1;
    if ((int)(iVar2 - (iVar8 + (uint)bVar17)) < 0 ==
        (SBORROW4(iVar2,iVar8) != SBORROW4(iVar2 - iVar8,(uint)bVar17))) {
      iVar8 = uVar11 << 0xc;
      lVar1 = (longlong)iVar8 * (longlong)iVar8;
      iVar8 = (int)((ulonglong)lVar1 >> 0x20);
      bVar17 = uVar6 < (uint)lVar1;
      if ((int)(iVar2 - (iVar8 + (uint)bVar17)) < 0 ==
          (SBORROW4(iVar2,iVar8) != SBORROW4(iVar2 - iVar8,(uint)bVar17))) {
        uVar4 = 0;
      }
      else {
        uVar4 = 1;
      }
    }
    else {
      uVar4 = 2;
    }
    *(undefined4 *)(param_2 + 0xc4) = uVar4;
    uVar6 = param_2 + 0xb8U & 3;
    uVar5 = *(uint *)(param_2 + 0xb8U & 0xfffffffc);
    if (uVar5 >> uVar6 * 8 != 0 || uVar5 << uVar6 * -8 + 0x20 != 0) {
      uVar6 = param_2 + 0xc4U & 3;
      uVar5 = *(uint *)(param_2 + 0xc4U & 0xfffffffc);
      *(uint *)(param_2 + 0xc4) = (uint)(uVar5 >> uVar6 * 8 == 0 && uVar5 << uVar6 * -8 + 0x20 == 0)
      ;
    }
  }
  uVar6 = param_2 + 0xc4U & 3;
  uVar5 = *(uint *)(param_2 + 0xc4U & 0xfffffffc);
  uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  if ((int)uVar6 < 2) {
    if ((int)uVar6 < 1) {
      uVar6 = param_2 + 0xa4U & 3;
      uVar5 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
      *(uint *)(param_2 + 0xa4) = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) - 0x4000;
      uVar6 = param_2 + 0xa4U & 3;
      uVar5 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
      if ((int)(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) < 0) {
        *(undefined4 *)(param_2 + 0xa4) = 0;
      }
    }
    else {
      uVar6 = param_2 + 0xa4U & 3;
      uVar5 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
      *(uint *)(param_2 + 0xa4) = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0x4000;
      uVar6 = param_2 + 0xa4U & 3;
      uVar5 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
      if (0x7f000 < (int)(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20)) {
        *(undefined4 *)(param_2 + 0xa4) = 0x7f000;
      }
    }
  }
  else {
    *(undefined4 *)(param_2 + 0xa4) = uRam020a0660;
  }
  if (*(short *)(param_2 + 0xbc) != 0) {
    uVar6 = param_2 + 0xc4U & 3;
    uVar5 = *(uint *)(param_2 + 0xc4U & 0xfffffffc);
    if (uVar5 >> uVar6 * 8 == 0 && uVar5 << uVar6 * -8 + 0x20 == 0) {
      uVar6 = param_2 + 200U & 3;
      uVar5 = *(uint *)(param_2 + 200U & 0xfffffffc);
      uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
      if (0 < (int)uVar6) {
        *(uint *)(param_2 + 200) = uVar6 - 1;
      }
    }
    else {
      uVar6 = func_02108e6c(8);
      if (*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 == 0 &&
          *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20 == 0) {
        uVar6 = param_2 + 200U & 3;
        uVar5 = *(uint *)(param_2 + 200U & 0xfffffffc);
        uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
        *(uint *)(param_2 + 200) = uVar6 - 1;
        if ((int)uVar6 < 1) {
          uVar4 = func_02108e6c(8);
          local_38[0] = (uint)*(ushort *)(param_2 + 0xbc);
          local_38[1] = 0;
          local_38[2] = 4;
          local_38[3] = func_020d4ef4();
          func_0210b760((uint)(uintptr_t)(local_38),uVar4);
          uVar7 = *(uint *)(uRam020a0664 & 0xfffffffc) >> (uRam020a0664 & 3) * 8 |
                  *(uint *)(uRam020a0664 & 0xfffffffc) << (uRam020a0664 & 3) * -8 + 0x20;
          iVar8 = uVar7 + iRam020a0668;
          uVar6 = iVar8 + 8U & 3;
          uVar5 = *(uint *)(iVar8 + 8U & 0xfffffffc);
          uVar12 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
          uVar6 = uVar7 + 0x498 & 3;
          uVar5 = *(uint *)(uVar7 + 0x498 & 0xfffffffc);
          uVar15 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
          uVar6 = iVar8 + 4U & 3;
          uVar10 = *(uint *)(iVar8 + 4U & 0xfffffffc);
          lVar1 = (ulonglong)uVar15 * (ulonglong)uVar12;
          uVar16 = (uint)lVar1;
          uVar5 = iVar8 + 0xcU & 3;
          uVar11 = *(uint *)(iVar8 + 0xcU & 0xfffffffc);
          uVar9 = iVar8 + 0x10U & 3;
          uVar13 = *(uint *)(iVar8 + 0x10U & 0xfffffffc);
          uVar14 = uVar13 >> uVar9 * 8 | uVar13 << uVar9 * -8 + 0x20;
          uVar9 = iVar8 + 0x14U & 3;
          uVar13 = *(uint *)(iVar8 + 0x14U & 0xfffffffc);
          *(uint *)(uVar7 + 0x498) = uVar14 + uVar16;
          *(uint *)(iVar8 + 4) =
               (uVar13 >> uVar9 * 8 | uVar13 << uVar9 * -8 + 0x20) +
               (uVar11 >> uVar5 * 8 | uVar11 << uVar5 * -8 + 0x20) * uVar15 +
               uVar12 * (uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20) +
               (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar14,uVar16);
          uVar6 = iVar8 + 4U & 3;
          uVar5 = *(uint *)(iVar8 + 4U & 0xfffffffc);
          *(int *)(param_2 + 200) =
               (int)((ulonglong)(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) * 0x3c >> 0x20) +
               0x78;
          *(undefined4 *)(param_2 + 0xa0) = 0x7f000;
        }
      }
      else {
        iVar8 = GetDriverEntry((short)*(char *)((*(uint *)(uRam020a065c & 0xfffffffc) >>
                                                 (uRam020a065c & 3) * 8 |
                                                *(uint *)(uRam020a065c & 0xfffffffc) <<
                                                (uRam020a065c & 3) * -8 + 0x20) + 0x62));
        uVar6 = iVar8 + 0x2a0U & 3;
        uVar9 = *(uint *)(iVar8 + 0x2a0U & 0xfffffffc);
        uVar5 = param_2 + 0xa0U & 3;
        uVar7 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
        *(uint *)(param_2 + 0xa0) =
             (uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) -
             (uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20);
        uVar6 = param_2 + 0xa0U & 3;
        uVar5 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
        if ((int)(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) < 0xc000) {
          *(undefined4 *)(param_2 + 0xa0) = 0xc000;
        }
      }
    }
    uVar6 = func_02108e6c(8);
    if (*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 != 0 ||
        *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20 != 0) {
      uVar6 = param_2 + 0xa0U & 3;
      uVar5 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
      uVar5 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
      uVar6 = param_2 + 0xa4U & 3;
      uVar9 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
      uVar6 = uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20;
      if ((int)uVar5 <= (int)uVar6) {
        uVar6 = uVar5;
      }
      uVar4 = func_02108e6c(8);
      func_02105b28(uVar4,(int)uVar6 >> 0xc);
    }
  }
  if (*(short *)(param_2 + 0xbe) != 0) {
    uVar6 = param_2 + 0xc4U & 3;
    uVar5 = *(uint *)(param_2 + 0xc4U & 0xfffffffc);
    if ((uVar5 >> uVar6 * 8 != 0 || uVar5 << uVar6 * -8 + 0x20 != 0) &&
       (uVar6 = func_02108e6c(9),
       *(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 == 0 &&
       *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20 == 0)) {
      uVar4 = func_02108e6c(9);
      auStack_28[0] = (uint)*(ushort *)(param_2 + 0xbe);
      auStack_28[1] = 0;
      auStack_28[2] = 4;
      auStack_28[3] = func_020d4ef4();
      func_0210b760((uint)(uintptr_t)(auStack_28),uVar4);
    }
    uVar6 = func_02108e6c(9);
    if (*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 != 0 ||
        *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20 != 0) {
      uVar4 = func_02108e6c(9);
      uVar6 = param_2 + 0xa4U & 3;
      uVar5 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
      func_02105b28(uVar4,(int)(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) >> 0xc);
      return;
    }
    return;
  }
  return;
}

