/* Decompiled C draft; module arm9; ROM address 02020a14. No matching claim. */
#include "types.h"
#include "deps/02020a14_func_02020a14.h"

void func_02020a14(uint param_1,int param_2,undefined4 param_3,int param_4,uint param_5,uint param_6
                  ,int param_7,int param_8,int param_9,int param_10)

{
  MaybeSoundSendCommand
            (0xe,param_1 | param_9 << 0x10,param_3,param_6 | param_7 << 0x18 | param_8 << 0x16,
             param_5 | param_4 << 0x1a | param_2 << 0x18 | param_10 << 0x10);
  return;
}

