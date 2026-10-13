/* Decompiled C draft; module arm9; ROM address 020ffeb8. No matching claim. */
#include "types.h"
#include "deps/020ffeb8_func_020ffeb8.h"

void func_020ffeb8(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = (int)((uint)*(ushort *)(param_2 + 0xa6) * -0x10000 >> 0x10) >> 4;
  MTX_RotX33__from_thumb
            ((undefined4 *)(uintptr_t)(param_2 + 0x28),(int)*(short *)(iRam020fff44 + iVar1 * 4),
             (int)*(short *)(iRam020fff44 + (iVar1 * 2 + 1) * 2));
  uVar3 = uRam020fff48;
  uVar2 = param_2 + 4U & 3;
  uVar4 = *(uint *)(param_2 + 4U & 0xfffffffc);
  *(int *)(param_2 + 0x4c) = (int)(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) >> 4;
  uVar2 = param_2 + 8U & 3;
  uVar4 = *(uint *)(param_2 + 8U & 0xfffffffc);
  *(int *)(param_2 + 0x50) = (int)(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) >> 4;
  uVar2 = param_2 + 0xcU & 3;
  uVar4 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
  *(int *)(param_2 + 0x54) = (int)(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) >> 4;
  uVar2 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  func_020ea8a8(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20,param_2 + 0x28,param_2 + 0x1c,
                param_4);
  return;
}

