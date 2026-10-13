/* Decompiled C draft; module arm7; ROM address 06001c98. No matching claim. */
#include "types.h"
#include "deps/06001c98_FUN_06001c98.h"

void FUN_06001c98(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  
  iVar3 = FUN_06000680();
  uVar4 = thunk_FUN_037faf70();
  uVar1 = iVar3 + 0x1544U & 3;
  uVar5 = *(uint *)(iVar3 + 0x1544U & 0xfffffffc);
  uVar2 = iVar3 + 0x1548U & 3;
  uVar6 = *(uint *)(iVar3 + 0x1548U & 0xfffffffc);
  thunk_FUN_037f9fd8(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20,
                     uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20,param_1);
  thunk_FUN_037faf84(uVar4);
  return;
}

