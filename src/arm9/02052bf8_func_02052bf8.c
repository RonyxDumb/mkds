/* Decompiled C draft; module arm9; ROM address 02052bf8. No matching claim. */
#include "types.h"
#include "deps/02052bf8_func_02052bf8.h"

void func_02052bf8(void)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = uRam02052c54;
  *(undefined4 *)
   (*(uint *)(uRam02052c54 & 0xfffffffc) >> (uRam02052c54 & 3) * 8 |
   *(uint *)(uRam02052c54 & 0xfffffffc) << (uRam02052c54 & 3) * -8 + 0x20) = 1;
  uVar2 = uRam02052c58;
  *(undefined4 *)
   ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
    *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0xc) = 5;
  *(undefined4 *)
   ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
    *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x10) = 1;
  uVar4 = (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
          *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x18;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  iVar3 = func_02143c80(uVar2,uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
  if (iVar3 != 2) {
    func_020533a0();
    return;
  }
  return;
}

