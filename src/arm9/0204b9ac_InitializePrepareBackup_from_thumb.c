/* Decompiled C draft; module arm9; ROM address 0204b9ac. No matching claim. */
#include "types.h"
#include "deps/0204b9ac_InitializePrepareBackup_from_thumb.h"

void InitializePrepareBackup_from_thumb(void)

{
  int *piVar1;
  int iVar2;
  
  if ((*psRam0204ba20 != 2) && (iVar2 = Os_IsEmulator(), iVar2 == 0)) {
    *(undefined4 *)(*piRam0204ba24 + 0xc) = 1;
    AllocateLockCardBackupResource_from_thumb();
    MaybeInitializeBackup(uRam0204ba28);
    CleanupUnlockBackup_from_thumb();
    piVar1 = piRam0204ba24;
    *(undefined4 *)*piRam0204ba24 = 0;
    *(undefined4 *)(*piVar1 + 4) = 0;
    *(undefined4 *)(*piVar1 + 8) = 0xfffffffd;
    *(undefined4 *)(*piVar1 + 0x10) = 0;
    *(undefined4 *)(*piVar1 + 0x14) = 0;
    *(undefined4 *)(*piVar1 + 0x28) = 0;
    *(undefined4 *)(*piVar1 + 0x30) = 0;
    *(undefined4 *)(*piVar1 + 0x40) = 0;
    *(undefined4 *)(*piVar1 + 0x48) = 0;
    *(undefined4 *)(*piVar1 + 0x58) = 0xffffffff;
    *(undefined4 *)(*piVar1 + 0x5c) = 0xffffffff;
    return;
  }
  *(undefined4 *)(*piRam0204ba24 + 0xc) = 0;
  return;
}

