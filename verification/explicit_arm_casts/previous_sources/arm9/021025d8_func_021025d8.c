/* Decompiled C draft; module arm9; ROM address 021025d8. No matching claim. */
#include "types.h"
#include "deps/021025d8_func_021025d8.h"

void func_021025d8(int param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0x154) = 0x13;
  *(undefined4 *)(param_1 + 0x158) = 0;
  uVar1 = uRam02102664;
  *(undefined4 *)(param_1 + 0x15c) = 0;
  *(undefined4 *)(param_1 + 0x160) = 0xe;
  StateDualHandler_Create(param_1 + 300,uVar1,7,param_1);
  *(undefined4 *)(param_1 + 0x140) = 8;
  *(undefined4 *)(param_1 + 0x144) = 0;
  func_020f9c40(param_1);
  *(undefined4 *)(param_1 + 0x24c) = 0;
  *(undefined4 *)(param_1 + 0x250) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x254) = 0x12;
  *(undefined4 *)(param_1 + 600) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x25c) = 0x12;
  *(undefined4 *)(param_1 + 0x260) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x264) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x268) = 0;
  *(undefined4 *)(param_1 + 0x26c) = 0;
  *(undefined4 *)(param_1 + 0x270) = 0;
  return;
}

