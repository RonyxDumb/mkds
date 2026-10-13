/* Decompiled C draft; module arm9; ROM address 020d80e4. No matching claim. */
#include "types.h"
#include "deps/020d80e4_func_020d80e4.h"

void func_020d80e4(undefined4 *param_1,int param_2,int param_3,int param_4,undefined4 *param_5,
                  undefined4 *param_6,int param_7)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  int *piVar8;
  undefined8 uVar9;
  longlong lVar10;
  longlong lVar11;
  longlong lVar12;
  uint local_74;
  undefined1 auStack_60 [12];
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  int local_30;
  int local_2c;
  int local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  
  uVar5 = 0;
  local_74 = 0;
  uVar3 = param_5[1];
  *param_1 = *param_5;
  param_1[1] = uVar3;
  param_1[2] = param_5[2];
  uVar3 = param_6[1];
  param_1[9] = *param_6;
  param_1[10] = uVar3;
  param_1[0xb] = param_6[2];
  VecFx32_Subtract(param_6,param_5,auStack_60);
  iVar1 = func_020d70ac(auStack_60,&local_54);
  if (iVar1 == 0) {
    param_1[3] = *param_1;
    param_1[4] = param_1[1];
    param_1[5] = param_1[2];
    param_1[6] = param_1[9];
    param_1[7] = param_1[10];
    param_1[8] = param_1[0xb];
    param_1[0xc] = 0;
    param_1[0xd] = 0;
    if (param_3 != 0) {
      uVar3 = puRam020d8448[1];
      puVar7 = puRam020d8448 + 2;
      param_1[0x12] = *puRam020d8448;
      param_1[0x13] = uVar3;
      param_1[0x14] = *puVar7;
      return;
    }
  }
  else {
    iVar4 = iVar1 >> 0x1f;
    if (param_4 == 0) {
      param_1[3] = *param_1;
      param_1[4] = param_1[1];
      param_1[5] = param_1[2];
    }
    else {
      VecFx32_Subtract(param_6,param_4,&local_48);
      iVar2 = func_020d70ac(&local_48,&local_48);
      if (iVar2 == 0) {
        param_1[3] = *param_1;
        param_1[4] = param_1[1];
        param_1[5] = param_1[2];
      }
      else {
        iVar2 = VecFx32_CrossProduct_0(&local_54,&local_48);
        uVar9 = Multiply64(iVar1,iVar4,iRam020d844c - iVar2 >> 1,iRam020d844c - iVar2 >> 0x1f);
        uVar5 = (uint)uVar9 >> 0xc | (int)((ulonglong)uVar9 >> 0x20) << 0x14;
        if (param_2 == 0) {
          iVar6 = iVar1 + uVar5;
          iVar2 = iVar6 >> 0x1f;
          uVar9 = Multiply64(local_48,local_48 >> 0x1f,iVar6,iVar2);
          local_3c = (uint)uVar9 >> 0xc | (int)((ulonglong)uVar9 >> 0x20) << 0x14;
          uVar9 = Multiply64(local_44,local_44 >> 0x1f,iVar6,iVar2);
          local_38 = (uint)uVar9 >> 0xc | (int)((ulonglong)uVar9 >> 0x20) << 0x14;
          uVar9 = Multiply64(local_40,local_40 >> 0x1f,iVar6,iVar2);
          local_34 = (uint)uVar9 >> 0xc | (int)((ulonglong)uVar9 >> 0x20) << 0x14;
        }
        else {
          uVar9 = Multiply64(local_48,local_48 >> 0x1f,iVar1,iVar4);
          local_3c = (uint)uVar9 >> 0xc | (int)((ulonglong)uVar9 >> 0x20) << 0x14;
          uVar9 = Multiply64(local_44,local_44 >> 0x1f,iVar1,iVar4);
          local_38 = (uint)uVar9 >> 0xc | (int)((ulonglong)uVar9 >> 0x20) << 0x14;
          uVar9 = Multiply64(local_40,local_40 >> 0x1f,iVar1,iVar4);
          local_34 = (uint)uVar9 >> 0xc | (int)((ulonglong)uVar9 >> 0x20) << 0x14;
        }
        VecFx32_AddScale1(uRam020d8450,&local_3c,param_1,param_1 + 3);
      }
    }
    if (param_7 == 0) {
      param_1[6] = param_1[9];
      param_1[7] = param_1[10];
      param_1[8] = param_1[0xb];
    }
    else {
      VecFx32_Subtract(param_7,param_5,&local_30);
      iVar2 = func_020d70ac(&local_30,&local_30);
      if (iVar2 == 0) {
        param_1[6] = param_1[9];
        param_1[7] = param_1[10];
        param_1[8] = param_1[0xb];
      }
      else {
        iVar2 = VecFx32_CrossProduct_0(&local_54,&local_30);
        uVar9 = Multiply64(iVar1,iVar4,iRam020d844c - iVar2 >> 1,iRam020d844c - iVar2 >> 0x1f);
        local_74 = (uint)uVar9 >> 0xc | (int)((ulonglong)uVar9 >> 0x20) << 0x14;
        if (param_2 == 0) {
          iVar2 = iVar1 + local_74;
          iVar4 = iVar2 >> 0x1f;
          uVar9 = Multiply64(local_30,local_30 >> 0x1f,iVar2,iVar4);
          local_24 = (uint)uVar9 >> 0xc | (int)((ulonglong)uVar9 >> 0x20) << 0x14;
          uVar9 = Multiply64(local_2c,local_2c >> 0x1f,iVar2,iVar4);
          local_20 = (uint)uVar9 >> 0xc | (int)((ulonglong)uVar9 >> 0x20) << 0x14;
          uVar9 = Multiply64(local_28,local_28 >> 0x1f,iVar2,iVar4);
          local_1c = (uint)uVar9 >> 0xc | (int)((ulonglong)uVar9 >> 0x20) << 0x14;
        }
        else {
          uVar9 = Multiply64(local_30,local_30 >> 0x1f,iVar1,iVar4);
          local_24 = (uint)uVar9 >> 0xc | (int)((ulonglong)uVar9 >> 0x20) << 0x14;
          uVar9 = Multiply64(local_2c,local_2c >> 0x1f,iVar1,iVar4);
          local_20 = (uint)uVar9 >> 0xc | (int)((ulonglong)uVar9 >> 0x20) << 0x14;
          uVar9 = Multiply64(local_28,local_28 >> 0x1f,iVar1,iVar4);
          local_1c = (uint)uVar9 >> 0xc | (int)((ulonglong)uVar9 >> 0x20) << 0x14;
        }
        VecFx32_AddScale1(uRam020d8454,&local_24,param_1 + 9,param_1 + 6);
      }
    }
    param_1[0x10] = iVar1;
    uVar3 = FX_Div(uRam020d8458,param_1[0x10]);
    param_1[0x11] = uVar3;
    param_1[0xe] = local_74 + iVar1 + uVar5;
    uVar3 = FX_Div(uRam020d8458,param_1[0xe]);
    param_1[0xf] = uVar3;
    param_1[0xc] = param_1[0xe];
    param_1[0xd] = param_1[0xf];
    if (param_3 != 0) {
      iVar1 = Vector3_DotProduct(&local_54,piRam020d845c);
      iVar4 = iVar1 >> 0x1f;
      uVar9 = Multiply64(local_54,local_54 >> 0x1f,iVar1,iVar4);
      param_1[0x12] =
           *piRam020d845c - ((uint)uVar9 >> 0xc | (int)((ulonglong)uVar9 >> 0x20) << 0x14);
      uVar9 = Multiply64(local_50,local_50 >> 0x1f,iVar1,iVar4);
      param_1[0x13] =
           piRam020d845c[1] - ((uint)uVar9 >> 0xc | (int)((ulonglong)uVar9 >> 0x20) << 0x14);
      uVar9 = Multiply64(local_4c,local_4c >> 0x1f,iVar1,iVar4);
      param_1[0x14] =
           piRam020d845c[2] - ((uint)uVar9 >> 0xc | (int)((ulonglong)uVar9 >> 0x20) << 0x14);
      iVar1 = param_1[0x13];
      iVar2 = param_1[0x12];
      iVar4 = param_1[0x14];
      lVar10 = Multiply64(iVar4,iVar4 >> 0x1f,iVar4,iVar4 >> 0x1f);
      lVar11 = Multiply64(iVar2,iVar2 >> 0x1f,iVar2,iVar2 >> 0x1f);
      lVar12 = Multiply64(iVar1,iVar1 >> 0x1f,iVar1,iVar1 >> 0x1f);
      lVar10 = lVar10 + lVar11 + lVar12;
      if ((int)((ulonglong)lVar10 >> 0x20) < (int)(uint)((uint)lVar10 < 0x10)) {
        iVar1 = 0;
      }
      else {
        iVar1 = Vector3_MaybeNormalize(param_1 + 0x12,param_1 + 0x12);
      }
      if (iVar1 == 0) {
        iVar1 = piRam020d845c[1];
        piVar8 = piRam020d845c + 2;
        param_1[0x12] = *piRam020d845c;
        param_1[0x13] = iVar1;
        param_1[0x14] = *piVar8;
      }
    }
  }
  return;
}

