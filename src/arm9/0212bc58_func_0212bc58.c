/* Decompiled C draft; module arm9; ROM address 0212bc58. No matching claim. */
#include "types.h"
#include "deps/0212bc58_func_0212bc58.h"

undefined4 func_0212bc58(uint param_1)

{
  if (param_1 == 0) {
    return 1;
  }
  if ((param_1 &
      (*(uint *)((uint)puRam0212bca8 & 0xfffffffc) >> ((uint)puRam0212bca8 & 3) * 8 |
      *(uint *)((uint)puRam0212bca8 & 0xfffffffc) << ((uint)puRam0212bca8 & 3) * -8 + 0x20)) == 0) {
    SND_LockChannel(param_1,0);
    *puRam0212bca8 =
         *(uint *)((uint)puRam0212bca8 & 0xfffffffc) >> ((uint)puRam0212bca8 & 3) * 8 |
         *(uint *)((uint)puRam0212bca8 & 0xfffffffc) << ((uint)puRam0212bca8 & 3) * -8 + 0x20 |
         param_1;
    return 1;
  }
  return 0;
}

