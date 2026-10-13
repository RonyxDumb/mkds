/* Decompiled C draft; module arm9; ROM address 020ae178. No matching claim. */
#include "types.h"
#include "deps/020ae178_GetCharacterNameString_from_thumb.h"

void GetCharacterNameString_from_thumb(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 local_48 [14];
  
  puVar4 = local_48;
  iVar3 = 6;
  puVar5 = puRam020ae1c8;
  do {
    uVar1 = *puVar5;
    uVar2 = puVar5[1];
    puVar5 = puVar5 + 2;
    *puVar4 = uVar1;
    puVar4[1] = uVar2;
    puVar4 = puVar4 + 2;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *puVar4 = *puVar5;
  if ((param_2 == 0) || (param_1 != 1)) {
    if ((param_2 == 0) || (param_1 != 8)) {
      uVar1 = local_48[param_1];
    }
    else {
      uVar1 = 0x22;
    }
  }
  else {
    uVar1 = 0x21;
  }
  uVar2 = func_020b47cc(uRam020ae1cc);
  Bmg_GetRawStringPointer_from_thumb(uVar2,uVar1);
  return;
}

