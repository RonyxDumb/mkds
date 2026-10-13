/* Decompiled C draft; module arm9; ROM address 020578fc. No matching claim. */
#include "types.h"
#include "deps/020578fc_ReadSaveDataSection_DownloadGhost_from_thumb.h"

void ReadSaveDataSection_DownloadGhost_from_thumb(int param_1,undefined4 param_2)

{
  int *piVar1;
  
  piVar1 = piRam02057930;
  if (*(int *)(*piRam02057930 + 0xc) != 0) {
    *(undefined4 *)(*piRam02057930 + 0x68) = param_2;
    *(char *)(*piVar1 + 0x6c) = (char)param_1;
    ReadSaveChunkImpl2_from_thumb
              (param_1 * 0x1000 + iRam02057938,*(undefined4 *)(*piVar1 + 0x60),uRam0205793c,
               uRam02057940,uRam02057934);
  }
  return;
}

