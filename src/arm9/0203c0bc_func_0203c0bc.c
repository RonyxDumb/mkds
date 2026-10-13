/* Decompiled C draft; module arm9; ROM address 0203c0bc. No matching claim. */
#include "types.h"
#include "deps/0203c0bc_func_0203c0bc.h"

undefined4 func_0203c0bc(void)

{
  int iVar1;
  uint auStack_8 [2];
  
  iVar1 = (int)*(char *)((*(uint *)(uRam0203c168 & 0xfffffffc) >> (uRam0203c168 & 3) * 8 |
                         *(uint *)(uRam0203c168 & 0xfffffffc) << (uRam0203c168 & 3) * -8 + 0x20) +
                        0x62);
  if (iVar1 == -1) {
    return 0;
  }
  if (6 < *(byte *)((*(uint *)(uRam0203c16c & 0xfffffffc) >> (uRam0203c16c & 3) * 8 |
                    *(uint *)(uRam0203c16c & 0xfffffffc) << (uRam0203c16c & 3) * -8 + 0x20) + 10)) {
    return 1;
  }
  iVar1 = StructCYB_SomeFn_0(iVar1 * 0x5c + iRam0203c170 + 0x28);
  if (iVar1 != 0) {
    return 1;
  }
  iVar1 = func_020617a8(auStack_8);
  if ((iVar1 != 0) && (900 < auStack_8[0])) {
    return 1;
  }
  return 0;
}

