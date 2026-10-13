/* Decompiled C draft; module arm9; ROM address 0211ba58. No matching claim. */
#include "types.h"
#include "deps/0211ba58_func_0211ba58.h"

void func_0211ba58(void)

{
  int *piVar1;
  
  piVar1 = piRam0211ba8c;
  *(undefined4 *)(*piRam0211ba8c + 0x34) = 4;
  *(undefined4 *)(*piVar1 + 0x38) = 0;
  if (*psRam0211ba90 != 2) {
    func_0212b7e8();
  }
  NNSi_MaybeSndPlayerStartSeq(uRam0211ba94,0,5);
  func_0211c474();
  return;
}

