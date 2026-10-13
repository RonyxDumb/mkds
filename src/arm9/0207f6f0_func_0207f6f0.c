/* Decompiled C draft; module arm9; ROM address 0207f6f0. No matching claim. */
#include "types.h"
#include "deps/0207f6f0_func_0207f6f0.h"

void func_0207f6f0(uint param_1,uint param_2,int param_3,uint param_4,undefined4 param_5,
                  undefined4 param_6)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  int local_30;
  int local_2c;
  int local_28;
  undefined1 auStack_24 [12];
  
  if ((param_4 != 0) &&
     ((*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
      *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) != param_4)) {
    func_0207f05c();
    func_02080adc((undefined4 *)(uintptr_t)(param_2),param_4);
    (*(code *)(*(uint *)(uRam0207f8ec & 0xfffffffc) >> (uRam0207f8ec & 3) * 8 |
              *(uint *)(uRam0207f8ec & 0xfffffffc) << (uRam0207f8ec & 3) * -8 + 0x20))
              (param_1,param_2,param_3);
    return;
  }
  uVar2 = func_02061f90();
  if (*(ushort *)(param_1 + 4) == uVar2) {
    uVar2 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
            *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 0x44;
    uVar6 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    if (((uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) & 0x2000) != 0) {
      func_0207e7f0(param_1);
    }
    VecFx32_Subtract(param_1 + 0x44,param_3 + 0x80,&local_30);
    iVar3 = Vector3_DotProduct(param_3 + 300,(uint)(uintptr_t)(&local_30));
    uVar2 = param_3 + 300U & 3;
    uVar6 = *(uint *)(param_3 + 300U & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20) * (longlong)iVar3;
    local_30 = local_30 - ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
    uVar2 = param_3 + 0x130U & 3;
    uVar6 = *(uint *)(param_3 + 0x130U & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20) * (longlong)iVar3;
    local_2c = local_2c - ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
    uVar2 = param_3 + 0x134U & 3;
    uVar6 = *(uint *)(param_3 + 0x134U & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20) * (longlong)iVar3;
    local_28 = local_28 - ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
    Vector3_Cross(param_6,(uint)(uintptr_t)(&local_30),(uint *)(void *)(auStack_24));
    uVar4 = VecFx32_Norm((uint)(uintptr_t)(auStack_24));
    uVar5 = VecFx32_CrossProduct_0(param_6,(uint)(uintptr_t)(&local_30));
    uVar2 = func_02148538(uVar4,uVar5);
    iVar7 = ((int)uVar2 >> 0x1f) * uRam0207f8f0 +
            uVar2 * 0x39 + (int)((ulonglong)uRam0207f8f0 * (ulonglong)uVar2 >> 0x20) +
            (uint)(0x7fffffff < (uint)((ulonglong)uRam0207f8f0 * (ulonglong)uVar2));
    iVar3 = VecFx32_CrossProduct_0((uint)(uintptr_t)(auStack_24),param_3 + 300);
    if (iVar3 < 0) {
      iVar7 = -iVar7;
    }
    uVar4 = AbsValue(iVar7);
    *(undefined4 *)(param_1 + 0x70) = uVar4;
  }
  iVar3 = func_02080bf4(param_2,param_5);
  if ((iVar3 == 0) &&
     (uVar2 = param_3 + 0x48U & 3, uVar6 = *(uint *)(param_3 + 0x48U & 0xfffffffc),
     ((uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20) & 0x40000000) == 0)) {
    iVar3 = func_02080c64(param_2,param_5);
  }
  if (iVar3 != 0) {
    func_0207f05c(param_1);
    (*(code *)(*(uint *)(uRam0207f8f4 & 0xfffffffc) >> (uRam0207f8f4 & 3) * 8 |
              *(uint *)(uRam0207f8f4 & 0xfffffffc) << (uRam0207f8f4 & 3) * -8 + 0x20))(param_2);
    (*(code *)(*(uint *)(uRam0207f8ec & 0xfffffffc) >> (uRam0207f8ec & 3) * 8 |
              *(uint *)(uRam0207f8ec & 0xfffffffc) << (uRam0207f8ec & 3) * -8 + 0x20))
              (param_1,param_2,param_3);
    *(undefined4 *)(param_2 + 0x14) = 0;
    *(undefined4 *)(param_2 + 0x18) = 0;
    return;
  }
  return;
}

