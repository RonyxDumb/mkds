/* Decompiled C draft; module arm9; ROM address 02118184. No matching claim. */
#include "types.h"
#include "deps/02118184_func_02118184.h"

void func_02118184(void)

{
  int *piVar1;
  
  piVar1 = piRam021181ac;
  *(undefined4 *)(*piRam021181ac + 0x34) = 4;
  *(undefined4 *)(*piVar1 + 0x38) = 0;
  if (*psRam021181b0 != 2) {
    NNSi_MaybeSndPlayerStartSeq(uRam021181b4,0,5);
  }
  return;
}

