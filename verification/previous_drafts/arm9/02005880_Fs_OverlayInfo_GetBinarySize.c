/* Decompiled C draft; module arm9; ROM address 02005880. No matching claim. */
#include "types.h"
#include "deps/02005880_Fs_OverlayInfo_GetBinarySize.h"

uint Fs_OverlayInfo_GetBinarySize(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  if ((*(byte *)(param_1 + 0x1f) & 1) == 0) {
    uVar2 = param_1 + 8U & 3;
    uVar1 = *(uint *)(param_1 + 8U & 0xfffffffc);
    uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  }
  else {
    uVar2 = param_1 + 0x1cU & 3;
    uVar1 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
    uVar2 = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0xffffff;
  }
  return uVar2;
}

