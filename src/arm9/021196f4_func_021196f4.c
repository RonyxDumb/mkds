/* Decompiled C draft; module arm9; ROM address 021196f4. No matching claim. */
#include "types.h"
#include "deps/021196f4_func_021196f4.h"

void func_021196f4(void)

{
  int iVar1;
  
  if (*(int *)(*piRam0211975c + 0x6c) == 1) {
    if (*(int *)(*piRam0211975c + 0x40) == 0) {
      iVar1 = func_0211e130();
      if (iVar1 != 0) {
        *puRam02119760 = *puRam02119760 & uRam02119764 | uRam02119768;
      }
    }
    else {
      *puRam02119760 = *puRam02119760 & uRam02119764 | uRam02119768;
    }
  }
  if (*psRam0211976c == 2) {
    func_0211f498();
  }
  else {
    func_0211de34();
    func_0211df38();
  }
  Mem_DestroyHeap(*(undefined4 *)(*piRam0211975c + 0x30));
  *piRam0211975c = 0;
  return;
}

