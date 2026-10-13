/* Decompiled C draft; module arm9; ROM address 020576b8. No matching claim. */
#include "types.h"
#include "deps/020576b8_ReadSaveDataSection_NKFE_from_thumb.h"

void ReadSaveDataSection_NKFE_from_thumb(undefined4 param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = piRam020576fc;
  iVar1 = iRam020576f8;
  param_2 = iRam020576f8 * param_2;
  if (*(int *)(*piRam020576fc + 0xc) != 0) {
    *(undefined4 *)(*piRam020576fc + 0x68) = param_1;
    *(undefined4 *)(*piVar2 + 0x5c) = 0xffffffff;
    ReadSaveChunkImpl_from_thumb
              (param_2 + iRam02057708,param_2 + iRam0205770c,*(undefined4 *)(*piVar2 + 0x60),iVar1,
               uRam02057700,uRam02057704,0);
  }
  return;
}

