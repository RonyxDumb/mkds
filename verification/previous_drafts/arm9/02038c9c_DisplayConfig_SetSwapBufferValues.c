/* Decompiled C draft; module arm9; ROM address 02038c9c. No matching claim. */
#include "types.h"
#include "deps/02038c9c_DisplayConfig_SetSwapBufferValues.h"

void DisplayConfig_SetSwapBufferValues(int param_1,undefined1 param_2,undefined1 param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x6cU & 3;
  uVar2 = *(uint *)(param_1 + 0x6cU & 0xfffffffc);
  *(undefined1 *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 2) = param_2;
  uVar1 = param_1 + 0x6cU & 3;
  uVar2 = *(uint *)(param_1 + 0x6cU & 0xfffffffc);
  *(undefined1 *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 3) = param_3;
  return;
}

