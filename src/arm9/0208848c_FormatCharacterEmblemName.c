/* Decompiled C draft; module arm9; ROM address 0208848c. No matching claim. */
#include "types.h"
#include "deps/0208848c_FormatCharacterEmblemName.h"

uint FormatCharacterEmblemName(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  if (param_2 == 0) {
    uVar2 = iRam020884b8 + param_1 * 0xc;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  }
  else {
    uVar2 = iRam020884b4 + param_1 * 0xc;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  }
  return uVar2;
}

