/* Decompiled C draft; module arm9_ov001; ROM address 0218f16c. No matching claim. */
#include "types.h"
#include "deps/0218f16c_FUN_0218f16c.h"

void FUN_0218f16c(int param_1)

{
  int iVar1;
  undefined1 auStack_14 [12];
  
  iVar1 = func_0x0207a974((short)*(char *)(*DAT_0218f230 + 0x62));
  func_0x02147fd8(-*(int *)(*(int *)(param_1 + 0xa0) + 0xe8),iVar1 + 0x68,iVar1 + 0x80,(int *)(void *)(auStack_14));
  FUN_02187218(param_1,3,DAT_0218f234);
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xc4),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + 200));
  FUN_02188d1c(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xcc),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xd0));
  FUN_02188cd8(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xd4),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xd8));
  FUN_02188c48(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xdc),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xe0));
  FUN_02188de0(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xe4),0,(undefined4 *)(void *)(auStack_14),DAT_0218f238);
  if (*DAT_0218f23c != 1) {
    *DAT_0218f240 = *DAT_0218f23c;
  }
  *DAT_0218f23c = 1;
  return;
}

