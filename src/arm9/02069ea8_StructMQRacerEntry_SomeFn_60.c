/* Decompiled C draft; module arm9; ROM address 02069ea8. No matching claim. */
#include "types.h"
#include "deps/02069ea8_StructMQRacerEntry_SomeFn_60.h"

void StructMQRacerEntry_SomeFn_60(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  
  *(undefined4 *)(param_1 + 0x398) = 0x1000;
  *(undefined4 *)(param_1 + 0x434) = 0x1000;
  *(undefined4 *)(param_1 + 0xc0) = 0x1000;
  uVar1 = param_1 + 0x4cU & 3;
  uVar2 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  puVar4 = (uint *)(param_1 + 0x4c);
  *(uint *)(param_1 + 0x4c) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xfffeffff;
  uVar2 = uRam02069f64;
  uVar1 = param_1 + 0x4cU & 3;
  uVar3 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0x80) != 0) {
    *puVar4 = (*(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
              *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20) & 0xffffff7f;
    *(undefined4 *)(param_1 + 0x428) = 0x1000;
    *(undefined4 *)(param_1 + 0x42c) = 0x1000;
    *(undefined4 *)(param_1 + 0x430) = 0x1000;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    if ((uint)*(ushort *)(param_1 + 0x74) ==
        (int)*(char *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0x62)) {
      func_0210fa74(0);
    }
    func_0210a664(param_1);
  }
  *(undefined4 *)(param_1 + 0xbc) = 0x1000;
  *(undefined4 *)(param_1 + 0xc0) = 0x1000;
  *(undefined4 *)(param_1 + 0xc4) = 0x1000;
  *(undefined4 *)(param_1 + 0x41c) = 0x1000;
  *(undefined4 *)(param_1 + 0x420) = 0x1000;
  *(undefined4 *)(param_1 + 0x424) = 0x1000;
  uVar1 = param_1 + 0x4cU & 3;
  uVar2 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & uRam02069f68) == 0) {
    *(undefined4 *)(param_1 + 0x394) = 0x1000;
  }
  uVar1 = param_1 + 0x7cU & 3;
  uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 1) != 0) {
    func_02074854();
    return;
  }
  return;
}

