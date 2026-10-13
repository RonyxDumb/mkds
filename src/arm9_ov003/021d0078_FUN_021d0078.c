/* Decompiled C draft; module arm9_ov003; ROM address 021d0078. No matching claim. */
#include "types.h"
#include "deps/021d0078_FUN_021d0078.h"

undefined4 FUN_021d0078(void)

{
  int *piVar1;
  int iVar2;
  ushort local_10;
  ushort local_e;
  ushort local_c;
  
  func_0x0200fe58((undefined4)(uintptr_t)(&local_10));
  piVar1 = DAT_021d0100;
  *(uint *)(*DAT_021d0100 + 0x58) = (uint)local_c + (uint)local_e + (uint)local_10 + *DAT_021d00fc;
  *(int *)(*piVar1 + 0x58) = DAT_021d0104 * *(int *)(*piVar1 + 0x58) + DAT_021d0108;
  *(undefined2 *)(*piVar1 + 0x5c) = 0;
  *(undefined2 *)(*piVar1 + 0x5e) = 0x65;
  FUN_021d07b0(3);
  iVar2 = FUN_021cfff8(1);
  if (iVar2 == 0x18) {
    FUN_021d079c(0x18);
    FUN_021d07b0(9);
    return 0;
  }
  if (iVar2 != 2) {
    FUN_021d079c();
    FUN_021d07b0(9);
    return 0;
  }
  return 1;
}

