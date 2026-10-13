/* Decompiled C draft; module arm9_ov000; ROM address 021892f4. No matching claim. */
#include "types.h"
#include "deps/021892f4_FUN_021892f4.h"

undefined4 FUN_021892f4(byte *param_1)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = *param_1;
  if (bVar1 < 0xb) {
    iVar2 = FUN_02189280();
    if (iVar2 == 1) {
      *param_1 = 0;
      return 1;
    }
    if (iVar2 == -1) {
      *param_1 = 0x12;
      return 1;
    }
  }
  else if (bVar1 == 0xe) {
    FUN_02187fb8();
    FUN_02188068();
    *param_1 = 0xc;
  }
  else if ((bVar1 < 0x12) && (iVar2 = FUN_0218925c(), iVar2 == 1)) {
    *param_1 = 10;
  }
  return 0;
}

