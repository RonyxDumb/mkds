/* Decompiled C draft; module arm9; ROM address 0210340c. No matching claim. */
#include "types.h"
#include "deps/0210340c_func_0210340c.h"

void func_0210340c(int *param_1,int param_2)

{
  *param_1 = param_2;
  param_1[1] = iRam02103458;
  param_1[1] = param_1[1] & uRam0210345c;
  param_1[2] = **(int **)(param_2 + 0x1c);
  param_1[3] = **(int **)(param_2 + 0x20);
  param_1[4] = *(int *)(param_2 + 0xc);
  param_1[5] = *(int *)(param_2 + 0x10);
  param_1[6] = 1 << (((param_1[2] & uRam02103460) >> 0x17) + 0xf & 0xff);
  param_1[7] = 1 << (((param_1[2] & uRam02103464) >> 0x14) + 0xf & 0xff);
  return;
}

