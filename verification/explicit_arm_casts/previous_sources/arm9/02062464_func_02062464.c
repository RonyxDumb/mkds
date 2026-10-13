/* Decompiled C draft; module arm9; ROM address 02062464. No matching claim. */
#include "types.h"
#include "deps/02062464_func_02062464.h"

void func_02062464(void)

{
  int *piVar1;
  undefined4 *puVar2;
  ushort *puVar3;
  short *psVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined4 extraout_r1;
  uint uVar11;
  
  *puRam0206282c = 1;
  func_01ffdb70();
  HandleCourseAnim();
  func_0207aaec();
  uVar5 = (*(uint *)(uRam02062830 & 0xfffffffc) >> (uRam02062830 & 3) * 8 |
          *(uint *)(uRam02062830 & 0xfffffffc) << (uRam02062830 & 3) * -8 + 0x20) + 0xc;
  uVar9 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  if (uVar5 >> uVar9 * 8 == 0 && uVar5 << uVar9 * -8 + 0x20 == 0) {
    func_02085778();
  }
  uVar5 = (*(uint *)(uRam02062834 & 0xfffffffc) >> (uRam02062834 & 3) * 8 |
          *(uint *)(uRam02062834 & 0xfffffffc) << (uRam02062834 & 3) * -8 + 0x20) + 8;
  uVar9 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar5 = uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20;
  if (uVar5 == 2) {
    func_020a08ec();
  }
  else if ((uVar5 == 4) &&
          (func_0x02181860(),
          uVar5 = (*(uint *)(uRam02062834 & 0xfffffffc) >> (uRam02062834 & 3) * 8 |
                  *(uint *)(uRam02062834 & 0xfffffffc) << (uRam02062834 & 3) * -8 + 0x20) + 8,
          uVar9 = uVar5 & 3, uVar5 = *(uint *)(uVar5 & 0xfffffffc),
          (uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20) == 4)) {
    func_020a08ec();
  }
  func_02073e98();
  uVar9 = *(uint *)(uRam02062830 & 0xfffffffc) >> (uRam02062830 & 3) * 8 |
          *(uint *)(uRam02062830 & 0xfffffffc) << (uRam02062830 & 3) * -8 + 0x20;
  uVar5 = uVar9 + 0x28;
  uVar10 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  if (uVar5 >> uVar10 * 8 == 0 && uVar5 << uVar10 * -8 + 0x20 == 0) {
    iVar6 = func_0203c5e4();
    if (iVar6 == 0) {
      uVar7 = GetDriverEntry((int)*(char *)((*(uint *)(uRam02062834 & 0xfffffffc) >>
                                             (uRam02062834 & 3) * 8 |
                                            *(uint *)(uRam02062834 & 0xfffffffc) <<
                                            (uRam02062834 & 3) * -8 + 0x20) + 0x62));
      StructHD_SomeMQFn(*(uint *)(uRam02062840 & 0xfffffffc) >> (uRam02062840 & 3) * 8 |
                        *(uint *)(uRam02062840 & 0xfffffffc) << (uRam02062840 & 3) * -8 + 0x20,uVar7
                       );
      StructHD_SomeLookAt(*(uint *)(uRam02062840 & 0xfffffffc) >> (uRam02062840 & 3) * 8 |
                          *(uint *)(uRam02062840 & 0xfffffffc) << (uRam02062840 & 3) * -8 + 0x20);
      piVar1 = piRam02062838;
      uVar5 = *(uint *)(uRam02062840 & 0xfffffffc) >> (uRam02062840 & 3) * 8 |
              *(uint *)(uRam02062840 & 0xfffffffc) << (uRam02062840 & 3) * -8 + 0x20;
      *puRam0206283c = uVar5;
      *piVar1 = uVar5 + 0x30;
    }
    else {
      uVar7 = GetDriverEntry(*(undefined1 *)
                              ((*(uint *)(uRam02062834 & 0xfffffffc) >> (uRam02062834 & 3) * 8 |
                               *(uint *)(uRam02062834 & 0xfffffffc) <<
                               (uRam02062834 & 3) * -8 + 0x20) + 99));
      StructHD_SomeMQFn(*(uint *)(uRam02062840 & 0xfffffffc) >> (uRam02062840 & 3) * 8 |
                        *(uint *)(uRam02062840 & 0xfffffffc) << (uRam02062840 & 3) * -8 + 0x20,uVar7
                       );
      StructHD_SomeLookAt(*(uint *)(uRam02062840 & 0xfffffffc) >> (uRam02062840 & 3) * 8 |
                          *(uint *)(uRam02062840 & 0xfffffffc) << (uRam02062840 & 3) * -8 + 0x20);
      iVar6 = StructHD_SomeFn_7(*(uint *)(uRam02062844 & 0xfffffffc) >> (uRam02062844 & 3) * 8 |
                                *(uint *)(uRam02062844 & 0xfffffffc) <<
                                (uRam02062844 & 3) * -8 + 0x20);
      piVar1 = piRam02062838;
      if (iVar6 == 0) {
        uVar5 = *(uint *)(uRam02062840 & 0xfffffffc) >> (uRam02062840 & 3) * 8 |
                *(uint *)(uRam02062840 & 0xfffffffc) << (uRam02062840 & 3) * -8 + 0x20;
        *puRam0206283c = uVar5;
        *piVar1 = uVar5 + 0x30;
      }
      else {
        uVar5 = *(uint *)(uRam02062844 & 0xfffffffc) >> (uRam02062844 & 3) * 8 |
                *(uint *)(uRam02062844 & 0xfffffffc) << (uRam02062844 & 3) * -8 + 0x20;
        *puRam0206283c = uVar5;
        *piVar1 = uVar5 + 0x30;
      }
    }
  }
  else {
    uVar9 = uVar9 + 0x2c;
    uVar5 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    if (uVar9 >> uVar5 * 8 == 0 && uVar9 << uVar5 * -8 + 0x20 == 0) {
      iVar6 = SomeLookAtHD_HD2();
    }
    else {
      iVar6 = SomeLookAtHD3();
    }
    *piRam02062838 = iVar6;
    uVar5 = func_02074888();
    *puRam0206283c = uVar5;
  }
  StructHD_SomeFn_2(*(uint *)((uint)puRam0206283c & 0xfffffffc) >> ((uint)puRam0206283c & 3) * 8 |
                    *(uint *)((uint)puRam0206283c & 0xfffffffc) <<
                    ((uint)puRam0206283c & 3) * -8 + 0x20);
  func_020d4f94(*(uint *)((uint)piRam02062838 & 0xfffffffc) >> ((uint)piRam02062838 & 3) * 8 |
                *(uint *)((uint)piRam02062838 & 0xfffffffc) << ((uint)piRam02062838 & 3) * -8 + 0x20
               );
  iVar6 = func_02073e88();
  if (iVar6 != 0) {
    func_020d50c4();
  }
  func_020fa920();
  func_020e9d10();
  func_020d4590();
  UpdateExplosionInstances();
  func_0208f0a0();
  func_0208b8c8();
  puVar3 = puRam02062854;
  puVar2 = puRam0206284c;
  if (*(uint *)((uint)puRam02062848 & 0xfffffffc) >> ((uint)puRam02062848 & 3) * 8 != 0 ||
      *(uint *)((uint)puRam02062848 & 0xfffffffc) << ((uint)puRam02062848 & 3) * -8 + 0x20 != 0) {
    if (*(uint *)((uint)puRam0206284c & 0xfffffffc) >> ((uint)puRam0206284c & 3) * 8 == 0 &&
        *(uint *)((uint)puRam0206284c & 0xfffffffc) << ((uint)puRam0206284c & 3) * -8 + 0x20 == 0) {
      *puRam02062854 = *puRam02062854 + 1;
      if (0x47 < *puVar3) {
        *puVar2 = 1;
      }
    }
    else {
      if (*psRam02062850 == 0) {
        *(undefined4 *)
         ((*(uint *)(uRam02062830 & 0xfffffffc) >> (uRam02062830 & 3) * 8 |
          *(uint *)(uRam02062830 & 0xfffffffc) << (uRam02062830 & 3) * -8 + 0x20) + 0x20) = 0;
        func_0207a5f0(1);
        func_02062ef8(0);
        puVar2 = puRam0206284c;
        *puRam02062848 = 0;
        *puVar2 = 0;
      }
      else {
        func_02061944(*psRam02062850,0);
      }
      *psRam02062850 = *psRam02062850 + -4;
    }
  }
  func_0208a218();
  func_0203ca38();
  func_0207aa7c();
  func_0208677c();
  uVar10 = uRam02062830;
  uVar5 = (*(uint *)(uRam02062834 & 0xfffffffc) >> (uRam02062834 & 3) * 8 |
          *(uint *)(uRam02062834 & 0xfffffffc) << (uRam02062834 & 3) * -8 + 0x20) + 8;
  uVar9 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  if ((uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20) == 5) {
    uVar11 = *(uint *)(uRam02062830 & 0xfffffffc) >> (uRam02062830 & 3) * 8 |
             *(uint *)(uRam02062830 & 0xfffffffc) << (uRam02062830 & 3) * -8 + 0x20;
    uVar5 = uVar11 + 0x34 & 3;
    uVar9 = *(uint *)(uVar11 + 0x34 & 0xfffffffc);
    if (uVar9 >> uVar5 * 8 == 0 && uVar9 << uVar5 * -8 + 0x20 == 0) {
      uVar5 = uVar11 + 0x30 & 3;
      uVar9 = *(uint *)(uVar11 + 0x30 & 0xfffffffc);
      if (uVar9 >> uVar5 * 8 == 0 && uVar9 << uVar5 * -8 + 0x20 == 0) {
        uVar5 = uVar11 + 4 & 3;
        uVar9 = *(uint *)(uVar11 + 4 & 0xfffffffc);
        *(uint *)(uVar11 + 4) = (uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20) + 1;
        uVar5 = uVar10 & 3;
        uVar9 = *(uint *)(uVar10 & 0xfffffffc);
        uVar10 = uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20;
        uVar5 = uVar10 + 4;
        uVar9 = uVar5 & 3;
        uVar5 = *(uint *)(uVar5 & 0xfffffffc);
        if (0x7f < (uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20)) {
          *(undefined4 *)(uVar10 + 0x30) = 1;
        }
      }
    }
    else {
      uVar5 = uVar11 + 4 & 3;
      uVar9 = *(uint *)(uVar11 + 4 & 0xfffffffc);
      *(uint *)(uVar11 + 4) = (uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20) + 1;
    }
  }
  else {
    uVar10 = *(uint *)(uRam02062830 & 0xfffffffc) >> (uRam02062830 & 3) * 8 |
             *(uint *)(uRam02062830 & 0xfffffffc) << (uRam02062830 & 3) * -8 + 0x20;
    uVar5 = uVar10 + 4;
    uVar9 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    *(uint *)(uVar10 + 4) = (uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20) + 1;
  }
  uVar8 = uRam02062834;
  uVar11 = uRam02062830;
  uVar10 = *(uint *)(uRam02062830 & 0xfffffffc) >> (uRam02062830 & 3) * 8 |
           *(uint *)(uRam02062830 & 0xfffffffc) << (uRam02062830 & 3) * -8 + 0x20;
  uVar5 = uVar10 + 4;
  uVar9 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  *(uint *)(uVar10 + 0xc) = (uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20) & 7;
  uVar10 = *(uint *)(uVar11 & 0xfffffffc) >> (uVar11 & 3) * 8 |
           *(uint *)(uVar11 & 0xfffffffc) << (uVar11 & 3) * -8 + 0x20;
  uVar5 = uVar10 + 4;
  uVar9 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  *(uint *)(uVar10 + 0x10) = (uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20) & 1;
  uVar10 = uVar8 & 3;
  uVar8 = *(uint *)(uVar8 & 0xfffffffc);
  uVar11 = *(uint *)(uVar11 & 0xfffffffc) >> (uVar11 & 3) * 8 |
           *(uint *)(uVar11 & 0xfffffffc) << (uVar11 & 3) * -8 + 0x20;
  uVar5 = uVar11 + 4;
  uVar9 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  MaybeBoundsCheck(uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20,
                   *(undefined1 *)((uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20) + 0x3d0));
  uVar9 = uRam02062830;
  *(undefined4 *)(uVar11 + 0x14) = extraout_r1;
  uVar5 = uVar9 & 3;
  uVar9 = *(uint *)(uVar9 & 0xfffffffc);
  uVar5 = (uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20) + 0x18;
  uVar9 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  G3X_SetToonTable(iRam02062858 + (uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20) * 2);
  psVar4 = psRam0206285c;
  uVar10 = uRam02062830;
  uVar11 = *(uint *)(uRam02062830 & 0xfffffffc) >> (uRam02062830 & 3) * 8 |
           *(uint *)(uRam02062830 & 0xfffffffc) << (uRam02062830 & 3) * -8 + 0x20;
  uVar5 = uVar11 + 0x1c;
  uVar9 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  *(uint *)(uVar11 + 0x1c) = (uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20) + 1;
  uVar11 = *(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
           *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20;
  uVar5 = uVar11 + 0x1c;
  uVar9 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  if ((uint)(int)*psVar4 < (uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20)) {
    *(undefined4 *)(uVar11 + 0x1c) = 0;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
             *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20;
    uVar5 = uVar10 + 0x18;
    uVar9 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    *(uint *)(uVar10 + 0x18) = (uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20) + 1;
  }
  uVar10 = *(uint *)(uRam02062830 & 0xfffffffc) >> (uRam02062830 & 3) * 8 |
           *(uint *)(uRam02062830 & 0xfffffffc) << (uRam02062830 & 3) * -8 + 0x20;
  uVar5 = uVar10 + 0x18;
  uVar9 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  if (7 < (uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20)) {
    *(undefined4 *)(uVar10 + 0x18) = 0;
  }
  return;
}

