/* Decompiled C draft; module arm9_ov001; ROM address 0219afc8. No matching claim. */
#include "types.h"
#include "deps/0219afc8_FUN_0219afc8.h"

void FUN_0219afc8(int param_1)

{
  int *piVar1;
  
  piVar1 = DAT_0219aff4;
  *(undefined4 *)
   (*(int *)(*DAT_0219aff4 + 0x1c) + (uint)*(ushort *)(DAT_0219aff8 + param_1 * 2) * 0x40) = 1;
  func_0x02124a20(*(undefined2 *)(DAT_0219affc + param_1 * 2),0xe,*(undefined4 *)(*piVar1 + 0xc),
                  *(undefined4 *)(*piVar1 + 0x10));
  return;
}

