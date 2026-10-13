/* Decompiled C draft; module arm9; ROM address 0210366c. No matching claim. */
#include "types.h"
#include "deps/0210366c_func_0210366c.h"

void func_0210366c(int param_1)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  
  iVar7 = param_1 + 0x10;
  uVar4 = 0;
  iVar5 = 0;
  do {
    iVar3 = uVar4 * 4;
    *(undefined2 *)(iVar7 + uVar4 * 4) = 0;
    uVar4 = uVar4 + 1;
    *(undefined2 *)(iVar7 + iVar3 + 2) = 0;
  } while ((int)uVar4 < 4);
  do {
    iVar6 = (int)*(short *)(param_1 + iVar5 * 4);
    iVar3 = (int)*(short *)(param_1 + iVar5 * 4 + 2);
    if (iVar6 < 1) {
      lVar2 = CONCAT44(iRam02103838,uVar4);
      if (iVar6 < iRam02103838) {
        lVar2 = (longlong)iVar6 * (longlong)iVar6;
      }
      uVar4 = (uint)lVar2;
      if (iVar6 < iRam02103838) {
        uVar4 = uVar4 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
        uVar8 = -uVar4;
      }
      else {
        uVar8 = 0xfffffe8f;
      }
    }
    else {
      lVar2 = CONCAT44(iRam02103838,uVar4);
      if (iRam02103838 < iVar6) {
        lVar2 = (longlong)iVar6 * (longlong)iVar6;
      }
      uVar4 = (uint)lVar2;
      uVar8 = uRam0210383c;
      if (iRam02103838 < iVar6) {
        uVar8 = uVar4 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
      }
    }
    if (iVar3 < 1) {
      lVar2 = CONCAT44(iRam02103838,uVar4);
      if (iVar3 < iRam02103838) {
        lVar2 = (longlong)iVar3 * (longlong)iVar3;
      }
      if (iVar3 < iRam02103838) {
        uVar9 = -((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14);
      }
      else {
        uVar9 = 0xfffffe8f;
      }
    }
    else {
      lVar2 = CONCAT44(iRam02103838,uVar4);
      if (iRam02103838 < iVar3) {
        lVar2 = (longlong)iVar3 * (longlong)iVar3;
      }
      uVar9 = uRam0210383c;
      if (iRam02103838 < iVar3) {
        uVar9 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
      }
    }
    uVar1 = (uVar8 << 3) >> 0xc;
    uVar4 = uVar1 | (((int)uVar8 >> 0x1f) << 3 | uVar8 >> 0x1d) << 0x14;
    iVar3 = 0;
    do {
      if (iVar5 == iVar3) {
        iVar6 = iVar7 + iVar3 * 4;
        *(short *)(iVar7 + iVar3 * 4) = *(short *)(iVar7 + iVar3 * 4) + (short)(uVar8 * 0xc >> 0xc);
        *(short *)(iVar6 + 2) = *(short *)(iVar6 + 2) + (short)(uVar9 * 0xc >> 0xc);
      }
      else {
        iVar6 = iVar7 + iVar3 * 4;
        *(short *)(iVar7 + iVar3 * 4) = *(short *)(iVar7 + iVar3 * 4) + (short)uVar1;
        *(short *)(iVar6 + 2) = *(short *)(iVar6 + 2) + (short)((uVar9 << 3) >> 0xc);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 4);
    iVar5 = iVar5 + 1;
  } while (iVar5 < 4);
  iVar5 = 0;
  do {
    iVar3 = iVar7 + iVar5 * 4;
    iVar5 = iVar5 + 1;
    if (*(short *)(iVar3 + 2) < 0) {
      *(undefined2 *)(iVar3 + 2) = 0;
    }
  } while (iVar5 < 4);
  *(undefined4 *)(param_1 + 0x28) = 1;
  return;
}

