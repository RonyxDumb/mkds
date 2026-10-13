/* Decompiled C draft; module arm9_ov001; ROM address 02196dbc. No matching claim. */
#include "types.h"
#include "deps/02196dbc_FUN_02196dbc.h"

void FUN_02196dbc(void)

{
  int *piVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  byte local_228 [16];
  ushort local_218 [258];
  
  piVar1 = DAT_02196e28;
  iVar4 = 0;
  iVar3 = 0;
  *(undefined4 *)(*DAT_02196e28 + 0x54) = 0xe;
  *(undefined4 *)(*piVar1 + 0x58) = 0;
  func_0x0205fdb4(*(undefined4 *)(DAT_02196e2c + *(int *)(*piVar1 + 0x6c) * 4),local_228);
  pbVar2 = local_228;
  do {
    iVar3 = iVar3 + 1;
    if (iVar3 < 5) {
      local_218[iVar4] = (ushort)*pbVar2;
      pbVar2 = pbVar2 + 1;
    }
    else {
      iVar3 = 0;
      local_218[iVar4] = 0x20;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0x13);
  local_218[iVar4] = 0;
  func_0x02126248(local_218,0,1,0,0,0);
  return;
}

