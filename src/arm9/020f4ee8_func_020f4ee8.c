/* Decompiled C draft; module arm9; ROM address 020f4ee8. No matching claim. */
#include "types.h"
#include "deps/020f4ee8_func_020f4ee8.h"

int func_020f4ee8(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = func_020fa3d0(3,8,uRam020f4f40,uRam020f4f40);
  if (iVar2 != 0) {
    uVar1 = iVar2 + 0x74U & 3;
    uVar3 = *(uint *)(iVar2 + 0x74U & 0xfffffffc);
    if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0x180000) == 0) {
      *(undefined4 *)(iVar2 + 0x120) = 0;
    }
    func_020f9c40(iVar2);
    *(undefined4 *)(iVar2 + 0x134) = 0;
    *(undefined4 *)(iVar2 + 0x130) = 0;
    return iVar2;
  }
  return 0;
}

