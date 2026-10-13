/* Decompiled C draft; module arm9; ROM address 02058efc. No matching claim. */
#include "types.h"
#include "deps/02058efc_func_02058efc.h"

void func_02058efc(void)

{
  int iVar1;
  
  iVar1 = Maybe_data_Sound_sound_data();
  if (iVar1 == 0) {
    *(undefined1 *)(*piRam02058f18 + iRam02058f1c) = 1;
  }
  return;
}

