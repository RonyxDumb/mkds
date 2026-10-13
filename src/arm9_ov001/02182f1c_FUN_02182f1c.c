/* Decompiled C draft; module arm9_ov001; ROM address 02182f1c. No matching claim. */
#include "types.h"
#include "deps/02182f1c_FUN_02182f1c.h"

void FUN_02182f1c(int param_1,int param_2)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0xac) = 0x1e;
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 0x80);
  *(int *)(param_1 + 8) = *(int *)(param_2 + 0x84) + DAT_02182f80;
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_2 + 0x88);
  *(undefined4 *)(param_1 + 0x14) = DAT_02182f84;
  *(undefined4 *)(param_1 + 0xf8) = 1;
  *(undefined4 *)(param_1 + 0xb0) = DAT_02182f88;
  *(undefined2 *)(param_1 + 0xa0) = 0x1f;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *DAT_02182f8c;
  uVar1 = func_0x0208b7bc(DAT_02182f90,param_1 + 4);
  *(undefined4 *)(param_1 + 0xfc) = uVar1;
  *(undefined4 *)(param_1 + DAT_02182f94) = 0xd;
  return;
}

