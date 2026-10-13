/* Decompiled C draft; module arm9; ROM address 0206b358. No matching claim. */
#include "types.h"
#include "deps/0206b358_StructMQRacerEntry_SomeFn_56.h"

/* WARNING: Removing unreachable block (ram,0x0206b4a0) */

void StructMQRacerEntry_SomeFn_56(int param_1)

{
  longlong lVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  undefined1 auStack_18 [16];
  
  DriverContext_HandleSomeCollision(param_1,3);
  uVar4 = param_1 + 0x4cU & 3;
  uVar3 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  *(uint *)(param_1 + 0x4c) = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20 | 0x10;
  uVar2 = uRam0206b4bc;
  *(undefined2 *)(param_1 + 0x314) = 0;
  *(undefined4 *)(param_1 + 0x360) = uVar2;
  *(undefined2 *)(param_1 + 0x370) = 0;
  *(undefined2 *)(param_1 + 0x35c) = 0;
  *(undefined4 *)(param_1 + 0x318) = 0;
  uVar4 = param_1 + 0x2a8U & 3;
  uVar3 = *(uint *)(param_1 + 0x2a8U & 0xfffffffc);
  *(uint *)(param_1 + 0x2a8) = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0x800;
  GetMQRacerVector444(param_1,param_1 + 0x31c);
  GetMQRacerVector333(param_1,auStack_18);
  VecFx32_AddScale1(uRam0206b4c0,auStack_18,param_1 + 0x31c,param_1 + 0x31c);
  Vector3_MaybeNormalize(param_1 + 0x31c,param_1 + 0x31c);
  func_01ffd190(param_1 + 0x31c,*(undefined2 *)(param_1 + 0x314),param_1 + 0x34c);
  uVar4 = param_1 + 0x2a8U & 3;
  uVar3 = *(uint *)(param_1 + 0x2a8U & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  lVar1 = (ulonglong)uRam0206b4c4 * (ulonglong)uVar4;
  *(uint *)(param_1 + 0x2a8) =
       (uint)lVar1 >> 0xc |
       (((int)uVar4 >> 0x1f) * uRam0206b4c4 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
  uVar4 = param_1 + 0x590U & 3;
  uVar3 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
  uVar4 = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0x58;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if (uVar4 >> uVar3 * 8 == 0 && uVar4 << uVar3 * -8 + 0x20 == 0) {
    func_0208b7bc(0xc,param_1 + 0x80);
    func_0208b7bc(0xd,param_1 + 0x80);
    func_0208b7bc(0xe,param_1 + 0x80);
  }
  uVar4 = param_1 + 0x48U & 3;
  uVar3 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  if (((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0x840) == 0) {
    uVar4 = param_1 + 0x3ccU & 3;
    uVar3 = *(uint *)(param_1 + 0x3ccU & 0xfffffffc);
    StructMQRacerEntry_SomeFn_5(param_1,uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20,2);
  }
  func_020efea4((uint)*(ushort *)(param_1 + 0x74) * 0x210 +
                (*(uint *)(uRam0206b4c8 & 0xfffffffc) >> (uRam0206b4c8 & 3) * 8 |
                *(uint *)(uRam0206b4c8 & 0xfffffffc) << (uRam0206b4c8 & 3) * -8 + 0x20));
  uVar4 = (*(uint *)(uRam0206b4cc & 0xfffffffc) >> (uRam0206b4cc & 3) * 8 |
          *(uint *)(uRam0206b4cc & 0xfffffffc) << (uRam0206b4cc & 3) * -8 + 0x20) + 8;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if ((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) != 4) {
    return;
  }
  func_0x0218173c();
  return;
}

