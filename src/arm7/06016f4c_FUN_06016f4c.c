/* Decompiled C draft; module arm7; ROM address 06016f4c. No matching claim. */
#include "types.h"
#include "deps/06016f4c_FUN_06016f4c.h"

void FUN_06016f4c(int param_1)

{
  int iVar1;
  int local_34 [2];
  undefined2 local_2c;
  ushort local_2a;
  undefined2 uStack_28;
  
  iVar1 = FUN_06013528(param_1 + 0x1e,0x50);
  if ((iVar1 == 0) &&
     (((*(ushort *)(param_1 + 0x24) & 1) != 0 || ((*(ushort *)(param_1 + 8) & 0x8000) != 0)))) {
    thunk_FUN_037fb24c(0,local_34,0x2c);
    local_34[0] = param_1 + 0x2c;
    local_2c = *(undefined2 *)(param_1 + 6);
    if (-1 < (int)((uint)*(ushort *)
                          ((*(uint *)(DAT_06017004 & 0xfffffffc) >> (DAT_06017004 & 3) * 8 |
                           *(uint *)(DAT_06017004 & 0xfffffffc) << (DAT_06017004 & 3) * -8 + 0x20) +
                          0x33a) << 0x1e)) {
      uStack_28 = 0x800;
    }
    FUN_060161b4((uint)(uintptr_t)(local_34));
    if (((local_2a & 1) == 1) && (iVar1 = FUN_06013784(param_1 + 0x1e), iVar1 != 0)) {
      FUN_060143ac();
    }
  }
  return;
}

