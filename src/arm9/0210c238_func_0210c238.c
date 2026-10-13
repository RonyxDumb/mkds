/* Decompiled C draft; module arm9; ROM address 0210c238. No matching claim. */
#include "types.h"
#include "deps/0210c238_func_0210c238.h"

void func_0210c238(int param_1,undefined4 param_2)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  uVar6 = param_1 + 0xcU & 3;
  uVar5 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  bVar2 = false;
  if (uVar6 != 0) {
    iVar4 = param_1 + 0xc;
    do {
      if ((*(byte *)(uVar6 + 0x19) & 4) == 0) {
        uVar5 = IntrusiveListWrapper_NextItem(iVar4,uVar6);
      }
      else {
        uVar5 = IntrusiveListWrapper_NextItem(iVar4,uVar6);
        func_0212c6f0(uVar6,param_2);
        *(byte *)(uVar6 + 0x19) = *(byte *)(uVar6 + 0x19) & 0xfb;
        *(byte *)(uVar6 + 0x19) = *(byte *)(uVar6 + 0x19) & 0xf7;
        *(byte *)(uVar6 + 0x19) = *(byte *)(uVar6 + 0x19) & 0xfd;
        func_0210bc54(iVar4,uVar6);
        bVar2 = true;
      }
      uVar6 = uVar5;
    } while (uVar5 != 0);
  }
  if (!bVar2) {
    return;
  }
  uVar6 = param_1 + 0xcU & 3;
  uVar5 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  uVar5 = 3;
  if (uVar6 != 0) {
    do {
      bVar1 = *(byte *)(uVar6 + 0x19);
      if ((bVar1 & 2) != 0) {
        uVar5 = 0;
        break;
      }
      if (((bVar1 & 8) != 0) || ((bVar1 & 1) != 0)) {
        uVar5 = 1;
      }
      uVar6 = IntrusiveListWrapper_NextItem(param_1 + 0xc);
    } while (uVar6 != 0);
  }
  uVar6 = param_1 + 0x18U & 3;
  uVar3 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
  uVar6 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
  if (uVar6 == uVar5) {
    return;
  }
  if (uVar6 != 3) {
    func_0210bc54(uVar6 * 0xc + iRam0210c3a4,param_1);
    *(undefined4 *)(param_1 + 0x18) = 3;
  }
  if (uVar5 != 3) {
    StructMQRacerEntry_MaybeInsertChildEntry(uVar5 * 0xc + iRam0210c3a4,param_1);
    *(uint *)(param_1 + 0x18) = uVar5;
    return;
  }
  return;
}

