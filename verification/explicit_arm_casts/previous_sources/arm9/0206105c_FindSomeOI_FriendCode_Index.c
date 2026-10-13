/* Decompiled C draft; module arm9; ROM address 0206105c. No matching claim. */
#include "types.h"
#include "deps/0206105c_FindSomeOI_FriendCode_Index.h"

int FindSomeOI_FriendCode_Index(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 auStack_48 [34];
  byte local_26;
  
  uVar2 = (*(uint *)(uRam020610fc & 0xfffffffc) >> (uRam020610fc & 3) * 8 |
          *(uint *)(uRam020610fc & 0xfffffffc) << (uRam020610fc & 3) * -8 + 0x20) + 0x20;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  iVar4 = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + iRam02061100;
  uVar2 = 0;
  do {
    GlobalZ_GetOI(uVar2,auStack_48);
    if ((int)((uint)local_26 << 0x1f) < 0) {
      iVar5 = uVar2 * 0xc + iVar4;
      iVar3 = FriendCode_HasNonzeroState_0_from_thumb(iVar5);
      if ((iVar3 != 0) && (iVar3 = FriendCode_SameAs_from_thumb(iVar5,param_1), iVar3 != 0)) {
        return (int)(char)uVar2;
      }
    }
    uVar2 = uVar2 + 1 & 0xff;
    if (0x3b < uVar2) {
      return -1;
    }
  } while( true );
}

