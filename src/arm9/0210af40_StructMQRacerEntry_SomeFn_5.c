/* Decompiled C draft; module arm9; ROM address 0210af40. No matching claim. */
#include "types.h"
#include "deps/0210af40_StructMQRacerEntry_SomeFn_5.h"

void StructMQRacerEntry_SomeFn_5(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iStack_18;
  
  uVar5 = *(uint *)(uRam0210b124 & 0xfffffffc) >> (uRam0210b124 & 3) * 8 |
          *(uint *)(uRam0210b124 & 0xfffffffc) << (uRam0210b124 & 3) * -8 + 0x20;
  if ((*(ushort *)(param_1 + 0x34) & 1) == 0) {
    return;
  }
  uVar3 = param_1 + 0x4cU & 3;
  uVar2 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if (((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 0x10000000) != 0) {
    return;
  }
  uVar3 = param_1 + 0x7cU & 3;
  uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 4) != 0) {
    return;
  }
  uVar3 = uRam0210b124 + 0xc & 3;
  uVar2 = *(uint *)(uRam0210b124 + 0xc & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if (uVar3 == 1) {
    uVar3 = 0xf0;
    uVar2 = 0x1e;
    if (param_3 - 1U < 2) {
      uVar3 = 0x3c;
      uVar2 = 0;
    }
    if (uVar3 <= uVar5) {
      uVar3 = param_1 + 0x480U & 3;
      uVar4 = *(uint *)(param_1 + 0x480U & 0xfffffffc);
      if (uVar2 <= uVar5 - (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20)) {
        StructMQRacerEntry_SomeFn_6(param_1,2,param_2 * 0xe + param_3,0x7f);
        *(uint *)(param_1 + 0x480) = uVar5;
        return;
      }
      return;
    }
    return;
  }
  if (uVar3 != 0) {
    return;
  }
  if ((uint)*(ushort *)(param_1 + 0x74) !=
      (int)*(char *)((*(uint *)(uRam0210b128 & 0xfffffffc) >> (uRam0210b128 & 3) * 8 |
                     *(uint *)(uRam0210b128 & 0xfffffffc) << (uRam0210b128 & 3) * -8 + 0x20) + 0x62)
     ) {
    if ((param_3 != 3) && (param_3 != 5)) {
      return;
    }
    StructMQRacerEntry_SomeFn_6(param_1,2,param_2 * 0xe + param_3 + 1,0x73);
    return;
  }
  iVar1 = IsInRaceSceneNormalOrReplay();
  if (iVar1 != 0) {
    func_0212c6a0(&iStack_18);
    if (iStack_18 != 0) {
      func_0212c6f0(&iStack_18,0);
    }
    func_0212ec04(&iStack_18,1,0xffffffff,0x7f);
    func_02105b28((undefined4)(uintptr_t)(&iStack_18),0x7f);
    func_0212c688(&iStack_18);
    return;
  }
  return;
}

