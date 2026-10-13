/* Decompiled C draft; module arm9; ROM address 0212d9dc. No matching claim. */
#include "types.h"
#include "deps/0212d9dc_Sound_Context_SetHeap.h"

bool Sound_Context_SetHeap(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  
  IntrusiveListWrapper_InitializeEmpty(param_1 + 1,0xc);
  *param_1 = param_2;
  iVar1 = Sound_Context_MaybeReset(param_1);
  return iVar1 != 0;
}

