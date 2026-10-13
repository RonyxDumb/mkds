/* Decompiled C draft; module arm9_ov001; ROM address 02183ff4. No matching claim. */
#include "types.h"
#include "deps/02183ff4_FUN_02183ff4.h"

void FUN_02183ff4(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  undefined8 uVar7;
  uint local_24;
  uint local_20;
  uint local_1c;
  
  uVar2 = *(uint *)(param_1 + 4);
  local_20 = 0;
  local_1c = *(int *)(param_1 + 0xc);
  local_24 = uVar2;
  lVar4 = func_0x02133048(local_1c,(int)local_1c >> 0x1f,local_1c,(int)local_1c >> 0x1f);
  lVar5 = func_0x02133048(uVar2,(int)uVar2 >> 0x1f,uVar2,(int)uVar2 >> 0x1f);
  lVar6 = func_0x02133048(0,0,0,0);
  lVar4 = lVar4 + lVar5 + lVar6;
  if ((int)(uint)((uint)lVar4 < 0x10) <= (int)((ulonglong)lVar4 >> 0x20)) {
    func_0x02039860((uint)(uintptr_t)(&local_24),&local_24);
  }
  iVar3 = *(int *)(*(int *)(param_1 + 0xa0) + DAT_02184138);
  iVar1 = iVar3 >> 0x1f;
  uVar7 = func_0x02133048(local_24,(int)local_24 >> 0x1f,iVar3,iVar1);
  local_24 = (uint)uVar7 >> 0xc | (int)((ulonglong)uVar7 >> 0x20) << 0x14;
  uVar7 = func_0x02133048(local_20,(int)local_20 >> 0x1f,iVar3,iVar1);
  local_20 = (uint)uVar7 >> 0xc | (int)((ulonglong)uVar7 >> 0x20) << 0x14;
  uVar7 = func_0x02133048(local_1c,(int)local_1c >> 0x1f,iVar3,iVar1);
  local_1c = (uint)uVar7 >> 0xc | (int)((ulonglong)uVar7 >> 0x20) << 0x14;
  local_20 = -*(int *)(*(int *)(param_1 + 0xa0) + DAT_0218413c);
  FUN_02187218(param_1,8,0);
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02184140),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02184144));
  FUN_02188c90(param_1);
  FUN_02188cec(param_1,0);
  FUN_02188950(param_1,&local_24);
  FUN_0218720c(param_1);
  FUN_02188e24(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02184148),DAT_0218414c);
  FUN_021874c4(param_1,0,0,0,DAT_02184150,0);
  FUN_021874c4(param_1,0,0,0,DAT_02184154,0);
  FUN_02187444(param_1,4,0);
  func_0x020d2774(param_1,DAT_02184158);
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *DAT_0218415c;
  return;
}

