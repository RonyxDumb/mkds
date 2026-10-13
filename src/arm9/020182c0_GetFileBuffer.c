/* Decompiled C draft; module arm9; ROM address 020182c0. No matching claim. */
#include "types.h"
#include "deps/020182c0_GetFileBuffer.h"

int GetFileBuffer(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined1 auStack_58 [8];
  int local_50;
  int local_34;
  
  iVar4 = 0;
  Fs_File_Initialize((undefined4 *)(void *)(auStack_58));
  iVar2 = Fs_File_Open(auStack_58,param_1);
  if (iVar2 != 0) {
    uVar1 = local_50 + 100U & 3;
    uVar3 = *(uint *)(local_50 + 100U & 0xfffffffc);
    iVar4 = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + local_34;
    Fs_File_Close((int)(uintptr_t)(auStack_58));
  }
  return iVar4;
}

