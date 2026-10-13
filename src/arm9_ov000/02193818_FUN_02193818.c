/* Decompiled C draft; module arm9_ov000; ROM address 02193818. No matching claim. */
#include "types.h"
#include "deps/02193818_FUN_02193818.h"

void FUN_02193818(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(*param_1 + DAT_02193854);
  iVar2 = 0;
  while( true ) {
    iVar1 = iVar3;
    if (iVar1 == 0) {
      return;
    }
    if (iVar1 == param_2) break;
    iVar3 = *(int *)(iVar1 + 0x20);
    iVar2 = iVar1;
  }
  if (iVar2 == 0) {
    *(undefined4 *)(*param_1 + DAT_02193854) = *(undefined4 *)(iVar1 + 0x20);
  }
  else {
    *(undefined4 *)(iVar2 + 0x20) = *(undefined4 *)(param_2 + 0x20);
  }
  FUN_02193858();
  return;
}

