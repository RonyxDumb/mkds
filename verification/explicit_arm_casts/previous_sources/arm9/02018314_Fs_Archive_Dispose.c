/* Decompiled C draft; module arm9; ROM address 02018314. No matching claim. */
#include "types.h"
#include "deps/02018314_Fs_Archive_Dispose.h"

undefined4 Fs_Archive_Dispose(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = Fs_Archive_UnloadFatFnt();
  if (iVar1 != 0) {
    Fs_UnregisterArchive(param_1);
    return 1;
  }
  return 0;
}

