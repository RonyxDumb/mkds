/* Decompiled C draft; module arm9_ov000; ROM address 021919ac. No matching claim. */
#include "types.h"
#include "deps/021919ac_FUN_021919ac.h"

undefined4 FUN_021919ac(int *param_1,int param_2)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 *local_290;
  undefined1 auStack_28c [33];
  undefined1 auStack_26b [512];
  undefined1 auStack_6b [87];
  
  iVar4 = *param_1;
  FUN_021920d8(param_2 + 0x80,0x20);
  if (*(char *)(param_2 + DAT_02191c28) == '\0') {
    iVar5 = iVar4 + DAT_02191c2c;
  }
  else {
    iVar5 = param_2 + DAT_02191c28;
  }
  uVar1 = func_0x0213a434(iVar5);
  FUN_0218e0fc(iVar5,uVar1,param_2 + 0xa1);
  if (*(char *)(param_2 + 0xc2) == '\0') {
    if (*(char *)(iVar4 + DAT_02191c30) == '\0') {
      func_0x02135014((undefined4)(uintptr_t)(auStack_6b),DAT_02191c34,iVar4 + DAT_02191c38,iVar4 + DAT_02191c3c);
      puVar2 = auStack_6b;
    }
    else {
      puVar2 = (undefined1 *)(iVar4 + DAT_02191c30);
    }
  }
  else {
    puVar2 = (undefined1 *)(param_2 + 0xc2);
  }
  func_0x02135014(auStack_26b,DAT_02191c40,param_2 + 0xa1,DAT_02191c44,puVar2,param_2 + 0x80,param_2
                  ,param_2 + 0xa1);
  uVar1 = func_0x0213a434(auStack_26b);
  FUN_0218e0fc((undefined4)(uintptr_t)(auStack_26b),uVar1,(undefined4)(uintptr_t)(auStack_28c));
  if (*(int *)(iVar4 + DAT_02191c48) != 0) {
    FUN_0219488c((undefined4)(uintptr_t)(param_1),iVar4 + DAT_02191c38,iVar4 + DAT_02191c3c,(undefined4 *)(void *)(&local_290));
    if (local_290 != (undefined4 *)0x0) {
      *(undefined4 *)(iVar4 + DAT_02191c4c) = local_290[1];
      *(undefined4 *)(iVar4 + DAT_02191c50) = *local_290;
    }
  }
  FUN_02190b80((undefined4)(uintptr_t)(param_1),iVar4 + DAT_02191c54,DAT_02191c58);
  FUN_02190b80((undefined4)(uintptr_t)(param_1),iVar4 + DAT_02191c54,DAT_02191c5c);
  FUN_02190b80((undefined4)(uintptr_t)(param_1),iVar4 + DAT_02191c54,param_2 + 0x80);
  if (*(char *)(param_2 + 0xc2) == '\0') {
    if (*(char *)(iVar4 + DAT_02191c30) == '\0') {
      FUN_02190b80((undefined4)(uintptr_t)(param_1),iVar4 + DAT_02191c54,DAT_02191c68);
      FUN_02190b80((undefined4)(uintptr_t)(param_1),iVar4 + DAT_02191c54,iVar4 + DAT_02191c38);
      FUN_02190b80((undefined4)(uintptr_t)(param_1),iVar4 + DAT_02191c54,DAT_02191c6c);
      FUN_02190b80((undefined4)(uintptr_t)(param_1),iVar4 + DAT_02191c54,iVar4 + DAT_02191c3c);
    }
    else {
      FUN_02190b80((undefined4)(uintptr_t)(param_1),iVar4 + DAT_02191c54,DAT_02191c64);
      FUN_02190b80((undefined4)(uintptr_t)(param_1),iVar4 + DAT_02191c54,iVar4 + DAT_02191c30);
    }
  }
  else {
    FUN_02190b80((undefined4)(uintptr_t)(param_1),iVar4 + DAT_02191c54,DAT_02191c60);
    FUN_02190b80((undefined4)(uintptr_t)(param_1),iVar4 + DAT_02191c54,param_2 + 0xc2);
  }
  if (*(int *)(iVar4 + DAT_02191c4c) != 0) {
    FUN_02190b80((undefined4)(uintptr_t)(param_1),iVar4 + DAT_02191c54,DAT_02191c70);
    FUN_02190b58(param_1,iVar4 + DAT_02191c54,*(undefined4 *)(iVar4 + DAT_02191c4c));
  }
  if (*(int *)(iVar4 + DAT_02191c50) != 0) {
    FUN_02190b80(param_1,iVar4 + DAT_02191c54,DAT_02191c74);
    FUN_02190b58(param_1,iVar4 + DAT_02191c54,*(undefined4 *)(iVar4 + DAT_02191c50));
  }
  FUN_02190b80(param_1,iVar4 + DAT_02191c54,DAT_02191c78);
  FUN_02190b80(param_1,iVar4 + DAT_02191c54,auStack_28c);
  if (*(int *)(iVar4 + DAT_02191c7c) == 1) {
    FUN_02190b80(param_1,iVar4 + DAT_02191c54,DAT_02191c80);
  }
  FUN_02190b80(param_1,iVar4 + DAT_02191c54,DAT_02191c84);
  uVar3 = *(uint *)(iVar4 + DAT_02191c88) & 0xffff;
  FUN_02190b58(param_1,iVar4 + DAT_02191c54,
               (int)(short)((ushort)(uVar3 >> 8) | (ushort)(uVar3 << 8) & (ushort)DAT_02191c8c));
  FUN_02190b80(param_1,iVar4 + DAT_02191c54,DAT_02191c90);
  FUN_02190b58(param_1,iVar4 + DAT_02191c54,*(undefined4 *)(iVar4 + DAT_02191c94));
  FUN_02190b80(param_1,iVar4 + DAT_02191c54,DAT_02191c98);
  FUN_02190b80(param_1,iVar4 + DAT_02191c54,DAT_02191c9c);
  FUN_02190b80(param_1,iVar4 + DAT_02191c54,DAT_02191ca0);
  FUN_02190b58(param_1,iVar4 + DAT_02191c54,*(undefined4 *)(iVar4 + DAT_02191ca4));
  FUN_02190b80(param_1,iVar4 + DAT_02191c54,DAT_02191ca8);
  FUN_02190b80(param_1,iVar4 + DAT_02191c54,DAT_02191cac);
  return 0;
}

