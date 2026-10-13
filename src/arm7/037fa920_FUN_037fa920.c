/* Decompiled C draft; module arm7; ROM address 037fa920. No matching claim. */
#include "types.h"
#include "deps/037fa920_FUN_037fa920.h"

uint FUN_037fa920(int param_1)

{
  FUN_037faf70();
  if (param_1 < (int)(*(uint *)((uint)DAT_037fa964 & 0xfffffffc) >> ((uint)DAT_037fa964 & 3) * 8 |
                     *(uint *)((uint)DAT_037fa964 & 0xfffffffc) <<
                     ((uint)DAT_037fa964 & 3) * -8 + 0x20)) {
    *DAT_037fa968 =
         (*(uint *)((uint)DAT_037fa968 & 0xfffffffc) >> ((uint)DAT_037fa968 & 3) * 8 |
         *(uint *)((uint)DAT_037fa968 & 0xfffffffc) << ((uint)DAT_037fa968 & 3) * -8 + 0x20) + 1;
  }
  *DAT_037fa964 = param_1;
  FUN_037faf84();
  return *(uint *)((uint)DAT_037fa968 & 0xfffffffc) >> ((uint)DAT_037fa968 & 3) * 8 |
         *(uint *)((uint)DAT_037fa968 & 0xfffffffc) << ((uint)DAT_037fa968 & 3) * -8 + 0x20;
}

