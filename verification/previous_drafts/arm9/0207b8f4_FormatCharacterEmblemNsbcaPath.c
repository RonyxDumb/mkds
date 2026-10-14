/* Decompiled C draft; module arm9; ROM address 0207b8f4. No matching claim. */
#include "types.h"
#include "deps/0207b8f4_FormatCharacterEmblemNsbcaPath.h"

char * FormatCharacterEmblemNsbcaPath(undefined4 param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar2 = FormatCharacterPath();
  uVar3 = FormatCharacterEmblemName(param_1,1);
  uVar4 = iRam0207b954 + param_2 * 0xc;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  _snprintf(pcRam0207b958,0x100,pcRam0207b95c,uVar2,uVar3,
            uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
  return pcRam0207b958;
}

