/* Decompiled C draft; module arm9; ROM address 02042044. No matching claim. */
#include "types.h"
#include "deps/02042044_GetLoadedNkmPathEntryPOIT.h"

int GetLoadedNkmPathEntryPOIT(undefined4 param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = GetLoadedNkmPathEntry_from_thumb();
  uVar1 = iVar2 + 4U & 3;
  uVar3 = *(uint *)(iVar2 + 4U & 0xfffffffc);
  return param_2 * 0x14 + (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
}

