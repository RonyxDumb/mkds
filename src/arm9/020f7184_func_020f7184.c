/* Decompiled C draft; module arm9; ROM address 020f7184. No matching claim. */
#include "types.h"
#include "deps/020f7184_func_020f7184.h"

undefined4 func_020f7184(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  code *pcVar4;
  uint uVar5;
  uint uVar6;
  int iVar8;
  uint uVar7;
  
  uVar7 = param_1 + 0x74U & 3;
  uVar6 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  uVar7 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
  iVar8 = param_1 + 0x5c;
  if ((uVar7 & 0x80000) != 0) {
    return 2;
  }
  if ((((param_3 == 0) && ((uVar7 & 0x8000000) != 0)) && ((uVar7 & 0x10000000) == 0)) &&
     ((uVar7 & 0x20000000) == 0)) {
    uVar1 = *(ushort *)(param_1 + 0x78);
    if ((uVar1 & 0xf00) == 0) {
      if (param_2 == 0) {
        *(ushort *)(param_1 + 0x78) = uVar1 | *puRam020f7380;
      }
      else {
        *(ushort *)(param_1 + 0x78) = uVar1 | *puRam020f7384;
        func_020f9c40();
      }
      *(undefined4 *)(param_1 + 0x120) = 0;
      return 1;
    }
    return 2;
  }
  if ((param_2 == 0) &&
     (uVar7 = param_1 + 0x44U & 3, uVar6 = *(uint *)(param_1 + 0x44U & 0xfffffffc),
     uVar7 = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) * 0xa8 +
             (*(uint *)(uRam020f7388 & 0xfffffffc) >> (uRam020f7388 & 3) * 8 |
             *(uint *)(uRam020f7388 & 0xfffffffc) << (uRam020f7388 & 3) * -8 + 0x20) + 0x34,
     uVar6 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
     pcVar4 = (code *)(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20), pcVar4 != (code *)0x0)) {
    iVar2 = (*pcVar4)(param_1);
    if (iVar2 == 0) {
      return 2;
    }
    if (iVar2 == 1) {
      return 0;
    }
  }
  if (param_2 == 0) {
    *(undefined4 *)(param_1 + 0x10c) = uRam020f7390;
    uVar7 = param_1 + 0x74U & 3;
    uVar6 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
    if (((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0x8000) == 0) {
      uVar6 = VecFx32_Norm(iVar8);
      uVar7 = param_1 + 0x10cU & 3;
      uVar5 = *(uint *)(param_1 + 0x10cU & 0xfffffffc);
      *(uint *)(param_1 + 0x10c) =
           (uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) +
           ((uint)((ulonglong)uVar6 * 0x15c) >> 0xc |
           (((int)uVar6 >> 0x1f) * 0x15c + (int)((ulonglong)uVar6 * 0x15c >> 0x20)) * 0x100000);
      uVar7 = param_1 + 0x10cU & 3;
      uVar6 = *(uint *)(param_1 + 0x10cU & 0xfffffffc);
      if (iRam020f7394 < (int)(uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20)) {
        *(int *)(param_1 + 0x10c) = iRam020f7394;
      }
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x10c) = uRam020f738c;
  }
  uVar7 = param_1 + 0x44U & 3;
  uVar6 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  uVar7 = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) * 0xa8 +
          (*(uint *)(uRam020f7388 & 0xfffffffc) >> (uRam020f7388 & 3) * 8 |
          *(uint *)(uRam020f7388 & 0xfffffffc) << (uRam020f7388 & 3) * -8 + 0x20) + 0x40;
  uVar6 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  if (uVar7 >> uVar6 * 8 == 0 && uVar7 << uVar6 * -8 + 0x20 == 0) {
    *(undefined4 *)(param_1 + 0x120) = uRam020f7398;
  }
  *(undefined4 *)(param_1 + 0x124) = uRam020f739c;
  uVar7 = param_1 + 0xf4U & 3;
  uVar6 = *(uint *)(param_1 + 0xf4U & 0xfffffffc);
  if (uVar6 >> uVar7 * 8 != 0 || uVar6 << uVar7 * -8 + 0x20 != 0) {
    iVar2 = VecFx32_CrossProduct_0(iVar8,param_1 + 0xf0);
    if (iVar2 < 0x3000) {
      VecFx32_AddScale1(0x3000 - iVar2,param_1 + 0xf0,iVar8,(int *)(uintptr_t)(iVar8));
    }
  }
  uVar7 = param_1 + 0x74U & 3;
  uVar6 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  *(uint *)(param_1 + 0x74) = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20 | uRam020f73a0;
  func_020f9c40(param_1);
  uVar3 = func_020e6b28();
  iVar8 = VecFx32_CrossProduct_0(iVar8,uVar3);
  if (iVar8 < 2) {
    *(undefined4 *)(param_1 + 0x108) = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x108) = 1;
  }
  return 0;
}

