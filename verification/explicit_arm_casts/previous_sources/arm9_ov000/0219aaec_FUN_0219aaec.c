/* Decompiled C draft; module arm9_ov000; ROM address 0219aaec. No matching claim. */
#include "types.h"
#include "deps/0219aaec_FUN_0219aaec.h"

void FUN_0219aaec(void)

{
  int *piVar1;
  int iVar2;
  
  if (*DAT_0219ab20 != 0) {
    iVar2 = FUN_0218dc44();
    piVar1 = DAT_0219ab20;
    while (iVar2 = iVar2 + -1, -1 < iVar2) {
      FUN_0218dbf8(*piVar1,iVar2);
      FUN_0219ab24();
    }
  }
  return;
}

