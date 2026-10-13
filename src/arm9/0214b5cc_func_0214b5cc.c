/* Decompiled C draft; module arm9; ROM address 0214b5cc. No matching claim. */
#include "types.h"
#include "deps/0214b5cc_func_0214b5cc.h"

void func_0214b5cc(void)

{
  int iVar1;
  
  iVar1 = func_02149018();
  *piRam0214b62c = iVar1;
  if (iVar1 == 0) {
    return;
  }
  if (iVar1 == 0x20) {
    *puRam0214b634 = uRam0214b638;
    return;
  }
  if (iVar1 == 0x40) {
    *puRam0214b634 = uRam0214b630;
  }
  return;
}

