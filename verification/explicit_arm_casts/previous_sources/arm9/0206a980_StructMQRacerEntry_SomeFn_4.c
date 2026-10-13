/* Decompiled C draft; module arm9; ROM address 0206a980. No matching claim. */
#include "types.h"
#include "deps/0206a980_StructMQRacerEntry_SomeFn_4.h"

undefined4 StructMQRacerEntry_SomeFn_4(int param_1,uint *param_2,int param_3)

{
  longlong lVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint local_38;
  uint local_34;
  uint local_30;
  undefined4 local_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  DriverContext_HandleSomeCollision(param_1,5);
  local_38 = *param_2;
  local_30 = param_2[2];
  iVar3 = 0;
  lVar1 = (longlong)(int)local_30 * (longlong)(int)local_30 +
          (longlong)(int)local_38 * (longlong)(int)local_38;
  local_34 = 0;
  if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
    iVar3 = Vector3_MaybeNormalize(&local_38,&local_38);
  }
  if (iVar3 == 0) {
    local_38 = *puRam0206abfc;
    local_34 = puRam0206abfc[1];
    local_30 = puRam0206abfc[2];
  }
  uVar4 = param_1 + 0x4cU & 3;
  uVar5 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  *(uint *)(param_1 + 0x4c) = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20 | 0x10;
  *(undefined2 *)(param_1 + 0x314) = 0;
  uVar5 = uRam0206ac00;
  *(undefined4 *)(param_1 + 0x318) = 0;
  puVar2 = puRam0206ac04;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  *(uint *)(param_1 + 0x360) = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  *(undefined2 *)(param_1 + 0x370) = 0;
  *(undefined2 *)(param_1 + 0x35c) = 0;
  local_2c = *puVar2;
  uStack_28 = puVar2[1];
  uStack_24 = puVar2[2];
  Vector3_Cross(&local_2c,&local_38,param_1 + 0x31c);
  uVar4 = param_1 + 0x7cU & 3;
  uVar5 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 0x400) == 0) {
    uVar4 = param_1 + 0x2d8U & 3;
    uVar5 = *(uint *)(param_1 + 0x2d8U & 0xfffffffc);
    *(uint *)(param_1 + 0x2d8) =
         (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) +
         ((local_38 << 0xe) >> 0xc | (local_38 >> 0x12) << 0x14);
    uVar4 = param_1 + 0x2e0U & 3;
    uVar5 = *(uint *)(param_1 + 0x2e0U & 0xfffffffc);
    *(uint *)(param_1 + 0x2e0) =
         (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) +
         ((local_30 << 0xe) >> 0xc | (local_30 >> 0x12) << 0x14);
    uVar4 = param_1 + 0x260U & 3;
    uVar5 = *(uint *)(param_1 + 0x260U & 0xfffffffc);
    *(uint *)(param_1 + 0x260) =
         (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) +
         ((local_34 << 0xe) >> 0xc | (local_34 >> 0x12) << 0x14);
    iVar3 = VecFx32_CrossProduct_0(param_1 + 0x50,&local_38);
    if (iVar3 < 1) {
      *(undefined4 *)(param_1 + 0x2a8) = 0;
    }
    else {
      uVar4 = param_1 + 0x2a8U & 3;
      uVar5 = *(uint *)(param_1 + 0x2a8U & 0xfffffffc);
      lVar1 = (longlong)(int)(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) * (longlong)iVar3;
      *(int *)(param_1 + 0x2a8) =
           (int)((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14) >> 2;
    }
  }
  func_01ffd190(param_1 + 0x31c,*(undefined2 *)(param_1 + 0x314),param_1 + 0x34c);
  func_020eff40((uint)*(ushort *)(param_1 + 0x74) * 0x210 +
                (*(uint *)(uRam0206ac08 & 0xfffffffc) >> (uRam0206ac08 & 3) * 8 |
                *(uint *)(uRam0206ac08 & 0xfffffffc) << (uRam0206ac08 & 3) * -8 + 0x20));
  uVar4 = (*(uint *)(uRam0206ac0c & 0xfffffffc) >> (uRam0206ac0c & 3) * 8 |
          *(uint *)(uRam0206ac0c & 0xfffffffc) << (uRam0206ac0c & 3) * -8 + 0x20) + 8;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if ((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) == 4) {
    func_0x0218173c();
  }
  uVar4 = param_1 + 0x590U & 3;
  uVar5 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
  uVar4 = (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) + 0x58;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if (uVar4 >> uVar5 * 8 == 0 && uVar4 << uVar5 * -8 + 0x20 == 0) {
    func_0208b7bc(0xc,param_1 + 0x80);
    func_0208b7bc(0xd,param_1 + 0x80);
    func_0208b7bc(0xe,param_1 + 0x80);
  }
  uVar4 = param_1 + 0x48U & 3;
  uVar5 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  if (((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 0x840) == 0) {
    uVar4 = param_1 + 0x3ccU & 3;
    uVar5 = *(uint *)(param_1 + 0x3ccU & 0xfffffffc);
    StructMQRacerEntry_SomeFn_5(param_1,uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20,2);
  }
  uVar4 = param_1 + 0x4cU & 3;
  uVar5 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  *(uint *)(param_1 + 0x4c) = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20 | 1;
  if (param_3 != 0) {
    uVar4 = param_1 + 0x7cU & 3;
    uVar5 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if (((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 0x200) != 0) {
      uVar4 = param_1 + 0x514U & 3;
      uVar5 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
      uVar6 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
      uVar4 = uVar6 + 0x2c;
      uVar5 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      *(uint *)(uVar6 + 0x2c) = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) ^ 0x40;
    }
    uVar4 = param_1 + 0x7cU & 3;
    uVar5 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if (((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 0x200) != 0) {
      uVar4 = param_1 + 0x514U & 3;
      uVar5 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
      uVar6 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
      uVar4 = param_2[1];
      uVar5 = param_2[2];
      *(uint *)(uVar6 + 0x98) = *param_2;
      *(uint *)(uVar6 + 0x9c) = uVar4;
      *(uint *)(uVar6 + 0xa0) = uVar5;
      uVar4 = param_1 + 0x514U & 3;
      uVar5 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
      *(undefined4 *)((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) + 0xa4) = 5;
    }
  }
  return 1;
}

