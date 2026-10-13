/* Decompiled C draft; module arm9_ov000; ROM address 021857e0. No matching claim. */
#include "types.h"
#include "deps/021857e0_FUN_021857e0.h"

void FUN_021857e0(void)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_02185814;
  *(undefined4 *)*DAT_02185814 = ((undefined4 *)*DAT_02185814)[1];
  if (*(int *)*puVar1 == 0) {
    FUN_0218583c();
    return;
  }
  if (*(int *)*puVar1 != 1) {
    return;
  }
  FUN_02185818();
  return;
}

