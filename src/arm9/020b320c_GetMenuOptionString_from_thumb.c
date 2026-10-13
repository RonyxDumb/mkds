/* Decompiled C draft; module arm9; ROM address 020b320c. No matching claim. */
#include "types.h"
#include "deps/020b320c_GetMenuOptionString_from_thumb.h"

void GetMenuOptionString_from_thumb(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 local_40 [8];
  undefined4 local_20;
  
  puVar4 = local_40;
  iVar3 = 5;
  puVar5 = puRam020b3258;
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
  iVar3 = GetDisplayMode_0();
  if (iVar3 == 2) {
    local_40[0] = 0x6a;
    local_20 = 99;
  }
  if (param_1 != 0) {
    local_40[2] = 0x60;
  }
  uVar1 = func_020b47cc(uRam020b325c);
  Bmg_GetRawStringPointer_from_thumb(uVar1,local_40[param_2]);
  return;
}

