/* Decompiled C draft; module arm7; ROM address 060133b4. No matching claim. */
#include "types.h"
#include "deps/060133b4_FUN_060133b4.h"

undefined4 FUN_060133b4(int param_1)

{
  FUN_060096e4(param_1,3);
  FUN_060096e4(param_1 + 1,1);
  FUN_060096e4(param_1 + 2,
               *(ushort *)
                ((*(uint *)(DAT_060133f8 & 0xfffffffc) >> (DAT_060133f8 & 3) * 8 |
                 *(uint *)(DAT_060133f8 & 0xfffffffc) << (DAT_060133f8 & 3) * -8 + 0x20) + 0x3be) &
               0xff);
  return 3;
}

