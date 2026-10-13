/* Decompiled C draft; module arm9; ROM address 02061104. No matching claim. */
#include "types.h"
#include "deps/02061104_CheckFriendCode.h"

undefined4 CheckFriendCode(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  char cVar7;
  int iVar8;
  longlong lVar9;
  longlong lVar10;
  undefined1 auStack_50 [12];
  undefined1 auStack_44 [34];
  byte bStack_22;
  
  lVar9 = ConvertFriendCodeTo64_from_thumb();
  uVar4 = (undefined4)((ulonglong)lVar9 >> 0x20);
  iVar1 = Friend_VerifyChecksum_from_thumb((int)lVar9,uVar4,uRam02061214);
  if (iVar1 == 0) {
    return 1;
  }
  uVar2 = *(uint *)(uRam02061218 & 0xfffffffc) >> (uRam02061218 & 3) * 8 |
          *(uint *)(uRam02061218 & 0xfffffffc) << (uRam02061218 & 3) * -8 + 0x20;
  uVar5 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  lVar10 = PlayerProfileInfo_GetProfileId_from_thumb
                     ((uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) + 0x4c);
  if (lVar9 == lVar10) {
    return 1;
  }
  FriendCode_SetProfileIdAndChecksum_from_thumb(auStack_50,(int)lVar9,uVar4);
  cVar7 = -1;
  uVar5 = (*(uint *)(uRam02061218 & 0xfffffffc) >> (uRam02061218 & 3) * 8 |
          *(uint *)(uRam02061218 & 0xfffffffc) << (uRam02061218 & 3) * -8 + 0x20) + 0x20;
  uVar2 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar6 = 0;
  iVar1 = (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) + iRam0206121c;
  do {
    GlobalZ_GetOI(uVar6,auStack_44);
    if ((int)((uint)bStack_22 << 0x1f) < 0) {
      iVar8 = uVar6 * 0xc + iVar1;
      iVar3 = FriendCode_HasNonzeroState_0_from_thumb(iVar8);
      if ((iVar3 != 0) && (iVar3 = FriendCode_SameAs_from_thumb(iVar8,auStack_50), iVar3 != 0)) {
        cVar7 = (char)uVar6;
        goto LAB_020611f8;
      }
    }
    uVar6 = uVar6 + 1 & 0xff;
    if (0x3b < uVar6) {
LAB_020611f8:
      if (cVar7 == -1) {
        uVar4 = 0;
      }
      else {
        uVar4 = 2;
      }
      return uVar4;
    }
  } while( true );
}

