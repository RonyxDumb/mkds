/* Decompiled C draft; module arm9; ROM address 0200964c. No matching claim. */
#include "types.h"
#include "deps/0200964c_func_0200964c.h"

void func_0200964c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_020096bc;
  do {
    switch(*(undefined1 *)(iVar1 + 0xc)) {
    case 0:
    case 1:
      iVar2 = func_020095fc();
      if (iVar2 == 0) {
        return;
      }
      break;
    case 2:
      func_020095c4();
      break;
    case 3:
      func_020094b8(param_1,param_2,param_3);
      return;
    case 4:
      func_02009494();
      break;
    case 5:
      func_020092d0(param_1,param_2,param_3);
      return;
    }
  } while( true );
}

