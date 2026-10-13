/* Decompiled C draft; module arm9_ov001; ROM address 02189ed8. No matching claim. */
#include "types.h"
#include "deps/02189ed8_FUN_02189ed8.h"

void FUN_02189ed8(int param_1,int param_2)

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
  
  iVar1 = FUN_02187c4c();
  if (iVar1 != 0) {
    FUN_02187bfc(param_1,0,0);
  }
  *(undefined4 *)(param_1 + DAT_02189fd0) = 2;
  FUN_021881f4(param_1,DAT_02189fd4);
  iVar1 = FUN_021871f8(param_1,7);
  if (iVar1 != 0) {
    uVar2 = *(int *)(param_1 + 4) - *(int *)(param_2 + 0x50);
    local_20 = 0;
    local_1c = *(int *)(param_1 + 0xc) - *(int *)(param_2 + 0x58);
    local_24 = uVar2;
    lVar4 = func_0x02133048(local_1c,(int)local_1c >> 0x1f,local_1c,(int)local_1c >> 0x1f);
    lVar5 = func_0x02133048(uVar2,(int)uVar2 >> 0x1f,uVar2,(int)uVar2 >> 0x1f);
    lVar6 = func_0x02133048(0,0,0,0);
    lVar4 = lVar4 + lVar5 + lVar6;
    if ((int)(uint)((uint)lVar4 < 0x10) <= (int)((ulonglong)lVar4 >> 0x20)) {
      func_0x02039860((uint)(uintptr_t)(&local_24),&local_24);
    }
    iVar3 = *(int *)(*(int *)(param_1 + 0xa0) + DAT_02189fd8);
    iVar1 = iVar3 >> 0x1f;
    uVar7 = func_0x02133048(local_24,(int)local_24 >> 0x1f,iVar3,iVar1);
    local_24 = (uint)uVar7 >> 0xc | (int)((ulonglong)uVar7 >> 0x20) << 0x14;
    uVar7 = func_0x02133048(local_20,(int)local_20 >> 0x1f,iVar3,iVar1);
    local_20 = (uint)uVar7 >> 0xc | (int)((ulonglong)uVar7 >> 0x20) << 0x14;
    uVar7 = func_0x02133048(local_1c,(int)local_1c >> 0x1f,iVar3,iVar1);
    local_1c = (uint)uVar7 >> 0xc | (int)((ulonglong)uVar7 >> 0x20) << 0x14;
    local_20 = *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02189fdc);
    FUN_02188950(param_1,&local_24);
    FUN_0218a41c(param_1);
  }
  return;
}

