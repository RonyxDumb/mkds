/* Decompiled C draft; module arm9; ROM address 020d9cf4. No matching claim. */
#include "types.h"
#include "deps/020d9cf4_func_020d9cf4.h"

void func_020d9cf4(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                  undefined2 param_6,undefined2 param_7,undefined2 param_8,undefined2 param_9,
                  undefined2 param_10,ushort param_11,undefined2 param_12,undefined2 param_13,
                  undefined2 param_14,undefined4 param_15)

{
  int *piVar1;
  int *piVar2;
  undefined2 uVar3;
  
  piVar1 = piRam020d9dcc;
  *(int *)(*piRam020d9dcc + 0x1c) = param_1 + param_2 >> 1;
  *(undefined4 *)(*piVar1 + 4) = *(undefined4 *)(*piVar1 + 0x1c);
  *(undefined4 *)(*piVar1 + 0x10) = *(undefined4 *)(*piVar1 + 4);
  *(int *)(*piVar1 + 0x28) = param_1 - param_2 >> 1;
  *(undefined2 *)(*piVar1 + 0x2c) = 0;
  *(undefined2 *)(*piVar1 + 0x3a) = 0;
  *(undefined2 *)(*piVar1 + 0x3c) = 0;
  *(undefined2 *)(*piVar1 + 0x50) = param_6;
  *(undefined2 *)(*piVar1 + 0x52) = param_7;
  uVar3 = _s32_div_f(uRam020d9dd0,param_8);
  piVar1 = piRam020d9dcc;
  *(undefined2 *)(*piRam020d9dcc + 0x2e) = uVar3;
  *(ushort *)(*piVar1 + 0x40) = *(ushort *)(*piVar1 + 0x2e) >> 2;
  *(undefined4 *)(*piVar1 + 0x24) = 0;
  *(undefined2 *)(*piVar1 + 0x34) = param_9;
  *(undefined2 *)(*piVar1 + 0x36) = param_10;
  *(undefined4 *)(*piVar1 + 0x30) = 0;
  piVar2 = piRam020d9dd4;
  *(undefined4 *)(*piVar1 + 0x18) = *(undefined4 *)(*piRam020d9dd4 + 4);
  *(undefined4 *)*piVar1 = ((undefined4 *)*piVar1)[6];
  *(undefined4 *)(*piVar1 + 0x20) = *(undefined4 *)(*piVar2 + 0xc);
  *(undefined4 *)(*piVar1 + 8) = *(undefined4 *)(*piVar1 + 0x20);
  *(undefined4 *)(*piVar1 + 0x44) = param_3;
  *(undefined4 *)(*piVar1 + 0x48) = param_4;
  *(undefined4 *)(*piVar1 + 0x4c) = param_5;
  *(uint *)(*piVar1 + 0x54) = (uint)param_11;
  *(undefined2 *)(*piVar1 + 0x58) = param_12;
  *(undefined2 *)(*piVar1 + 0x5a) = param_13;
  *(undefined2 *)(*piVar1 + 0x5c) = param_14;
  Matrix4x3_Identity(*piVar1 + iRam020d9dd8);
  *(undefined4 *)(*piRam020d9dcc + iRam020d9ddc) = param_15;
  return;
}

