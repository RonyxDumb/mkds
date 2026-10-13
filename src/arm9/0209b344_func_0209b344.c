/* Decompiled C draft; module arm9; ROM address 0209b344. No matching claim. */
#include "types.h"
#include "deps/0209b344_func_0209b344.h"

undefined1 func_0209b344(undefined4 param_1,int param_2,char *param_3,undefined1 *param_4)

{
  undefined1 uVar1;
  
  uVar1 = *param_4;
  if (*param_3 == '\x01') {
    func_0209b388(param_1,param_2 + 0x80,param_2 + 0x68,param_2 + 0xa4);
    func_020d26f8(param_1,param_2);
  }
  return uVar1;
}

