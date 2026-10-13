/* Decompiled C draft; module arm9; ROM address 0204ea14. No matching claim. */
#include "types.h"
#include "deps/0204ea14_SetGlobalBAN_from_thumb.h"

void SetGlobalBAN_from_thumb(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar2 = Bmg_GetRawStringPointer_from_thumb(param_1,0);
  uVar3 = Bmg_GetRawStringPointer_from_thumb(param_1,1);
  iVar1 = iRam0204ea38;
  *(undefined4 *)(iRam0204ea38 + 4) = uVar2;
  *(undefined4 *)(iVar1 + 8) = uVar3;
  return;
}

