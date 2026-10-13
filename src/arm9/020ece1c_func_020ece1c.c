/* Decompiled C draft; module arm9; ROM address 020ece1c. No matching claim. */
#include "types.h"
#include "deps/020ece1c_func_020ece1c.h"

void func_020ece1c(int param_1,undefined4 param_2,undefined4 param_3)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  
  func_020f2228();
  uVar6 = param_1 + 0x158U & 3;
  uVar2 = *(uint *)(param_1 + 0x158U & 0xfffffffc);
  if ((uVar2 >> uVar6 * 8 != 0 || uVar2 << uVar6 * -8 + 0x20 != 0) &&
     (uVar6 = param_1 + 0x74U & 3, uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc),
     ((uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) & 0x20000) != 0)) {
    iVar3 = GetDriverEntry(*(ushort *)(param_1 + 0x78) & 0xff);
    uVar6 = iVar3 + 0x9cU & 3;
    uVar5 = *(uint *)(iVar3 + 0x9cU & 0xfffffffc);
    uVar2 = param_1 + 0x54U & 3;
    uVar4 = *(uint *)(param_1 + 0x54U & 0xfffffffc);
    iVar3 = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0x1e000;
    if ((int)(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) < iVar3) {
      *(int *)(param_1 + 0x54) = iVar3;
    }
  }
  uVar6 = param_1 + 0x74U & 3;
  uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  uVar6 = uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20;
  if ((uVar6 & 1) != 0) {
    return;
  }
  uVar2 = param_1 + 0x158U & 3;
  uVar4 = *(uint *)(param_1 + 0x158U & 0xfffffffc);
  if ((uVar4 >> uVar2 * 8 == 0 && uVar4 << uVar2 * -8 + 0x20 == 0) && ((uVar6 & 0x20000) != 0)) {
    return;
  }
  uVar6 = param_1 + 0x13c;
  iVar3 = func_020f3bb4(param_1 + 0x21c,param_1 + 0x168,param_1 + 0x21c);
  if (iVar3 != 0) {
    func_020f371c(param_1 + 0x21c,param_1 + 0x168,param_3);
  }
  uVar2 = param_1 + 0x168U & 3;
  uVar4 = *(uint *)(param_1 + 0x168U & 0xfffffffc);
  uVar2 = (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) + 0x18;
  uVar4 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  VecFx32_Subtract(uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20,param_1 + 0x50,&iStack_28);
  uVar2 = param_1 + 0x74U & 3;
  uVar4 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) & 0x40000000) != 0) {
    iVar3 = Vector3_DotProduct(uVar6,(uint)(uintptr_t)(&iStack_28));
    lVar1 = (longlong)
            (int)(*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
                 *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) * (longlong)iVar3;
    iStack_28 = iStack_28 - ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
    uVar2 = param_1 + 0x140U & 3;
    uVar4 = *(uint *)(param_1 + 0x140U & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) * (longlong)iVar3;
    iStack_24 = iStack_24 - ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
    uVar2 = param_1 + 0x144U & 3;
    uVar4 = *(uint *)(param_1 + 0x144U & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) * (longlong)iVar3;
    iStack_20 = iStack_20 - ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
    iVar3 = Vector3_DotProduct(param_1 + 0xf0,(uint)(uintptr_t)(&iStack_28));
    uVar2 = param_1 + 0xf0U & 3;
    uVar4 = *(uint *)(param_1 + 0xf0U & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) * (longlong)iVar3;
    iStack_28 = iStack_28 - ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
    uVar2 = param_1 + 0xf4U & 3;
    uVar4 = *(uint *)(param_1 + 0xf4U & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) * (longlong)iVar3;
    iStack_24 = iStack_24 - ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
    uVar2 = param_1 + 0xf8U & 3;
    uVar4 = *(uint *)(param_1 + 0xf8U & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) * (longlong)iVar3;
    iStack_20 = iStack_20 - ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
    VecFx32_AddScale1(0x29,(uint)(uintptr_t)(&iStack_28),param_1 + 0x50,(int *)(uintptr_t)(param_1 + 0x50));
    VecFx32_AddScale1(3,(uint)(uintptr_t)(&iStack_28),uVar6,(int *)(uintptr_t)(uVar6));
    return;
  }
  iVar3 = VecFx32_CrossProduct_0(uVar6,(uint)(uintptr_t)(&iStack_28));
  if (iVar3 < 0) {
    piVar9 = (int *)(param_1 + 0x148);
    Vector3_Cross(uVar6,param_1 + 0xf0);
    iVar3 = VecFx32_CrossProduct_0((uint)(uintptr_t)(piVar9),(uint)(uintptr_t)(&iStack_28));
    if (iVar3 < 1) {
      iStack_28 = -(*(uint *)((uint)piVar9 & 0xfffffffc) >> ((uint)piVar9 & 3) * 8 |
                   *(uint *)((uint)piVar9 & 0xfffffffc) << ((uint)piVar9 & 3) * -8 + 0x20);
      uVar6 = param_1 + 0x14cU & 3;
      uVar2 = *(uint *)(param_1 + 0x14cU & 0xfffffffc);
      iStack_24 = -(uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20);
      uVar6 = param_1 + 0x150U & 3;
      uVar2 = *(uint *)(param_1 + 0x150U & 0xfffffffc);
      iStack_20 = -(uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20);
    }
    else {
      iStack_28 = *piVar9;
      iStack_24 = *(int *)(param_1 + 0x14c);
      iStack_20 = *(int *)(param_1 + 0x150);
    }
    *(undefined4 *)(param_1 + 0x224) = 1;
  }
  lVar1 = (longlong)iStack_20 * (longlong)iStack_20 +
          (longlong)iStack_28 * (longlong)iStack_28 + (longlong)iStack_24 * (longlong)iStack_24;
  if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
    Vector3_MaybeNormalize((uint)(uintptr_t)(&iStack_28),&iStack_28);
  }
  uVar6 = param_1 + 0x214U & 3;
  uVar8 = *(uint *)(param_1 + 0x214U & 0xfffffffc);
  uVar2 = param_1 + 0x218U & 3;
  uVar7 = *(uint *)(param_1 + 0x218U & 0xfffffffc);
  uVar4 = param_1 + 0x224U & 3;
  uVar5 = *(uint *)(param_1 + 0x224U & 0xfffffffc);
  iVar3 = iRam020ed0f0;
  if (uVar5 >> uVar4 * 8 == 0 && uVar5 << uVar4 * -8 + 0x20 == 0) {
    iVar3 = 0x148;
  }
  lVar1 = (longlong)iVar3 *
          (longlong)
          (int)(0x1000 - (uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) *
                         (uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20));
  func_020eacc0(param_1 + 0x130,(uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14,
                (undefined4)(uintptr_t)(&iStack_28),(undefined4)(uintptr_t)(&iStack_28));
  func_020f1d70(param_1,(uint)(uintptr_t)(&iStack_28));
  return;
}

