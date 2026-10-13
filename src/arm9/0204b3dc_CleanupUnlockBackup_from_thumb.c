/* Decompiled C draft; module arm9; ROM address 0204b3dc. No matching claim. */
#include "types.h"
#include "deps/0204b3dc_CleanupUnlockBackup_from_thumb.h"

void CleanupUnlockBackup_from_thumb(void)

{
  if (*(uint *)(*piRam0204b414 + 8) != 0xfffffffd) {
    Card_UnlockBackupResource(*(uint *)(*piRam0204b414 + 8) & 0xffff);
    Os_ReleaseLockId(*(uint *)(*piRam0204b414 + 8) & 0xffff);
    *(undefined4 *)(*piRam0204b414 + 8) = 0xfffffffd;
  }
  return;
}

