/* Decompiled C draft; module arm7; ROM address 037fbb74. No matching claim. */
#include "types.h"
#include "deps/037fbb74_FUN_037fbb74.h"

void FUN_037fbb74(int param_1)

{
  int iVar1;
  int iVar2;
  
  *DAT_037fbbd0 = param_1;
  iVar1 = DAT_037fbbd4;
  if (-1 < param_1) {
    iVar1 = 0;
    do {
      *(char *)(iVar1 * 0x10 + 0x4000402) = (char)param_1;
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x10);
    return;
  }
  iVar2 = 0;
  do {
    *(undefined1 *)(iVar2 * 0x10 + 0x4000402) = *(undefined1 *)(iVar1 + iVar2);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x10);
  return;
}

