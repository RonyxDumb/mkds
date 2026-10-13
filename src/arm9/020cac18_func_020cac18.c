/* Decompiled C draft; module arm9; ROM address 020cac18. No matching claim. */
#include "types.h"
#include "deps/020cac18_func_020cac18.h"

void func_020cac18(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(*piRam020cac64 + 0x28);
  iVar3 = *(int *)(*piRam020cac64 + 0x68) + 0xc;
  if (iVar3 != 0) {
    for (iVar1 = 0; iVar1 < iVar2; iVar1 = iVar1 + 1) {
      func_020cac68(iVar3,2,iVar2 * -2 + 0xd + iVar1 * 4);
    }
    func_020b44a4(iVar3,0,0,0x20,0x18,0xf);
  }
  return;
}

