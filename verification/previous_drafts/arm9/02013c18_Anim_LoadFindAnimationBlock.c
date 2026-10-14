/* Decompiled C draft; module arm9; ROM address 02013c18. No matching claim. */
#include "types.h"
#include "deps/02013c18_Anim_LoadFindAnimationBlock.h"

uint Anim_LoadFindAnimationBlock(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  
  if (((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
       *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) == param_2) &&
     (uVar2 = 0, *(short *)(param_1 + 0xe) != 0)) {
    do {
      uVar1 = Anim_GetBlock(param_1,uVar2);
      if ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) == param_3) {
        return uVar1;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(ushort *)(param_1 + 0xe));
  }
  return 0;
}

