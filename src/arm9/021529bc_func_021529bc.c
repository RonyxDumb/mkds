/* Decompiled C draft; module arm9; ROM address 021529bc. No matching claim. */
#include "types.h"
#include "deps/021529bc_func_021529bc.h"

void func_021529bc(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FriendCode_GetState_from_thumb();
  if (iVar1 == 3) {
    uVar2 = FriendCode_GetFlags_from_thumb((uint *)(uintptr_t)(param_1));
    FriendCode_SetFlags_from_thumb(param_1,uVar2 | 4);
  }
  return;
}

