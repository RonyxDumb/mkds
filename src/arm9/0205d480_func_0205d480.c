/* Decompiled C draft; module arm9; ROM address 0205d480. No matching claim. */
#include "types.h"
#include "deps/0205d480_func_0205d480.h"

int func_0205d480(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(ushort *)
           ((*(uint *)(uRam0205d4e0 & 0xfffffffc) >> (uRam0205d4e0 & 3) * 8 |
            *(uint *)(uRam0205d4e0 & 0xfffffffc) << (uRam0205d4e0 & 3) * -8 + 0x20) + 0x60) - 1;
  iVar1 = iVar2 >> 0x1f;
  iVar3 = 0;
  do {
    if ((int)((uint)*(byte *)((*(uint *)(uRam0205d4e4 & 0xfffffffc) >> (uRam0205d4e4 & 3) * 8 |
                              *(uint *)(uRam0205d4e4 & 0xfffffffc) << (uRam0205d4e4 & 3) * -8 + 0x20
                              ) + (((uint)(iVar2 * 0x40000000 + iVar1) >> 0x1e | iVar1 << 2) - iVar1
                                  & 0xff) * 8 + iVar3 * 4 + 0x147) << 0x1f) < 0) {
      return iVar3;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 2);
  return -1;
}

