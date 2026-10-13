/* Decompiled C draft; module arm9; ROM address 0208832c. No matching claim. */
#include "types.h"
#include "deps/0208832c_Anim_GetFrameCount_BCA.h"

undefined2 Anim_GetFrameCount_BCA(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 8U & 3;
  uVar2 = *(uint *)(param_1 + 8U & 0xfffffffc);
  return *(undefined2 *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 4);
}

