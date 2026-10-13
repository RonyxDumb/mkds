/* Decompiled C draft; module arm9; ROM address 0204b3a4. No matching claim. */
#include "types.h"
#include "deps/0204b3a4_AllocateLockCardBackupResource_from_thumb.h"

undefined4 AllocateLockCardBackupResource_from_thumb(void)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = Os_AllocateLockId();
  piVar1 = piRam0204b3d8;
  *(undefined4 *)(*piRam0204b3d8 + 8) = uVar2;
  if (*(uint *)(*piVar1 + 8) == 0xfffffffd) {
    return 0;
  }
  Card_LockBackupResource(*(uint *)(*piVar1 + 8) & 0xffff);
  return 1;
}

