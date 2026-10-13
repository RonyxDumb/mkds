/* Decompiled C draft; module arm9_ov001; ROM address 02181b68. No matching claim. */
#include "types.h"
#include "deps/02181b68_FUN_02181b68.h"

undefined4 FUN_02181b68(int param_1)

{
  return *(undefined4 *)
          (*DAT_02181b80 + (param_1 - (uint)*(byte *)(*DAT_02181b84 + DAT_02181b88)) * 4 + 0x48);
}

