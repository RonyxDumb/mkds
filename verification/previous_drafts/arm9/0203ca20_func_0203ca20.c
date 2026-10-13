/* Decompiled C draft; module arm9; ROM address 0203ca20. No matching claim. */
#include "types.h"
#include "deps/0203ca20_func_0203ca20.h"

void func_0203ca20(void)

{
  *(undefined4 *)
   ((*(uint *)(uRam0203ca34 & 0xfffffffc) >> (uRam0203ca34 & 3) * 8 |
    *(uint *)(uRam0203ca34 & 0xfffffffc) << (uRam0203ca34 & 3) * -8 + 0x20) + 4) = 1;
  return;
}

