/* Decompiled C draft; module arm9; ROM address 0206add0. No matching claim. */
#include "types.h"
#include "deps/0206add0_StructMQRacerEntry_SomeFn_59.h"

void StructMQRacerEntry_SomeFn_59(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  uint uVar11;
  uint uVar12;
  undefined4 local_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  DriverContext_HandleSomeCollision(param_1,4);
  uVar6 = param_1 + 0x4cU & 3;
  uVar8 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  *(uint *)(param_1 + 0x4c) = uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20 | 0x10;
  *(undefined2 *)(param_1 + 0x314) = 0;
  uVar8 = uRam0206b00c;
  *(undefined4 *)(param_1 + 0x318) = 0;
  puVar5 = puRam0206b010;
  uVar6 = uVar8 & 3;
  uVar8 = *(uint *)(uVar8 & 0xfffffffc);
  *(uint *)(param_1 + 0x360) = uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20;
  *(undefined2 *)(param_1 + 0x370) = 0;
  *(undefined2 *)(param_1 + 0x35c) = 0;
  local_34 = *puVar5;
  uStack_30 = puVar5[1];
  uStack_2c = puVar5[2];
  Vector3_Cross((uint)(uintptr_t)(&local_34),(uint)(uintptr_t)(param_2),(uint *)(uintptr_t)(param_1 + 0x31c));
  func_020eff40((uint)*(ushort *)(param_1 + 0x74) * 0x210 +
                (*(uint *)(uRam0206b014 & 0xfffffffc) >> (uRam0206b014 & 3) * 8 |
                *(uint *)(uRam0206b014 & 0xfffffffc) << (uRam0206b014 & 3) * -8 + 0x20));
  uVar6 = (*(uint *)(uRam0206b018 & 0xfffffffc) >> (uRam0206b018 & 3) * 8 |
          *(uint *)(uRam0206b018 & 0xfffffffc) << (uRam0206b018 & 3) * -8 + 0x20) + 8;
  uVar8 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  if ((uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20) == 4) {
    func_0x0218173c();
  }
  uVar6 = param_1 + 0x7cU & 3;
  uVar8 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) & 0x400) == 0) {
    uVar8 = *(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
            *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20;
    lVar2 = (ulonglong)uRam0206b01c * (ulonglong)uVar8;
    uVar6 = (uint)(param_2 + 1) & 3;
    uVar11 = *(uint *)((uint)(param_2 + 1) & 0xfffffffc);
    uVar11 = uVar11 >> uVar6 * 8 | uVar11 << uVar6 * -8 + 0x20;
    uVar6 = (uint)(param_2 + 2) & 3;
    uVar12 = *(uint *)((uint)(param_2 + 2) & 0xfffffffc);
    uVar6 = uVar12 >> uVar6 * 8 | uVar12 << uVar6 * -8 + 0x20;
    lVar3 = (ulonglong)uRam0206b01c * (ulonglong)uVar11;
    lVar4 = (ulonglong)uRam0206b01c * (ulonglong)uVar6;
    iVar7 = ((int)uVar11 >> 0x1f) * uRam0206b01c;
    iVar1 = ((int)uVar6 >> 0x1f) * uRam0206b01c;
    uVar6 = param_1 + 0x2d8U & 3;
    uVar11 = *(uint *)(param_1 + 0x2d8U & 0xfffffffc);
    *(uint *)(param_1 + 0x2d8) =
         (uVar11 >> uVar6 * 8 | uVar11 << uVar6 * -8 + 0x20) +
         ((uint)lVar2 >> 0xc |
         (((int)uVar8 >> 0x1f) * uRam0206b01c + (int)((ulonglong)lVar2 >> 0x20)) * 0x100000);
    uVar6 = param_1 + 0x2e0U & 3;
    uVar8 = *(uint *)(param_1 + 0x2e0U & 0xfffffffc);
    *(uint *)(param_1 + 0x2e0) =
         (uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) +
         ((uint)lVar4 >> 0xc | (iVar1 + (int)((ulonglong)lVar4 >> 0x20)) * 0x100000);
    uVar6 = param_1 + 0x260U & 3;
    uVar8 = *(uint *)(param_1 + 0x260U & 0xfffffffc);
    *(uint *)(param_1 + 0x260) =
         (uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) +
         ((uint)lVar3 >> 0xc | (iVar7 + (int)((ulonglong)lVar3 >> 0x20)) * 0x100000);
    iVar7 = VecFx32_CrossProduct_0(param_1 + 0x50,(uint)(uintptr_t)(param_2));
    if (iVar7 < 1) {
      *(undefined4 *)(param_1 + 0x2a8) = 0;
    }
    else {
      uVar6 = param_1 + 0x2a8U & 3;
      uVar8 = *(uint *)(param_1 + 0x2a8U & 0xfffffffc);
      lVar2 = (longlong)(int)(uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) * (longlong)iVar7;
      *(int *)(param_1 + 0x2a8) =
           (int)((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14) >> 2;
    }
  }
  func_01ffd190(param_1 + 0x31c,*(undefined2 *)(param_1 + 0x314),(uint *)(uintptr_t)(param_1 + 0x34c));
  uVar6 = param_1 + 0x590U & 3;
  uVar8 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
  uVar6 = (uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) + 0x58;
  uVar8 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  if (uVar6 >> uVar8 * 8 == 0 && uVar6 << uVar8 * -8 + 0x20 == 0) {
    func_0208b7bc(0xc,param_1 + 0x80);
    func_0208b7bc(0xd,param_1 + 0x80);
    func_0208b7bc(0xe,param_1 + 0x80);
  }
  uVar6 = param_1 + 0x4cU & 3;
  uVar8 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  *(uint *)(param_1 + 0x4c) = uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20 | 1;
  uVar6 = param_1 + 0x48U & 3;
  uVar8 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  if (((uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) & 0x840) == 0) {
    uVar6 = param_1 + 0x3ccU & 3;
    uVar8 = *(uint *)(param_1 + 0x3ccU & 0xfffffffc);
    StructMQRacerEntry_SomeFn_5(param_1,uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20,2);
  }
  if (param_3 == 0) {
    return;
  }
  uVar6 = param_1 + 0x7cU & 3;
  uVar8 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) & 0x200) != 0) {
    uVar6 = param_1 + 0x514U & 3;
    uVar8 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
    uVar11 = uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20;
    uVar6 = uVar11 + 0x2c;
    uVar8 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    *(uint *)(uVar11 + 0x2c) = (uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20) ^ 0x20;
  }
  uVar6 = param_1 + 0x7cU & 3;
  uVar8 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) & 0x200) == 0) {
    return;
  }
  uVar6 = param_1 + 0x514U & 3;
  uVar8 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
  uVar6 = uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20;
  uVar9 = param_2[1];
  uVar10 = param_2[2];
  *(undefined4 *)(uVar6 + 0x98) = *param_2;
  *(undefined4 *)(uVar6 + 0x9c) = uVar9;
  *(undefined4 *)(uVar6 + 0xa0) = uVar10;
  uVar6 = param_1 + 0x514U & 3;
  uVar8 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
  *(undefined4 *)((uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) + 0xa4) = 4;
  return;
}

