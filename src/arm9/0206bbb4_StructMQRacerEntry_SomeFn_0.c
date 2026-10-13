/* Decompiled C draft; module arm9; ROM address 0206bbb4. No matching claim. */
#include "types.h"
#include "deps/0206bbb4_StructMQRacerEntry_SomeFn_0.h"

void StructMQRacerEntry_SomeFn_0(int param_1,undefined2 param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = 1;
  DriverContext_HandleSomeCollision(param_1,2);
  uVar2 = param_1 + 0x44U & 3;
  uVar1 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 10) == 0) {
    uVar2 = param_1 + 0x2d4U & 3;
    uVar1 = *(uint *)(param_1 + 0x2d4U & 0xfffffffc);
    if ((int)(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) < 0) {
      iVar4 = -1;
    }
  }
  else {
    uVar2 = param_1 + 0x2c4U & 3;
    uVar1 = *(uint *)(param_1 + 0x2c4U & 0xfffffffc);
    if ((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) == 1) {
      iVar4 = -1;
    }
  }
  *(undefined4 *)(param_1 + 0x36c) = 0x750;
  uVar2 = param_1 + 0x36cU & 3;
  uVar1 = *(uint *)(param_1 + 0x36cU & 0xfffffffc);
  *(uint *)(param_1 + 0x36c) = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) * iVar4;
  *(undefined2 *)(param_1 + 0x364) = 0;
  *(undefined4 *)(param_1 + 0x368) = 0;
  *(undefined2 *)(param_1 + 0x366) = param_2;
  uVar1 = uRam0206bca8;
  uVar2 = param_1 + 0x4cU & 3;
  uVar3 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  *(uint *)(param_1 + 0x4c) = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20 | 0x20;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  func_020efea4((uint)*(ushort *)(param_1 + 0x74) * 0x210 +
                (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20));
  uVar2 = (*(uint *)(uRam0206bcac & 0xfffffffc) >> (uRam0206bcac & 3) * 8 |
          *(uint *)(uRam0206bcac & 0xfffffffc) << (uRam0206bcac & 3) * -8 + 0x20) + 8;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 4) {
    func_0x0218173c();
  }
  if (param_3 == 0) {
    uVar2 = param_1 + 0x48U & 3;
    uVar1 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
    if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0x840) == 0) {
      uVar2 = param_1 + 0x3ccU & 3;
      uVar1 = *(uint *)(param_1 + 0x3ccU & 0xfffffffc);
      StructMQRacerEntry_SomeFn_5(param_1,uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20,1);
      return;
    }
    return;
  }
  return;
}

