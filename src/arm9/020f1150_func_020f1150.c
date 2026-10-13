/* Decompiled C draft; module arm9; ROM address 020f1150. No matching claim. */
#include "types.h"
#include "deps/020f1150_func_020f1150.h"

void func_020f1150(int param_1,int param_2)

{
  *(uint *)(param_1 + 0x228) =
       param_2 * 0x210 +
       (*(uint *)(uRam020f117c & 0xfffffffc) >> (uRam020f117c & 3) * 8 |
       *(uint *)(uRam020f117c & 0xfffffffc) << (uRam020f117c & 3) * -8 + 0x20);
  *(undefined4 *)(param_1 + 0x22c) = 0;
  *(undefined4 *)(param_1 + 0x230) = 0;
  *(undefined4 *)(param_1 + 0x234) = 0;
  *(undefined4 *)(param_1 + 0x238) = 0;
  return;
}

