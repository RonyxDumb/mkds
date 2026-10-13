/* Decompiled C draft; module arm9_ov001; ROM address 0218ee88. No matching claim. */
#include "types.h"
#include "deps/0218ee88_FUN_0218ee88.h"

void FUN_0218ee88(int param_1)

{
  int iVar1;
  uint *puVar2;
  undefined4 local_18 [2];
  undefined4 local_10;
  
  iVar1 = func_0x0207a974((short)*(char *)(*DAT_0218ef20 + 0x62));
  func_0x02147fd8(-*(int *)(*(int *)(param_1 + 0xa0) + 0xe8),iVar1 + 0x68,iVar1 + 0x80,local_18);
  *(undefined4 *)(param_1 + 4) = local_18[0];
  *(int *)(param_1 + 8) =
       *(int *)(*(int *)(param_1 + 0x9c) + 4) + *(int *)(*(int *)(param_1 + 0xa0) + 0x80);
  *(undefined4 *)(param_1 + 0xc) = local_10;
  iVar1 = func_0x02148714(*(int *)(iVar1 + 0x80) - *(int *)(param_1 + 4),
                          *(int *)(iVar1 + 0x88) - *(int *)(param_1 + 0xc));
  puVar2 = (uint *)(param_1 + DAT_0218ef28);
  *puVar2 = iVar1 + DAT_0218ef24 & 0xffff;
  *(uint *)(param_1 + DAT_0218ef2c) = *puVar2;
  FUN_0218ef30(param_1);
  FUN_02182a3c(0);
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) & 0xfffe;
  return;
}

