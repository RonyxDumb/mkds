/* Decompiled C draft; module arm9; ROM address 0211fda8. No matching claim. */
#include "types.h"
#include "deps/0211fda8_func_0211fda8.h"

void func_0211fda8(void)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  
  sVar1 = *(short *)((*(uint *)(uRam0211fe14 & 0xfffffffc) >> (uRam0211fe14 & 3) * 8 |
                     *(uint *)(uRam0211fe14 & 0xfffffffc) << (uRam0211fe14 & 3) * -8 + 0x20) + 0x16)
  ;
  if (sVar1 == 0) {
    return;
  }
  iVar2 = func_0x021a377c(sVar1);
  if (iVar2 != 0) {
    func_02120714(iVar2);
    uVar3 = *(uint *)(uRam0211fe14 & 0xfffffffc) >> (uRam0211fe14 & 3) * 8 |
            *(uint *)(uRam0211fe14 & 0xfffffffc) << (uRam0211fe14 & 3) * -8 + 0x20;
    *(undefined2 *)(uVar3 + 0x18) = 0;
    *(undefined2 *)(uVar3 + 0x1a) = 1;
    return;
  }
  return;
}

