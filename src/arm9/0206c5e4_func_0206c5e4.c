/* Decompiled C draft; module arm9; ROM address 0206c5e4. No matching claim. */
#include "types.h"
#include "deps/0206c5e4_func_0206c5e4.h"

void func_0206c5e4(int param_1)

{
  longlong lVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 *puVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  undefined1 auStack_20 [12];
  
  uVar8 = param_1 + 0x44U & 3;
  uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  uVar2 = uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20;
  uVar8 = param_1 + 0x7cU & 3;
  uVar7 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) & 0x400) != 0) {
    return;
  }
  uVar8 = param_1 + 0x380U & 3;
  uVar7 = *(uint *)(param_1 + 0x380U & 0xfffffffc);
  if ((4 < (uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20)) && ((uVar2 & 0x1a) == 0)) {
    uVar8 = param_1 + 0x78U & 3;
    uVar7 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
    if ((*(ushort *)(iRam0206cc18 + (uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) * 0x5c) &
        0x100) == 0) {
      uVar8 = param_1 + 0x44U & 3;
      uVar7 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
      *(uint *)(param_1 + 0x44) = (uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) & 0xfffffffe;
    }
    else if (((uVar2 & 1) == 0) &&
            (uVar8 = param_1 + 0x2c4U & 3, uVar7 = *(uint *)(param_1 + 0x2c4U & 0xfffffffc),
            uVar7 >> uVar8 * 8 == 0 && uVar7 << uVar8 * -8 + 0x20 == 0)) {
      uVar8 = param_1 + 0x48U & 3;
      uVar7 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
      uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
      if ((uVar8 & 0x10) == 0) {
        if ((uVar8 & 8) != 0) {
          *(undefined4 *)(param_1 + 0x2c4) = 0xffffffff;
          uVar8 = param_1 + 0x44U & 3;
          uVar7 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
          *(uint *)(param_1 + 0x44) = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20 | 1;
        }
      }
      else {
        *(undefined4 *)(param_1 + 0x2c4) = 1;
        uVar8 = param_1 + 0x44U & 3;
        uVar7 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
        *(uint *)(param_1 + 0x44) = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20 | 1;
      }
    }
  }
  uVar8 = param_1 + 0x44U & 3;
  uVar7 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  if ((((uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) & 2) != 0) &&
     (uVar8 = param_1 + 0x2c4U & 3, uVar7 = *(uint *)(param_1 + 0x2c4U & 0xfffffffc),
     uVar7 >> uVar8 * 8 == 0 && uVar7 << uVar8 * -8 + 0x20 == 0)) {
    uVar8 = param_1 + 0x48U & 3;
    uVar7 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
    uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
    if ((uVar8 & 0x10) == 0) {
      if ((uVar8 & 8) != 0) {
        *(undefined4 *)(param_1 + 0x2c4) = 0xffffffff;
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x2c4) = 1;
    }
  }
  uVar8 = param_1 + 0x44U & 3;
  uVar7 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  uVar7 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
  uVar8 = param_1 + 0x2c4U & 3;
  uVar13 = *(uint *)(param_1 + 0x2c4U & 0xfffffffc);
  uVar8 = uVar13 >> uVar8 * 8 | uVar13 << uVar8 * -8 + 0x20;
  if (((uVar7 & 8) == 0) && ((uVar7 & 0x10) != 0)) {
    if (((uVar7 & 3) == 0) ||
       (((uVar7 = param_1 + 0x2ccU & 3, uVar13 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc),
         uVar7 = (uVar13 >> uVar7 * 8 | uVar13 << uVar7 * -8 + 0x20) + 0x10, uVar13 = uVar7 & 3,
         uVar7 = *(uint *)(uVar7 & 0xfffffffc),
         uVar11 = uVar7 >> uVar13 * 8 | uVar7 << uVar13 * -8 + 0x20,
         lVar1 = (ulonglong)uRam0206cc1c * (ulonglong)uVar11, uVar7 = param_1 + 0x2a4U & 3,
         uVar13 = *(uint *)(param_1 + 0x2a4U & 0xfffffffc),
         (int)(uVar13 >> uVar7 * 8 | uVar13 << uVar7 * -8 + 0x20) <=
         (int)((uint)lVar1 >> 0xc |
              (((int)uVar11 >> 0x1f) * uRam0206cc1c + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000)
         || (uVar8 == 0)) ||
        (uVar7 = param_1 + 0x78U & 3, uVar13 = *(uint *)(param_1 + 0x78U & 0xfffffffc),
        (*(ushort *)(iRam0206cc18 + (uVar13 >> uVar7 * 8 | uVar13 << uVar7 * -8 + 0x20) * 0x5c) &
        0x100) == 0)))) {
      *(undefined4 *)(param_1 + 0x2c4) = 0;
    }
    else {
      uVar7 = param_1 + 0x44U & 3;
      uVar13 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
      *(uint *)(param_1 + 0x44) = uVar13 >> uVar7 * 8 | uVar13 << uVar7 * -8 + 0x20 | 8;
      *(undefined4 *)(param_1 + 0x2fc) = 1;
      iVar4 = iRam0206cc20;
      uVar7 = param_1 + 0x2c4U & 3;
      uVar13 = *(uint *)(param_1 + 0x2c4U & 0xfffffffc);
      if ((int)(uVar13 >> uVar7 * 8 | uVar13 << uVar7 * -8 + 0x20) < 1) {
        *(int *)(param_1 + 0x304) = param_1 + iRam0206cc20;
        *(int *)(param_1 + 0x308) = param_1 + 0x300;
      }
      else {
        *(int *)(param_1 + 0x304) = param_1 + 0x300;
        *(int *)(param_1 + 0x308) = param_1 + iVar4;
      }
      uVar7 = param_1 + 0x4cU & 3;
      uVar13 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
      if (((uVar13 >> uVar7 * 8 | uVar13 << uVar7 * -8 + 0x20) & 0x8000) != 0) {
        uVar3 = func_0208c5b8(*(undefined2 *)(param_1 + 0x74));
        func_0208ccf0();
        func_0208d6b0(uVar3);
      }
    }
    uVar7 = param_1 + 0x44U & 3;
    uVar13 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    *(uint *)(param_1 + 0x44) = (uVar13 >> uVar7 * 8 | uVar13 << uVar7 * -8 + 0x20) & uRam0206cc24;
  }
  uVar7 = param_1 + 0x44U & 3;
  uVar13 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  uVar7 = uVar13 >> uVar7 * 8 | uVar13 << uVar7 * -8 + 0x20;
  if ((uVar7 & 8) != 0) {
    uVar13 = param_1 + 0x78U & 3;
    uVar11 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
    if ((((*(ushort *)(iRam0206cc18 + (uVar11 >> uVar13 * 8 | uVar11 << uVar13 * -8 + 0x20) * 0x5c)
          & 0x100) == 0) ||
        (uVar13 = param_1 + 0x48U & 3, uVar11 = *(uint *)(param_1 + 0x48U & 0xfffffffc),
        ((uVar11 >> uVar13 * 8 | uVar11 << uVar13 * -8 + 0x20) & 2) == 0)) ||
       ((uVar13 = param_1 + 0x2ccU & 3, uVar9 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc),
        uVar11 = param_1 + 0x2a4U & 3, uVar12 = *(uint *)(param_1 + 0x2a4U & 0xfffffffc),
        uVar13 = (uVar9 >> uVar13 * 8 | uVar9 << uVar13 * -8 + 0x20) + 0x10, uVar9 = uVar13 & 3,
        uVar13 = *(uint *)(uVar13 & 0xfffffffc),
        (int)(uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20) <
        (int)(uVar13 >> uVar9 * 8 | uVar13 << uVar9 * -8 + 0x20) / 2 ||
        ((uVar7 & uRam0206cc28) != 0)))) {
      if ((uVar7 & 0x10) == 0) {
        uVar7 = param_1 + 0x44U & 3;
        uVar13 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
        *(uint *)(param_1 + 0x44) = uVar13 >> uVar7 * 8 | uVar13 << uVar7 * -8 + 0x20 | 0x8000;
      }
      uVar7 = param_1 + 0x2fcU & 3;
      uVar13 = *(uint *)(param_1 + 0x2fcU & 0xfffffffc);
      if ((uVar13 >> uVar7 * 8 | uVar13 << uVar7 * -8 + 0x20) == 4) {
        uVar7 = param_1 + 0x2ccU & 3;
        uVar13 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc);
        DriverContext_MaybeApplyBoost
                  (param_1,1,
                   (int)*(short *)((uVar13 >> uVar7 * 8 | uVar13 << uVar7 * -8 + 0x20) + 0xe));
        uVar7 = param_1 + 0x48U & 3;
        uVar13 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
        *(uint *)(param_1 + 0x48) = uVar13 >> uVar7 * 8 | uVar13 << uVar7 * -8 + 0x20 | 0x80000;
        uVar7 = param_1 + 0x2ccU & 3;
        uVar13 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc);
        *(undefined2 *)(param_1 + 0x23c) =
             *(undefined2 *)((uVar13 >> uVar7 * 8 | uVar13 << uVar7 * -8 + 0x20) + 0xe);
        uVar7 = param_1 + 0x7cU & 3;
        uVar13 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
        if (((uVar13 >> uVar7 * 8 | uVar13 << uVar7 * -8 + 0x20) & 1) != 0) {
          iVar4 = GetGlobalRK();
          uVar13 = uRam0206cc2c;
          uVar7 = iVar4 + 4U & 3;
          uVar11 = *(uint *)(iVar4 + 4U & 0xfffffffc);
          *(uint *)(iVar4 + 4) = (uVar11 >> uVar7 * 8 | uVar11 << uVar7 * -8 + 0x20) + 1;
          uVar7 = uVar13 & 3;
          uVar13 = *(uint *)(uVar13 & 0xfffffffc);
          uVar7 = (uVar13 >> uVar7 * 8 | uVar13 << uVar7 * -8 + 0x20) + 8;
          uVar13 = uVar7 & 3;
          uVar7 = *(uint *)(uVar7 & 0xfffffffc);
          if ((uVar7 >> uVar13 * 8 | uVar7 << uVar13 * -8 + 0x20) == 4) {
            func_0x0218171c();
          }
        }
      }
      uVar7 = param_1 + 0x44U & 3;
      uVar13 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
      *(uint *)(param_1 + 0x44) = (uVar13 >> uVar7 * 8 | uVar13 << uVar7 * -8 + 0x20) & uRam0206cc30
      ;
      *(undefined4 *)(param_1 + 0x2c4) = 0;
      *(undefined4 *)(param_1 + 0x2fc) = 0;
      *(undefined2 *)(param_1 + 0x302) = 0;
      *(undefined2 *)(param_1 + 0x300) = *(undefined2 *)(param_1 + 0x302);
      *(undefined4 *)(param_1 + 0x30c) = 0;
      func_0208c5b8(*(undefined2 *)(param_1 + 0x74));
      func_0208c534();
    }
    else if ((uVar7 & 0x10) != 0) {
      func_0206cc60(param_1,0);
    }
  }
  if (((uVar2 & 2) != 0) &&
     (uVar2 = param_1 + 0x44U & 3, uVar7 = *(uint *)(param_1 + 0x44U & 0xfffffffc),
     ((uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20) & 0x10) != 0)) {
    iVar4 = 0;
    iVar5 = Vector3_DotProduct(param_1 + 0x284,param_1 + 0x138);
    uVar2 = param_1 + 0x284U & 3;
    uVar13 = *(uint *)(param_1 + 0x284U & 0xfffffffc);
    uVar7 = param_1 + 0x138U & 3;
    uVar11 = *(uint *)(param_1 + 0x138U & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar13 >> uVar2 * 8 | uVar13 << uVar2 * -8 + 0x20) * (longlong)iVar5;
    iStack_2c = (uVar11 >> uVar7 * 8 | uVar11 << uVar7 * -8 + 0x20) -
                ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
    uVar2 = param_1 + 0x288U & 3;
    uVar13 = *(uint *)(param_1 + 0x288U & 0xfffffffc);
    uVar7 = param_1 + 0x13cU & 3;
    uVar11 = *(uint *)(param_1 + 0x13cU & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar13 >> uVar2 * 8 | uVar13 << uVar2 * -8 + 0x20) * (longlong)iVar5;
    iStack_28 = (uVar11 >> uVar7 * 8 | uVar11 << uVar7 * -8 + 0x20) -
                ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
    uVar2 = param_1 + 0x28cU & 3;
    uVar7 = *(uint *)(param_1 + 0x28cU & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20) * (longlong)iVar5;
    uVar2 = param_1 + 0x140U & 3;
    uVar7 = *(uint *)(param_1 + 0x140U & 0xfffffffc);
    iStack_24 = (uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20) -
                ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
    lVar1 = (longlong)iStack_24 * (longlong)iStack_24 +
            (longlong)iStack_2c * (longlong)iStack_2c + (longlong)iStack_28 * (longlong)iStack_28;
    iVar5 = 0;
    if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
      iVar5 = Vector3_MaybeNormalize((uint)(uintptr_t)(&iStack_2c),&iStack_2c);
    }
    if (iVar5 != 0) {
      Vector3_Cross(param_1 + 0x290,(uint)(uintptr_t)(&iStack_2c),(uint *)(void *)(auStack_20));
      uVar3 = VecFx32_Norm((uint)(uintptr_t)(auStack_20));
      uVar6 = VecFx32_CrossProduct_0(param_1 + 0x290,(uint)(uintptr_t)(&iStack_2c));
      uVar2 = func_02148538(uVar3,uVar6);
      iVar4 = (int)((((int)uVar2 >> 0x1f) * uRam0206cc34 +
                     uVar2 * iRam0206cc38 +
                     (int)((ulonglong)uRam0206cc34 * (ulonglong)uVar2 >> 0x20) +
                    (uint)(0x7fffffff < (uint)((ulonglong)uRam0206cc34 * (ulonglong)uVar2))) * 0x10)
              >> 0x10;
    }
    iVar5 = iRam0206cc3c;
    uVar2 = param_1 + 0x2a8U & 3;
    uVar7 = *(uint *)(param_1 + 0x2a8U & 0xfffffffc);
    if ((int)(uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20) < 0) {
      uVar8 = -uVar8;
    }
    *(short *)(param_1 + 0x388) =
         *(short *)(param_1 + 0x388) + (short)(iVar4 * uVar8 * 0x10000 >> 0x10);
    if (iVar5 < *(short *)(param_1 + 0x388)) {
      *(short *)(param_1 + 0x388) = (short)iVar5;
    }
    else if (*(short *)(param_1 + 0x388) < iRam0206cc40) {
      *(short *)(param_1 + 0x388) = (short)iRam0206cc40;
    }
    uVar8 = param_1 + 0x44U & 3;
    uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    if (((uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20) & 8) == 0) {
      return;
    }
    uVar8 = param_1 + 0x2a4U & 3;
    uVar2 = *(uint *)(param_1 + 0x2a4U & 0xfffffffc);
    *(short *)(param_1 + 0x38a) =
         (short)((uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20) * 0x1a >> 0xc);
    return;
  }
  uVar8 = param_1 + 0x78U & 3;
  uVar2 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
  if (((*(ushort *)(iRam0206cc44 + (uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20) * 0x5c) & 0x100
       ) == 0) &&
     (uVar8 = param_1 + 0x44U & 3, uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc),
     ((uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20) & 0x20000000) == 0)) {
    return;
  }
  uVar8 = param_1 + 0x4cU & 3;
  uVar2 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if (((uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20) & 0x10000000) != 0) {
    return;
  }
  uVar8 = param_1 + 0x44U & 3;
  uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  if (((uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20) & 0x10) == 0) {
    return;
  }
  uVar8 = param_1 + 0x7cU & 3;
  uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20) & 1) != 0) {
    iVar4 = GetAED0PlayerUnk(*(undefined2 *)(param_1 + 0x74));
    iVar5 = func_0210a578();
    func_0210ddf4(uRam0206cc48,iVar4 + iVar5,uRam0206cc4c,param_1);
  }
  uVar2 = uRam0206cc54;
  uVar8 = param_1 + 0x44U & 3;
  uVar7 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  *(uint *)(param_1 + 0x44) = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20 | uRam0206cc50;
  uVar3 = uRam0206cc58;
  uVar8 = param_1 + 0x44U & 3;
  uVar7 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  *(uint *)(param_1 + 0x44) = (uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) & uVar2;
  *(undefined4 *)(param_1 + 0x2b8) = uVar3;
  uVar8 = param_1 + 0x260U & 3;
  uVar2 = *(uint *)(param_1 + 0x260U & 0xfffffffc);
  *(uint *)(param_1 + 0x260) = (uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20) + iRam0206cc5c;
  *(undefined4 *)(param_1 + 700) = 0;
  *(undefined4 *)(param_1 + 0x2c4) = 0;
  *(undefined2 *)(param_1 + 0x38a) = 0;
  *(undefined4 *)(param_1 + 0x2fc) = 0;
  *(undefined2 *)(param_1 + 0x302) = 0;
  *(undefined2 *)(param_1 + 0x300) = *(undefined2 *)(param_1 + 0x302);
  *(undefined4 *)(param_1 + 0x30c) = 0;
  GetMQRacerVector333(param_1,(uint *)(uintptr_t)(param_1 + 0x290));
  StructMQRacerEntry_GetVec555(param_1,(uint *)(uintptr_t)(param_1 + 0x284));
  uVar8 = param_1 + 0x208U & 3;
  uVar2 = *(uint *)(param_1 + 0x208U & 0xfffffffc);
  puVar10 = (undefined4 *)(uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20);
  if (*(uint *)((uint)puVar10 & 0xfffffffc) >> ((uint)puVar10 & 3) * 8 != 0 ||
      *(uint *)((uint)puVar10 & 0xfffffffc) << ((uint)puVar10 & 3) * -8 + 0x20 != 0) {
    *puVar10 = 0;
  }
  uVar8 = param_1 + 0x7cU & 3;
  uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20) & 0x200) != 0) {
    uVar8 = param_1 + 0x514U & 3;
    uVar2 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
    uVar7 = uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20;
    uVar8 = uVar7 + 0x2c;
    uVar2 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    *(uint *)(uVar7 + 0x2c) = (uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20) ^ 1;
  }
  return;
}

