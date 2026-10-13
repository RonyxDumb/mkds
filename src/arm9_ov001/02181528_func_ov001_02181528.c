/* Decompiled C draft; module arm9_ov001; ROM address 02181528. No matching claim. */
#include "types.h"
#include "deps/02181528_func_ov001_02181528.h"

/* WARNING: Removing unreachable block (ram,0x02181540) */

undefined4 func_ov001_02181528(void)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(int *)(*piRam02181554 + 8) == 4) {
    uVar1 = FUN_02181b54();
    iVar2 = FUN_02181b68(uVar1);
  }
  else {
    iVar2 = 0;
  }
  return *(undefined4 *)(iVar2 + iRam02181558);
}

