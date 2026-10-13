/* Decompiled C draft; module arm9_ov000; ROM address 021aed3c. No matching claim. */
#include "types.h"
#include "deps/021aed3c_FUN_021aed3c.h"

void FUN_021aed3c(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = FUN_021af284(((int)(uint)*(ushort *)(param_1 + 0xc) >> 8 |
                       (*(ushort *)(param_1 + 0xc) & 0xff) << 8) << 0x10 |
                       (int)(uint)*(ushort *)(param_1 + 0xe) >> 8 |
                       (*(ushort *)(param_1 + 0xe) & 0xff) << 8,
                       ((int)(uint)*(ushort *)(param_1 + 0x10) >> 8 |
                       (*(ushort *)(param_1 + 0x10) & 0xff) << 8) << 0x10 |
                       (int)(uint)*(ushort *)(param_1 + 0x12) >> 8 |
                       (*(ushort *)(param_1 + 0x12) & 0xff) << 8);
  if ((iVar1 != 0) && (iVar1 = FUN_021aedd8(param_1,param_2,param_3), iVar1 == 0)) {
    iVar1 = FUN_021af15c(param_1,(ushort *)(uintptr_t)(param_2));
    if (iVar1 != 0) {
      FUN_021aee38(param_1,param_2);
      return;
    }
    func_0x0200dd94();
    iVar1 = FUN_021af15c(param_1,(ushort *)(uintptr_t)(param_2));
    if (iVar1 != 0) {
      FUN_021aee38(param_1,param_2);
    }
  }
  return;
}

