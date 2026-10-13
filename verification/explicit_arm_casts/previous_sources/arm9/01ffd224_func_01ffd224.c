/* Decompiled C draft; module arm9; ROM address 01ffd224. No matching claim. */
#include "types.h"
#include "deps/01ffd224_func_01ffd224.h"

void func_01ffd224(uint param_1,uint param_2,undefined4 param_3)

{
  longlong lVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint unaff_r5;
  uint uVar8;
  undefined1 auStack_b8 [12];
  int iStack_ac;
  int iStack_a8;
  int iStack_a4;
  undefined1 auStack_a0 [12];
  int iStack_94;
  int iStack_90;
  uint uStack_8c;
  int iStack_88;
  int iStack_84;
  int iStack_80;
  undefined1 auStack_7c [12];
  int iStack_70;
  int iStack_6c;
  int iStack_68;
  int iStack_64;
  int iStack_60;
  int iStack_5c;
  int iStack_58;
  int iStack_54;
  int iStack_50;
  undefined1 auStack_4c [12];
  int iStack_40;
  int iStack_3c;
  int iStack_38;
  undefined1 auStack_34 [4];
  undefined4 uStack_30;
  
  uVar7 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  uVar8 = uVar7 + 0x180 & 3;
  uVar3 = *(uint *)(uVar7 + 0x180 & 0xfffffffc);
  if (uVar3 >> uVar8 * 8 != 0 || uVar3 << uVar8 * -8 + 0x20 != 0) {
    return;
  }
  uVar8 = uVar7 + 0x44 & 3;
  uVar3 = *(uint *)(uVar7 + 0x44 & 0xfffffffc);
  if (((uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20) & 2) != 0) {
    return;
  }
  uVar8 = uVar7 + 0x4c & 3;
  uVar3 = *(uint *)(uVar7 + 0x4c & 0xfffffffc);
  if (((uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20) & 0x10000000) != 0) {
    return;
  }
  bVar2 = false;
  func_0208c1d0(auStack_b8,&iStack_ac,param_1);
  uVar8 = param_1 + 0xa8 & 3;
  uVar3 = *(uint *)(param_1 + 0xa8 & 0xfffffffc);
  if ((uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20) == 1) {
    iVar4 = Vector3_DotProduct(uVar7 + 300,&iStack_ac);
    uVar8 = uVar7 + 300 & 3;
    uVar3 = *(uint *)(uVar7 + 300 & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20) * (longlong)iVar4;
    iStack_64 = iStack_ac - ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
    uVar8 = uVar7 + 0x130 & 3;
    uVar3 = *(uint *)(uVar7 + 0x130 & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20) * (longlong)iVar4;
    iStack_60 = iStack_a8 - ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
    uVar8 = uVar7 + 0x134 & 3;
    uVar3 = *(uint *)(uVar7 + 0x134 & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20) * (longlong)iVar4;
    iStack_5c = iStack_a4 - ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
    iVar4 = VecFx32_CrossProduct_0(uVar7 + 0x138,&iStack_64);
    if (iRam01ffd630 < iVar4) {
      func_0208c1d0(auStack_a0,&iStack_94,param_1);
      uVar8 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
              *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
      bVar2 = true;
      VecFx32_Subtract(uVar8 + 0x80,auStack_a0,auStack_34);
      uStack_30 = 0;
      StructMQRacerEntry_GetVec555(uVar8,&iStack_58);
      iVar4 = Vector3_DotProduct(&iStack_58,&iStack_94);
      iStack_40 = iStack_94 -
                  ((uint)((longlong)iStack_58 * (longlong)iVar4) >> 0xc |
                  (int)((ulonglong)((longlong)iStack_58 * (longlong)iVar4) >> 0x20) << 0x14);
      iStack_3c = iStack_90 -
                  ((uint)((longlong)iStack_54 * (longlong)iVar4) >> 0xc |
                  (int)((ulonglong)((longlong)iStack_54 * (longlong)iVar4) >> 0x20) << 0x14);
      iStack_38 = uStack_8c -
                  ((uint)((longlong)iStack_50 * (longlong)iVar4) >> 0xc |
                  (int)((ulonglong)((longlong)iStack_50 * (longlong)iVar4) >> 0x20) << 0x14);
      Vector3_Cross(auStack_34,&iStack_40,auStack_4c);
      iVar4 = VecFx32_CrossProduct_0(&iStack_58,auStack_4c);
      unaff_r5 = uStack_8c;
      if (0 < iVar4) {
        unaff_r5 = 1;
      }
      if (iVar4 < 1) {
        unaff_r5 = 0xffffffff;
      }
      *(short *)(uVar7 + 0x236) = (short)unaff_r5 * 200 + *(short *)(uVar7 + 0x236);
      goto LAB_01ffd5f8;
    }
  }
  uVar8 = param_1 + 0x70 & 3;
  uVar3 = *(uint *)(param_1 + 0x70 & 0xfffffffc);
  if (0x2000 < (int)(uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20)) {
    uVar8 = uVar7 + 0x2a4 & 3;
    uVar6 = *(uint *)(uVar7 + 0x2a4 & 0xfffffffc);
    uVar5 = *(uint *)(uRam01ffd634 & 0xfffffffc) >> (uRam01ffd634 & 3) * 8 |
            *(uint *)(uRam01ffd634 & 0xfffffffc) << (uRam01ffd634 & 3) * -8 + 0x20;
    uVar3 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20) *
            (longlong)(int)(uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20);
    uVar8 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    if (0x1000 < (int)uVar8) {
      uVar8 = 0x1000;
    }
    StructMQRacerEntry_GetVec555(uVar7,&iStack_88);
    iVar4 = Vector3_DotProduct(&iStack_88,param_2);
    iStack_70 = (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
                *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) -
                ((uint)((longlong)iStack_88 * (longlong)iVar4) >> 0xc |
                (int)((ulonglong)((longlong)iStack_88 * (longlong)iVar4) >> 0x20) << 0x14);
    uVar3 = param_2 + 4 & 3;
    uVar5 = *(uint *)(param_2 + 4 & 0xfffffffc);
    iStack_6c = (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) -
                ((uint)((longlong)iStack_84 * (longlong)iVar4) >> 0xc |
                (int)((ulonglong)((longlong)iStack_84 * (longlong)iVar4) >> 0x20) << 0x14);
    uVar3 = param_2 + 8 & 3;
    uVar5 = *(uint *)(param_2 + 8 & 0xfffffffc);
    unaff_r5 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
    iStack_68 = unaff_r5 -
                ((uint)((longlong)iStack_80 * (longlong)iVar4) >> 0xc |
                (int)((ulonglong)((longlong)iStack_80 * (longlong)iVar4) >> 0x20) << 0x14);
    Vector3_Cross(param_3,&iStack_70,auStack_7c);
    iVar4 = VecFx32_CrossProduct_0(&iStack_88,auStack_7c);
    if (0 < iVar4) {
      unaff_r5 = 1;
    }
    uVar3 = param_1 + 0x70 & 3;
    uVar5 = *(uint *)(param_1 + 0x70 & 0xfffffffc);
    uVar3 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
    if (iVar4 < 1) {
      unaff_r5 = 0xffffffff;
    }
    lVar1 = (longlong)
            (int)(((int)uVar3 >> 0x1f) * uRam01ffd638 +
                  uVar3 * 0xb6 + (int)((ulonglong)uRam01ffd638 * (ulonglong)uVar3 >> 0x20) +
                 (uint)(0x7fffffff < (uint)((ulonglong)uRam01ffd638 * (ulonglong)uVar3))) *
            (longlong)
            (int)((uint)((ulonglong)uVar8 * 0xa4) >> 0xc |
                 (((int)uVar8 >> 0x1f) * 0xa4 + (int)((ulonglong)uVar8 * 0xa4 >> 0x20)) * 0x100000);
    bVar2 = true;
    *(short *)(uVar7 + 0x236) =
         (short)((int)((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14) >> 0xc) *
         (short)unaff_r5 + *(short *)(uVar7 + 0x236);
  }
  iVar4 = iRam01ffd644;
  uVar8 = uVar7 + 0x4c & 3;
  uVar3 = *(uint *)(uVar7 + 0x4c & 0xfffffffc);
  if ((((((uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20) & 0x8000000) == 0) ||
       (uVar8 = param_1 + 0x70 & 3, uVar3 = *(uint *)(param_1 + 0x70 & 0xfffffffc),
       0x45fff < (int)(uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20))) ||
      (uVar8 = uVar7 + 0x44 & 3, uVar3 = *(uint *)(uVar7 + 0x44 & 0xfffffffc),
      ((uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20) & 0x10) == 0)) ||
     (((uVar8 = uVar7 + 0x48 & 3, uVar3 = *(uint *)(uVar7 + 0x48 & 0xfffffffc),
       ((uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20) & uRam01ffd63c) != 0 ||
       (uVar8 = uVar7 + 0x2a4 & 3, uVar3 = *(uint *)(uVar7 + 0x2a4 & 0xfffffffc),
       (int)(uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20) < 0x3001)) ||
      ((uVar8 = param_1 + 0x90 & 3, uVar3 = *(uint *)(param_1 + 0x90 & 0xfffffffc),
       (uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20) == 2 ||
       (uVar8 = param_1 + 0xa8 & 3, uVar3 = *(uint *)(param_1 + 0xa8 & 0xfffffffc),
       uVar3 >> uVar8 * 8 != 0 || uVar3 << uVar8 * -8 + 0x20 != 0)))))) {
    *(undefined2 *)(param_1 + 0xca) = 0;
    *(undefined2 *)(param_1 + 200) = 0;
  }
  else {
    *(short *)(param_1 + 200) = *(short *)(param_1 + 200) + (short)uRam01ffd640;
    *(short *)(param_1 + 0xca) =
         (short)(*(short *)(iVar4 + ((int)(uint)*(ushort *)(param_1 + 200) >> 4) * 4) * 0xfa +
                 0x800U >> 0xc);
    uVar8 = param_1 + 0xcc & 3;
    uVar3 = *(uint *)(param_1 + 0xcc & 0xfffffffc);
    bVar2 = true;
    *(ushort *)(uVar7 + 0x236) =
         *(short *)(param_1 + 0xca) *
         ((ushort)(uVar3 >> uVar8 * 8) | (ushort)(uVar3 << uVar8 * -8 + 0x20)) +
         *(short *)(uVar7 + 0x236);
  }
LAB_01ffd5f8:
  if (bVar2) {
    if ((int)unaff_r5 < 1) {
      uVar8 = uVar7 + 0x48 & 3;
      uVar3 = *(uint *)(uVar7 + 0x48 & 0xfffffffc);
      *(uint *)(uVar7 + 0x48) = uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20 | 0x10;
    }
    else {
      uVar8 = uVar7 + 0x48 & 3;
      uVar3 = *(uint *)(uVar7 + 0x48 & 0xfffffffc);
      *(uint *)(uVar7 + 0x48) = uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20 | 8;
    }
    return;
  }
  return;
}

