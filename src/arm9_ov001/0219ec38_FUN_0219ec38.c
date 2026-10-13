/* Decompiled C draft; module arm9_ov001; ROM address 0219ec38. No matching claim. */
#include "types.h"
#include "deps/0219ec38_FUN_0219ec38.h"

void FUN_0219ec38(void)

{
  short sVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  uint uVar7;
  short *psVar8;
  ushort *puVar9;
  
  uVar7 = 0xffffffff;
  func_0x021059e0();
  bVar6 = false;
  bVar2 = false;
  psVar8 = (short *)(DAT_0219eed0 + 0x2e0);
  if ((*(short *)(DAT_0219eed0 + 0x2e0) == 0) && (*(ushort *)(DAT_0219eed4 + 0x2e0) < 5)) {
    bVar2 = true;
  }
  if (((!bVar2) && (*(short *)(DAT_0219eed8 + 0x2e0) == 0)) &&
     (*(short *)(DAT_0219eed0 + 0x2e0) != 0)) {
    bVar6 = true;
  }
  if (bVar6) {
    uVar7 = func_0x0201ea84(*(undefined4 *)(*DAT_0219eedc + 8),*(undefined2 *)(DAT_0219eee0 + 0x2e0)
                            ,*(undefined2 *)(DAT_0219eee4 + 0x2e0));
  }
  puVar9 = (ushort *)(DAT_0219eee8 + 0x2e0);
  if ((*(ushort *)(DAT_0219eee8 + 0x2e0) & 2) == 0) {
    bVar6 = false;
    bVar2 = false;
    if ((*psVar8 == 0) && (*(ushort *)(DAT_0219eed4 + 0x2e0) < 5)) {
      bVar2 = true;
    }
    if (((!bVar2) && (*(short *)(DAT_0219eed8 + 0x2e0) == 0)) && (*psVar8 != 0)) {
      bVar6 = true;
    }
    if ((!bVar6) ||
       (iVar4 = func_0x02128210(*(undefined2 *)(DAT_0219eee0 + 0x2e0),
                                *(undefined2 *)(DAT_0219eee4 + 0x2e0)), iVar4 == 0)) {
      if (6 < uVar7) {
        if ((*puVar9 & 1) != 0) {
          *(undefined4 *)(*DAT_0219eedc + *(short *)(*DAT_0219eedc + 0x4c) * 4 + 0x28) = 5;
          FUN_0219f1f4();
          return;
        }
        iVar4 = func_0x020ae408(8,0x40);
        if (iVar4 == 0) {
          iVar4 = func_0x020ae408(8,0x80);
          if (iVar4 == 0) {
            iVar4 = func_0x020ae408(8,0x20);
            if (iVar4 == 0) {
              iVar4 = func_0x020ae408(8,0x10);
              if (iVar4 != 0) {
                iVar4 = (int)*(short *)(DAT_0219ef04 + *(short *)(*DAT_0219eedc + 0x4c) * 2);
                if (iVar4 != 0) {
                  iVar4 = (*(short *)(*DAT_0219eedc + 0x4c) + iVar4) * 0x10000;
                  iVar5 = FUN_0219f688(iVar4 >> 0x10);
                  piVar3 = DAT_0219eedc;
                  if (iVar5 != 0) {
                    *(short *)(*DAT_0219eedc + 0x4c) = (short)((uint)iVar4 >> 0x10);
                    *(undefined4 *)(*piVar3 + *(short *)(*piVar3 + 0x4c) * 4 + 0x28) = 5;
                    func_0x0212ecc0(DAT_0219eef4,0,0);
                  }
                }
              }
            }
            else {
              iVar4 = (int)*(short *)(DAT_0219ef00 + *(short *)(*DAT_0219eedc + 0x4c) * 2);
              if (iVar4 != 0) {
                iVar4 = (*(short *)(*DAT_0219eedc + 0x4c) + iVar4) * 0x10000;
                iVar5 = FUN_0219f688(iVar4 >> 0x10);
                piVar3 = DAT_0219eedc;
                if (iVar5 != 0) {
                  *(short *)(*DAT_0219eedc + 0x4c) = (short)((uint)iVar4 >> 0x10);
                  *(undefined4 *)(*piVar3 + *(short *)(*piVar3 + 0x4c) * 4 + 0x28) = 5;
                  func_0x0212ecc0(DAT_0219eef4,0,0);
                  return;
                }
              }
            }
          }
          else {
            iVar4 = (int)*(short *)(DAT_0219eefc + *(short *)(*DAT_0219eedc + 0x4c) * 2);
            if (iVar4 != 0) {
              iVar4 = (*(short *)(*DAT_0219eedc + 0x4c) + iVar4) * 0x10000;
              iVar5 = FUN_0219f688(iVar4 >> 0x10);
              piVar3 = DAT_0219eedc;
              if (iVar5 != 0) {
                *(short *)(*DAT_0219eedc + 0x4c) = (short)((uint)iVar4 >> 0x10);
                *(undefined4 *)(*piVar3 + *(short *)(*piVar3 + 0x4c) * 4 + 0x28) = 5;
                func_0x0212ecc0(DAT_0219eef4,0,0);
                return;
              }
            }
          }
        }
        else {
          iVar4 = (int)*(short *)(DAT_0219eef8 + *(short *)(*DAT_0219eedc + 0x4c) * 2);
          if (iVar4 != 0) {
            iVar4 = (*(short *)(*DAT_0219eedc + 0x4c) + iVar4) * 0x10000;
            iVar5 = FUN_0219f688(iVar4 >> 0x10);
            piVar3 = DAT_0219eedc;
            if (iVar5 != 0) {
              *(short *)(*DAT_0219eedc + 0x4c) = (short)((uint)iVar4 >> 0x10);
              *(undefined4 *)(*piVar3 + *(short *)(*piVar3 + 0x4c) * 4 + 0x28) = 5;
              func_0x0212ecc0(DAT_0219eef4,0,0);
              return;
            }
          }
        }
        return;
      }
      sVar1 = *(short *)(DAT_0219eef0 + uVar7 * 2);
      iVar4 = FUN_0219f688((int)sVar1);
      piVar3 = DAT_0219eedc;
      if (iVar4 == 0) {
        func_0x0212ecc0(DAT_0219eef4,0,0x16);
        return;
      }
      *(short *)(*DAT_0219eedc + 0x4c) = sVar1;
      *(undefined4 *)(*piVar3 + *(short *)(*piVar3 + 0x4c) * 4 + 0x28) = 5;
      FUN_0219f1f4();
      return;
    }
  }
  func_0x021281c8(0xe);
  FUN_0219f198();
  piVar3 = DAT_0219eedc;
  *(short *)(*DAT_0219eedc + 0x48) = (short)DAT_0219eeec;
  *(undefined4 *)(*piVar3 + 0x58) = 2;
  func_0x02128310(0);
  return;
}

