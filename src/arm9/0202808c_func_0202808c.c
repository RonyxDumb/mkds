/* Decompiled C draft; module arm9; ROM address 0202808c. No matching claim. */
#include "types.h"
#include "deps/0202808c_func_0202808c.h"

void func_0202808c(void)

{
  int iVar1;
  
  if ((*(int *)(*piRam020280d4 + iRam020280d8) == 1) && (iVar1 = func_0202811c(), iVar1 == 2)) {
    func_021281fc();
  }
  iVar1 = func_020280dc();
  if (iVar1 == 0) {
    func_0212b91c();
  }
  else {
    func_0211f498();
  }
  Mem_DestroyHeap(*(undefined4 *)(*piRam020280d4 + 0x8c));
  *piRam020280d4 = 0;
  return;
}

