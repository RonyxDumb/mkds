/* Decompiled C draft; module arm9_ov000; ROM address 0218381c. No matching claim. */
#include "types.h"
#include "deps/0218381c_FUN_0218381c.h"

void FUN_0218381c(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_0218384c;
  *(int *)(*DAT_0218384c + 8) = *(int *)(*DAT_0218384c + 8) + 1;
  iVar2 = *piVar1;
  if (0x4f < *(int *)(iVar2 + 8)) {
    *(undefined4 *)(iVar2 + 4) = 4;
    *(undefined4 *)(*piVar1 + 8) = 0;
    func_0x0212ecc0(DAT_02183850,0,DAT_02183854);
  }
  return;
}

