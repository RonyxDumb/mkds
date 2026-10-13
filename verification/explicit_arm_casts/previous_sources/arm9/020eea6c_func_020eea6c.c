/* Decompiled C draft; module arm9; ROM address 020eea6c. No matching claim. */
#include "types.h"
#include "deps/020eea6c_func_020eea6c.h"

void func_020eea6c(int param_1)

{
  short sVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int *piVar13;
  int local_48;
  uint local_44;
  int local_30;
  int local_2c;
  uint uVar12;
  
  uVar5 = param_1 + 0x20U & 3;
  uVar11 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  uVar12 = uVar11 >> uVar5 * 8 | uVar11 << uVar5 * -8 + 0x20;
  iVar6 = (int)(uint)*(ushort *)(param_1 + 0x174) >> 4;
  uVar5 = param_1 + 0x178U & 3;
  uVar11 = *(uint *)(param_1 + 0x178U & 0xfffffffc);
  uVar5 = uVar11 >> uVar5 * 8 | uVar11 << uVar5 * -8 + 0x20;
  iVar10 = 0;
  lVar2 = (longlong)(int)uVar5 * (longlong)(int)*(short *)(iRam020eec40 + (iVar6 * 2 + 1) * 2);
  lVar3 = (longlong)(int)uVar5 * (longlong)(int)*(short *)(iRam020eec40 + iVar6 * 4);
  local_44 = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14;
  uVar11 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  local_48 = param_1 + 0x14;
  local_30 = (int)uVar11 >> 0x1f;
  uVar5 = (uint)((ulonglong)uRam020eec44 * (ulonglong)uVar11) >> 0xc |
          (((int)uVar11 >> 0x1f) * uRam020eec44 +
          (int)((ulonglong)uRam020eec44 * (ulonglong)uVar11 >> 0x20)) * 0x100000;
  local_2c = ((int)local_44 >> 0x1f) * uRam020eec44 +
             (int)((ulonglong)uRam020eec44 * (ulonglong)local_44 >> 0x20);
  iVar8 = param_1 + 0x44;
  iVar7 = param_1 + 0x2c;
  iVar6 = param_1 + 0x180;
  piVar13 = &local_48;
  if ((int)uVar12 < 1) {
    piVar13 = (int *)&stack0xffffffdc;
  }
  uVar4 = (uint)((ulonglong)uRam020eec44 * (ulonglong)local_44) >> 0xc | local_2c * 0x100000;
  if (0 < (int)uVar12) {
    piVar13[2] = ((int)-uVar11 >> 1) - uVar4;
    piVar13[4] = ((int)-uVar11 >> 1) + uVar4;
    piVar13[3] = ((int)-local_44 >> 1) + uVar5;
    piVar13[5] = ((int)-local_44 >> 1) - uVar5;
    do {
      sVar1 = *(short *)(param_1 + iVar10 * 2 + 0x18c);
      uVar5 = *piVar13 + iVar10 * 4 & 3;
      uVar4 = *(uint *)(*piVar13 + iVar10 * 4 & 0xfffffffc);
      iVar9 = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x50;
      if (sVar1 == 0) {
        VecFx32_AddScale1(uVar11,iVar8,iVar6,iVar9);
        VecFx32_AddScale1(piVar13[1],iVar7,iVar9,iVar9);
      }
      else if (sVar1 == 1) {
        VecFx32_AddScale1(piVar13[2],iVar8,iVar6,iVar9);
        VecFx32_AddScale1(piVar13[3],iVar7,iVar9,iVar9);
      }
      else {
        VecFx32_AddScale1(piVar13[4],iVar8,iVar6,iVar9);
        VecFx32_AddScale1(piVar13[5],iVar7,iVar9,iVar9);
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 < (int)uVar12);
    return;
  }
  return;
}

