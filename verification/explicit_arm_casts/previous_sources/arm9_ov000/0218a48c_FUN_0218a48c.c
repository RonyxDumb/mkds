/* Decompiled C draft; module arm9_ov000; ROM address 0218a48c. No matching claim. */
#include "types.h"
#include "deps/0218a48c_FUN_0218a48c.h"

void FUN_0218a48c(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int extraout_r1;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  undefined1 *puVar6;
  int iVar7;
  undefined1 local_28 [20];
  
  puVar6 = local_28;
  iVar5 = 0;
  do {
    func_0x02133068(iVar5,7);
    *(byte *)(param_2 + iVar5) = *(byte *)(param_1 + iVar5) ^ *(byte *)(param_1 + extraout_r1 + 0xd)
    ;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0xd);
  iVar5 = 0;
  do {
    *(byte *)(param_2 + iVar5 + 3) =
         *(byte *)(param_2 + iVar5 + 3) ^ *(byte *)(param_1 + iVar5 + 0xd);
    piVar1 = DAT_0218a56c;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 7);
  iVar5 = 0;
  do {
    *(byte *)(param_2 + iVar5) = *(byte *)(param_2 + iVar5) ^ *(byte *)(*piVar1 + iVar5);
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0xd);
  func_0x0214d1fc(param_2,local_28,0xd);
  iVar5 = 0;
  pbVar4 = DAT_0218a570;
  do {
    *(undefined1 *)(param_2 + (uint)*pbVar4) = *puVar6;
    piVar1 = DAT_0218a574;
    puVar6 = puVar6 + 1;
    pbVar4 = pbVar4 + 1;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0xd);
  iVar5 = 0;
  do {
    *(byte *)(param_2 + iVar5) = *(byte *)(param_2 + iVar5) ^ *(byte *)(*piVar1 + iVar5);
    iVar2 = DAT_0218a578;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0xd);
  iVar5 = 0;
  do {
    *(byte *)(param_2 + iVar5) =
         *(char *)(iVar2 + ((int)(uint)*(byte *)(param_2 + iVar5) >> 4)) << 4 |
         *(byte *)(iVar2 + (*(byte *)(param_2 + iVar5) & 0xf));
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0xd);
  iVar5 = 0;
  do {
    iVar3 = iVar5 + 6;
    *(byte *)(param_2 + iVar5) = *(byte *)(param_2 + iVar5) ^ *(byte *)(param_2 + iVar3);
    iVar2 = iVar5 + 9;
    iVar7 = iVar5 + 3;
    *(byte *)(param_2 + iVar7) = *(byte *)(param_2 + iVar7) ^ *(byte *)(param_2 + iVar2);
    *(byte *)(param_2 + iVar3) = *(byte *)(param_2 + iVar3) ^ *(byte *)(param_2 + iVar7);
    *(byte *)(param_2 + iVar2) = *(byte *)(param_2 + iVar2) ^ *(byte *)(param_2 + iVar5);
    *(byte *)(param_2 + 0xc) = *(byte *)(param_2 + 0xc) ^ *(byte *)(param_2 + iVar5);
    iVar5 = iVar5 + 1;
  } while (iVar5 < 3);
  return;
}

