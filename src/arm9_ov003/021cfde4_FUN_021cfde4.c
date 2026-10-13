/* Decompiled C draft; module arm9_ov003; ROM address 021cfde4. No matching claim. */
#include "types.h"
#include "deps/021cfde4_FUN_021cfde4.h"

undefined4 FUN_021cfde4(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_021cfe34;
  *(undefined4 *)(*DAT_021cfe34 + DAT_021cfe38) = 0;
  *(undefined4 *)(*piVar1 + DAT_021cfe3c) = 0;
  *(undefined4 *)(*piVar1 + 0x48) = 0;
  *(undefined2 *)(*piVar1 + 0x50) = 0;
  *(undefined2 *)(*piVar1 + 0x52) = 1;
  *(undefined4 *)(*piVar1 + 0x54) = 0;
  *(undefined4 *)*piVar1 = 0;
  *(undefined2 *)(*piVar1 + 4) = 0;
  *(undefined4 *)(*piVar1 + 0x4c) = 0;
  iVar2 = FUN_021cfd88();
  if (iVar2 != 0) {
    return 1;
  }
  return 0;
}

