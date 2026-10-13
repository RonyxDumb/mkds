/* Decompiled C draft; module arm9_ov003; ROM address 021cc97c. No matching claim. */
#include "types.h"
#include "deps/021cc97c_FUN_021cc97c.h"

void FUN_021cc97c(void)

{
  if (*(char *)(*DAT_021cc9b4 + DAT_021cc9b8) != '\0') {
    func_0x0200ee74(*DAT_021cc9b4 + 4,DAT_021cc9bc);
    func_0x0214bc9c(*DAT_021cc9b4 + 4,0,DAT_021cc9bc);
    *(undefined1 *)(*DAT_021cc9b4 + DAT_021cc9b8) = 0;
  }
  return;
}

