/* Decompiled C draft; module arm9; ROM address 0210c558. No matching claim. */
#include "types.h"
#include "deps/0210c558_StructMQRacerEntry_SomeFn_75.h"

void StructMQRacerEntry_SomeFn_75(int param_1,uint param_2,uint param_3,undefined4 param_4)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = iRam0210c60c + 0x10U & 3;
  uVar2 = *(uint *)(iRam0210c60c + 0x10U & 0xfffffffc);
  if (uVar2 >> uVar3 * 8 == 0 && uVar2 << uVar3 * -8 + 0x20 == 0) {
    return;
  }
  uVar3 = param_1 + 0xcU & 3;
  uVar2 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if (uVar3 == 0) {
    return;
  }
  do {
    if (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 == 0 &&
        *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20 == 0) {
LAB_0210c5d4:
      bVar1 = false;
    }
    else {
      if ((*(ushort *)(uVar3 + 0x16) == param_3) && (*(byte *)(uVar3 + 0x18) == param_2)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (!bVar1) goto LAB_0210c5d4;
      bVar1 = true;
    }
    if (bVar1) {
      StructMQRacerEntry_SomeFn_9(param_1,uVar3,param_4);
      return;
    }
    uVar3 = IntrusiveListWrapper_NextItem(param_1 + 0xc);
    if (uVar3 == 0) {
      return;
    }
  } while( true );
}

