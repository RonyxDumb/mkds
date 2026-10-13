/* Decompiled C draft; module arm9_ov000; ROM address 0219b130. No matching claim. */
#include "types.h"
#include "deps/0219b130_FUN_0219b130.h"

void FUN_0219b130(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = FUN_0218dc44(*DAT_0219b174);
  puVar1 = DAT_0219b174;
  if (0 < iVar2) {
    do {
      iVar2 = FUN_0218dbf8(*puVar1,iVar3);
      if (param_1 == iVar2) {
        FUN_0218da9c(*DAT_0219b174,iVar3);
        return;
      }
      iVar3 = iVar3 + 1;
      iVar2 = FUN_0218dc44(*puVar1);
    } while (iVar3 < iVar2);
  }
  return;
}

