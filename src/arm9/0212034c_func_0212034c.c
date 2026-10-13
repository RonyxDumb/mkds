/* Decompiled C draft; module arm9; ROM address 0212034c. No matching claim. */
#include "types.h"
#include "deps/0212034c_func_0212034c.h"

void func_0212034c(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (*(uint *)(uRam021203f8 & 0xfffffffc) >> (uRam021203f8 & 3) * 8 == 0 &&
      *(uint *)(uRam021203f8 & 0xfffffffc) << (uRam021203f8 & 3) * -8 + 0x20 == 0) {
    return;
  }
  uVar2 = *(uint *)(uRam021203fc & 0xfffffffc) >> (uRam021203fc & 3) * 8 |
          *(uint *)(uRam021203fc & 0xfffffffc) << (uRam021203fc & 3) * -8 + 0x20;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 == 0 && uVar2 << uVar1 * -8 + 0x20 == 0) {
    func_0x0219bf10();
    iVar3 = func_0x0219c3cc(0);
    if (iVar3 != 0) {
      uVar4 = func_0x0219c3cc((*(uint *)(uRam021203f8 & 0xfffffffc) >> (uRam021203f8 & 3) * 8 |
                              *(uint *)(uRam021203f8 & 0xfffffffc) << (uRam021203f8 & 3) * -8 + 0x20
                              ) + iRam02120400);
      *(undefined4 *)
       ((*(uint *)(uRam021203f8 & 0xfffffffc) >> (uRam021203f8 & 3) * 8 |
        *(uint *)(uRam021203f8 & 0xfffffffc) << (uRam021203f8 & 3) * -8 + 0x20) + 0x1f44) = uVar4;
      func_0x0219c3b0();
    }
    if (*(short *)((*(uint *)(uRam021203f8 & 0xfffffffc) >> (uRam021203f8 & 3) * 8 |
                   *(uint *)(uRam021203f8 & 0xfffffffc) << (uRam021203f8 & 3) * -8 + 0x20) + 0x16)
        != 0) {
      func_02120404();
    }
    StateDualHandler_Execute
              ((*(uint *)(uRam021203f8 & 0xfffffffc) >> (uRam021203f8 & 3) * 8 |
               *(uint *)(uRam021203f8 & 0xfffffffc) << (uRam021203f8 & 3) * -8 + 0x20) + 8);
    return;
  }
  return;
}

