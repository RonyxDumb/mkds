/* Decompiled C draft; module arm9; ROM address 0205edcc. No matching claim. */
#include "types.h"
#include "deps/0205edcc_SaveFriendList.h"

void SaveFriendList(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam0205edf4 & 0xfffffffc) >> (uRam0205edf4 & 3) * 8 |
          *(uint *)(uRam0205edf4 & 0xfffffffc) << (uRam0205edf4 & 3) * -8 + 0x20) + 0x20;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  WriteSaveDataSection_FriendList_from_thumb(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  WriteSaveDataHeader_from_thumb();
  return;
}

