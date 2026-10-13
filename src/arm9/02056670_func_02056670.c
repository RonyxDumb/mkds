/* Decompiled C draft; module arm9; ROM address 02056670. No matching claim. */
#include "types.h"
#include "deps/02056670_func_02056670.h"

void func_02056670(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(*piRam020566a4 + 0x18);
  iVar1 = func_020573c8();
  if (iVar1 == 0) {
    *(uint *)(iVar2 + 8) = *(uint *)(iVar2 + 8) & 0xfffffffe;
    return;
  }
  ReadSaveDataSection_DownloadGhost_from_thumb(param_1,iVar2);
  return;
}

