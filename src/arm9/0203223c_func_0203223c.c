/* Decompiled C draft; module arm9; ROM address 0203223c. No matching claim. */
#include "types.h"
#include "deps/0203223c_func_0203223c.h"

void func_0203223c(void)

{
  if (*(int *)(*piRam02032278 + 0x68) == 1) {
    func_0202b604();
    if (*(int *)(*piRam0203227c + 0x1c) << 0x1d < 0) {
      func_020cee5c();
    }
  }
  Mem_DestroyHeap(*(undefined4 *)(*piRam02032278 + 0x40));
  *piRam02032278 = 0;
  return;
}

