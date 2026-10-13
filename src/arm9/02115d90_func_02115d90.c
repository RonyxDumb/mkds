/* Decompiled C draft; module arm9; ROM address 02115d90. No matching claim. */
#include "types.h"
#include "deps/02115d90_func_02115d90.h"

void func_02115d90(void)

{
  int *piVar1;
  
  piVar1 = piRam02115db8;
  *(undefined4 *)(*piRam02115db8 + 0x58) = 7;
  *(undefined4 *)(*piVar1 + 0x5c) = 0;
  func_021282c8();
  NNSi_MaybeSndPlayerStartSeq(uRam02115dbc,0,5);
  return;
}

