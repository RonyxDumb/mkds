/* Decompiled C draft; module arm7; ROM address 038026e4. No matching claim. */
#include "types.h"
#include "deps/038026e4_FUN_038026e4.h"

void FUN_038026e4(void)

{
  int iVar1;
  int iVar2;
  
  *DAT_03802718 = 1;
  iVar1 = DAT_0380271c;
  iVar2 = 0;
  *(undefined4 *)(DAT_0380271c + 0x20) = 0;
  do {
    *(undefined2 *)(iVar1 + iVar2 * 2) = 0;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x10);
  return;
}

