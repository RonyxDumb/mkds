/* Decompiled C draft; module arm9; ROM address 021282c8. No matching claim. */
#include "types.h"
#include "deps/021282c8_func_021282c8.h"

void func_021282c8(void)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = func_02128274();
  if (iVar2 == 0) {
    *(undefined4 *)(*piRam02128300 + iRam02128304) = 1;
  }
  else {
    *(undefined4 *)(*piRam02128300 + iRam02128304) = 0;
  }
  piVar1 = piRam02128300;
  *(undefined4 *)(*piRam02128300 + iRam02128308) = 0;
  *(undefined4 *)(*piVar1 + iRam0212830c) = 0;
  return;
}

