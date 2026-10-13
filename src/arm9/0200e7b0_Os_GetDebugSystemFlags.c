/* Decompiled C draft; module arm9; ROM address 0200e7b0. No matching claim. */
#include "types.h"
#include "deps/0200e7b0_Os_GetDebugSystemFlags.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Os_GetDebugSystemFlags(void)

{
  bool bVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 local_30;
  
  bVar1 = false;
  uVar2 = Os_AllocateLockId();
  local_30 = 0x2000000;
  uVar6 = 0;
  do {
    iVar5 = -1;
    uVar3 = Os_DisableIrq();
    uVar4 = Os_Lock_GetOwnerId(uRam0200e874);
    if (((uVar4 & 0x40) != 0) || (iVar5 = Operation_CartArm9(uVar2), iVar5 == 0)) {
      uVar6 = local_30;
      if ((_DAT_08000000 == iRam0200e878) &&
         ((*(uint *)(uRam0200e87c & 0xfffffffc) >> (uRam0200e87c & 3) * 8 |
          *(uint *)(uRam0200e87c & 0xfffffffc) << (uRam0200e87c & 3) * -8 + 0x20) == uRam0200e880))
      {
        uVar6 = 0x1000000;
      }
      if (iVar5 == 0) {
        Operation_CartArm7(uVar2);
        bVar1 = true;
      }
    }
    Os_RestoreIrq(uVar3);
  } while (!bVar1);
  return uVar6;
}

