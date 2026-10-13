/* Decompiled C draft; module arm9; ROM address 0211f6e8. No matching claim. */
#include "types.h"
#include "deps/0211f6e8_func_0211f6e8.h"

void func_0211f6e8(undefined1 param_1,undefined1 param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  OI_JoinInSlot1FreeSlot2(param_2,param_1);
  CopyFriendCodesToSaveData
            ((*(uint *)(uRam0211f76c & 0xfffffffc) >> (uRam0211f76c & 3) * 8 |
             *(uint *)(uRam0211f76c & 0xfffffffc) << (uRam0211f76c & 3) * -8 + 0x20) + iRam0211f770)
  ;
  func_02060b68();
  WriteFriendListSaveDataSection();
  uVar3 = *(uint *)(uRam0211f778 & 0xfffffffc) >> (uRam0211f778 & 3) * 8 |
          *(uint *)(uRam0211f778 & 0xfffffffc) << (uRam0211f778 & 3) * -8 + 0x20;
  do {
    if (*(char *)((*(uint *)(uRam0211f774 & 0xfffffffc) >> (uRam0211f774 & 3) * 8 |
                  *(uint *)(uRam0211f774 & 0xfffffffc) << (uRam0211f774 & 3) * -8 + 0x20) + 0x28) ==
        '\0') {
      uVar2 = uVar3 + 0xc;
      uVar1 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      if (uVar2 >> uVar1 * 8 == 0 && uVar2 << uVar1 * -8 + 0x20 == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = uVar3 + 0x10;
        uVar1 = uVar2 & 3;
        uVar2 = *(uint *)(uVar2 & 0xfffffffc);
        uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
      }
    }
    else {
      uVar2 = 1;
    }
  } while (uVar2 != 0);
  return;
}

