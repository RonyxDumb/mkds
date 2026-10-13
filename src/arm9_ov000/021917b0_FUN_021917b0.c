/* Decompiled C draft; module arm9_ov000; ROM address 021917b0. No matching claim. */
#include "types.h"
#include "deps/021917b0_FUN_021917b0.h"

undefined4 FUN_021917b0(int *param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  byte local_100 [31];
  undefined1 auStack_e1 [45];
  byte local_b4 [65];
  undefined1 auStack_73 [95];
  
  iVar4 = *param_1;
  uVar2 = func_0x0213a434(iVar4 + DAT_02191958);
  FUN_0218e2a4(DAT_0219195c);
  uVar3 = 0;
  if (uVar2 != 0) {
    pbVar5 = local_100;
    do {
      bVar1 = FUN_0218e284(0,0xff);
      *pbVar5 = bVar1 ^ *(byte *)(iVar4 + uVar3 + DAT_02191958);
      pbVar5 = pbVar5 + 1;
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar2);
  }
  local_100[uVar3] = 0;
  FUN_0218e15c((int)(uintptr_t)(local_100),auStack_e1,uVar2,1);
  FUN_02190b80((undefined4)(uintptr_t)(param_1),iVar4 + DAT_02191960,DAT_02191964);
  FUN_02190b80((undefined4)(uintptr_t)(param_1),iVar4 + DAT_02191960,DAT_02191968);
  FUN_02190b80((undefined4)(uintptr_t)(param_1),iVar4 + DAT_02191960,iVar4 + DAT_0219196c);
  FUN_02190b80((undefined4)(uintptr_t)(param_1),iVar4 + DAT_02191960,DAT_02191970);
  FUN_02190b80((undefined4)(uintptr_t)(param_1),iVar4 + DAT_02191960,iVar4 + DAT_02191974);
  FUN_02190b80((undefined4)(uintptr_t)(param_1),iVar4 + DAT_02191960,DAT_02191978);
  FUN_02190b80((undefined4)(uintptr_t)(param_1),iVar4 + DAT_02191960,(undefined4)(uintptr_t)(auStack_e1));
  FUN_02190b80((undefined4)(uintptr_t)(param_1),iVar4 + DAT_02191960,DAT_0219197c);
  FUN_02190b58(param_1,iVar4 + DAT_02191960,*(undefined4 *)(iVar4 + DAT_02191980));
  FUN_02190b80((undefined4)(uintptr_t)(param_1),iVar4 + DAT_02191960,DAT_02191984);
  FUN_02190b80((undefined4)(uintptr_t)(param_1),iVar4 + DAT_02191960,DAT_02191988);
  FUN_02190b80((undefined4)(uintptr_t)(param_1),iVar4 + DAT_02191960,DAT_0219198c);
  FUN_02190b58(param_1,iVar4 + DAT_02191960,*(undefined4 *)(iVar4 + DAT_02191990));
  FUN_02190b80((undefined4)(uintptr_t)(param_1),iVar4 + DAT_02191960,DAT_02191994);
  FUN_02190b80((undefined4)(uintptr_t)(param_1),iVar4 + DAT_02191960,iVar4 + DAT_02191998);
  if (*(char *)(param_2 + DAT_0219199c) != '\0') {
    uVar2 = func_0x0213a434(param_2 + DAT_0219199c);
    FUN_0218e2a4(DAT_0219195c);
    uVar3 = 0;
    if (uVar2 != 0) {
      pbVar5 = local_b4;
      do {
        bVar1 = FUN_0218e284(0,0xff);
        *pbVar5 = bVar1 ^ *(byte *)(param_2 + uVar3 + DAT_0219199c);
        pbVar5 = pbVar5 + 1;
        uVar3 = uVar3 + 1;
      } while (uVar3 < uVar2);
    }
    local_b4[uVar3] = 0;
    FUN_0218e15c((int)(uintptr_t)(local_b4),auStack_73,uVar2,1);
    FUN_02190b80(param_1,iVar4 + DAT_02191960,DAT_021919a0);
    FUN_02190b80(param_1,iVar4 + DAT_02191960,auStack_73);
  }
  FUN_02190b80(param_1,iVar4 + DAT_02191960,DAT_021919a4);
  FUN_02190b80(param_1,iVar4 + DAT_02191960,DAT_021919a8);
  return 0;
}

