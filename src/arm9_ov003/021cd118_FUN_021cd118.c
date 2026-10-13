/* Decompiled C draft; module arm9_ov003; ROM address 021cd118. No matching claim. */
#include "types.h"
#include "deps/021cd118_FUN_021cd118.h"

undefined4 FUN_021cd118(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_021cd180;
  *(undefined1 *)(*DAT_021cd180 + DAT_021cd184) = 1;
  func_0x02143520(*piVar1 + DAT_021cd188);
  if (*(short *)(*DAT_021cd180 + DAT_021cd188) != 2) {
    iVar2 = func_0x02143dd0(DAT_021cd18c);
    if (iVar2 != 2) {
      return 0;
    }
    do {
      func_0x02143520(*DAT_021cd180 + DAT_021cd188);
    } while (*(short *)(*DAT_021cd180 + DAT_021cd188) != 2);
  }
  iVar2 = func_0x02143d88(DAT_021cd18c);
  if (iVar2 != 2) {
    return 0;
  }
  return 1;
}

