/* Decompiled C draft; module arm9_ov000; ROM address 02180814. No matching claim. */
#include "types.h"
#include "deps/02180814_FUN_02180814.h"

void FUN_02180814(void)

{
  if (*(code **)(*DAT_02180840 + 0x20) != (code *)0x0) {
    (**(code **)(*DAT_02180840 + 0x20))();
  }
  FUN_02180be8();
  func_0x0202bb60();
  func_0x0212abd0();
  func_0x02125da0();
  *DAT_02180840 = 0;
  return;
}

