/* Decompiled C draft; module arm9_ov001; ROM address 02196fd8. No matching claim. */
#include "types.h"
#include "deps/02196fd8_FUN_02196fd8.h"

void FUN_02196fd8(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_0219700c;
  *(undefined4 *)(*DAT_0219700c + 0x54) = 4;
  *(undefined4 *)(*piVar1 + 0x58) = 0;
  iVar2 = *(int *)(*piVar1 + 0x70);
  if (iVar2 == 0) {
    FUN_021972b4();
  }
  else if (iVar2 == 1) {
    FUN_02197274();
  }
  FUN_021972f4();
  return;
}

