/* Decompiled C draft; module arm9_ov001; ROM address 0219b510. No matching claim. */
#include "types.h"
#include "deps/0219b510_FUN_0219b510.h"

void FUN_0219b510(void)

{
  int iVar1;
  ushort in_stack_00000004;
  ushort in_stack_00000008;
  
  iVar1 = func_0x0209bfa8();
  *(uint *)(iVar1 + 0x24) = (uint)in_stack_00000004;
  *(uint *)(iVar1 + 0x28) = (uint)in_stack_00000008;
  *(undefined4 *)(iVar1 + 0x38) = DAT_0219b538;
  *(undefined4 *)(iVar1 + 0x3c) = DAT_0219b53c;
  return;
}

