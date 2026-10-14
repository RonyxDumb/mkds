/* Decompiled C draft; module arm9; ROM address 02005814. No matching claim. */
#include "types.h"
#include "deps/02005814_Fs_GetOverlayFileId.h"

void Fs_GetOverlayFileId(undefined4 *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_2 + 0x18U & 3;
  uVar2 = *(uint *)(param_2 + 0x18U & 0xfffffffc);
  *param_1 = uRam02005838;
  param_1[1] = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  return;
}

