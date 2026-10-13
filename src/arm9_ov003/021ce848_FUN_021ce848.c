/* Decompiled C draft; module arm9_ov003; ROM address 021ce848. No matching claim. */
#include "types.h"
#include "deps/021ce848_FUN_021ce848.h"

undefined4 FUN_021ce848(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_021ce8d8;
  *(undefined1 *)(*DAT_021ce8d8 + DAT_021ce8dc) = 1;
  func_0x02143520(*piVar1 + DAT_021ce8e0);
  if (*(short *)(*DAT_021ce8d8 + DAT_021ce8e0) != 2) {
    iVar2 = func_0x02143dd0(DAT_021ce8e4);
    if (iVar2 != 2) {
      return 0;
    }
    do {
      func_0x02143520(*DAT_021ce8d8 + DAT_021ce8e0);
    } while (*(short *)(*DAT_021ce8d8 + DAT_021ce8e0) != 2);
  }
  iVar2 = func_0x02143d88(DAT_021ce8e4);
  if (iVar2 != 2) {
    return 0;
  }
  if (*(int *)(*DAT_021ce8d8 + DAT_021ce8e8) != 0) {
    thunk_FUN_021d3488(0);
  }
  do {
  } while (*(char *)(*DAT_021ce8d8 + DAT_021ce8dc) != '\x02');
  FUN_021d2808(DAT_021ce8d8);
  return 1;
}

