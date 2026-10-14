/* Decompiled C draft; module arm9; ROM address 0208f0a0. No matching claim. */
#include "types.h"
#include "deps/0208f0a0_func_0208f0a0.h"

void func_0208f0a0(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = IntrusiveListWrapper_NextItem
                    (*(uint *)(uRam0208f0f4 & 0xfffffffc) >> (uRam0208f0f4 & 3) * 8 |
                     *(uint *)(uRam0208f0f4 & 0xfffffffc) << (uRam0208f0f4 & 3) * -8 + 0x20,0);
  uVar2 = uRam0208f0f4;
  if (iVar3 == 0) {
    return;
  }
  do {
    func_0208e99c(iVar3);
    uVar1 = uVar2 & 3;
    uVar4 = *(uint *)(uVar2 & 0xfffffffc);
    iVar3 = IntrusiveListWrapper_NextItem(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20,iVar3);
  } while (iVar3 != 0);
  return;
}

