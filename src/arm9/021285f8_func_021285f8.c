/* Decompiled C draft; module arm9; ROM address 021285f8. No matching claim. */
#include "types.h"
#include "deps/021285f8_func_021285f8.h"

void func_021285f8(void)

{
  int *piVar1;
  
  piVar1 = piRam0212861c;
  if (*(int *)(*piRam0212861c + iRam02128620) != 0) {
    *(undefined4 *)(*piRam0212861c + 8) = 1;
    *(undefined4 *)(*piVar1 + 0xc) = 0;
    func_02128624();
  }
  return;
}

