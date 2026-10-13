/* Decompiled C draft; module arm9; ROM address 020487a0. No matching claim. */
#include "types.h"
#include "deps/020487a0_InitializeMountDatas_from_thumb.h"

void InitializeMountDatas_from_thumb(int param_1)

{
  int iVar1;
  
  iVar1 = *piRam020487cc + iRam020487d0 + param_1 * 0xc;
  *(undefined4 *)(*piRam020487cc + iRam020487d0 + param_1 * 0xc) = 0;
  *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) & uRam020487d4;
  *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) | uRam020487d8;
  *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) & uRam020487dc;
  return;
}

