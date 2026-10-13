/* Decompiled C draft; module arm9; ROM address 02060468. No matching claim. */
#include "types.h"
#include "deps/02060468_func_02060468.h"

bool func_02060468(int param_1,undefined4 param_2)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined8 uVar6;
  undefined1 auStack_38 [34];
  byte local_16;
  
  GlobalZ_GetOI(param_1,auStack_38);
  uVar4 = (*(uint *)(uRam02060508 & 0xfffffffc) >> (uRam02060508 & 3) * 8 |
          *(uint *)(uRam02060508 & 0xfffffffc) << (uRam02060508 & 3) * -8 + 0x20) + 0x20;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  iVar5 = param_1 * 0xc + (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) + iRam0206050c;
  if ((((int)((uint)local_16 << 0x1f) < 0) && ((int)((uint)local_16 << 0x1e) < 0)) &&
     (iVar3 = FriendCode_HasNonzeroState_from_thumb(iVar5), iVar3 != 0)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    uVar6 = FriendCode_GetFriendCodePacked_0_from_thumb(iVar5);
    PrintfUll_from_thumb((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),param_2);
  }
  return bVar2;
}

