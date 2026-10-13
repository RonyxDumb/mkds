/* Decompiled C draft; module arm9; ROM address 02010998. No matching claim. */
#include "types.h"
#include "deps/02010998_Tex0Block_SetTexturesVramKeys.h"

void Tex0Block_SetTexturesVramKeys(int param_1,int param_2,int param_3)

{
  if (param_2 != 0) {
    *(int *)(param_1 + 8) = param_2;
  }
  if (param_3 != 0) {
    *(int *)(param_1 + 0x18) = param_3;
  }
  return;
}

