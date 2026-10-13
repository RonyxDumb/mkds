/* Decompiled C draft; module arm9_ov001; ROM address 021949d4. No matching claim. */
#include "types.h"
#include "deps/021949d4_FUN_021949d4.h"

void FUN_021949d4(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_02194a08;
  *(undefined4 *)(*DAT_02194a08 + 100) = 4;
  *(undefined4 *)(*piVar1 + 0x68) = 0;
  iVar2 = *(int *)(*piVar1 + 0x7c);
  if (iVar2 == 0) {
    FUN_02194d48();
  }
  else if (iVar2 == 1) {
    FUN_02194d18();
  }
  FUN_02194d78();
  return;
}

