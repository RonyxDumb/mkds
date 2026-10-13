/* Decompiled C draft; module arm9; ROM address 02020b70. No matching claim. */
#include "types.h"
#include "deps/02020b70_func_02020b70.h"

void func_02020b70(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,
                  int param_6,int param_7)

{
  MaybeSoundSendCommand
            (0x11,param_3,param_4,
             param_1 << 0x1f | param_2 << 0x1e | param_5 << 0x1d | param_6 << 0x1c | param_7 << 0x1b
             ,0);
  return;
}

