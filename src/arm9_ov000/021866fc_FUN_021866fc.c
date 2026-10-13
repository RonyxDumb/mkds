/* Decompiled C draft; module arm9_ov000; ROM address 021866fc. No matching claim. */
#include "types.h"
#include "deps/021866fc_FUN_021866fc.h"

undefined4 FUN_021866fc(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  char *pcVar9;
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  
  local_18 = 0;
  local_20 = param_1;
  local_1c = param_2;
  func_0x0214d168((uint *)(uintptr_t)(param_1),0,param_2 << 3);
  iVar2 = func_0x02139f70(param_4,DAT_02186880);
  if (iVar2 == 0) {
    return 0;
  }
  iVar3 = func_0x0213a434(iVar2 + 4);
  iVar4 = func_0x02139f70(param_4,DAT_02186884);
  if (iVar4 == 0) {
    return 0;
  }
  *(undefined1 *)(iVar4 + 4) = 0;
  iVar5 = FUN_021868a4(&local_20,DAT_02186888,iVar4 + 1);
  if (iVar5 != 1) {
    return 0;
  }
  if ((param_3 == 1) || (iVar5 = func_0x0213a038(iVar4 + 1,DAT_0218688c,3), iVar5 != 0)) {
    iVar2 = FUN_021868a4(&local_20,DAT_02186890,iVar2 + 4);
    if (iVar2 != 1) {
      return 0;
    }
    return 1;
  }
  puVar6 = (undefined1 *)func_0x02139f70(iVar4 + 5,DAT_02186894);
  if (puVar6 == (undefined1 *)0x0) {
    return 0;
  }
  while (((pcVar9 = puVar6 + 2, *pcVar9 != '\r' && (puVar6[3] != '\n')) &&
         (puVar6 = (undefined1 *)func_0x02139f70((uint)(uintptr_t)(pcVar9),DAT_02186898), puVar6 != (undefined1 *)0x0))
        ) {
    puVar6[1] = 0;
    *puVar6 = puVar6[1];
    puVar6 = puVar6 + 2;
    puVar7 = (undefined1 *)func_0x02139f70((uint)(uintptr_t)(puVar6),DAT_02186894);
    if (puVar7 == (undefined1 *)0x0) break;
    puVar7[1] = 0;
    *puVar7 = puVar7[1];
    iVar4 = FUN_021868a4(&local_20,(undefined4)(uintptr_t)(pcVar9),(undefined4)(uintptr_t)(puVar6));
    if (iVar4 != 1) {
      return 0;
    }
    iVar4 = func_0x0213a434(puVar6);
    puVar6 = puVar6 + iVar4;
  }
  uVar1 = DAT_0218689c;
  puVar6 = (undefined1 *)(iVar2 + 4);
  while( true ) {
    if (((undefined1 *)(iVar2 + 4 + iVar3) <= puVar6) ||
       (puVar7 = (undefined1 *)func_0x02139f70((uint)(uintptr_t)(puVar6),uVar1), puVar7 == (undefined1 *)0x0)) {
      return 1;
    }
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
    puVar8 = (undefined1 *)func_0x02139f70((uint)(uintptr_t)(puVar7),DAT_021868a0);
    if (puVar8 == (undefined1 *)0x0) {
      puVar8 = (undefined1 *)func_0x02139f70((uint)(uintptr_t)(puVar7),DAT_02186894);
    }
    if (puVar8 != (undefined1 *)0x0) {
      *puVar8 = 0;
    }
    iVar4 = FUN_021868a4(&local_20,(undefined4)(uintptr_t)(puVar6),(undefined4)(uintptr_t)(puVar7));
    if (iVar4 != 1) break;
    iVar4 = func_0x0213a434(puVar7);
    puVar6 = puVar7 + iVar4 + 1;
  }
  return 0;
}

