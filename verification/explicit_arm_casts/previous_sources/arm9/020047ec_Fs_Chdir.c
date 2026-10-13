/* Decompiled C draft; module arm9; ROM address 020047ec. No matching claim. */
#include "types.h"
#include "deps/020047ec_Fs_Chdir.h"

bool Fs_Chdir(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined1 auStack_54 [76];
  
  Fs_File_Initialize(auStack_54);
  iVar2 = Fs_File_FindPath(auStack_54,param_1);
  puVar1 = puRam0200483c;
  if (iVar2 != 0) {
    *puRam0200483c = uStack_60;
    puVar1[1] = uStack_5c;
    puVar1[2] = uStack_58;
  }
  return iVar2 != 0;
}

