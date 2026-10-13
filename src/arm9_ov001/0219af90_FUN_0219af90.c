/* Decompiled C draft; module arm9_ov001; ROM address 0219af90. No matching claim. */
#include "types.h"
#include "deps/0219af90_FUN_0219af90.h"

void FUN_0219af90(int param_1)

{
  int *piVar1;
  
  piVar1 = DAT_0219afbc;
  *(undefined4 *)
   (*(int *)(*DAT_0219afbc + 0x1c) + (uint)*(ushort *)(DAT_0219afc0 + param_1 * 2) * 0x40) = 0;
  func_0x02124a20(*(undefined2 *)(DAT_0219afc4 + param_1 * 2),0xf,*(undefined4 *)(*piVar1 + 0xc),
                  *(undefined4 *)(*piVar1 + 0x10));
  return;
}

