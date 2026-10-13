/* Decompiled C draft; module arm9_ov001; ROM address 02183ad8. No matching claim. */
#include "types.h"
#include "deps/02183ad8_FUN_02183ad8.h"

void FUN_02183ad8(ushort *param_1)

{
  int iVar1;
  
  iVar1 = func_0x0207a974((short)*(char *)(*DAT_02183b84 + 0x62));
  FUN_02187218(param_1,3,0);
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0x50) + 0xcc),
               *(undefined4 *)(*(int *)(param_1 + 0x50) + 0xd0));
  FUN_02188c48(param_1,*(undefined4 *)(*(int *)(param_1 + 0x50) + 0xd8),
               *(undefined4 *)(*(int *)(param_1 + 0x50) + 0xd8));
  FUN_02188998(param_1,iVar1 + 0x80);
  FUN_02188cec(param_1,*(undefined4 *)(*(int *)(param_1 + 0x50) + 0xd4));
  FUN_02188de0(param_1,0,*(undefined4 *)(*(int *)(param_1 + 0x50) + 0xe4),iVar1 + 0x80,DAT_02183b88)
  ;
  if (*param_1 == DAT_02183b8c) {
    func_0x020d2774(param_1,DAT_02183b90);
  }
  else if (*param_1 == DAT_02183b94) {
    func_0x020d2774(param_1,DAT_02183b98);
  }
  FUN_02184e6c(param_1);
  return;
}

