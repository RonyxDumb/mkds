/* Decompiled C draft; module arm9; ROM address 0205c594. No matching claim. */
#include "types.h"
#include "deps/0205c594_E7FnList4_Fn7.h"

void E7FnList4_Fn7(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = uRam0205c608;
  uVar1 = *(uint *)(uRam0205c608 & 0xfffffffc) >> (uRam0205c608 & 3) * 8 |
          *(uint *)(uRam0205c608 & 0xfffffffc) << (uRam0205c608 & 3) * -8 + 0x20;
  *(short *)(uVar1 + 0x736) = *(short *)(uVar1 + 0x736) + -1;
  uVar1 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
          *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
  if (*(short *)(uVar1 + 0x736) < 1) {
    *(undefined2 *)(uVar1 + 0x736) = 0xffff;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
            *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
    *(undefined2 *)(uVar2 + 0x10) = 4;
    *(undefined2 *)(uVar2 + 0x12) = 1;
    return;
  }
  func_0205c800(*(undefined2 *)(uVar1 + 0x734),uRam0205c60c);
  return;
}

