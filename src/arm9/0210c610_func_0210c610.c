/* Decompiled C draft; module arm9; ROM address 0210c610. No matching claim. */
#include "types.h"
#include "deps/0210c610_func_0210c610.h"

uint func_0210c610(int param_1,uint param_2,uint param_3,undefined1 param_4,undefined2 param_5)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = iRam0210c85c + 0x10U & 3;
  uVar1 = *(uint *)(iRam0210c85c + 0x10U & 0xfffffffc);
  uVar3 = 0;
  if (uVar1 >> uVar2 * 8 == 0 && uVar1 << uVar2 * -8 + 0x20 == 0) {
    return 0;
  }
  if ((*(ushort *)(param_1 + 0x34) & 1) == 0) {
    return 0;
  }
  uVar2 = param_1 + 0xcU & 3;
  uVar1 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (uVar2 != 0) {
    do {
      if ((*(byte *)(uVar2 + 0x19) & 4) != 0) {
        uVar1 = uVar3;
        if ((*(ushort *)(uVar2 + 0x16) == param_3) && (*(byte *)(uVar2 + 0x18) == param_2)) {
          uVar1 = 1;
        }
        if (uVar1 != 0) {
          if (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 != 0 ||
              *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20 != 0) {
            *(byte *)(uVar2 + 0x19) = *(byte *)(uVar2 + 0x19) | 8;
            *(undefined1 *)(uVar2 + 0x1a) = param_4;
            *(undefined2 *)(uVar2 + 0x14) = param_5;
            uVar3 = param_1 + 0x18U & 3;
            uVar1 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
            if ((uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) == 3) {
              StructMQRacerEntry_MaybeInsertChildEntry(uRam0210c860,param_1);
              *(undefined4 *)(param_1 + 0x18) = 1;
            }
            return uVar2;
          }
          StructMQRacerEntry_SomeFn_9(param_1,uVar2,0);
          func_0210e328(uVar2);
          StructMQChild_Create((undefined4 *)(uintptr_t)(uVar2 + 8));
          *(undefined1 *)(uVar2 + 0x18) = 0;
          *(undefined2 *)(uVar2 + 0x16) = 0;
          *(undefined1 *)(uVar2 + 0x19) = 0;
          *(undefined2 *)(uVar2 + 0x14) = 0;
          *(undefined1 *)(uVar2 + 0x1a) = 0x7f;
          uVar3 = uVar2;
          break;
        }
      }
      uVar2 = IntrusiveListWrapper_NextItem(param_1 + 0xc,uVar2);
    } while (uVar2 != 0);
  }
  if (uVar3 == 0) {
    uVar3 = GetSomeSndPlayer(uRam0210c864);
    func_0210c084(uVar3,0);
    uVar2 = uVar3 + 0x10 & 3;
    uVar1 = *(uint *)(uVar3 + 0x10 & 0xfffffffc);
    uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    if (uVar2 != 0) {
      func_0210bc54(uVar2,uVar3);
      func_0210bfbc(uVar2 - 0xc);
    }
    func_0210cfe8(uVar3);
  }
  func_0210e328(uVar3);
  StructMQChild_Create((undefined4 *)(uintptr_t)(uVar3 + 8));
  *(undefined1 *)(uVar3 + 0x18) = 0;
  *(undefined2 *)(uVar3 + 0x16) = 0;
  *(undefined1 *)(uVar3 + 0x19) = 0;
  *(undefined2 *)(uVar3 + 0x14) = 0;
  *(undefined1 *)(uVar3 + 0x1a) = 0x7f;
  *(char *)(uVar3 + 0x18) = (char)param_2;
  *(short *)(uVar3 + 0x16) = (short)param_3;
  *(byte *)(uVar3 + 0x19) = *(byte *)(uVar3 + 0x19) | 2;
  *(undefined1 *)(uVar3 + 0x1a) = param_4;
  *(undefined2 *)(uVar3 + 0x14) = param_5;
  *(byte *)(uVar3 + 0x19) = *(byte *)(uVar3 + 0x19) | 4;
  *(byte *)(uVar3 + 0x19) = *(byte *)(uVar3 + 0x19) | 8;
  StructMQRacerEntry_MaybeInsertChildEntry(param_1 + 0xc,uVar3);
  uVar2 = param_1 + 0x18U & 3;
  uVar1 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (uVar2 != 0) {
    if (uVar2 != 3) {
      func_0210bc54(uVar2 * 0xc + iRam0210c868,param_1);
      *(undefined4 *)(param_1 + 0x18) = 3;
    }
    StructMQRacerEntry_MaybeInsertChildEntry(iRam0210c868,param_1);
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  return uVar3;
}

