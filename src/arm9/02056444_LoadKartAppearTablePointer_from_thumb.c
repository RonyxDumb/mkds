/* Decompiled C draft; module arm9; ROM address 02056444. No matching claim. */
#include "types.h"
#include "deps/02056444_LoadKartAppearTablePointer_from_thumb.h"

undefined4 * LoadKartAppearTablePointer_from_thumb(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)Mem_AllocateHeap(param_1,4);
  uVar2 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam02056460);
  *puVar1 = uVar2;
  return puVar1;
}

