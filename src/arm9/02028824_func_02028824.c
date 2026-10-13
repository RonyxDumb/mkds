/* Decompiled C draft; module arm9; ROM address 02028824. No matching claim. */
#include "types.h"
#include "deps/02028824_func_02028824.h"

void func_02028824(undefined1 param_1)

{
  int iVar1;
  
  iVar1 = func_02028850();
  if (iVar1 == 8) {
    *(undefined1 *)
     ((*(uint *)(uRam0202884c & 0xfffffffc) >> (uRam0202884c & 3) * 8 |
      *(uint *)(uRam0202884c & 0xfffffffc) << (uRam0202884c & 3) * -8 + 0x20) + 0x15f7) = param_1;
  }
  return;
}

