/* Decompiled C draft; module arm9; ROM address 0212b158. No matching claim. */
#include "types.h"
#include "deps/0212b158_InitializeGlobal1A44_from_thumb.h"

void InitializeGlobal1A44_from_thumb(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = Mem_AllocateHeap(param_1,uRam0212b1a0);
  *piRam0212b1a4 = iVar1;
  G2d_Sprite_CreateFromTiles(iVar1 + 0x14,iVar1 + 0x44,0x20,5,4);
  iVar1 = *piRam0212b1a4;
  *(int *)(iVar1 + 0x34) = iVar1 + 0x14;
  *(undefined4 *)(iVar1 + 0x38) = 0;
  *(undefined4 *)(iVar1 + 0x3c) = 1;
  *(undefined4 *)(iVar1 + 0x40) = 2;
  ResetMultiplayErrors_from_thumb();
  return;
}

