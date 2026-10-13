/* Decompiled C draft; module arm9; ROM address 0204b518. No matching claim. */
#include "types.h"
#include "deps/0204b518_func_0204b518.h"

undefined4 func_0204b518(void)

{
  int iVar1;
  
  if ((*(int *)(*piRam0204b56c + 0xc) != 0) && (iVar1 = CardIsNotBusy(), iVar1 != 0)) {
    iVar1 = AllocateLockCardBackupResource_from_thumb();
    if (iVar1 == 0) {
      return 0;
    }
    Card_RequestStreamCommand(0,*(undefined4 *)(*piRam0204b56c + 100),1,uRam0204b570,0,1,6,1,0);
    return 1;
  }
  return 0;
}

