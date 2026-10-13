/* Decompiled C draft; module arm9; ROM address 02055b1c. No matching claim. */
#include "types.h"
#include "deps/02055b1c_func_02055b1c.h"

bool func_02055b1c(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  
  bVar4 = false;
  uVar1 = *(uint *)(uRam02055bcc & 0xfffffffc) >> (uRam02055bcc & 3) * 8 |
          *(uint *)(uRam02055bcc & 0xfffffffc) << (uRam02055bcc & 3) * -8 + 0x20;
  if (uVar1 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
            *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
  }
  if ((uVar3 != 0) &&
     (uVar3 = uVar1 + 4 & 3, uVar1 = *(uint *)(uVar1 + 4 & 0xfffffffc),
     (uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) != 0xd)) {
    bVar4 = true;
  }
  if (!bVar4) {
    return (*(ushort *)
             ((*(uint *)(uRam02055bd0 & 0xfffffffc) >> (uRam02055bd0 & 3) * 8 |
              *(uint *)(uRam02055bd0 & 0xfffffffc) << (uRam02055bd0 & 3) * -8 + 0x20) + 8) & 8) != 0
    ;
  }
  iVar2 = func_0204ffbc();
  if (iVar2 == 0) {
    return false;
  }
  uVar1 = (*(uint *)(uRam02055bcc & 0xfffffffc) >> (uRam02055bcc & 3) * 8 |
          *(uint *)(uRam02055bcc & 0xfffffffc) << (uRam02055bcc & 3) * -8 + 0x20) + 0x15c8;
  uVar3 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  return (*(byte *)((uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) + 6) & 4) != 0;
}

