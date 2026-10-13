/* Decompiled C draft; module arm9_ov000; ROM address 0218a71c. No matching claim. */
#include "types.h"
#include "deps/0218a71c_FUN_0218a71c.h"

byte FUN_0218a71c(int param_1,byte param_2)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte *pbVar6;
  
  pbVar2 = (byte *)(param_1 + DAT_0218a7a8);
  bVar1 = *pbVar2;
  *pbVar2 = bVar1 + 1;
  pbVar3 = (byte *)(param_1 + DAT_0218a7ac);
  *pbVar3 = *pbVar3 + *(char *)(param_1 + (uint)bVar1);
  pbVar6 = (byte *)(param_1 + DAT_0218a7b0);
  bVar1 = *(byte *)(param_1 + (uint)*pbVar6);
  *(undefined1 *)(param_1 + (uint)*pbVar6) = *(undefined1 *)(param_1 + (uint)*pbVar3);
  pbVar4 = (byte *)(param_1 + DAT_0218a7b4);
  *(undefined1 *)(param_1 + (uint)*pbVar3) = *(undefined1 *)(param_1 + (uint)*pbVar4);
  *(undefined1 *)(param_1 + (uint)*pbVar4) = *(undefined1 *)(param_1 + (uint)*pbVar2);
  *(byte *)(param_1 + (uint)*pbVar2) = bVar1;
  pbVar5 = (byte *)(param_1 + DAT_0218a7b8);
  *pbVar5 = *pbVar5 + *(char *)(param_1 + (uint)bVar1);
  *pbVar4 = param_2 ^ *(byte *)(param_1 +
                               ((uint)*(byte *)(param_1 + (uint)*pbVar5) +
                                (uint)*(byte *)(param_1 + (uint)*pbVar2) & 0xff)) ^
            *(byte *)(param_1 +
                     (uint)*(byte *)(param_1 +
                                    ((uint)*(byte *)(param_1 + (uint)*pbVar3) +
                                     (uint)*(byte *)(param_1 + (uint)*pbVar4) +
                                     (uint)*(byte *)(param_1 + (uint)*pbVar6) & 0xff)));
  *pbVar6 = param_2;
  return *pbVar4;
}

