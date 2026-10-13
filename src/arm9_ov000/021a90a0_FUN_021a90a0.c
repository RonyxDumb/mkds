/* Decompiled C draft; module arm9_ov000; ROM address 021a90a0. No matching claim. */
#include "types.h"
#include "deps/021a90a0_FUN_021a90a0.h"

int FUN_021a90a0(void)

{
  uint uVar1;
  int iVar2;
  int in_stack_00000000;
  undefined2 local_20;
  undefined4 local_1c;
  
  iVar2 = FUN_021a7de0();
  uVar1 = DAT_021a90f8;
  if ((-1 < iVar2) && (in_stack_00000000 != 0)) {
    *(ushort *)(in_stack_00000000 + 2) = local_20 >> 8 | local_20 << 8 & (ushort)DAT_021a90f8;
    *(uint *)(in_stack_00000000 + 4) =
         local_1c << 0x18 & DAT_021a90fc |
         local_1c << 8 & DAT_021a9100 | local_1c >> 0x18 | local_1c >> 8 & uVar1;
  }
  return iVar2;
}

