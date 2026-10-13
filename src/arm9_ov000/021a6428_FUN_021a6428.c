/* Decompiled C draft; module arm9_ov000; ROM address 021a6428. No matching claim. */
#include "types.h"
#include "deps/021a6428_FUN_021a6428.h"

undefined4 FUN_021a6428(void)

{
  func_0x0200fca0();
  if (*DAT_021a6468 == 0) {
    func_0x0200fcb4();
    return 1;
  }
  if (*(int *)(*DAT_021a6468 + DAT_021a646c) != 1) {
    func_0x0200fcb4();
    return 1;
  }
  *DAT_021a6468 = 0;
  func_0x0200fcb4();
  return 0;
}

