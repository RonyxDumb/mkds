/* Decompiled C draft; module arm9; ROM address 020fd308. No matching claim. */
#include "types.h"
#include "deps/020fd308_func_020fd308.h"

int func_020fd308(int param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar3 = uRam020fd334;
  uVar1 = param_1 + 0x188U & 3;
  uVar4 = *(uint *)(param_1 + 0x188U & 0xfffffffc);
  *param_2 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0x70U & 3;
  uVar5 = *(uint *)(param_1 + 0x70U & 0xfffffffc);
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) *
          (longlong)(int)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20);
  *param_3 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  return param_1 + 0x50;
}

