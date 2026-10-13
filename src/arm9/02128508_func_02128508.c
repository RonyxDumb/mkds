/* Decompiled C draft; module arm9; ROM address 02128508. No matching claim. */
#include "types.h"
#include "deps/02128508_func_02128508.h"

void func_02128508(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = piRam0212855c;
  *(int *)(*piRam0212855c + iRam02128564) =
       (int)*(char *)(iRam02128560 + *(int *)(*piRam0212855c + 0xc));
  iVar2 = *piVar1;
  *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;
  iVar2 = *piVar1;
  if (8 < *(int *)(iVar2 + 0xc)) {
    if (*(int *)(iVar2 + iRam02128568) == 0) {
      *(undefined4 *)(iVar2 + 8) = 2;
      func_02128624(1);
    }
    else {
      *(undefined4 *)(iVar2 + 8) = 4;
      func_02128624(0);
    }
    piVar1 = piRam0212855c;
    *(undefined4 *)(*piRam0212855c + 0xc) = 0;
    *(undefined4 *)(*piVar1 + iRam0212856c) = 0;
  }
  return;
}

