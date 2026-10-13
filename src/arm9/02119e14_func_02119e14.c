/* Decompiled C draft; module arm9; ROM address 02119e14. No matching claim. */
#include "types.h"
#include "deps/02119e14_func_02119e14.h"

void func_02119e14(void)

{
  int iVar1;
  
  iVar1 = GetSelectedCup_from_thumb();
  func_0211e418(*(undefined4 *)
                 (*(short *)(*piRam02119e4c + 0x50) * 4 +
                 iRam02119e48 + *(int *)(iRam02119e44 + iVar1 * 4) * 0x10));
  func_0202949c(0);
  return;
}

