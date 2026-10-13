/* Decompiled C draft; module arm9; ROM address 020577b4. No matching claim. */
#include "types.h"
#include "deps/020577b4_WriteSaveDataSection_FriendList_from_thumb.h"

void WriteSaveDataSection_FriendList_from_thumb(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(*piRam020577ec + 0x60);
  if (*(int *)(*piRam020577ec + 0xc) != 0) {
    Mem_CpuCopy8(param_1,puVar1,uRam020577f0);
    *puVar1 = uRam020577f4;
    SV_MaybeCompressWriteTwoOffsetsFlagC_from_thumb
              (uRam020577f8,uRam020577fc,puVar1,uRam020577f0,0,0);
  }
  return;
}

