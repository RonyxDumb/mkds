/* Decompiled C draft; module arm9; ROM address 0208b190. No matching claim. */
#include "types.h"
#include "deps/0208b190_func_0208b190.h"

void func_0208b190(void)

{
  byte bVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar14;
  uint uVar15;
  int iVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  undefined1 auStack_78 [4];
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  uint auStack_64 [4];
  uint uStack_54;
  uint uStack_50;
  int aiStack_4c [4];
  int iStack_3c;
  int iStack_38;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  uint uVar13;
  uint uVar16;
  
  uVar4 = uRam0208b440;
  uVar11 = *(uint *)(uRam0208b440 & 0xfffffffc) >> (uRam0208b440 & 3) * 8 |
           *(uint *)(uRam0208b440 & 0xfffffffc) << (uRam0208b440 & 3) * -8 + 0x20;
  *(short *)(uVar11 + 0x60) = *(short *)(uVar11 + 0x60) + -1;
  uVar11 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if (*(short *)((uVar4 >> uVar11 * 8 | uVar4 << uVar11 * -8 + 0x20) + 0x60) < 1) {
    iVar21 = -1;
    iVar5 = GetGlobalHD4();
    uVar11 = uRam0208b440;
    iVar22 = 0;
    uStack_70 = *(undefined4 *)(iVar5 + 0x15c);
    uStack_6c = *(undefined4 *)(iVar5 + 0x160);
    uStack_68 = *(undefined4 *)(iVar5 + 0x164);
    iVar5 = 0;
    do {
      uVar4 = uVar11 & 3;
      uVar12 = *(uint *)(uVar11 & 0xfffffffc);
      uVar13 = uVar12 >> uVar4 * 8 | uVar12 << uVar4 * -8 + 0x20;
      uVar4 = uVar13 + iVar22 * 4 + 0x48;
      uVar12 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      if (uVar4 >> uVar12 * 8 != 0 || uVar4 << uVar12 * -8 + 0x20 != 0) {
        iVar17 = uVar13 + 0x48;
        uVar6 = (*(code *)(*(uint *)(uRam0208b444 & 0xfffffffc) >> (uRam0208b444 & 3) * 8 |
                          *(uint *)(uRam0208b444 & 0xfffffffc) << (uRam0208b444 & 3) * -8 + 0x20))
                          (auStack_78,0);
        uVar4 = iVar17 + iVar5;
        uVar12 = uVar4 & 3;
        uVar4 = *(uint *)(uVar4 & 0xfffffffc);
        func_020184e4(uVar6,uVar4 >> uVar12 * 8 | uVar4 << uVar12 * -8 + 0x20);
        *(undefined4 *)(iVar17 + iVar5) = 0;
      }
      uVar4 = uRam0208b440;
      iVar22 = (iVar22 + 1) * 0x10000 >> 0x10;
      iVar5 = iVar5 + 4;
    } while (iVar22 < 6);
    iVar22 = 0;
    iVar17 = 0;
    iVar5 = -0x1000;
    do {
      uVar11 = uVar4 & 3;
      uVar12 = *(uint *)(uVar4 & 0xfffffffc);
      iVar7 = Vector3_DotProduct(&uStack_70,
                                 (uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20) + iVar17);
      iVar3 = iRam0208b44c;
      uVar12 = uRam0208b444;
      uVar11 = uRam0208b440;
      iVar20 = iVar5;
      if (iVar5 <= iVar7) {
        iVar20 = iVar7;
      }
      if (iVar5 <= iVar7) {
        iVar21 = iVar22;
      }
      iVar22 = (iVar22 + 1) * 0x10000 >> 0x10;
      iVar17 = iVar17 + 0xc;
      iVar5 = iVar20;
    } while (iVar22 < 6);
    aiStack_4c[0] = iVar21 + -1;
    if (aiStack_4c[0] < 0) {
      aiStack_4c[0] = 5;
    }
    iStack_3c = iVar21 + 1;
    if (5 < iStack_3c) {
      iStack_3c = 0;
    }
    uVar4 = iRam0208b448 + iVar21 * 8;
    uVar13 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    auStack_64[2] = uVar4 >> uVar13 * 8 | uVar4 << uVar13 * -8 + 0x20;
    uVar4 = iRam0208b448 + aiStack_4c[0] * 8;
    uVar13 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    auStack_64[0] = uVar4 >> uVar13 * 8 | uVar4 << uVar13 * -8 + 0x20;
    uVar4 = iRam0208b448 + (aiStack_4c[0] * 2 + 1) * 4;
    uVar13 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    auStack_64[1] = uVar4 >> uVar13 * 8 | uVar4 << uVar13 * -8 + 0x20;
    uVar4 = iRam0208b448 + (iVar21 * 2 + 1) * 4;
    uVar13 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    auStack_64[3] = uVar4 >> uVar13 * 8 | uVar4 << uVar13 * -8 + 0x20;
    uVar4 = iRam0208b448 + iStack_3c * 8;
    uVar13 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uStack_54 = uVar4 >> uVar13 * 8 | uVar4 << uVar13 * -8 + 0x20;
    uVar4 = iRam0208b448 + (iStack_3c * 2 + 1) * 4;
    uVar13 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uStack_50 = uVar4 >> uVar13 * 8 | uVar4 << uVar13 * -8 + 0x20;
    iVar22 = 0;
    aiStack_4c[1] = aiStack_4c[0];
    aiStack_4c[2] = iVar21;
    aiStack_4c[3] = iVar21;
    iStack_38 = iStack_3c;
    do {
      iVar21 = aiStack_4c[iVar22];
      uVar4 = uVar12 & 3;
      uVar13 = *(uint *)(uVar12 & 0xfffffffc);
      iVar5 = iVar3 + iVar21 * 0xc;
      uVar6 = (*(code *)(uVar13 >> uVar4 * 8 | uVar13 << uVar4 * -8 + 0x20))
                        (&uStack_74,auStack_64[iVar22]);
      uVar4 = iVar3 + iVar21 * 0xc;
      uVar13 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      iStack_34 = (int)(uVar4 >> uVar13 * 8 | uVar4 << uVar13 * -8 + 0x20) >> 4;
      uVar4 = iVar5 + 4;
      uVar13 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      iStack_30 = (int)(uVar4 >> uVar13 * 8 | uVar4 << uVar13 * -8 + 0x20) >> 4;
      uVar4 = iVar5 + 8;
      uVar13 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      iStack_2c = (int)(uVar4 >> uVar13 * 8 | uVar4 << uVar13 * -8 + 0x20) >> 4;
      iVar21 = func_02018600(uVar6,uStack_74,&iStack_34);
      if (iVar21 != 0) {
        uVar4 = iVar21 + 0x20U & 3;
        uVar13 = *(uint *)(iVar21 + 0x20U & 0xfffffffc);
        uVar13 = uVar13 >> uVar4 * 8 | uVar13 << uVar4 * -8 + 0x20;
        uVar4 = uVar13 & 3;
        uVar13 = *(uint *)(uVar13 & 0xfffffffc);
        bVar1 = *(byte *)((uVar13 >> uVar4 * 8 | uVar13 << uVar4 * -8 + 0x20) + 0x54);
        if ((bVar1 & 0x80) == 0) {
          if ((bVar1 & 0x40) != 0) {
            uVar4 = iVar21 + 0x80U & 3;
            uVar13 = *(uint *)(iVar21 + 0x80U & 0xfffffffc);
            *(uint *)(iVar21 + 0x80) =
                 (uVar13 >> uVar4 * 8 | uVar13 << uVar4 * -8 + 0x20) & 0xfff8ffff | 0x20000;
          }
        }
        else {
          uVar4 = iVar21 + 0x80U & 3;
          uVar13 = *(uint *)(iVar21 + 0x80U & 0xfffffffc);
          *(uint *)(iVar21 + 0x80) =
               (uVar13 >> uVar4 * 8 | uVar13 << uVar4 * -8 + 0x20) & 0xfff8ffff | 0x10000;
        }
      }
      iVar5 = iVar22 * 4;
      iVar22 = iVar22 + 1;
      *(int *)((*(uint *)(uVar11 & 0xfffffffc) >> (uVar11 & 3) * 8 |
               *(uint *)(uVar11 & 0xfffffffc) << (uVar11 & 3) * -8 + 0x20) + iVar5 + 0x48) = iVar21;
    } while (iVar22 < 6);
    uVar19 = *(uint *)(uRam0208b450 & 0xfffffffc) >> (uRam0208b450 & 3) * 8 |
             *(uint *)(uRam0208b450 & 0xfffffffc) << (uRam0208b450 & 3) * -8 + 0x20;
    iVar22 = uVar19 + iRam0208b454;
    uVar4 = iVar22 + 8U & 3;
    uVar12 = *(uint *)(iVar22 + 8U & 0xfffffffc);
    uVar14 = uVar12 >> uVar4 * 8 | uVar12 << uVar4 * -8 + 0x20;
    uVar4 = uVar19 + 0x498 & 3;
    uVar12 = *(uint *)(uVar19 + 0x498 & 0xfffffffc);
    uVar10 = uVar12 >> uVar4 * 8 | uVar12 << uVar4 * -8 + 0x20;
    uVar4 = iVar22 + 4U & 3;
    uVar8 = *(uint *)(iVar22 + 4U & 0xfffffffc);
    lVar2 = (ulonglong)uVar10 * (ulonglong)uVar14;
    uVar18 = (uint)lVar2;
    uVar12 = iVar22 + 0xcU & 3;
    uVar9 = *(uint *)(iVar22 + 0xcU & 0xfffffffc);
    uVar13 = iVar22 + 0x10U & 3;
    uVar15 = *(uint *)(iVar22 + 0x10U & 0xfffffffc);
    uVar16 = uVar15 >> uVar13 * 8 | uVar15 << uVar13 * -8 + 0x20;
    uVar13 = iVar22 + 0x14U & 3;
    uVar15 = *(uint *)(iVar22 + 0x14U & 0xfffffffc);
    *(uint *)(uVar19 + 0x498) = uVar16 + uVar18;
    *(uint *)(iVar22 + 4) =
         (uVar15 >> uVar13 * 8 | uVar15 << uVar13 * -8 + 0x20) +
         (uVar9 >> uVar12 * 8 | uVar9 << uVar12 * -8 + 0x20) * uVar10 +
         uVar14 * (uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20) +
         (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar16,uVar18);
    uVar4 = iVar22 + 4U & 3;
    uVar12 = *(uint *)(iVar22 + 4U & 0xfffffffc);
    *(short *)((*(uint *)(uVar11 & 0xfffffffc) >> (uVar11 & 3) * 8 |
               *(uint *)(uVar11 & 0xfffffffc) << (uVar11 & 3) * -8 + 0x20) + 0x60) =
         (short)((uint)((int)((ulonglong)(uVar12 >> uVar4 * 8 | uVar12 << uVar4 * -8 + 0x20) * 0x19
                             >> 0x20) * 0x10000) >> 0x10) + 0x14;
    return;
  }
  return;
}

