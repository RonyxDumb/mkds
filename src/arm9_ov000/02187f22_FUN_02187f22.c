/* Decompiled C draft; module arm9_ov000; ROM address 02187f22. No matching claim. */
#include "types.h"
#include "deps/02187f22_FUN_02187f22.h"

void FUN_02187f22(void)

{
  int in_stack_00000008;
  int in_stack_00000010;
  int in_stack_00000018;
  
  if (in_stack_00000008 != 0) {
    (**(code **)(*DAT_02187fa4 + DAT_02187f94))(DAT_02187f7c,in_stack_00000008,0);
  }
  if (in_stack_00000010 != 0) {
    (**(code **)(*DAT_02187fa4 + DAT_02187f94))(DAT_02187f80,in_stack_00000010,0);
  }
  if (in_stack_00000018 != 0) {
    (**(code **)(*DAT_02187fa4 + DAT_02187f94))(DAT_02187f70,in_stack_00000018,0);
  }
  return;
}

