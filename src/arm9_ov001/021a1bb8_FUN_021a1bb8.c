/* Decompiled C draft; module arm9_ov001; ROM address 021a1bb8. No matching claim. */
#include "types.h"
#include "deps/021a1bb8_FUN_021a1bb8.h"

void FUN_021a1bb8(void)

{
  if (*(int *)(*DAT_021a1bf0 + 0x34) == 3) {
    func_0x020295c0(*(undefined4 *)(DAT_021a1bf4 + 8));
    func_0x020295b0();
  }
  else {
    func_0x020295c0(*(undefined4 *)(DAT_021a1bf4 + *(int *)(*DAT_021a1bf0 + 0x34) * 4));
    func_0x020295a0();
  }
  func_0x02029590(0);
  return;
}

