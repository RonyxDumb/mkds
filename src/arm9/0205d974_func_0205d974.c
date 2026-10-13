/* Decompiled C draft; module arm9; ROM address 0205d974. No matching claim. */
#include "types.h"
#include "deps/0205d974_func_0205d974.h"

void func_0205d974(uint param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(ushort *)
           ((*(uint *)(uRam0205d9cc & 0xfffffffc) >> (uRam0205d9cc & 3) * 8 |
            *(uint *)(uRam0205d9cc & 0xfffffffc) << (uRam0205d9cc & 3) * -8 + 0x20) + 0x60) - 1;
  iVar1 = iVar2 >> 0x1f;
  *(undefined2 *)
   ((param_1 & 0xff) * 10 +
   (((uint)(iVar2 * 0x40000000 + iVar1) >> 0x1e | iVar1 << 2) - iVar1 & 0xff) * 0x50 +
   (*(uint *)(uRam0205d9d0 & 0xfffffffc) >> (uRam0205d9d0 & 3) * 8 |
   *(uint *)(uRam0205d9d0 & 0xfffffffc) << (uRam0205d9d0 & 3) * -8 + 0x20)) = 0;
  return;
}

