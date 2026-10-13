/* Decompiled C draft; module arm9_ov000; ROM address 02180c3c. No matching claim. */
#include "types.h"
#include "deps/02180c3c_FUN_02180c3c.h"

void FUN_02180c3c(void)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_02180cd8;
  *(undefined4 *)*DAT_02180cd8 = ((undefined4 *)*DAT_02180cd8)[1];
  switch(*(undefined4 *)*puVar1) {
  case 0:
    FUN_02181458();
    return;
  case 1:
    FUN_0218134c();
    return;
  case 2:
    FUN_021812f4();
    return;
  case 3:
    FUN_021811ec();
    return;
  case 4:
    FUN_021810dc();
    return;
  case 5:
    FUN_02180ffc();
    return;
  case 6:
    FUN_02180f80();
    return;
  case 7:
    FUN_02180e58();
    return;
  case 8:
    FUN_02180d94();
    return;
  case 9:
    FUN_02180cdc();
  }
  return;
}

