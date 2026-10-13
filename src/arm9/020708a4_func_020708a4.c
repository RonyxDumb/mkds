/* Decompiled C draft; module arm9; ROM address 020708a4. No matching claim. */
#include "types.h"
#include "deps/020708a4_func_020708a4.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void func_020708a4(int param_1)

{
  longlong lVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  uint local_e4;
  uint local_e0;
  uint local_dc;
  uint local_d8;
  uint local_d4;
  uint local_d0;
  undefined4 local_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  int local_c0;
  int local_bc;
  int local_b8;
  undefined1 auStack_b4 [12];
  undefined1 auStack_a8 [12];
  undefined1 auStack_9c [4];
  undefined4 local_98;
  int local_90 [3];
  undefined1 auStack_84 [12];
  undefined1 auStack_78 [36];
  uint local_54;
  uint local_50;
  uint local_4c;
  undefined1 auStack_48 [36];
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  uVar11 = *(uint *)(uRam02070f48 & 0xfffffffc) >> (uRam02070f48 & 3) * 8 |
           *(uint *)(uRam02070f48 & 0xfffffffc) << (uRam02070f48 & 3) * -8 + 0x20;
  uVar4 = uVar11 + 0xfc & 3;
  uVar9 = *(uint *)(uVar11 + 0xfc & 0xfffffffc);
  uVar5 = uVar11 + 0x34 & 3;
  uVar3 = *(uint *)(uVar11 + 0x34 & 0xfffffffc);
  iVar10 = (uint)*(ushort *)(uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20) * 0x1c;
  uVar4 = (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) + iVar10;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  local_e4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar4 = uVar11 + 0x34 & 3;
  uVar5 = *(uint *)(uVar11 + 0x34 & 0xfffffffc);
  uVar4 = (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) + iVar10 + 4;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  local_e0 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar4 = uVar11 + 0x34 & 3;
  uVar5 = *(uint *)(uVar11 + 0x34 & 0xfffffffc);
  uVar4 = (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) + iVar10 + 8;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  local_dc = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar4 = uVar11 + 0xfc & 3;
  uVar9 = *(uint *)(uVar11 + 0xfc & 0xfffffffc);
  uVar5 = uVar11 + 0x34 & 3;
  uVar3 = *(uint *)(uVar11 + 0x34 & 0xfffffffc);
  iVar12 = (uint)*(ushort *)(uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20) * 0x1c +
           (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20);
  uVar4 = iVar12 + 0xcU & 3;
  uVar5 = *(uint *)(iVar12 + 0xcU & 0xfffffffc);
  local_d8 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  uVar4 = iVar12 + 0x10U & 3;
  uVar5 = *(uint *)(iVar12 + 0x10U & 0xfffffffc);
  local_d4 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  iVar10 = (int)((((int)local_d4 >> 0x1f) * uRam02070f50 +
                  local_d4 * 0xb6 + (int)((ulonglong)uRam02070f50 * (ulonglong)local_d4 >> 0x20) +
                 (uint)(0x7fffffff < (uint)((ulonglong)uRam02070f50 * (ulonglong)local_d4))) * 0x10
                >> 0x10) >> 4;
  uVar4 = iVar12 + 0x14U & 3;
  uVar5 = *(uint *)(iVar12 + 0x14U & 0xfffffffc);
  local_d0 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  MTX_RotY33__from_thumb
            ((undefined4 *)(void *)(auStack_48),(int)*(short *)(iRam02070f54 + iVar10 * 4),
             (int)*(short *)(iRam02070f54 + (iVar10 * 2 + 1) * 2));
  MTX_MultVec33(uRam02070f58,(uint)(uintptr_t)(auStack_48),(uint *)(void *)(auStack_b4));
  func_021035ac(*(undefined2 *)(param_1 + 0x74));
  uVar4 = param_1 + 0x4cU & 3;
  uVar5 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  uVar4 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  if ((((uVar4 & 0x20000) == 0) && ((uVar4 & 0x8000000) != 0)) &&
     (*(short *)(param_1 + iRam02070f5c + 0x1c) < 0x191)) {
    *(undefined2 *)(param_1 + iRam02070f5c + 0x1c) = 400;
    uVar4 = param_1 + 0x4cU & 3;
    uVar5 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    *(uint *)(param_1 + 0x4c) = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20 | 0x20000;
    uVar6 = func_0207a134();
    uVar7 = func_0207a11c();
    uVar8 = func_0207a104();
    uVar4 = param_1 + 0x590U & 3;
    uVar5 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
    CharacterKartContext_SomeFn_1_0
              (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20,uVar6,uVar7,uVar8);
  }
  uVar4 = param_1 + 0x4cU & 3;
  uVar5 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if (((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 0x8000000) != 0) {
    StructMQRacerEntry_SomeFn_40(param_1);
  }
  uVar4 = param_1 + 0x4cU & 3;
  uVar5 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  uVar4 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  if ((uVar4 & 0x10000000) == 0) {
    if ((uVar4 & 0x80) != 0) {
      StructMQRacerEntry_SomeFn_82(param_1);
    }
    uVar4 = param_1 + 0x4cU & 3;
    uVar5 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    if (((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 0x10000) != 0) {
      StructMQRacerEntry_SomeFn_81(param_1);
    }
    uVar4 = param_1 + 0x7cU & 3;
    uVar5 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if (((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & uRam02070f60) != 0) {
      StructMQRacerEntry_SomeFn_80(param_1);
    }
  }
  else {
    StructMQRacerEntry_SomeFn_79(param_1);
  }
  uVar4 = param_1 + 0x4cU & 3;
  uVar5 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if (((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 0x2000) != 0) {
    uVar4 = param_1 + 0x7cU & 3;
    uVar5 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    iVar10 = param_1 + iRam02070f5c;
    if (((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 1) != 0) {
      uVar6 = GetAED0PlayerUnk(*(undefined2 *)(param_1 + 0x74));
      func_0210ddf4(uRam02070f64,uVar6,uRam02070f68,param_1,0xa3);
    }
    *(short *)(iVar10 + 10) = *(short *)(iVar10 + 10) + 1;
    if ((0xb4 < *(short *)(iVar10 + 10)) &&
       (uVar4 = param_1 + 0x4cU & 3, uVar5 = *(uint *)(param_1 + 0x4cU & 0xfffffffc),
       ((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 0x2000) != 0)) {
      uVar4 = param_1 + 0x4cU & 3;
      uVar5 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
      *(uint *)(param_1 + 0x4c) = (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 0xffffdfff;
      *(undefined4 *)(param_1 + 0xd8) = 0x1000;
      uVar4 = param_1 + 0x4cU & 3;
      uVar5 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
      if (((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 0x8000000) == 0) {
        StructMQRacerEntry_SomeFn_2(param_1);
      }
      StructMQRacerEntry_SomeFn_3(param_1);
    }
  }
  uVar4 = param_1 + 0x4cU & 3;
  uVar5 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if (((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 0x40) != 0) {
    iVar10 = param_1 + iRam02070f5c;
    func_0208181c(*(undefined2 *)(param_1 + 0x74));
    uVar4 = param_1 + 0x7cU & 3;
    uVar5 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if ((((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 0x10) != 0) &&
       (uVar4 = param_1 + 0x590U & 3, uVar5 = *(uint *)(param_1 + 0x590U & 0xfffffffc),
       uVar4 = (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) + 8, uVar5 = uVar4 & 3,
       uVar4 = *(uint *)(uVar4 & 0xfffffffc),
       *(short *)((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x1a) == 0)) {
      DriverContext_UpdateCharacterAnimation(param_1,2,1);
    }
    iVar12 = iRam02070f6c;
    *(short *)(iVar10 + 6) = *(short *)(iVar10 + 6) + 1;
    if (iVar12 < *(short *)(iVar10 + 6)) {
      uVar4 = param_1 + 0x4cU & 3;
      uVar5 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
      *(uint *)(param_1 + 0x4c) = (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 0xffffffbf;
      func_0207b1a8(param_1);
      *(undefined4 *)(param_1 + 0x29c) = 0;
      func_020817b8(*(undefined2 *)(param_1 + 0x74));
      DriverContext_UpdateCharacterAnimation(param_1,0,1);
      uVar4 = param_1 + 0x7cU & 3;
      uVar5 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
      if ((((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 1) != 0) &&
         (uVar4 = (*(uint *)(uRam02070f70 & 0xfffffffc) >> (uRam02070f70 & 3) * 8 |
                  *(uint *)(uRam02070f70 & 0xfffffffc) << (uRam02070f70 & 3) * -8 + 0x20) + 0xc,
         uVar5 = uVar4 & 3, uVar4 = *(uint *)(uVar4 & 0xfffffffc),
         uVar4 >> uVar5 * 8 == 0 && uVar4 << uVar5 * -8 + 0x20 == 0)) {
        func_02106dc8();
      }
      uVar4 = param_1 + 0x4cU & 3;
      uVar5 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
      if (((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 0x2000) != 0) {
        StructMQRacerEntry_SomeFn_36(param_1);
      }
    }
  }
  uVar6 = uRam02070f7c;
  uVar4 = param_1 + 0x78U & 3;
  uVar5 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
  *(short *)(iRam02070f78 + (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) * 0x5c) =
       (short)uRam02070f74;
  Vector3_Cross(uVar6,(uint)(uintptr_t)(auStack_b4),(uint *)(void *)(auStack_a8));
  VecFx32_Subtract(param_1 + 0x80,(uint)(uintptr_t)(&local_e4),(int *)(void *)(auStack_9c));
  local_98 = 0;
  uVar6 = VecFx32_CrossProduct_0((uint)(uintptr_t)(auStack_a8),(uint)(uintptr_t)(auStack_9c));
  VecFx32_AddScale1(uVar6,(uint)(uintptr_t)(auStack_a8),(uint)(uintptr_t)(&local_e4),&local_e4);
  VecFx32_CrossProduct_0((uint)(uintptr_t)(auStack_a8),(uint)(uintptr_t)(auStack_9c));
  VecFx32_Subtract((uint)(uintptr_t)(&local_e4),param_1 + 0x80,&local_c0);
  uVar4 = 0;
  lVar1 = (longlong)local_b8 * (longlong)local_b8 +
          (longlong)local_c0 * (longlong)local_c0 + (longlong)local_bc * (longlong)local_bc;
  if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
    uVar4 = Vector3_MaybeNormalize((uint)(uintptr_t)(&local_c0),&local_c0);
  }
  iVar10 = VecFx32_CrossProduct_0((uint)(uintptr_t)(&local_c0),(uint)(uintptr_t)(auStack_b4));
  if (iVar10 < 1) {
    func_02055c5c();
    uVar5 = param_1 + 0x48U & 3;
    uVar3 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
    *(uint *)(param_1 + 0x48) = (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) & 0xfffeffff;
    func_01ffa11c(param_1,param_1 + 0x244);
    uVar5 = param_1 + 0x48U & 3;
    uVar3 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
    *(uint *)(param_1 + 0x48) = (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) & 0xfffbffff;
    *(short *)(param_1 + 1000) =
         (short)((((local_d8 << 0xe) >> 0xc | (local_d8 >> 0x12) << 0x14) << 4) >> 0x10) + 0x32;
    uVar5 = param_1 + 0x7cU & 3;
    uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if ((((uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) & 1) != 0) &&
       (uVar3 = *(uint *)(uRam02070f70 & 0xfffffffc) >> (uRam02070f70 & 3) * 8 |
                *(uint *)(uRam02070f70 & 0xfffffffc) << (uRam02070f70 & 3) * -8 + 0x20,
       uVar5 = uVar3 & 3, uVar3 = *(uint *)(uVar3 & 0xfffffffc),
       (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) == 0x13)) {
      uVar6 = func_02108e6c(7);
      func_0212c6f0(uVar6,0x14);
    }
  }
  else {
    if (0x64000 < (int)uVar4) {
      *(int *)(param_1 + 0x50) = local_c0;
      *(int *)(param_1 + 0x54) = local_bc;
      *(int *)(param_1 + 0x58) = local_b8;
    }
    local_90[0] = *(int *)(param_1 + 0x50);
    local_90[2] = *(int *)(param_1 + 0x58);
    local_90[1] = 0;
    *(undefined4 *)(param_1 + 0x3a8) = 0x1000;
    lVar1 = (longlong)local_90[2] * (longlong)local_90[2] +
            (longlong)local_90[0] * (longlong)local_90[0];
    if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
      Vector3_MaybeNormalize(local_90,local_90);
    }
    uVar5 = func_02148538(local_90[0],local_90[2]);
    puVar2 = puRam02070f84;
    *(short *)(param_1 + 0x236) =
         (short)((int)((uint)((ulonglong)uRam02070f80 * (ulonglong)uVar5) >> 0xc |
                      (((int)uVar5 >> 0x1f) * uRam02070f80 +
                      (int)((ulonglong)uRam02070f80 * (ulonglong)uVar5 >> 0x20)) * 0x100000) >> 0xc)
    ;
    local_24 = *puVar2;
    uStack_20 = puVar2[1];
    uStack_1c = puVar2[2];
    func_01ffd190(&local_24,*(undefined2 *)(param_1 + 0x236),param_1 + 0xe0);
    Vector3_Cross(uRam02070f7c,param_1 + 0x50,auStack_84);
    Vector3_Cross(param_1 + 0x50,auStack_84,&local_cc);
    iVar10 = iRam02070f88;
    if ((iRam02070f88 < *(short *)(param_1 + 0x234)) &&
       (*(short *)(param_1 + 0x234) = *(short *)(param_1 + 0x234) + -300,
       *(short *)(param_1 + 0x234) < iVar10)) {
      *(short *)(param_1 + 0x234) = (short)iVar10;
    }
    iVar10 = (int)(uint)*(ushort *)(param_1 + 0x234) >> 4;
    func_02146f98(auStack_78,param_1 + 0x120,(int)*(short *)(iRam02070f54 + iVar10 * 4),
                  (int)*(short *)(iRam02070f54 + (iVar10 * 2 + 1) * 2));
    MTX_MultVec33(&local_cc,auStack_78,&local_cc);
    *(undefined4 *)(param_1 + 0x244) = local_cc;
    *(undefined4 *)(param_1 + 0x248) = uStack_c8;
    *(undefined4 *)(param_1 + 0x24c) = uStack_c4;
    func_01ff9f60(param_1,&local_cc);
  }
  *(undefined4 *)(param_1 + 0x2a8) = 0x1e000;
  uVar5 = param_1 + 0x2a8U & 3;
  uVar3 = *(uint *)(param_1 + 0x2a8U & 0xfffffffc);
  uVar3 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
  uVar5 = param_1 + 0x50U & 3;
  uVar9 = *(uint *)(param_1 + 0x50U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20) * (longlong)(int)uVar3;
  local_54 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar5 = param_1 + 0x54U & 3;
  uVar9 = *(uint *)(param_1 + 0x54U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20) * (longlong)(int)uVar3;
  local_50 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar5 = param_1 + 0x58U & 3;
  uVar9 = *(uint *)(param_1 + 0x58U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20) * (longlong)(int)uVar3;
  local_4c = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(param_1 + 0x6c) = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(param_1 + 0x58);
  if (((int)uVar4 < 0x3e8000) &&
     (uVar5 = param_1 + 0x2a8U & 3, uVar3 = *(uint *)(param_1 + 0x2a8U & 0xfffffffc),
     iVar10 = ((uint)((ulonglong)uVar4 * 0x29) >> 0xc |
              (((int)uVar4 >> 0x1f) * 0x29 + (int)((ulonglong)uVar4 * 0x29 >> 0x20)) * 0x100000) +
              0x14000, iVar10 < (int)(uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20))) {
    *(int *)(param_1 + 0x2a8) = iVar10;
  }
  *(uint *)(param_1 + 0xa4) = local_54;
  *(uint *)(param_1 + 0xa8) = local_50;
  *(uint *)(param_1 + 0xac) = local_4c;
  VecFx32_Add(param_1 + 0x80,(uint *)(param_1 + 0xa4),param_1 + 0x80);
  return;
}

