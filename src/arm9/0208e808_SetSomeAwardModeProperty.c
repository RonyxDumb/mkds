/* Decompiled C draft; module arm9; ROM address 0208e808. No matching claim. */
#include "types.h"
#include "deps/0208e808_SetSomeAwardModeProperty.h"

void SetSomeAwardModeProperty(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam0208e824 & 0xfffffffc) >> (uRam0208e824 & 3) * 8 |
          *(uint *)(uRam0208e824 & 0xfffffffc) << (uRam0208e824 & 3) * -8 + 0x20) + 0xc;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 5) {
    *puRam0208e828 = param_1;
  }
  return;
}

