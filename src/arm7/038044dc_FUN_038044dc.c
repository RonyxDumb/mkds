/* Decompiled C draft; module arm7; ROM address 038044dc. No matching claim. */
#include "types.h"
#include "deps/038044dc_FUN_038044dc.h"

void FUN_038044dc(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_03804500;
  iVar2 = 0;
  do {
    *(undefined2 *)(iVar1 + iVar2 * 2) = 0;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x10);
  return;
}

