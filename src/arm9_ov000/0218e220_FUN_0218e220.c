/* Decompiled C draft; module arm9_ov000; ROM address 0218e220. No matching claim. */
#include "types.h"
#include "deps/0218e220_FUN_0218e220.h"

void FUN_0218e220(int param_1,undefined1 *param_2,int param_3)

{
  int iVar1;
  byte *pbVar2;
  byte local_10 [8];
  
  pbVar2 = local_10;
  iVar1 = 0;
  if (0 < param_3) {
    do {
      *pbVar2 = *(undefined1 *)(param_1 + iVar1);
      pbVar2 = pbVar2 + 1;
      iVar1 = iVar1 + 1;
    } while (iVar1 < param_3);
  }
  if (iVar1 < 3) {
    pbVar2 = local_10 + iVar1;
    do {
      *pbVar2 = 0;
      pbVar2 = pbVar2 + 1;
      iVar1 = iVar1 + 1;
    } while (iVar1 < 3);
  }
  *param_2 = (char)((int)(uint)local_10[0] >> 2);
  param_2[1] = (byte)((local_10[0] & 3) << 4) | (byte)((int)(uint)local_10[1] >> 4);
  param_2[2] = (byte)((local_10[1] & 0xf) << 2) | (byte)((int)(uint)local_10[2] >> 6);
  param_2[3] = local_10[2] & 0x3f;
  return;
}

