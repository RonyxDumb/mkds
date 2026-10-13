/* Decompiled C draft; module arm9; ROM address 0207a74c. No matching claim. */
#include "types.h"
#include "deps/0207a74c_func_0207a74c.h"

void func_0207a74c(int param_1)

{
  longlong lVar1;
  
  lVar1 = (longlong)param_1 *
          (longlong)
          (int)(*(uint *)(uRam0207a778 & 0xfffffffc) >> (uRam0207a778 & 3) * 8 |
               *(uint *)(uRam0207a778 & 0xfffffffc) << (uRam0207a778 & 3) * -8 + 0x20) + 0x800;
  *puRam0207a77c = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000;
  return;
}

