/* Decompiled C draft; module arm9_ov001; ROM address 02187684. No matching claim. */
#include "types.h"
#include "deps/02187684_FUN_02187684.h"

void FUN_02187684(int param_1,int param_2,int *param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  
  param_2 = param_2 * 0x18;
  switch(*(undefined4 *)(param_1 + param_2 + 0xbc)) {
  case 1:
    iVar3 = (int)(*(uint *)(param_1 + DAT_02187aa8) & 0xffff) >> 4;
    iVar4 = *(int *)(param_1 + 0xcc + param_2);
    iVar6 = (int)*(short *)(DAT_02187aac + iVar3 * 4);
    uVar8 = func_0x02133048(iVar4,iVar4 >> 0x1f,iVar6,iVar6 >> 0x1f);
    iVar4 = *(int *)(param_1 + 0xc4 + param_2);
    iVar3 = (int)*(short *)(DAT_02187aac + (iVar3 * 2 + 1) * 2);
    uVar9 = func_0x02133048(iVar4,iVar4 >> 0x1f,iVar3,iVar3 >> 0x1f);
    *param_3 = *(int *)(param_1 + 4) +
               ((uint)uVar8 >> 0xc | (int)((ulonglong)uVar8 >> 0x20) << 0x14) +
               ((uint)uVar9 >> 0xc | (int)((ulonglong)uVar9 >> 0x20) << 0x14);
    param_3[1] = *(int *)(param_1 + 8) + *(int *)(param_1 + param_2 + 200);
    iVar3 = (int)(*(uint *)(param_1 + DAT_02187aa8) & 0xffff) >> 4;
    iVar4 = *(int *)(param_1 + 0xcc + param_2);
    iVar6 = (int)*(short *)(DAT_02187aac + (iVar3 * 2 + 1) * 2);
    uVar8 = func_0x02133048(iVar4,iVar4 >> 0x1f,iVar6,iVar6 >> 0x1f);
    iVar4 = *(int *)(param_1 + 0xc4 + param_2);
    iVar3 = (int)*(short *)(DAT_02187aac + iVar3 * 4);
    uVar9 = func_0x02133048(iVar4,iVar4 >> 0x1f,iVar3,iVar3 >> 0x1f);
    param_3[2] = (*(int *)(param_1 + 0xc) +
                 ((uint)uVar8 >> 0xc | (int)((ulonglong)uVar8 >> 0x20) << 0x14)) -
                 ((uint)uVar9 >> 0xc | (int)((ulonglong)uVar9 >> 0x20) << 0x14);
    return;
  case 2:
    iVar3 = *(int *)(param_1 + param_2 + 200);
    uVar8 = func_0x02133048(iVar3,iVar3 >> 0x1f,*(int *)(param_1 + 0x20),
                            *(int *)(param_1 + 0x20) >> 0x1f);
    iVar3 = (int)(*(uint *)(param_1 + DAT_02187aa8) & 0xffff) >> 4;
    iVar4 = *(int *)(param_1 + param_2 + 0xc4);
    uVar9 = func_0x02133048(iVar4,iVar4 >> 0x1f,*(int *)(param_1 + 0x1c),
                            *(int *)(param_1 + 0x1c) >> 0x1f);
    uVar1 = (uint)uVar9 >> 0xc | (int)((ulonglong)uVar9 >> 0x20) << 0x14;
    iVar4 = *(int *)(param_1 + param_2 + 0xcc);
    uVar9 = func_0x02133048(iVar4,iVar4 >> 0x1f,*(int *)(param_1 + 0x24),
                            *(int *)(param_1 + 0x24) >> 0x1f);
    uVar2 = (uint)uVar9 >> 0xc | (int)((ulonglong)uVar9 >> 0x20) << 0x14;
    iVar4 = (int)*(short *)(DAT_02187aac + iVar3 * 4);
    uVar9 = func_0x02133048(uVar2,(int)uVar2 >> 0x1f,iVar4,iVar4 >> 0x1f);
    iVar3 = (int)*(short *)(DAT_02187aac + (iVar3 * 2 + 1) * 2);
    uVar7 = func_0x02133048(uVar1,(int)uVar1 >> 0x1f,iVar3,iVar3 >> 0x1f);
    *param_3 = *(int *)(param_1 + 4) +
               ((uint)uVar9 >> 0xc | (int)((ulonglong)uVar9 >> 0x20) << 0x14) +
               ((uint)uVar7 >> 0xc | (int)((ulonglong)uVar7 >> 0x20) << 0x14);
    param_3[1] = *(int *)(param_1 + 8) +
                 ((uint)uVar8 >> 0xc | (int)((ulonglong)uVar8 >> 0x20) << 0x14);
    iVar3 = (int)(*(uint *)(param_1 + DAT_02187aa8) & 0xffff) >> 4;
    iVar4 = (int)*(short *)(DAT_02187aac + (iVar3 * 2 + 1) * 2);
    uVar8 = func_0x02133048(uVar2,(int)uVar2 >> 0x1f,iVar4,iVar4 >> 0x1f);
    iVar3 = (int)*(short *)(DAT_02187aac + iVar3 * 4);
    uVar9 = func_0x02133048(uVar1,(int)uVar1 >> 0x1f,iVar3,iVar3 >> 0x1f);
    param_3[2] = (*(int *)(param_1 + 0xc) +
                 ((uint)uVar8 >> 0xc | (int)((ulonglong)uVar8 >> 0x20) << 0x14)) -
                 ((uint)uVar9 >> 0xc | (int)((ulonglong)uVar9 >> 0x20) << 0x14);
    return;
  case 3:
    iVar3 = func_0x02061808();
    iVar4 = (int)(*(uint *)(param_1 + DAT_02187aa8) & 0xffff) >> 4;
    iVar6 = *(int *)(param_1 + 0xcc + param_2);
    iVar5 = (int)*(short *)(DAT_02187aac + iVar4 * 4);
    uVar8 = func_0x02133048(iVar6,iVar6 >> 0x1f,iVar5,iVar5 >> 0x1f);
    iVar6 = *(int *)(param_1 + 0xc4 + param_2);
    iVar4 = (int)*(short *)(DAT_02187aac + (iVar4 * 2 + 1) * 2);
    uVar9 = func_0x02133048(iVar6,iVar6 >> 0x1f,iVar4,iVar4 >> 0x1f);
    *param_3 = *(int *)(param_1 + 4) + *(int *)(iVar3 + 0x24) +
               ((uint)uVar8 >> 0xc | (int)((ulonglong)uVar8 >> 0x20) << 0x14) +
               ((uint)uVar9 >> 0xc | (int)((ulonglong)uVar9 >> 0x20) << 0x14);
    param_3[1] = *(int *)(param_1 + 8) + *(int *)(iVar3 + 0x28) + *(int *)(param_1 + param_2 + 200);
    iVar4 = (int)(*(uint *)(param_1 + DAT_02187aa8) & 0xffff) >> 4;
    iVar6 = *(int *)(param_1 + 0xcc + param_2);
    iVar5 = (int)*(short *)(DAT_02187aac + (iVar4 * 2 + 1) * 2);
    uVar8 = func_0x02133048(iVar6,iVar6 >> 0x1f,iVar5,iVar5 >> 0x1f);
    iVar6 = *(int *)(param_1 + 0xc4 + param_2);
    iVar4 = (int)*(short *)(DAT_02187aac + iVar4 * 4);
    uVar9 = func_0x02133048(iVar6,iVar6 >> 0x1f,iVar4,iVar4 >> 0x1f);
    param_3[2] = (*(int *)(param_1 + 0xc) + *(int *)(iVar3 + 0x2c) +
                 ((uint)uVar8 >> 0xc | (int)((ulonglong)uVar8 >> 0x20) << 0x14)) -
                 ((uint)uVar9 >> 0xc | (int)((ulonglong)uVar9 >> 0x20) << 0x14);
    *param_3 = *param_3 >> 1;
    param_3[1] = param_3[1] >> 1;
    param_3[2] = param_3[2] >> 1;
    return;
  case 4:
    iVar3 = (int)(*(uint *)(param_1 + DAT_02187aa8) & 0xffff) >> 4;
    iVar4 = *(int *)(param_1 + 0xcc + param_2);
    iVar6 = (int)*(short *)(DAT_02187aac + iVar3 * 4);
    uVar8 = func_0x02133048(iVar4,iVar4 >> 0x1f,iVar6,iVar6 >> 0x1f);
    iVar4 = *(int *)(param_1 + 0xc4 + param_2);
    iVar3 = (int)*(short *)(DAT_02187aac + (iVar3 * 2 + 1) * 2);
    uVar9 = func_0x02133048(iVar4,iVar4 >> 0x1f,iVar3,iVar3 >> 0x1f);
    *param_3 = *(int *)(param_1 + 4) +
               ((uint)uVar8 >> 0xc | (int)((ulonglong)uVar8 >> 0x20) << 0x14) +
               ((uint)uVar9 >> 0xc | (int)((ulonglong)uVar9 >> 0x20) << 0x14);
    param_3[1] = *(int *)(*(int *)(param_1 + 0x9c) + 4) + *(int *)(param_1 + param_2 + 200);
    iVar3 = (int)(*(uint *)(param_1 + DAT_02187aa8) & 0xffff) >> 4;
    iVar4 = *(int *)(param_1 + 0xcc + param_2);
    iVar6 = (int)*(short *)(DAT_02187aac + (iVar3 * 2 + 1) * 2);
    uVar8 = func_0x02133048(iVar4,iVar4 >> 0x1f,iVar6,iVar6 >> 0x1f);
    iVar4 = *(int *)(param_1 + 0xc4 + param_2);
    iVar3 = (int)*(short *)(DAT_02187aac + iVar3 * 4);
    uVar9 = func_0x02133048(iVar4,iVar4 >> 0x1f,iVar3,iVar3 >> 0x1f);
    param_3[2] = (*(int *)(param_1 + 0xc) +
                 ((uint)uVar8 >> 0xc | (int)((ulonglong)uVar8 >> 0x20) << 0x14)) -
                 ((uint)uVar9 >> 0xc | (int)((ulonglong)uVar9 >> 0x20) << 0x14);
    return;
  case 5:
    iVar3 = (int)(*(uint *)(param_1 + DAT_02187aa8) & 0xffff) >> 4;
    iVar4 = *(int *)(param_1 + 0xcc + param_2);
    iVar6 = (int)*(short *)(DAT_02187aac + iVar3 * 4);
    uVar8 = func_0x02133048(iVar4,iVar4 >> 0x1f,iVar6,iVar6 >> 0x1f);
    iVar4 = *(int *)(param_1 + 0xc4 + param_2);
    iVar3 = (int)*(short *)(DAT_02187aac + (iVar3 * 2 + 1) * 2);
    uVar9 = func_0x02133048(iVar4,iVar4 >> 0x1f,iVar3,iVar3 >> 0x1f);
    *param_3 = *(int *)(param_1 + 4) +
               ((uint)uVar8 >> 0xc | (int)((ulonglong)uVar8 >> 0x20) << 0x14) +
               ((uint)uVar9 >> 0xc | (int)((ulonglong)uVar9 >> 0x20) << 0x14);
    iVar3 = func_0x020d3d48(0);
    param_3[1] = *(int *)(param_1 + param_2 + 200) - iVar3;
    iVar3 = (int)(*(uint *)(param_1 + DAT_02187aa8) & 0xffff) >> 4;
    iVar4 = *(int *)(param_1 + 0xcc + param_2);
    iVar6 = (int)*(short *)(DAT_02187aac + (iVar3 * 2 + 1) * 2);
    uVar8 = func_0x02133048(iVar4,iVar4 >> 0x1f,iVar6,iVar6 >> 0x1f);
    iVar4 = *(int *)(param_1 + 0xc4 + param_2);
    iVar3 = (int)*(short *)(DAT_02187af0 + iVar3 * 4);
    uVar9 = func_0x02133048(iVar4,iVar4 >> 0x1f,iVar3,iVar3 >> 0x1f);
    param_3[2] = (*(int *)(param_1 + 0xc) +
                 ((uint)uVar8 >> 0xc | (int)((ulonglong)uVar8 >> 0x20) << 0x14)) -
                 ((uint)uVar9 >> 0xc | (int)((ulonglong)uVar9 >> 0x20) << 0x14);
  }
  return;
}

