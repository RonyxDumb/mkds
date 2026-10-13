/* Decompiled C draft; module arm9_ov001; ROM address 0219baf4. No matching claim. */
#include "types.h"
#include "deps/0219baf4_FUN_0219baf4.h"

void FUN_0219baf4(void)

{
  if (*(int *)(*DAT_0219bb38 + 0x6c) == 1) {
    *DAT_0219bb3c = *DAT_0219bb3c & DAT_0219bb40 | DAT_0219bb44;
  }
  func_0x0212b91c();
  func_0x0211de34();
  func_0x0211df38();
  func_0x02117218();
  func_0x02036ab0(*(undefined4 *)(*DAT_0219bb38 + 0x44));
  *DAT_0219bb38 = 0;
  return;
}

