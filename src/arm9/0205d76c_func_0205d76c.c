/* Decompiled C draft; module arm9; ROM address 0205d76c. No matching claim. */
#include "types.h"
#include "deps/0205d76c_func_0205d76c.h"

void func_0205d76c(uint param_1,undefined1 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(ushort *)
           ((*(uint *)(uRam0205d7c0 & 0xfffffffc) >> (uRam0205d7c0 & 3) * 8 |
            *(uint *)(uRam0205d7c0 & 0xfffffffc) << (uRam0205d7c0 & 3) * -8 + 0x20) + 0x60) - 1;
  iVar1 = iVar2 >> 0x1f;
  *(undefined1 *)
   ((param_1 & 0xff) * 10 +
    (((uint)(iVar2 * 0x40000000 + iVar1) >> 0x1e | iVar1 << 2) - iVar1 & 0xff) * 0x50 +
    (*(uint *)(uRam0205d7c4 & 0xfffffffc) >> (uRam0205d7c4 & 3) * 8 |
    *(uint *)(uRam0205d7c4 & 0xfffffffc) << (uRam0205d7c4 & 3) * -8 + 0x20) + 2) = param_2;
  return;
}

