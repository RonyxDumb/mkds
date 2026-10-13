/* Decompiled C draft; module arm9; ROM address 0214b048. No matching claim. */
#include "types.h"
#include "deps/0214b048_G3i_FrustumW_.h"

void G3i_FrustumW_(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                  uint param_7,int param_8,int *param_9)

{
  longlong lVar1;
  longlong lVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int *unaff_r4;
  uint uVar10;
  uint uVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  
  FX_InvAsync(param_4 - param_3);
  piVar3 = piRam0214b32c;
  if (param_8 != 0) {
    *puRam0214b328 = 0;
    unaff_r4 = piVar3;
  }
  if (param_9 != (int *)0x0) {
    param_9[1] = 0;
    param_9[2] = 0;
    param_9[3] = 0;
    param_9[4] = 0;
    param_9[6] = 0;
    param_9[7] = 0;
    param_9[0xb] = -param_7;
    param_9[0xc] = 0;
    param_9[0xd] = 0;
    param_9[0xf] = 0;
  }
  uVar10 = param_5 * 2;
  uVar12 = FX_GetDivResultFx64c();
  puVar4 = puRam0214b330;
  *puRam0214b330 = 0;
  piVar3 = piRam0214b334;
  puVar4[1] = 0x1000;
  *piVar3 = param_1 - param_2;
  piVar3[1] = 0;
  iVar9 = (int)param_7 >> 0x1f;
  if (param_7 != 0x1000) {
    lVar1 = (ulonglong)param_7 * (uVar12 & 0xffffffff);
    uVar12 = func_02132e98((int)lVar1,
                           (int)(uVar12 >> 0x20) * param_7 +
                           (int)uVar12 * iVar9 + (int)((ulonglong)lVar1 >> 0x20));
  }
  iVar6 = (int)(uVar12 >> 0x20);
  lVar1 = (ulonglong)uVar10 * (uVar12 & 0xffffffff);
  iVar5 = iVar6 * uVar10 + (int)uVar12 * ((int)uVar10 >> 0x1f) + (int)((ulonglong)lVar1 >> 0x20) +
          (uint)(0x7fffffff < (uint)lVar1);
  if (param_8 != 0) {
    *unaff_r4 = iVar5;
    *unaff_r4 = 0;
    *unaff_r4 = 0;
    *unaff_r4 = 0;
  }
  if (param_9 != (int *)0x0) {
    *param_9 = iVar5;
  }
  uVar13 = FX_GetDivResultFx64c();
  puVar4 = puRam0214b330;
  *puRam0214b330 = 0;
  puVar4[1] = 0x1000;
  piVar3 = piRam0214b334;
  *piRam0214b334 = param_5 - param_6;
  piVar3[1] = 0;
  if (param_7 != 0x1000) {
    lVar1 = (ulonglong)param_7 * (uVar13 & 0xffffffff);
    uVar13 = func_02132e98((int)lVar1,
                           (int)(uVar13 >> 0x20) * param_7 +
                           (int)uVar13 * iVar9 + (int)((ulonglong)lVar1 >> 0x20));
  }
  iVar5 = (int)(uVar13 >> 0x20);
  lVar1 = (ulonglong)uVar10 * (uVar13 & 0xffffffff);
  iVar7 = iVar5 * uVar10 + (int)uVar13 * ((int)uVar10 >> 0x1f) + (int)((ulonglong)lVar1 >> 0x20) +
          (uint)(0x7fffffff < (uint)lVar1);
  if (param_8 != 0) {
    *unaff_r4 = 0;
    *unaff_r4 = iVar7;
    *unaff_r4 = 0;
    *unaff_r4 = 0;
  }
  if (param_9 != (int *)0x0) {
    param_9[5] = iVar7;
  }
  uVar11 = param_4 + param_3;
  lVar1 = (ulonglong)uVar11 * (uVar12 & 0xffffffff);
  uVar8 = param_1 + param_2;
  lVar2 = (ulonglong)uVar8 * (uVar13 & 0xffffffff);
  iVar6 = iVar6 * uVar11 + (int)uVar12 * ((int)uVar11 >> 0x1f) + (int)((ulonglong)lVar1 >> 0x20) +
          (uint)(0x7fffffff < (uint)lVar1);
  iVar5 = iVar5 * uVar8 + (int)uVar13 * ((int)uVar8 >> 0x1f) + (int)((ulonglong)lVar2 >> 0x20) +
          (uint)(0x7fffffff < (uint)lVar2);
  if (param_8 != 0) {
    *unaff_r4 = iVar6;
    *unaff_r4 = iVar5;
  }
  if (param_9 != (int *)0x0) {
    param_9[8] = iVar6;
    param_9[9] = iVar5;
  }
  uVar12 = FX_GetDivResultFx64c();
  if (param_7 != 0x1000) {
    lVar1 = (ulonglong)param_7 * (uVar12 & 0xffffffff);
    uVar12 = func_02132e98((int)lVar1,
                           (int)(uVar12 >> 0x20) * param_7 +
                           (int)uVar12 * iVar9 + (int)((ulonglong)lVar1 >> 0x20),0x1000,0);
  }
  iVar9 = (int)(uVar12 >> 0x20);
  uVar8 = param_6 + param_5;
  lVar1 = (ulonglong)uVar8 * (uVar12 & 0xffffffff);
  iVar5 = iVar9 * uVar8 + (int)uVar12 * ((int)uVar8 >> 0x1f) + (int)((ulonglong)lVar1 >> 0x20) +
          (uint)(0x7fffffff < (uint)lVar1);
  lVar1 = (longlong)(int)uVar10 * (longlong)param_6 + 0x800;
  uVar10 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000;
  lVar1 = (ulonglong)uVar10 * (uVar12 & 0xffffffff);
  iVar9 = iVar9 * uVar10 + (int)uVar12 * ((int)uVar10 >> 0x1f) + (int)((ulonglong)lVar1 >> 0x20) +
          (uint)(0x7fffffff < (uint)lVar1);
  if (param_8 != 0) {
    *unaff_r4 = iVar5;
    *unaff_r4 = -param_7;
    *unaff_r4 = 0;
    *unaff_r4 = 0;
    *unaff_r4 = iVar9;
    *unaff_r4 = 0;
  }
  if (param_9 != (int *)0x0) {
    param_9[10] = iVar5;
    param_9[0xe] = iVar9;
  }
  return;
}

