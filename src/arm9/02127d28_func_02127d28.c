/* Decompiled C draft; module arm9; ROM address 02127d28. No matching claim. */
#include "types.h"
#include "deps/02127d28_func_02127d28.h"

void func_02127d28(void)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(*piRam02127d68 + 0x18);
  *(undefined4 *)(*piRam02127d68 + 0x18) = 0xffffffff;
  func_02127db8();
  piVar1 = piRam02127d68;
  *(undefined4 *)(*piRam02127d68 + 0x18) = uVar2;
  *(undefined4 *)(*piVar1 + 0x10) = 0;
  *(undefined4 *)(*piVar1 + 0x14) = 1;
  if (*psRam02127d6c != 2) {
    AllocateReserveTEQSub(0x18,0,*piVar1 + 0x2c,uRam02127d70);
  }
  return;
}

