/* Decompiled C draft; module arm9_ov001; ROM address 0218d3ec. No matching claim. */
#include "types.h"
#include "deps/0218d3ec_FUN_0218d3ec.h"

void FUN_0218d3ec(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  
  uVar1 = func_0x020a1154((short)*(char *)(*DAT_0218d4bc + 0x62));
  if (uVar1 < 2) {
    iVar3 = DAT_0218d4c0 - *(int *)(*(int *)(param_1 + 0xa0) + 0xac);
    iVar2 = FUN_02187f38(param_1);
    uVar4 = func_0x02133048(iVar2,iVar2 >> 0x1f,iVar3,iVar3 >> 0x1f);
    uVar1 = (uint)uVar4 >> 0xc | (int)((ulonglong)uVar4 >> 0x20) << 0x14;
  }
  else {
    uVar1 = func_0x020a1154((short)*(char *)(*DAT_0218d4bc + 0x62));
    if (uVar1 < 3) {
      iVar3 = DAT_0218d4c0 - *(int *)(*(int *)(param_1 + 0xa0) + 0xa8);
      iVar2 = FUN_02187f38(param_1);
      uVar4 = func_0x02133048(iVar2,iVar2 >> 0x1f,iVar3,iVar3 >> 0x1f);
      uVar1 = (uint)uVar4 >> 0xc | (int)((ulonglong)uVar4 >> 0x20) << 0x14;
    }
    else {
      uVar1 = FUN_02187f38(param_1);
    }
  }
  FUN_02187218(param_1,1,DAT_0218d4c4);
  FUN_02188dcc(param_1,0);
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0x88),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0x8c));
  FUN_0218d824(param_1,uVar1);
  FUN_0218d87c(param_1,uVar1);
  FUN_0218d8f4(param_1,uVar1);
  FUN_0218dce4(param_1);
  return;
}

