/* Decompiled C draft; module arm9_ov000; ROM address 021845ac. No matching claim. */
#include "types.h"
#include "deps/021845ac_FUN_021845ac.h"

void FUN_021845ac(void)

{
  ushort uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_30;
  int local_2c;
  byte *local_28;
  int local_20;
  
  iVar3 = DAT_02184668;
  piVar2 = DAT_02184654;
  uVar1 = *(ushort *)(*(int *)(*DAT_02184654 + DAT_02184658) + 6);
  local_30 = 0;
  local_2c = DAT_02184660;
  local_28 = DAT_02184664;
  local_20 = 0;
  iVar5 = local_20;
  iVar4 = DAT_0218465c;
  do {
    do {
      *(undefined4 *)(*(int *)(*piVar2 + iVar3) + (uint)*(byte *)(iVar4 + iVar5) * 0x40 + 0x10) = 1;
      *(undefined4 *)
       (*(int *)(*piVar2 + iVar3) + ((uint)uVar1 + (uint)*(byte *)(local_2c + iVar5)) * 0x40 + 0x10)
           = 1;
      func_0x02124b1c(*(int *)(*piVar2 + iVar3) + (uint)*(byte *)(iVar4 + iVar5) * 0x40,0,
                      DAT_0218466c);
      iVar5 = iVar5 + 1;
    } while (iVar5 < 2);
    *(undefined4 *)(*(int *)(*piVar2 + iVar3) + (uint)*local_28 * 0x40 + 0x10) = 1;
    func_0x02124b1c(*(int *)(*piVar2 + iVar3) + (uint)*local_28 * 0x40,0,DAT_0218466c);
    iVar4 = iVar4 + 2;
    local_2c = local_2c + 2;
    local_28 = local_28 + 1;
    local_30 = local_30 + 1;
    iVar5 = local_20;
  } while (local_30 < 3);
  return;
}

