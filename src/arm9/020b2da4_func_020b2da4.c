/* Decompiled C draft; module arm9; ROM address 020b2da4. No matching claim. */
#include "types.h"
#include "deps/020b2da4_func_020b2da4.h"

void func_020b2da4(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = GetCurrentOptionMenuKind_from_thumb();
  iVar3 = *(int *)(*piRam020b2dfc + iVar1 * 0x1c + 0x50);
  iVar1 = func_020b32f8();
  if (iVar1 != 0) {
    for (iVar2 = 0; iVar2 < iVar3; iVar2 = iVar2 + 1) {
      func_020b2e00(iVar1,2,iVar3 * -2 + 0xd + iVar2 * 4);
    }
    func_020b44a4(iVar1,0,0,0x20,0x18,0xf);
  }
  return;
}

