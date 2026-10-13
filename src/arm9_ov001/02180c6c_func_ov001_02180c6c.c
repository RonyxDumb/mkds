/* Decompiled C draft; module arm9_ov001; ROM address 02180c6c. No matching claim. */
#include "types.h"
#include "deps/02180c6c_func_ov001_02180c6c.h"

void func_ov001_02180c6c(int param_1)

{
  *puRam02180c84 =
       (*(uint *)((uint)puRam02180c84 & 0xfffffffc) >> ((uint)puRam02180c84 & 3) * 8 |
       *(uint *)((uint)puRam02180c84 & 0xfffffffc) << ((uint)puRam02180c84 & 3) * -8 + 0x20) &
       0xffffe0ff | param_1 << 8;
  return;
}

