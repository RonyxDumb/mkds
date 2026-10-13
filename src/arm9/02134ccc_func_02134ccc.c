/* Decompiled C draft; module arm9; ROM address 02134ccc. No matching claim. */
#include "types.h"
#include "deps/02134ccc_func_02134ccc.h"

uint func_02134ccc(ushort *param_1,uint param_2,int param_3)

{
  if (param_2 == 0) {
    return 0;
  }
  if (param_3 == 0) {
    return 0xffffffff;
  }
  if (param_1 != (ushort *)0x0) {
    *param_1 = ((ushort)(*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8) |
               (ushort)(*(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20)) & 0xff;
  }
  return (uint)(((*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
                 *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) & 0xff) != 0);
}

