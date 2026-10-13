/* Decompiled C draft; module arm9; ROM address 0200c620. No matching claim. */
#include "types.h"
#include "deps/0200c620_CTRDGi_InitCommon_from_thumb.h"

void CTRDGi_InitCommon_from_thumb(void)

{
  undefined2 uVar1;
  undefined4 local_8 [2];
  
  local_8[0] = 0;
  CpuSet(local_8,iRam0200c640,uRam0200c644);
  uVar1 = Os_AllocateLockId();
  *(undefined2 *)(iRam0200c640 + 2) = uVar1;
  return;
}

