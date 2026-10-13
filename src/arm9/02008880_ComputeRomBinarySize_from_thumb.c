/* Decompiled C draft; module arm9; ROM address 02008880. No matching claim. */
#include "types.h"
#include "deps/02008880_ComputeRomBinarySize_from_thumb.h"

uint ComputeRomBinarySize_from_thumb(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 auStack_78 [100];
  
  puVar4 = puRam020088d0;
  if (param_1 != 0) {
    iVar3 = *(int *)(param_1 + 0x2c);
    iVar2 = *(int *)(param_1 + 0x24);
    uVar1 = Fs_File_Read(param_1,auStack_78,0x60);
    puVar4 = (undefined1 *)0x0;
    if (0x5f < uVar1) {
      puVar4 = auStack_78;
    }
    Fs_File_Seek(param_1,iVar3 - iVar2,0);
  }
  uVar1 = 0;
  if ((puVar4 != (undefined1 *)0x0) &&
     (uVar1 = *(int *)(puVar4 + 0x2c) + iRam020088d4 + *(int *)(puVar4 + 0x3c), uVar1 < uRam020088d8
     )) {
    uVar1 = uRam020088d8;
  }
  return uVar1;
}

