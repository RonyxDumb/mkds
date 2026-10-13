/* Decompiled C draft; module arm9_ov003; ROM address 021bd998. No matching claim. */
#include "types.h"
#include "deps/021bd998_FUN_021bd998.h"

undefined4 FUN_021bd998(undefined4 param_1,undefined4 *param_2)

{
  uint uVar1;
  int iVar2;
  ushort *puVar3;
  uint uVar4;
  uint local_34;
  uint local_30;
  int local_2c;
  int local_28;
  int local_24;
  undefined1 auStack_20 [4];
  int local_1c [2];
  
  iVar2 = FUN_021bdc5c((ushort *)(uintptr_t)(param_1),&local_2c,&local_28);
  uVar4 = 0;
  local_34 = 0;
  local_30 = 0;
  if (iVar2 == 0) {
    return 0;
  }
  if (local_2c != 1) {
    return 0;
  }
  local_1c[0] = iVar2 + 8;
  puVar3 = (ushort *)FUN_021bdc08(local_1c,(ushort *)(uintptr_t)(iVar2 + local_28),&local_24,(uint *)(void *)(auStack_20));
  uVar1 = DAT_021bda74;
  while (puVar3 != (ushort *)0x0) {
    if (local_24 == 1) {
      uVar4 = (int)(uint)*puVar3 >> 8 | (uint)*puVar3 << 8 & uVar1 & 0xffff;
    }
    else if (local_24 == 2) {
      local_34 = (int)(uint)*puVar3 >> 8 | (uint)*puVar3 << 8 & uVar1 & 0xffff;
    }
    else if (local_24 == 5) {
      local_30 = (int)(uint)*puVar3 >> 8 | (uint)*puVar3 << 8 & uVar1 & 0xffff;
    }
    puVar3 = (ushort *)FUN_021bdc08(local_1c,(ushort *)(uintptr_t)(iVar2 + local_28),&local_24,(uint *)(void *)(auStack_20));
  }
  if ((uVar4 == 1) && (local_34 == 1)) {
    if (local_30 == 0) {
      *param_2 = 0;
    }
    else {
      *param_2 = 1;
    }
    return 1;
  }
  return 0;
}

