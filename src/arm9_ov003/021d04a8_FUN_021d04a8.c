/* Decompiled C draft; module arm9_ov003; ROM address 021d04a8. No matching claim. */
#include "types.h"
#include "deps/021d04a8_FUN_021d04a8.h"

undefined4 FUN_021d04a8(void)

{
  int iVar1;
  
  if (*(int *)(*DAT_021d0518 + 0x40) - 4U < 3) {
    return 1;
  }
  FUN_021d07b0(4);
  iVar1 = *DAT_021d0518;
  iVar1 = func_0x02144230(DAT_021d0520,iVar1 + DAT_021d0524,*(uint *)(iVar1 + DAT_021d0528) & 0xffff
                          ,iVar1 + DAT_021d052c,*(uint *)(iVar1 + DAT_021d051c) & 0xffff,1,0,0,0,0,0
                         );
  if (iVar1 != 2) {
    FUN_021d079c();
    return 0;
  }
  return 1;
}

