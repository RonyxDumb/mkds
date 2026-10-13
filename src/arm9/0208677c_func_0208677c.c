/* Decompiled C draft; module arm9; ROM address 0208677c. No matching claim. */
#include "types.h"
#include "deps/0208677c_func_0208677c.h"

void func_0208677c(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int *piVar11;
  uint uVar12;
  uint local_50;
  uint local_4c;
  int *piVar13;
  
  iVar2 = func_02061818();
  if (iVar2 == 0) {
    *puRam020869ec = uRam020869e8;
  }
  else {
    *puRam020869ec = uRam020869f0;
  }
  func_02086a04();
  uVar1 = uRam020869f4;
  iVar2 = 0;
  uVar7 = *(uint *)(uRam020869f4 & 0xfffffffc) >> (uRam020869f4 & 3) * 8 |
          *(uint *)(uRam020869f4 & 0xfffffffc) << (uRam020869f4 & 3) * -8 + 0x20;
  uVar12 = uVar7 + 0x20 & 3;
  uVar3 = *(uint *)(uVar7 + 0x20 & 0xfffffffc);
  if (0 < (int)(uVar3 >> uVar12 * 8 | uVar3 << uVar12 * -8 + 0x20)) {
    local_4c = 0;
    local_50 = 0x1000;
    do {
      uVar12 = uVar7 + iVar2 * 4 + 0xc4;
      uVar3 = uVar12 & 3;
      uVar12 = *(uint *)(uVar12 & 0xfffffffc);
      piVar13 = (int *)(uVar12 >> uVar3 * 8 | uVar12 << uVar3 * -8 + 0x20);
      iVar4 = GetDriverEntry((short)piVar13[3]);
      uVar12 = iVar4 + 0x508U & 3;
      uVar3 = *(uint *)(iVar4 + 0x508U & 0xfffffffc);
      piVar11 = (int *)(uVar3 >> uVar12 * 8 | uVar3 << uVar12 * -8 + 0x20);
      iVar4 = *piVar11;
      iVar8 = piVar11[1];
      iVar10 = piVar11[2];
      iVar5 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
              *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) +
              (uint)*(ushort *)(piVar13 + 3) * 4;
      uVar12 = iVar5 + 0x104;
      uVar3 = uVar12 & 3;
      uVar12 = *(uint *)(uVar12 & 0xfffffffc);
      uVar3 = uVar12 >> uVar3 * 8 | uVar12 << uVar3 * -8 + 0x20;
      uVar12 = local_50;
      if (0 < (int)uVar3) {
        uVar7 = iVar5 + 0x124;
        uVar6 = uVar7 & 3;
        uVar7 = *(uint *)(uVar7 & 0xfffffffc);
        if (((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) < uRam020869f8) ||
           (iVar5 = func_02061818(), iVar5 == 3)) {
          uVar3 = uVar3 - 0x14000;
          if ((int)uVar3 < 0) {
            uVar3 = local_4c;
          }
          uVar12 = (uint)((ulonglong)uVar3 * 0x44);
          *(undefined2 *)(piVar13 + 8) = 1;
          piVar13[5] = 1;
          uVar12 = uVar12 + 0x800 >> 0xc |
                   (((int)uVar3 >> 0x1f) * 0x44 + (int)((ulonglong)uVar3 * 0x44 >> 0x20) +
                   (uint)(0xfffff7ff < uVar12)) * 0x100000;
        }
        else {
          *(undefined2 *)(piVar13 + 8) = 0xffff;
          piVar13[5] = 2;
        }
      }
      uVar3 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
              *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) +
              (uint)*(ushort *)(piVar13 + 3) * 4 + 0xe4;
      uVar7 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      if ((uVar3 >> uVar7 * 8 == 0 && uVar3 << uVar7 * -8 + 0x20 == 0) &&
         (iVar5 = GetDriverEntry(), uVar3 = iVar5 + 0x7cU & 3,
         uVar7 = *(uint *)(iVar5 + 0x7cU & 0xfffffffc),
         ((uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) & uRam020869fc) == 0)) {
        iVar5 = GetDriverEntry((int)*(char *)((*(uint *)(uRam02086a00 & 0xfffffffc) >>
                                               (uRam02086a00 & 3) * 8 |
                                              *(uint *)(uRam02086a00 & 0xfffffffc) <<
                                              (uRam02086a00 & 3) * -8 + 0x20) + 0x62));
        uVar3 = (uint)(piVar11 + 1) & 3;
        uVar9 = *(uint *)((uint)(piVar11 + 1) & 0xfffffffc);
        uVar7 = iVar5 + 0x84U & 3;
        uVar6 = *(uint *)(iVar5 + 0x84U & 0xfffffffc);
        iVar5 = AbsValue((uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20) -
                         (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20));
        if ((0x96000 < iVar5) && (iVar5 = func_02061818(), iVar5 != 3)) goto LAB_020868f4;
      }
      else {
LAB_020868f4:
        *(undefined2 *)(piVar13 + 8) = 0xffff;
      }
      uVar3 = (uint)(piVar13 + 6) & 3;
      uVar7 = *(uint *)((uint)(piVar13 + 6) & 0xfffffffc);
      if (uVar7 >> uVar3 * 8 == 0 && uVar7 << uVar3 * -8 + 0x20 == 0) {
        if ((short)piVar13[8] != 0) {
          *(short *)((int)piVar13 + 0x22) = *(short *)((int)piVar13 + 0x22) + (short)piVar13[8];
          if (*(short *)((int)piVar13 + 0x22) < 0x1f) {
            if (*(short *)((int)piVar13 + 0x22) < 0) {
              *(undefined2 *)((int)piVar13 + 0x22) = 0;
              *(undefined2 *)(piVar13 + 8) = 0;
            }
          }
          else {
            *(undefined2 *)((int)piVar13 + 0x22) = 0x1e;
            *(undefined2 *)(piVar13 + 8) = 0;
          }
        }
      }
      else {
        iVar5 = func_0203c598();
        if (0 < iVar5 + -0x3c) {
          piVar13[6] = 0;
        }
      }
      if ((int)uVar12 < 0x1000) {
        *(short *)(piVar13 + 9) =
             (short)((int)*(short *)((int)piVar13 + 0x22) * uVar12 + 0x800 >> 0xc);
      }
      else {
        *(undefined2 *)(piVar13 + 9) = *(undefined2 *)((int)piVar13 + 0x22);
      }
      *piVar13 = iVar4 >> 4;
      iVar2 = iVar2 + 1;
      piVar13[1] = iVar8 + 0xf000 >> 4;
      piVar13[2] = iVar10 >> 4;
      uVar7 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
              *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
      uVar12 = uVar7 + 0x20 & 3;
      uVar3 = *(uint *)(uVar7 + 0x20 & 0xfffffffc);
    } while (iVar2 < (int)(uVar3 >> uVar12 * 8 | uVar3 << uVar12 * -8 + 0x20));
  }
  func_020866b4();
  func_020865ec();
  return;
}

