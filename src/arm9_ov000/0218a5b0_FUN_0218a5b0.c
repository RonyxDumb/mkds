/* Decompiled C draft; module arm9_ov000; ROM address 0218a5b0. No matching claim. */
#include "types.h"
#include "deps/0218a5b0_FUN_0218a5b0.h"

void FUN_0218a5b0(undefined4 param_1,int param_2)

{
  byte bVar1;
  undefined1 uVar2;
  uint uVar3;
  undefined1 uVar4;
  int *piVar5;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  uint uVar9;
  uint local_30;
  byte local_2c [24];
  
  pbVar7 = local_2c;
  iVar6 = 0x18;
  pbVar8 = DAT_0218a640;
  do {
    bVar1 = *pbVar8;
    pbVar8 = pbVar8 + 1;
    *pbVar7 = bVar1;
    pbVar7 = pbVar7 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  FUN_0218a350(param_1,param_2,0x20,0x18);
  piVar5 = DAT_0218a644;
  iVar6 = 0;
  do {
    *(byte *)(param_2 + iVar6) = *(byte *)(param_2 + iVar6) ^ *(byte *)(*piVar5 + iVar6);
    iVar6 = iVar6 + 1;
  } while (iVar6 < 0x18);
  local_30 = 0;
  do {
    bVar1 = local_2c[local_30 & 0xff];
    uVar3 = local_30 & 0xff;
    uVar4 = *(undefined1 *)(param_2 + local_30);
    piVar5 = DAT_0218a648;
    while (DAT_0218a648 = piVar5, bVar1 != 0xff) {
      uVar9 = (uint)local_2c[uVar3];
      uVar2 = *(undefined1 *)(param_2 + uVar9);
      *(undefined1 *)(param_2 + (uint)local_2c[uVar3]) = uVar4;
      local_2c[uVar3] = 0xff;
      uVar3 = uVar9;
      uVar4 = uVar2;
      piVar5 = DAT_0218a648;
      bVar1 = local_2c[uVar9];
    }
    local_30 = local_30 + 1;
  } while ((int)local_30 < 0x18);
  iVar6 = 0;
  do {
    *(byte *)(param_2 + iVar6) = *(byte *)(param_2 + iVar6) ^ *(byte *)(*piVar5 + iVar6);
    iVar6 = iVar6 + 1;
  } while (iVar6 < 0x18);
  return;
}

