/* Decompiled C draft; module arm9; ROM address 0212f1f8. No matching claim. */
#include "types.h"
#include "deps/0212f1f8_func_0212f1f8.h"

void func_0212f1f8(int param_1,int param_2,uint param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  
  iVar4 = iRam0212f3f4;
  param_3 = param_3 >> 1;
  iVar11 = 0;
  iVar5 = iVar11;
  if (0x18 < param_3) {
    do {
      iVar11 = 0;
      do {
        iVar7 = iVar11 + iVar5;
        iVar9 = param_4 + iVar11 * 8;
        uVar10 = iVar9 + 0x18;
        uVar6 = uVar10 & 3;
        uVar2 = *(uint *)(uVar10 & 0xfffffffc);
        uVar10 = iVar9 + 0x1c;
        uVar1 = uVar10 & 3;
        uVar10 = *(uint *)(uVar10 & 0xfffffffc);
        iVar9 = (int)*(short *)(param_1 + iVar7 * 2) +
                (uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20);
        iVar12 = (int)*(short *)(param_2 + iVar7 * 2) +
                 (uVar10 >> uVar1 * 8 | uVar10 << uVar1 * -8 + 0x20);
        if (iVar9 < -0x8000) {
          iVar3 = -0x8000;
        }
        else {
          iVar3 = iVar9;
          if (iVar4 < iVar9) {
            iVar3 = iVar4;
          }
        }
        *(short *)(param_1 + iVar7 * 2) = (short)iVar3;
        if (iVar12 < -0x8000) {
          iVar3 = -0x8000;
        }
        else {
          iVar3 = iVar12;
          if (iVar4 < iVar12) {
            iVar3 = iVar4;
          }
        }
        iVar13 = param_4 + iVar11 * 8;
        *(short *)(param_2 + iVar7 * 2) = (short)iVar3;
        iVar11 = iVar11 + 1;
        *(int *)(iVar13 + 0x18) = iVar12 + 1 >> 2;
        *(int *)(iVar13 + 0x1c) = iVar9 + 1 >> 2;
      } while (iVar11 < 0x18);
      iVar11 = iVar5 + 0x18;
      uVar10 = iVar5 + 0x30;
      iVar5 = iVar11;
    } while (uVar10 < param_3);
  }
  iVar4 = iRam0212f3f4;
  param_3 = param_3 - iVar11;
  uVar10 = 0;
  if (param_3 != 0) {
    do {
      iVar7 = uVar10 + iVar11;
      iVar5 = param_4 + uVar10 * 8;
      uVar6 = iVar5 + 0x18;
      uVar1 = uVar6 & 3;
      uVar8 = *(uint *)(uVar6 & 0xfffffffc);
      uVar6 = iVar5 + 0x1c;
      uVar2 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      iVar12 = (int)*(short *)(param_1 + iVar7 * 2) +
               (uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20);
      iVar9 = (int)*(short *)(param_2 + iVar7 * 2) +
              (uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20);
      iVar5 = -0x8000;
      if ((-0x8001 < iVar12) && (iVar5 = iVar12, iVar4 < iVar12)) {
        iVar5 = iVar4;
      }
      *(short *)(param_1 + iVar7 * 2) = (short)iVar5;
      iVar5 = -0x8000;
      if ((-0x8001 < iVar9) && (iVar5 = iVar9, iVar4 < iVar9)) {
        iVar5 = iVar4;
      }
      uVar10 = uVar10 + 1;
      *(short *)(param_2 + iVar7 * 2) = (short)iVar5;
    } while (uVar10 < param_3);
  }
  uVar10 = 0;
  if (-param_3 != -0x18) {
    do {
      iVar5 = param_4 + param_3 * 8 + uVar10 * 8;
      uVar6 = iVar5 + 0x18;
      uVar1 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      iVar4 = param_4 + uVar10 * 8;
      *(uint *)(iVar4 + 0x18) = uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20;
      uVar6 = iVar5 + 0x1c;
      uVar1 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      uVar10 = uVar10 + 1;
      *(uint *)(iVar4 + 0x1c) = uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20;
    } while (uVar10 < -param_3 + 0x18);
  }
  uVar10 = 0;
  if (param_3 != 0) {
    do {
      iVar4 = (uVar10 + iVar11) * 2;
      iVar5 = param_4 + ((uVar10 + 0x18) - param_3) * 8;
      *(int *)(iVar5 + 0x18) = *(short *)(param_2 + iVar4) + 1 >> 2;
      uVar10 = uVar10 + 1;
      *(int *)(iVar5 + 0x1c) = *(short *)(param_1 + iVar4) + 1 >> 2;
    } while (uVar10 < param_3);
    return;
  }
  return;
}

