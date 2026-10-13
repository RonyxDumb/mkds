/* Decompiled C draft; module arm7; ROM address 03800ae4. No matching claim. */
#include "types.h"
#include "deps/03800ae4_FUN_03800ae4.h"

void FUN_03800ae4(undefined4 param_1,undefined4 param_2)

{
  do {
  } while (((*(uint *)(DAT_03800b5c & 0xfffffffc) >> (DAT_03800b5c & 3) * 8 |
            *(uint *)(DAT_03800b5c & 0xfffffffc) << (DAT_03800b5c & 3) * -8 + 0x20) & 0x80000000) !=
           0);
  *DAT_03800b60 = 0xc0;
  *DAT_03800b64 = (char)((uint)param_1 >> 0x18);
  *DAT_03800b68 = (char)((uint)param_1 >> 0x10);
  *DAT_03800b6c = (char)((uint)param_1 >> 8);
  *DAT_03800b70 = (char)param_1;
  *DAT_03800b74 = (char)((uint)param_2 >> 0x18);
  *DAT_03800b78 = (char)((uint)param_2 >> 0x10);
  *DAT_03800b7c = (char)((uint)param_2 >> 8);
  *DAT_03800b80 = (char)param_2;
  return;
}

