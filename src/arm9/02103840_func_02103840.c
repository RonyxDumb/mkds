/* Decompiled C draft; module arm9; ROM address 02103840. No matching claim. */
#include "types.h"
#include "deps/02103840_func_02103840.h"

void func_02103840(int param_1)

{
  uint uVar1;
  
  if (param_1 !=
      *(char *)((*(uint *)(uRam02103880 & 0xfffffffc) >> (uRam02103880 & 3) * 8 |
                *(uint *)(uRam02103880 & 0xfffffffc) << (uRam02103880 & 3) * -8 + 0x20) + 0x62)) {
    return;
  }
  if (*(uint *)(uRam02103884 & 0xfffffffc) >> (uRam02103884 & 3) * 8 == 0 &&
      *(uint *)(uRam02103884 & 0xfffffffc) << (uRam02103884 & 3) * -8 + 0x20 == 0) {
    return;
  }
  uVar1 = *(uint *)(uRam02103888 & 0xfffffffc) >> (uRam02103888 & 3) * 8 |
          *(uint *)(uRam02103888 & 0xfffffffc) << (uRam02103888 & 3) * -8 + 0x20;
  if ((int)(*(uint *)((uint)puRam0210388c & 0xfffffffc) >> ((uint)puRam0210388c & 3) * 8 |
           *(uint *)((uint)puRam0210388c & 0xfffffffc) << ((uint)puRam0210388c & 3) * -8 + 0x20) <
      (int)uVar1) {
    *puRam0210388c = uVar1;
  }
  return;
}

