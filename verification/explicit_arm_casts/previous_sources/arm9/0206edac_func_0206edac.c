/* Decompiled C draft; module arm9; ROM address 0206edac. No matching claim. */
#include "types.h"
#include "deps/0206edac_func_0206edac.h"

void func_0206edac(int param_1,uint param_2)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uStack_24;
  uint uStack_20;
  uint uStack_1c;
  
  uVar7 = param_1 + 0x44U & 3;
  uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  if (((uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) & 0x40000010) != 0) {
    return;
  }
  uVar7 = param_1 + 0x44U & 3;
  uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  *(uint *)(param_1 + 0x44) = uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20 | 0x10000;
  if (*(short *)(param_1 + 0x4dc) < 1) {
    uVar7 = param_1 + 0x7cU & 3;
    uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if (((uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) & 1) == 0) {
      iVar8 = 2;
    }
    else {
      iVar8 = 3;
    }
    uVar7 = iRam0206f034 + 8U & 3;
    uVar2 = *(uint *)(iRam0206f034 + 8U & 0xfffffffc);
    iVar3 = GetAED0PlayerUnk(*(undefined2 *)(param_1 + 0x74));
    func_0210ddf4(iRam0206f038 + iVar8 * 8,iVar3 + (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20)
                  ,uRam0206f03c,param_1);
    DriverContext_SomeFn(param_1,0);
  }
  *(undefined2 *)(param_1 + 0x4dc) = 7;
  uVar7 = param_1 + 0x48U & 3;
  uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  if (((uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) & 0x2000000) != 0) {
    uVar7 = param_1 + 0x4cU & 3;
    uVar2 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    *(uint *)(param_1 + 0x4c) = (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) & 0xfffff7ff;
    uVar7 = param_1 + 0x48U & 3;
    uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
    *(uint *)(param_1 + 0x48) = (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) & 0xfdffffff;
    uVar4 = GetSomeTimeOrDuration();
    *(undefined4 *)(param_1 + 0x40c) = uVar4;
    func_020c4a04(*(undefined2 *)(param_1 + 0x74));
    return;
  }
  uVar7 = param_1 + 0x4cU & 3;
  uVar2 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if ((((((uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) & 0x10000000) == 0) &&
       (uVar7 = param_1 + 0xa8U & 3, uVar2 = *(uint *)(param_1 + 0xa8U & 0xfffffffc),
       (int)(uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) < 0)) &&
      ((uVar7 = param_1 + 0x380U & 3, uVar2 = *(uint *)(param_1 + 0x380U & 0xfffffffc),
       0x19 < (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) ||
       (uVar7 = param_1 + 0x2acU & 3, uVar6 = *(uint *)(param_1 + 0x2acU & 0xfffffffc),
       uVar2 = param_1 + 0x84U & 3, uVar5 = *(uint *)(param_1 + 0x84U & 0xfffffffc),
       0x1e000 < (int)((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) -
                      (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20)))))) ||
     (uVar7 = param_1 + 0x180U & 3, uVar2 = *(uint *)(param_1 + 0x180U & 0xfffffffc),
     (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) == 6)) {
    iVar8 = Vector3_DotProduct(param_2,param_1 + 0xa4);
    lVar1 = (longlong)
            (int)(*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
                 *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) * (longlong)iVar8;
    uStack_24 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    uVar7 = param_2 + 4 & 3;
    uVar2 = *(uint *)(param_2 + 4 & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) * (longlong)iVar8;
    uStack_20 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    uVar7 = param_2 + 8 & 3;
    uVar2 = *(uint *)(param_2 + 8 & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) * (longlong)iVar8;
    uStack_1c = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    iVar8 = VecFx32_Norm(&uStack_24);
    if (0x2000 < iVar8) {
      uVar7 = param_1 + 0xdcU & 3;
      uVar2 = *(uint *)(param_1 + 0xdcU & 0xfffffffc);
      uVar2 = uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20;
      lVar1 = (ulonglong)uVar2 * 0x1800;
      uVar7 = uStack_20;
      if ((int)uStack_20 < 1) {
        uVar7 = -uStack_20;
      }
      uVar5 = (uint)lVar1 >> 0xc |
              (((int)uVar2 >> 0x1f) * 0x1800 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
      *(uint *)(param_1 + 0x260) =
           (uint)((ulonglong)uRam0206f040 * (ulonglong)uVar7) >> 0xc |
           (((int)uVar7 >> 0x1f) * uRam0206f040 +
           (int)((ulonglong)uRam0206f040 * (ulonglong)uVar7 >> 0x20)) * 0x100000;
      uVar7 = param_1 + 0x260U & 3;
      uVar2 = *(uint *)(param_1 + 0x260U & 0xfffffffc);
      if ((int)uVar5 < (int)(uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20)) {
        *(uint *)(param_1 + 0x260) = uVar5;
      }
      uVar7 = param_1 + 0x7cU & 3;
      uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
      uVar7 = uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20;
      if ((((uVar7 & 0x10) != 0) &&
          (uVar2 = param_1 + 0x590U & 3, uVar5 = *(uint *)(param_1 + 0x590U & 0xfffffffc),
          uVar2 = (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) + 0x58, uVar5 = uVar2 & 3,
          uVar2 = *(uint *)(uVar2 & 0xfffffffc),
          uVar2 >> uVar5 * 8 == 0 && uVar2 << uVar5 * -8 + 0x20 == 0)) &&
         (((uVar7 & 1) != 0 || ((uVar7 & uRam0206f044) == 0)))) {
        func_0208b748(0x4e,param_1 + 0x80,param_1,uRam0206f048);
      }
    }
  }
  uVar7 = param_1 + 0x380U & 3;
  uVar2 = *(uint *)(param_1 + 0x380U & 0xfffffffc);
  if ((uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) < 0x15) {
    return;
  }
  iVar8 = VecFx32_CrossProduct_0(param_1 + 0x138,param_2);
  if (-1 < iVar8) {
    return;
  }
  if (1000 < *(short *)(param_1 + 0x234)) {
    uVar7 = param_1 + 0x2a8U & 3;
    uVar2 = *(uint *)(param_1 + 0x2a8U & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) *
            (longlong)(iVar8 + 0x1000);
    *(uint *)(param_1 + 0x2a8) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    return;
  }
  return;
}

