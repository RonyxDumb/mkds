/* Decompiled C draft; module arm9_ov003; ROM address 021d0df8. No matching claim. */
#include "types.h"
#include "deps/021d0df8_FUN_021d0df8.h"

void FUN_021d0df8(void)

{
  int *piVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  
  uVar3 = FUN_021d010c();
  piVar1 = DAT_021d0e80;
  switch(uVar3) {
  case 0:
    *(undefined4 *)(*DAT_021d0e80 + DAT_021d0e88) = 0;
    *(undefined1 *)(*piVar1 + DAT_021d0e8c) = 3;
    return;
  case 1:
    FUN_021d0078();
    return;
  default:
    func_0x0200fd1c();
switchD_021d0e10_caseD_3:
    return;
  case 3:
    goto switchD_021d0e10_caseD_3;
  case 7:
    uVar2 = FUN_021cfed8();
    piVar1 = DAT_021d0e80;
    *(undefined2 *)(*DAT_021d0e80 + DAT_021d0e84) = uVar2;
    *(undefined4 *)(*piVar1 + DAT_021d0e88) = 0;
    *(undefined1 *)(*piVar1 + DAT_021d0e8c) = 3;
    return;
  case 9:
    FUN_021cfb80();
    return;
  }
}

