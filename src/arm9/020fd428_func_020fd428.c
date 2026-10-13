/* Decompiled C draft; module arm9; ROM address 020fd428. No matching claim. */
#include "types.h"
#include "deps/020fd428_func_020fd428.h"

int func_020fd428(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = func_020fa3d0(9,8,uRam020fd490,uRam020fd490);
  if (iVar2 != 0) {
    uVar1 = iVar2 + 0x74U & 3;
    uVar3 = *(uint *)(iVar2 + 0x74U & 0xfffffffc);
    if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0x180000) == 0) {
      *(undefined4 *)(iVar2 + 0x120) = 0;
    }
    func_020f9c40(iVar2);
    *(undefined4 *)(iVar2 + 0x1a0) = 0;
    StateDualHandler_SetState(iVar2 + 0x184,3);
    *(undefined4 *)(iVar2 + 0x174) = 0;
    return iVar2;
  }
  return 0;
}

