/* Decompiled C draft; module arm9_ov001; ROM address 02192f8c. No matching claim. */
#include "types.h"
#include "deps/02192f8c_FUN_02192f8c.h"

void FUN_02192f8c(void)

{
  if (*(code **)(*DAT_02192fb4 + 0x1c) != (code *)0x0) {
    (**(code **)(*DAT_02192fb4 + 0x1c))();
  }
  FUN_021932c8();
  func_0x0212abd0();
  func_0x02125da0();
  *DAT_02192fb4 = 0;
  return;
}

