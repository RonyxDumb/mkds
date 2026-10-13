/* Decompiled C draft; module arm9; ROM address 02119e50. No matching claim. */
#include "types.h"
#include "deps/02119e50_func_02119e50.h"

void func_02119e50(void)

{
  int iVar1;
  
  iVar1 = GetSelectedCup_from_thumb();
  func_02029580(*(undefined4 *)
                 (*(short *)(*piRam02119e84 + 0x50) * 4 +
                 iRam02119e80 + *(int *)(iRam02119e7c + iVar1 * 4) * 0x10));
  return;
}

