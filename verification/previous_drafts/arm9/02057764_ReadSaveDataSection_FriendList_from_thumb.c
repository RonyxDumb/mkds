/* Decompiled C draft; module arm9; ROM address 02057764. No matching claim. */
#include "types.h"
#include "deps/02057764_ReadSaveDataSection_FriendList_from_thumb.h"

void ReadSaveDataSection_FriendList_from_thumb(undefined4 param_1)

{
  int *piVar1;
  
  piVar1 = piRam0205779c;
  if (*(int *)(*piRam0205779c + 0xc) != 0) {
    *(undefined4 *)(*piRam0205779c + 0x68) = param_1;
    *(undefined4 *)(*piVar1 + 0x5c) = 0xffffffff;
    ReadSaveChunkImpl_from_thumb
              (uRam020577a8,uRam020577ac,*(undefined4 *)(*piVar1 + 0x60),uRam020577b0,uRam020577a0,
               uRam020577a4,0);
  }
  return;
}

