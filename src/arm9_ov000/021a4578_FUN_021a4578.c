/* Decompiled C draft; module arm9_ov000; ROM address 021a4578. No matching claim. */
#include "types.h"
#include "deps/021a4578_FUN_021a4578.h"

void FUN_021a4578(byte *param_1,int param_2,undefined1 *param_3)

{
  byte bVar1;
  undefined1 uVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  byte *local_30;
  int local_28;
  int local_20;
  byte local_1c [8];
  
  iVar5 = 0;
  if (0 < param_2) {
    local_20 = 0;
    local_28 = 0;
    local_30 = param_1;
    do {
      pbVar3 = local_1c;
      iVar4 = local_28;
      do {
        if (iVar5 < param_2) {
          bVar1 = *local_30;
          local_30 = local_30 + 1;
          *pbVar3 = bVar1;
        }
        else {
          *pbVar3 = 0;
        }
        pbVar3 = pbVar3 + 1;
        iVar4 = iVar4 + 1;
        iVar5 = iVar5 + 1;
      } while (iVar4 < 3);
      local_1c[3] = (char)((int)(uint)local_1c[0] >> 2);
      local_1c[4] = (local_1c[0] & 3) * '\x10' + (char)((int)(uint)local_1c[1] >> 4);
      local_1c[5] = (local_1c[1] & 0xf) * '\x04' + (char)((int)(uint)local_1c[2] >> 6);
      local_1c[6] = local_1c[2] & 0x3f;
      pbVar3 = local_1c + 3;
      iVar4 = local_20;
      do {
        uVar2 = FUN_021a4610(*pbVar3);
        *param_3 = uVar2;
        param_3 = param_3 + 1;
        pbVar3 = pbVar3 + 1;
        iVar4 = iVar4 + 1;
      } while (iVar4 < 4);
    } while (iVar5 < param_2);
  }
  *param_3 = 0;
  return;
}

