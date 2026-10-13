/* Decompiled C draft; module arm9; ROM address 020097ac. No matching claim. */
#include "types.h"
#include "deps/020097ac_SomeFileRead_from_thumb.h"

undefined4 SomeFileRead_from_thumb(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_58 [36];
  int local_34;
  int local_30;
  
  if (param_3 == 0) {
    iVar1 = 0x20;
  }
  else {
    param_2 = param_2 + 0x20;
    iVar1 = iRam02009824;
  }
  if (param_1 == 0) {
    return 0;
  }
  Fs_File_Initialize(auStack_58);
  iVar2 = Fs_File_Open(auStack_58,param_1);
  if (iVar2 == 0) {
    return 0;
  }
  if (iVar1 == local_30 - local_34) {
    Fs_File_Read(auStack_58,param_2,iVar1);
    Fs_File_Close(auStack_58);
    return 1;
  }
  Fs_File_Close(auStack_58);
  return 0;
}

