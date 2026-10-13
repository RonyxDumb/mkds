/* Decompiled C draft; module arm9; ROM address 0214ad4c. No matching claim. */
#include "types.h"
#include "deps/0214ad4c_G3i_OrthoW_.h"

void G3i_OrthoW_(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                uint param_7,int param_8,uint *param_9)

{
  int iVar1;
  longlong lVar2;
  uint *puVar3;
  undefined4 *puVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  uint *unaff_r4;
  uint uVar8;
  uint uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  int local_44;
  int local_2c;
  
  FX_InvAsync(param_4 - param_3);
  puVar3 = puRam0214b03c;
  if (param_8 != 0) {
    *puRam0214b038 = 0;
    unaff_r4 = puVar3;
  }
  if (param_9 != (uint *)0x0) {
    param_9[1] = 0;
    param_9[2] = 0;
    param_9[3] = 0;
    param_9[4] = 0;
    param_9[6] = 0;
    param_9[7] = 0;
    param_9[8] = 0;
    param_9[9] = 0;
    param_9[0xb] = 0;
    param_9[0xf] = param_7;
  }
  uVar10 = FX_GetDivResultFx64c();
  puVar4 = puRam0214b040;
  *puRam0214b040 = 0;
  piVar5 = piRam0214b044;
  puVar4[1] = 0x1000;
  *piVar5 = param_1 - param_2;
  piVar5[1] = 0;
  iVar1 = (int)param_7 >> 0x1f;
  if (param_7 != 0x1000) {
    lVar2 = (ulonglong)param_7 * (uVar10 & 0xffffffff);
    uVar10 = func_02132e98((int)lVar2,
                           (int)(uVar10 >> 0x20) * param_7 +
                           (int)uVar10 * iVar1 + (int)((ulonglong)lVar2 >> 0x20));
  }
  local_44 = (int)(uVar10 >> 0x20);
  uVar6 = (int)((uVar10 << 0xd) >> 0x20) + (uint)(0x7fffffff < (uint)(uVar10 << 0xd));
  if (param_8 != 0) {
    *unaff_r4 = uVar6;
    *unaff_r4 = 0;
    *unaff_r4 = 0;
    *unaff_r4 = 0;
    *unaff_r4 = 0;
  }
  if (param_9 != (uint *)0x0) {
    *param_9 = uVar6;
  }
  uVar11 = FX_GetDivResultFx64c();
  puVar4 = puRam0214b040;
  *puRam0214b040 = 0;
  puVar4[1] = 0x1000;
  piVar5 = piRam0214b044;
  *piRam0214b044 = param_5 - param_6;
  piVar5[1] = 0;
  if (param_7 != 0x1000) {
    lVar2 = (ulonglong)param_7 * (uVar11 & 0xffffffff);
    uVar11 = func_02132e98((int)lVar2,
                           (int)(uVar11 >> 0x20) * param_7 +
                           (int)uVar11 * iVar1 + (int)((ulonglong)lVar2 >> 0x20));
  }
  local_2c = (int)(uVar11 >> 0x20);
  uVar6 = (int)((uVar11 << 0xd) >> 0x20) + (uint)(0x7fffffff < (uint)(uVar11 << 0xd));
  if (param_8 != 0) {
    *unaff_r4 = uVar6;
    *unaff_r4 = 0;
    *unaff_r4 = 0;
    *unaff_r4 = 0;
    *unaff_r4 = 0;
  }
  if (param_9 != (uint *)0x0) {
    param_9[5] = uVar6;
  }
  uVar12 = FX_GetDivResultFx64c();
  if (param_7 != 0x1000) {
    lVar2 = (ulonglong)param_7 * (uVar12 & 0xffffffff);
    uVar12 = func_02132e98((int)lVar2,
                           (int)(uVar12 >> 0x20) * param_7 +
                           (int)uVar12 * iVar1 + (int)((ulonglong)lVar2 >> 0x20),0x1000,0);
  }
  uVar6 = (int)((uVar12 << 0xd) >> 0x20) + (uint)(0x7fffffff < (uint)(uVar12 << 0xd));
  if (param_8 != 0) {
    *unaff_r4 = uVar6;
    *unaff_r4 = 0;
  }
  if (param_9 != (uint *)0x0) {
    param_9[10] = uVar6;
  }
  uVar6 = -(param_4 + param_3);
  uVar8 = -(param_1 + param_2);
  uVar7 = param_6 + param_5;
  lVar2 = (ulonglong)uVar6 * (uVar10 & 0xffffffff);
  uVar9 = local_44 * uVar6 + (int)uVar10 * ((int)uVar6 >> 0x1f) + (int)((ulonglong)lVar2 >> 0x20) +
          (uint)(0x7fffffff < (uint)lVar2);
  lVar2 = (ulonglong)uVar8 * (uVar11 & 0xffffffff);
  uVar8 = local_2c * uVar8 + (int)uVar11 * ((int)uVar8 >> 0x1f) + (int)((ulonglong)lVar2 >> 0x20) +
          (uint)(0x7fffffff < (uint)lVar2);
  lVar2 = (ulonglong)uVar7 * (uVar12 & 0xffffffff);
  uVar6 = (int)(uVar12 >> 0x20) * uVar7 +
          (int)uVar12 * ((int)uVar7 >> 0x1f) + (int)((ulonglong)lVar2 >> 0x20) +
          (uint)(0x7fffffff < (uint)lVar2);
  if (param_8 != 0) {
    *unaff_r4 = uVar9;
    *unaff_r4 = uVar8;
    *unaff_r4 = uVar6;
    *unaff_r4 = param_7;
  }
  if (param_9 != (uint *)0x0) {
    param_9[0xc] = uVar9;
    param_9[0xd] = uVar8;
    param_9[0xe] = uVar6;
  }
  return;
}

