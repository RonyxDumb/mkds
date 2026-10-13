/* Decompiled C draft; module arm9; ROM address 02025c94. No matching claim. */
#include "types.h"
#include "deps/02025c94_func_02025c94.h"

void func_02025c94(undefined4 param_1,ushort param_2,ushort param_3,undefined4 param_4)

{
  ushort uVar1;
  ushort uVar2;
  ushort *puVar3;
  
  puVar3 = (ushort *)func_0201ea30(param_4,param_1);
  uVar1 = (ushort)uRam02025cc8;
  uVar2 = (ushort)uRam02025ccc;
  *puVar3 = *puVar3 & uVar1 | param_2 & uVar2;
  puVar3[1] = puVar3[1] & uVar1 | param_3 & uVar2;
  return;
}

