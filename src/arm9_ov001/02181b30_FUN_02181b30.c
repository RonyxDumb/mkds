/* Decompiled C draft; module arm9_ov001; ROM address 02181b30. No matching claim. */
#include "types.h"
#include "deps/02181b30_FUN_02181b30.h"

uint FUN_02181b30(void)

{
  return (*(int *)(*DAT_02181b48 + 0x44) + (uint)*(byte *)(*DAT_02181b4c + DAT_02181b50)) - 1 &
         0xffff;
}

