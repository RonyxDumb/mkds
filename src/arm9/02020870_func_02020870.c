/* Decompiled C draft; module arm9; ROM address 02020870. No matching claim. */
#include "types.h"
#include "deps/02020870_func_02020870.h"

void func_02020870(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5
                  )

{
  MaybeSoundSendCommand(7,param_1 | param_5 << 0x18,param_2,param_3,param_4);
  return;
}

