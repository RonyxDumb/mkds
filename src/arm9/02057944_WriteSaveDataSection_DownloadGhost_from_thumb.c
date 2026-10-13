/* Decompiled C draft; module arm9; ROM address 02057944. No matching claim. */
#include "types.h"
#include "deps/02057944_WriteSaveDataSection_DownloadGhost_from_thumb.h"

void WriteSaveDataSection_DownloadGhost_from_thumb(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(*piRam0205797c + 0x60);
  if (*(int *)(*piRam0205797c + 0xc) != 0) {
    Mem_CpuCopy8((ushort *)(uintptr_t)(param_2),puVar1,uRam02057980);
    *puVar1 = uRam02057984;
    SV_MaybeCompressWriteNoFlagsBC_from_thumb(param_1 * 0x1000 + iRam02057988,puVar1,uRam02057980,0)
    ;
  }
  return;
}

