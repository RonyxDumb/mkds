/* Decompiled C draft; module arm9; ROM address 020b2c80. No matching claim. */
#include "types.h"
#include "deps/020b2c80_func_020b2c80.h"

void func_020b2c80(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = GetCurrentOptionMenuKind_from_thumb();
  iVar3 = *(int *)(*piRam020b2d00 + iVar1 * 0x1c + 0x50);
  iVar1 = func_020b32f8();
  if ((iVar1 != 0) &&
     ((iVar2 = *piRam020b2d00, *(int *)(iVar2 + 0x10) == 0 || (4 < *(int *)(iVar2 + 0x14))))) {
    iVar3 = iVar3 * -2 + 0xd + param_1 * 4;
    if (*(int *)(iVar2 + 0x34) < 0x1e) {
      func_020b4428(iVar1,2,iVar3,1,1,0x21);
      func_020b4428(iVar1,2,iVar3 + 1,1,1,0x41);
    }
    func_020b44a4(iVar1,0,iVar3 + -1,0x20,4,0xe);
  }
  return;
}

