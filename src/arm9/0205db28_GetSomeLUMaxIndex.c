/* Decompiled C draft; module arm9; ROM address 0205db28. No matching claim. */
#include "types.h"
#include "deps/0205db28_GetSomeLUMaxIndex.h"

uint GetSomeLUMaxIndex(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(ushort *)
           ((*(uint *)(uRam0205db4c & 0xfffffffc) >> (uRam0205db4c & 3) * 8 |
            *(uint *)(uRam0205db4c & 0xfffffffc) << (uRam0205db4c & 3) * -8 + 0x20) + 0x60) - 1;
  iVar1 = iVar2 >> 0x1f;
  return ((uint)(iVar2 * 0x40000000 + iVar1) >> 0x1e | iVar1 << 2) - iVar1 & 0xff;
}

