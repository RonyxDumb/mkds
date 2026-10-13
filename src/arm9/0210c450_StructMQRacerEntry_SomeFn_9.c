/* Decompiled C draft; module arm9; ROM address 0210c450. No matching claim. */
#include "types.h"
#include "deps/0210c450_StructMQRacerEntry_SomeFn_9.h"

void StructMQRacerEntry_SomeFn_9(int param_1,int param_2,undefined4 param_3)

{
  byte bVar1;
  uint uVar2;
  uint uVar4;
  uint uVar3;
  
  func_0212c6f0(param_2,param_3);
  *(byte *)(param_2 + 0x19) = *(byte *)(param_2 + 0x19) & 0xfb;
  *(byte *)(param_2 + 0x19) = *(byte *)(param_2 + 0x19) & 0xf7;
  *(byte *)(param_2 + 0x19) = *(byte *)(param_2 + 0x19) & 0xfd;
  func_0210bc54(param_1 + 0xc,param_2);
  uVar3 = param_1 + 0xcU & 3;
  uVar2 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  uVar2 = 3;
  if (uVar3 != 0) {
    do {
      bVar1 = *(byte *)(uVar3 + 0x19);
      if ((bVar1 & 2) != 0) {
        uVar2 = 0;
        break;
      }
      if (((bVar1 & 8) != 0) || ((bVar1 & 1) != 0)) {
        uVar2 = 1;
      }
      uVar3 = IntrusiveListWrapper_NextItem(param_1 + 0xc);
    } while (uVar3 != 0);
  }
  uVar3 = param_1 + 0x18U & 3;
  uVar4 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
  uVar3 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  if (uVar3 == uVar2) {
    return;
  }
  if (uVar3 != 3) {
    func_0210bc54(uVar3 * 0xc + iRam0210c554,param_1);
    *(undefined4 *)(param_1 + 0x18) = 3;
  }
  if (uVar2 != 3) {
    StructMQRacerEntry_MaybeInsertChildEntry(uVar2 * 0xc + iRam0210c554,param_1);
    *(uint *)(param_1 + 0x18) = uVar2;
    return;
  }
  return;
}

