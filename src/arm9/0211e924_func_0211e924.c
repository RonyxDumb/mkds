/* Decompiled C draft; module arm9; ROM address 0211e924. No matching claim. */
#include "types.h"
#include "deps/0211e924_func_0211e924.h"

void func_0211e924(void)

{
  if (*psRam0211e950 == 2) {
    func_0211f498();
  }
  else {
    func_0211de34();
  }
  Mem_DestroyHeap(*(undefined4 *)(*piRam0211e954 + 0x28));
  *piRam0211e954 = 0;
  return;
}

