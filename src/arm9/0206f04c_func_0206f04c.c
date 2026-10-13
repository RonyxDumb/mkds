/* Decompiled C draft; module arm9; ROM address 0206f04c. No matching claim. */
#include "types.h"
#include "deps/0206f04c_func_0206f04c.h"

undefined4
func_0206f04c(int param_1,uint param_2,int param_3,int param_4,int param_5,int param_6,int param_7)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  short sVar8;
  undefined4 uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  bool bVar13;
  bool bVar14;
  uint local_48;
  uint local_44;
  uint local_40;
  undefined1 auStack_3c [12];
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  
  uVar9 = 0;
  iVar2 = VecFx32_CrossProduct_0(param_1 + 0x5c);
  iVar10 = iVar2 + 0x1000;
  bVar14 = SBORROW4(iVar10,0x1000);
  bVar13 = iVar10 == 0x1000;
  if (0x1000 < iVar10) {
    iVar10 = 0x1000;
  }
  if ((bVar13 || iVar2 < 0 != bVar14) && (iVar10 < 0x29)) {
    iVar10 = 0x29;
  }
  iVar2 = Vector3_DotProduct(param_2,param_1 + 0x2d8);
  uVar4 = param_1 + 0x2d8U & 3;
  uVar11 = *(uint *)(param_1 + 0x2d8U & 0xfffffffc);
  lVar1 = (longlong)
          (int)(*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
               *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) * (longlong)iVar2;
  *(uint *)(param_1 + 0x2d8) =
       (uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20) -
       ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
  uVar4 = param_2 + 4 & 3;
  uVar5 = *(uint *)(param_2 + 4 & 0xfffffffc);
  uVar11 = param_1 + 0x2dcU & 3;
  uVar12 = *(uint *)(param_1 + 0x2dcU & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) * (longlong)iVar2;
  *(uint *)(param_1 + 0x2dc) =
       (uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20) -
       ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
  uVar4 = param_2 + 8 & 3;
  uVar5 = *(uint *)(param_2 + 8 & 0xfffffffc);
  uVar11 = param_1 + 0x2e0U & 3;
  uVar12 = *(uint *)(param_1 + 0x2e0U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) * (longlong)iVar2;
  *(uint *)(param_1 + 0x2e0) =
       (uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20) -
       ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
  iVar2 = Vector3_DotProduct(param_2,param_1 + 0x2e4);
  uVar4 = param_1 + 0x2e4U & 3;
  uVar11 = *(uint *)(param_1 + 0x2e4U & 0xfffffffc);
  lVar1 = (longlong)
          (int)(*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
               *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) * (longlong)iVar2;
  *(uint *)(param_1 + 0x2e4) =
       (uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20) -
       ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
  uVar4 = param_2 + 4 & 3;
  uVar5 = *(uint *)(param_2 + 4 & 0xfffffffc);
  uVar11 = param_1 + 0x2e8U & 3;
  uVar12 = *(uint *)(param_1 + 0x2e8U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) * (longlong)iVar2;
  *(uint *)(param_1 + 0x2e8) =
       (uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20) -
       ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
  uVar4 = param_2 + 8 & 3;
  uVar11 = *(uint *)(param_2 + 8 & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20) * (longlong)iVar2;
  uVar4 = param_1 + 0x2ecU & 3;
  uVar11 = *(uint *)(param_1 + 0x2ecU & 0xfffffffc);
  *(uint *)(param_1 + 0x2ec) =
       (uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20) -
       ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
  *(uint *)(param_1 + 0x38c) =
       (uint)((longlong)param_4 * (longlong)iVar10) >> 0xc |
       (int)((ulonglong)((longlong)param_4 * (longlong)iVar10) >> 0x20) << 0x14;
  iVar2 = VecFx32_CrossProduct_0(param_1 + 0x1fc,param_2);
  if (iVar2 < -0x800) {
    uVar6 = puRam0206f558[1];
    uVar7 = puRam0206f558[2];
    *(undefined4 *)(param_1 + 0x1fc) = *puRam0206f558;
    *(undefined4 *)(param_1 + 0x200) = uVar6;
    *(undefined4 *)(param_1 + 0x204) = uVar7;
  }
  if (param_3 == 0) {
    iVar2 = VecFx32_CrossProduct_0(param_1 + 0x138,param_2);
    uVar9 = 1;
    iVar3 = Vector3_DotProduct(param_2,param_1 + 0xa4);
    lVar1 = (longlong)
            (int)(*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
                 *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) * (longlong)iVar3;
    local_48 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    uVar4 = param_2 + 4 & 3;
    uVar11 = *(uint *)(param_2 + 4 & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20) * (longlong)iVar3;
    local_44 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    uVar4 = param_2 + 8 & 3;
    uVar11 = *(uint *)(param_2 + 8 & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20) * (longlong)iVar3;
    local_40 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    *(undefined4 *)(param_1 + 0x2fc) = 0;
    *(undefined2 *)(param_1 + 0x302) = 0;
    *(undefined2 *)(param_1 + 0x300) = *(undefined2 *)(param_1 + 0x302);
    *(undefined4 *)(param_1 + 0x30c) = 0;
    *(undefined2 *)(param_1 + 0x386) = 0;
    uVar4 = param_1 + 0x2a4U & 3;
    uVar11 = *(uint *)(param_1 + 0x2a4U & 0xfffffffc);
    if (0x1800 < (int)(uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20)) {
      uVar4 = param_1 + 0x48U & 3;
      uVar11 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
      if (((((uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20) & 0x20) == 0) &&
          (((local_48 != 0 || (local_44 != 0)) || (local_40 != 0)))) && (param_4 != 0x1000)) {
        func_020eaa14(&local_48,(uint *)(uintptr_t)(param_2),0,iRam0206f55c,0,&local_48);
        *(uint *)(param_1 + 0x2d8) = local_48;
        *(uint *)(param_1 + 0x2e0) = local_40;
        uVar4 = param_1 + 0x260U & 3;
        uVar11 = *(uint *)(param_1 + 0x260U & 0xfffffffc);
        *(uint *)(param_1 + 0x260) = (uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20) + local_44;
      }
      if (*(short *)(param_1 + 0x4da) < 1) {
        if (-1 < param_5) {
          func_0210b234(param_1,0,param_5,param_6,0);
        }
        if (((param_7 == 2) && (param_6 != 5)) &&
           (uVar4 = param_1 + 0x590U & 3, uVar11 = *(uint *)(param_1 + 0x590U & 0xfffffffc),
           uVar4 = (uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20) + 0x58, uVar11 = uVar4 & 3,
           uVar4 = *(uint *)(uVar4 & 0xfffffffc),
           uVar4 >> uVar11 * 8 == 0 && uVar4 << uVar11 * -8 + 0x20 == 0)) {
          uVar4 = param_1 + 0x7cU & 3;
          uVar11 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
          uVar4 = uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20;
          bVar13 = false;
          if (((uVar4 & 1) == 0) && ((uVar4 & uRam0206f560) != 0)) {
            bVar13 = true;
          }
          if (!bVar13) {
            local_30 = *(undefined4 *)(param_1 + 0x80);
            uStack_2c = *(undefined4 *)(param_1 + 0x84);
            uStack_28 = *(undefined4 *)(param_1 + 0x88);
            uVar4 = param_1 + 0x4cU & 3;
            uVar5 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
            uVar11 = param_1 + 0x1d0U & 3;
            uVar12 = *(uint *)(param_1 + 0x1d0U & 0xfffffffc);
            iVar3 = 0x800;
            if (((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 0x10000) != 0) {
              iVar3 = iRam0206f55c;
            }
            VecFx32_AddScale1(-(uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20),param_2,
                              param_1 + 0x80,&local_30);
            uVar4 = param_1 + 0xc0U & 3;
            uVar11 = *(uint *)(param_1 + 0xc0U & 0xfffffffc);
            lVar1 = (longlong)(int)(uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20) *
                    (longlong)(iVar3 << 4) + 0x800;
            VecFx32_AddScale1((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000,
                              param_1 + 300,(uint)(uintptr_t)(&local_30),&local_30);
            func_0208b748(0x3b,(uint)(uintptr_t)(&local_30),param_1,uRam0206f564);
          }
        }
        DriverContext_SomeFn(param_1,2);
      }
    }
    if (iVar2 < 1) {
      uVar4 = param_1 + 0x2a4U & 3;
      uVar11 = *(uint *)(param_1 + 0x2a4U & 0xfffffffc);
      uVar4 = uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20;
      if ((((0x2000 < (int)uVar4) && (param_4 != 0x1000)) && (0x1800 < (int)uVar4)) &&
         (iRam0206f570 < 0x1000 - iVar10)) {
        lVar1 = (longlong)(int)uVar4 * (longlong)(0x1000 - iVar10);
        sVar8 = (short)((uint)(((int)((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14)
                               >> 0xc) * 0x1e0000) >> 0x10);
        Vector3_Cross(param_1 + 0x5c,param_2,(uint *)(void *)(auStack_3c));
        iVar2 = VecFx32_CrossProduct_0((uint)(uintptr_t)(auStack_3c),param_1 + 300);
        bVar13 = iVar2 < 0;
        if (bVar13) {
          iVar2 = -1;
        }
        if (bVar13) {
          sVar8 = sVar8 * (short)iVar2;
        }
        *(short *)(param_1 + 0x386) = sVar8;
      }
    }
    else {
      *(int *)(param_1 + 0x38c) = iRam0206f55c;
      uVar4 = param_1 + 0x3dcU & 3;
      uVar11 = *(uint *)(param_1 + 0x3dcU & 0xfffffffc);
      uVar4 = uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20;
      if ((uVar4 != 0xb) && (uVar4 != 8)) {
        uVar4 = param_1 + 0x48U & 3;
        uVar11 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
        *(uint *)(param_1 + 0x48) =
             (uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20) & uRam0206f568;
        *(undefined2 *)(param_1 + 0x238) = 0;
        *(undefined2 *)(param_1 + 0x538) = 0;
        *(undefined2 *)(param_1 + 0x23c) = 0;
        uVar4 = param_1 + 0x7cU & 3;
        uVar11 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
        if (((uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20) & 1) != 0) {
          uVar4 = param_1 + 0x4cU & 3;
          uVar11 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
          if ((((uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20) & 0x10000000) == 0) &&
             (uVar4 = param_1 + 0x48U & 3, uVar11 = *(uint *)(param_1 + 0x48U & 0xfffffffc),
             ((uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20) & 0x4000000) == 0)) {
            func_02074854();
          }
          func_02055c5c();
        }
      }
      uVar4 = param_1 + 0x2a4U & 3;
      uVar11 = *(uint *)(param_1 + 0x2a4U & 0xfffffffc);
      uVar4 = uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20;
      if ((0x2000 < (int)uVar4) && (param_4 != 0x1000)) {
        iVar2 = ((int)uVar4 >> 0xc) * 0x640000;
        sVar8 = (short)((uint)iVar2 >> 0x10);
        if (uRam0206f56c < *(ushort *)(param_1 + 0x388)) {
          iVar2 = -1;
        }
        if (uRam0206f56c < *(ushort *)(param_1 + 0x388)) {
          sVar8 = sVar8 * (short)iVar2;
        }
        *(short *)(param_1 + 0x386) = sVar8;
      }
    }
    uVar4 = param_1 + 0x7cU & 3;
    uVar11 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if (((((uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20) & 1) != 0) &&
        (uVar4 = param_1 + 0x2a4U & 3, uVar11 = *(uint *)(param_1 + 0x2a4U & 0xfffffffc),
        0x3000 < (int)(uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20))) && (param_7 == 2)) {
      iVar2 = GetGlobalRK();
      uVar4 = iVar2 + 0x10U & 3;
      uVar11 = *(uint *)(iVar2 + 0x10U & 0xfffffffc);
      *(uint *)(iVar2 + 0x10) = (uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20) + 1;
    }
    *(undefined2 *)(param_1 + 0x388) = 0;
  }
  else if (param_6 == 4) {
    func_020813ec(*(undefined2 *)(param_1 + 0x74),param_2);
  }
  uVar4 = param_1 + 0x180U & 3;
  uVar11 = *(uint *)(param_1 + 0x180U & 0xfffffffc);
  if (uVar11 >> uVar4 * 8 != 0 || uVar11 << uVar4 * -8 + 0x20 != 0) {
    *(undefined2 *)(param_1 + 0x386) = 0;
  }
  return uVar9;
}

