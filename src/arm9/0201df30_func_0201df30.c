/* Decompiled C draft; module arm9; ROM address 0201df30. No matching claim. */
#include "types.h"
#include "deps/0201df30_func_0201df30.h"

void func_0201df30(int param_1,int param_2,int param_3)

{
  uint uVar1;
  short sVar2;
  short sVar3;
  uint uVar4;
  short *psVar5;
  
  uVar1 = param_2 + 4U & 3;
  uVar4 = *(uint *)(param_2 + 4U & 0xfffffffc);
  psVar5 = (short *)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
  if (param_3 < (int)(uint)*(byte *)(psVar5 + 3)) {
    sVar2 = *psVar5;
    sVar3 = _s32_div_f(param_3 * ((int)psVar5[1] - (int)sVar2));
    *(short *)(param_1 + 0x34) = sVar2 + sVar3;
    return;
  }
  if ((int)(uint)*(byte *)((int)psVar5 + 7) <= param_3) {
    sVar2 = psVar5[2];
    sVar3 = _s32_div_f((param_3 + -0xff) * ((int)sVar2 - (int)psVar5[1]),
                       0xff - (uint)*(byte *)((int)psVar5 + 7));
    *(short *)(param_1 + 0x34) = sVar2 + sVar3;
    return;
  }
  *(short *)(param_1 + 0x34) = psVar5[1];
  return;
}

