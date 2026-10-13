/* Decompiled C draft; module arm9; ROM address 0206a624. No matching claim. */
#include "types.h"
#include "deps/0206a624_DriverContext_ApplyThunderShrink.h"

void DriverContext_ApplyThunderShrink(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  uVar3 = param_1 + 0x4cU & 3;
  uVar5 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  iVar6 = param_1 + iRam0206a764;
  if (((uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) & uRam0206a768) != 0) {
    return;
  }
  uVar3 = param_1 + 0x7cU & 3;
  uVar5 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) & uRam0206a76c) != 0) {
    return;
  }
  uVar3 = param_1 + 0x48U & 3;
  uVar5 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  if (((uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) & uRam0206a770) != 0) {
    return;
  }
  iVar2 = GetDriverPlace(*(undefined2 *)(param_1 + 0x74));
  uVar1 = uRam0206a778;
  *(undefined2 *)(iVar6 + 2) = *(undefined2 *)(iRam0206a774 + (iVar2 + -1) * 2);
  *(undefined2 *)(iVar6 + 4) = 0;
  *(undefined4 *)(param_1 + 0x394) = uVar1;
  uVar3 = param_1 + 0x4cU & 3;
  uVar5 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  *(uint *)(param_1 + 0x4c) = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20 | 0x80;
  StructMQRacerEntry_SomeFn_27(param_1,2,1);
  StructMQRacerEntry_SomeFn_28(param_1);
  func_020eff40((uint)*(ushort *)(param_1 + 0x74) * 0x210 +
                (*(uint *)(uRam0206a77c & 0xfffffffc) >> (uRam0206a77c & 3) * 8 |
                *(uint *)(uRam0206a77c & 0xfffffffc) << (uRam0206a77c & 3) * -8 + 0x20));
  uVar3 = (*(uint *)(uRam0206a780 & 0xfffffffc) >> (uRam0206a780 & 3) * 8 |
          *(uint *)(uRam0206a780 & 0xfffffffc) << (uRam0206a780 & 3) * -8 + 0x20) + 8;
  uVar5 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if ((uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) == 4) {
    func_0x0218173c();
  }
  *(undefined4 *)(param_1 + 0x41c) = 0x1000;
  *(undefined4 *)(param_1 + 0x420) = 0x1000;
  *(undefined4 *)(param_1 + 0x424) = 0x1000;
  StructMQRacerEntry_SomeFn_29(param_1);
  if ((uint)*(ushort *)(param_1 + 0x74) ==
      (int)*(char *)((*(uint *)(uRam0206a780 & 0xfffffffc) >> (uRam0206a780 & 3) * 8 |
                     *(uint *)(uRam0206a780 & 0xfffffffc) << (uRam0206a780 & 3) * -8 + 0x20) + 0x62)
     ) {
    func_0210fa74(1);
  }
  uVar3 = param_1 + 0x7cU & 3;
  uVar5 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) & 0x200) != 0) {
    uVar3 = param_1 + 0x514U & 3;
    uVar5 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
    uVar4 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
    uVar3 = uVar4 + 0x2c;
    uVar5 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    *(uint *)(uVar4 + 0x2c) = (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) ^ 0x8000;
  }
  return;
}

