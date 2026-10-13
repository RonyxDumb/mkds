/* Decompiled C draft; module arm9; ROM address 020caba4. No matching claim. */
#include "types.h"
#include "deps/020caba4_func_020caba4.h"

void func_020caba4(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *piRam020cac14;
  iVar3 = *(int *)(iVar1 + 0x68) + 0xc;
  if ((iVar3 != 0) && ((*(int *)(iVar1 + 0x10) == 0 || (4 < *(int *)(iVar1 + 0x14))))) {
    iVar2 = *(int *)(iVar1 + 0x28) * -2 + 0xd + param_1 * 4;
    if (*(int *)(iVar1 + 0x24) < 0x1e) {
      func_020b4428(iVar3,2,iVar2,1,1,0x21);
      func_020b4428(iVar3,2,iVar2 + 1,1,1,0x41);
    }
    func_020b44a4(iVar3,0,iVar2 + -1,0x20,4,0xe);
  }
  return;
}

