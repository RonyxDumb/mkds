/* Decompiled C draft; module arm9; ROM address 02008dbc. No matching claim. */
#include "types.h"
#include "deps/02008dbc_func_02008dbc.h"

void func_02008dbc(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = iRam02008e00 * param_2;
  if (*(short *)(param_1 + 0x48) != *(short *)(*piRam02008e04 + iVar1 + iRam02008e08)) {
    func_0200895c(param_2);
    CopyMemory16(param_1,*piRam02008e04 + iRam02008e0c + iVar1,0xc0);
    func_02008a4c(param_2);
  }
  return;
}

