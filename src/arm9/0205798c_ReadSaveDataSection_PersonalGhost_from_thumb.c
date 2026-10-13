/* Decompiled C draft; module arm9; ROM address 0205798c. No matching claim. */
#include "types.h"
#include "deps/0205798c_ReadSaveDataSection_PersonalGhost_from_thumb.h"

void ReadSaveDataSection_PersonalGhost_from_thumb(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = iRam020579bc;
  param_1 = iRam020579bc * param_1;
  iVar2 = *piRam020579c0;
  if (*(int *)(iVar2 + 0xc) != 0) {
    *(undefined4 *)(iVar2 + 0x68) = param_2;
    ReadSaveChunkImpl2_from_thumb
              (param_1 + iRam020579c8,*(undefined4 *)(iVar2 + 0x60),iVar1,uRam020579cc,uRam020579c4)
    ;
  }
  return;
}

