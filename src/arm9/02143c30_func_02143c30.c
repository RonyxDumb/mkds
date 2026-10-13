/* Decompiled C draft; module arm9; ROM address 02143c30. No matching claim. */
#include "types.h"
#include "deps/02143c30_func_02143c30.h"

undefined4 func_02143c30(int param_1)

{
  if (0x70 < *(ushort *)(param_1 + 4)) {
    return 0;
  }
  if ((9 < *(ushort *)(param_1 + 0x18)) && (*(ushort *)(param_1 + 0x18) < 0x3e9)) {
    if ((*(ushort *)(param_1 + 0x32) != 0) && (*(ushort *)(param_1 + 0x32) < 0xf)) {
      return 1;
    }
    return 0;
  }
  return 0;
}

