/* Decompiled C draft; module arm9_ov000; ROM address 021af4d4. No matching claim. */
#include "types.h"
#include "deps/021af4d4_FUN_021af4d4.h"

void FUN_021af4d4(int param_1)

{
  uint *puVar1;
  
  *(short *)(param_1 + 6) = (short)DAT_021af544;
  func_0x0214d1fc((ushort *)(uintptr_t)(param_1 + 8),(uint *)(uintptr_t)(param_1 + 0x12),10);
  func_0x0214d1fc((ushort *)(uintptr_t)(DAT_021af548),(uint *)(uintptr_t)(param_1 + 8),6);
  puVar1 = DAT_021af54c;
  *(ushort *)(param_1 + 0xe) =
       (ushort)(byte)(*DAT_021af54c >> 0x18) | (ushort)((*DAT_021af54c >> 0x10) << 8);
  *(ushort *)(param_1 + 0x10) =
       (ushort)((*puVar1 & 0xffff) >> 8) | (ushort)((*puVar1 & 0xffff) << 8);
  func_0x0214d1fc((ushort *)(uintptr_t)(param_1 + 0x12),(uint *)(uintptr_t)(param_1 + -0xe),6);
  func_0x0214d1fc((ushort *)(uintptr_t)(DAT_021af548),(uint *)(uintptr_t)(param_1 + -8),6);
  FUN_021affcc(param_1 + -0xe,0x2a,0,0);
  return;
}

