/* Decompiled C draft; module arm9; ROM address 020260e4. No matching claim. */
#include "types.h"
#include "deps/020260e4_func_020260e4.h"

void func_020260e4(void)

{
  int iVar1;
  
  if (*psRam02026118 == 2) {
    iVar1 = GetGlobalCA_from_thumb();
    if (*(int *)(iVar1 + 200) == 2) {
      func_0211f498();
    }
  }
  Mem_DestroyHeap(*(undefined4 *)(*piRam0202611c + 0x5c));
  *piRam0202611c = 0;
  return;
}

