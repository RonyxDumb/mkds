/* Decompiled C draft; module arm9_ov001; ROM address 0218f2a8. No matching claim. */
#include "types.h"
#include "deps/0218f2a8_FUN_0218f2a8.h"

void FUN_0218f2a8(int param_1)

{
  int iVar1;
  undefined1 auStack_14 [12];
  
  iVar1 = func_0x0207a974((short)*(char *)(*DAT_0218f37c + 0x62));
  func_0x02147fd8(*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218f380),iVar1 + 0x68,iVar1 + 0x80
                  ,auStack_14);
  FUN_02187218(param_1,5,DAT_0218f384);
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xec),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xf0));
  FUN_02188d1c(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xf4),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xf8));
  FUN_02188cd8(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xfc),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218f388));
  FUN_02188c48(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218f38c),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218f390));
  FUN_02188de0(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218f398),0,auStack_14,
               DAT_0218f394);
  if (*DAT_0218f39c != 2) {
    *DAT_0218f3a0 = *DAT_0218f39c;
  }
  *DAT_0218f39c = 2;
  FUN_02188200(param_1,DAT_0218f3a4);
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *DAT_0218f3a8;
  return;
}

