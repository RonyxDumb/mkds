/* Decompiled C draft; module arm7; ROM address 0600af34. No matching claim. */
#include "types.h"
#include "deps/0600af34_FUN_0600af34.h"

undefined4 FUN_0600af34(ushort *param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(DAT_0600af78 & 0xfffffffc) >> (DAT_0600af78 & 3) * 8 |
          *(uint *)(DAT_0600af78 & 0xfffffffc) << (DAT_0600af78 & 3) * -8 + 0x20;
  *(ushort *)(uVar1 + 0x3a4) = *param_1;
  *(ushort *)(uVar1 + 0x3a6) = param_1[1] | *param_1;
  FUN_0600aea0();
  return 0;
}

