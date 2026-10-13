/* Decompiled C draft; module arm9; ROM address 0206b914. No matching claim. */
#include "types.h"
#include "deps/0206b914_StructMQRacerEntry_SomeFn.h"

void StructMQRacerEntry_SomeFn(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  *(undefined4 *)(param_1 + 0x2a8) = 0;
  *(undefined2 *)(param_1 + 0x388) = 0;
  uVar1 = param_1 + 0x48U & 3;
  uVar3 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  *(uint *)(param_1 + 0x48) = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & uRam0206baac;
  *(undefined2 *)(param_1 + 0x238) = 0;
  *(undefined2 *)(param_1 + 0x538) = 0;
  *(undefined2 *)(param_1 + 0x23c) = 0;
  uVar1 = param_1 + 0x7cU & 3;
  uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 1) != 0) {
    uVar1 = param_1 + 0x4cU & 3;
    uVar3 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    if ((((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0x10000000) == 0) &&
       (uVar1 = param_1 + 0x48U & 3, uVar3 = *(uint *)(param_1 + 0x48U & 0xfffffffc),
       ((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0x4000000) == 0)) {
      func_02074854();
    }
    func_02055c5c();
  }
  uVar1 = param_1 + 0x4cU & 3;
  uVar3 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0x2000) != 0) {
    uVar1 = param_1 + 0x4cU & 3;
    uVar3 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    *(uint *)(param_1 + 0x4c) = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0xffffdfff;
    *(undefined4 *)(param_1 + 0xd8) = 0x1000;
    uVar1 = param_1 + 0x4cU & 3;
    uVar3 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0x8000000) == 0) {
      StructMQRacerEntry_SomeFn_2(param_1);
    }
    StructMQRacerEntry_SomeFn_3(param_1);
  }
  *(undefined4 *)(param_1 + 0x180) = 6;
  uVar1 = param_1 + 0x4cU & 3;
  uVar3 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  *(uint *)(param_1 + 0x4c) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20 | 0x10;
  *(undefined4 *)(param_1 + 0x260) = 0x6000;
  *(undefined4 *)(param_1 + 0x318) = 0;
  *(undefined2 *)(param_1 + 0x314) = 0;
  *(undefined4 *)(param_1 + 0x360) = 4000;
  *(undefined2 *)(param_1 + 0x35c) = 0;
  GetMQRacerVector444(param_1,param_1 + 0x31c);
  GetMQRacerVector333(param_1,param_1 + 0x328);
  *(undefined4 *)(param_1 + 0x334) = 0;
  *(undefined2 *)(param_1 + 0x338) = 0;
  *(undefined4 *)(param_1 + 0x33c) = 0;
  *(undefined4 *)(param_1 + 0x344) = 0;
  uVar3 = uRam0206bab0;
  uVar1 = param_1 + 0x84U & 3;
  uVar2 = *(uint *)(param_1 + 0x84U & 0xfffffffc);
  *(uint *)(param_1 + 0x340) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  *(undefined4 *)(param_1 + 0x348) = 0;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  func_020eff40((uint)*(ushort *)(param_1 + 0x74) * 0x210 +
                (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20));
  uVar1 = (*(uint *)(uRam0206bab4 & 0xfffffffc) >> (uRam0206bab4 & 3) * 8 |
          *(uint *)(uRam0206bab4 & 0xfffffffc) << (uRam0206bab4 & 3) * -8 + 0x20) + 8;
  uVar3 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  if ((uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) == 4) {
    func_0x0218173c();
  }
  uVar1 = param_1 + 0x48U & 3;
  uVar3 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0x840) == 0) {
    uVar1 = param_1 + 0x3ccU & 3;
    uVar3 = *(uint *)(param_1 + 0x3ccU & 0xfffffffc);
    StructMQRacerEntry_SomeFn_5(param_1,uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,2);
  }
  uVar1 = param_1 + 0x4cU & 3;
  uVar3 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  *(uint *)(param_1 + 0x4c) = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0x7fffffff;
  uVar1 = param_1 + 0x7cU & 3;
  uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 1) == 0) {
    return;
  }
  func_020747f4(1);
  return;
}

