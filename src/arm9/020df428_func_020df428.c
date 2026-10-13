/* Decompiled C draft; module arm9; ROM address 020df428. No matching claim. */
#include "types.h"
#include "deps/020df428_func_020df428.h"

void func_020df428(int param_1,int param_2)

{
  func_020de6a8();
  if (*(int *)(param_1 + 0xf8) != 0) {
    *(short *)(param_1 + iRam020df480) = (short)uRam020df47c;
    return;
  }
  func_020d7d4c(param_1 + iRam020df484,param_2,*puRam020df488,(int)*(short *)(param_2 + 0x28));
  func_020d859c(param_1 + iRam020df484,*(undefined2 *)(param_2 + 0x30),1);
  func_020d8c74(param_1 + iRam020df484,param_1 + 4);
  return;
}

