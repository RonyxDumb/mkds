/* Decompiled C draft; module arm9; ROM address 021187d4. No matching claim. */
#include "types.h"
#include "deps/021187d4_func_021187d4.h"

void func_021187d4(void)

{
  if (*psRam02118808 != 2) {
    func_020d0efc(*(undefined4 *)
                   (*(short *)(*piRam0211880c + 0x78) * 4 +
                   iRam02118810 + *(int *)(*piRam0211880c + 0x44) * 0x10));
    *(undefined4 *)(*piRam0211880c + 0x7c) = 1;
  }
  return;
}

