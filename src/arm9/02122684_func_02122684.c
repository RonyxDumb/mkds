/* Decompiled C draft; module arm9; ROM address 02122684. No matching claim. */
#include "types.h"
#include "deps/02122684_func_02122684.h"

void func_02122684(void)

{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  uVar2 = uRam02122724;
  iVar4 = 0;
  uVar5 = 0;
  do {
    uVar3 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
            *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
    if (uVar5 < *(byte *)(uVar3 + 0x1f53)) {
      if (((uint)*(byte *)(uVar3 + 0x1f55) & 1 << uVar5) == 0) {
        *(undefined1 *)(uVar3 + uVar5 + 0x1f4e) = 0xff;
      }
      else {
        uVar1 = *(undefined1 *)(uVar3 + uVar5 + 0x1f4e);
        *(char *)(uVar3 + uVar5 + 0x1f4e) = (char)iVar4;
        iVar4 = (iVar4 + 1) * 0x1000000 >> 0x18;
        func_0205d0e8(uVar1,*(undefined1 *)
                             ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                              *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + uVar5 +
                             0x1f4e));
      }
    }
    else {
      *(undefined1 *)(uVar3 + uVar5 + 0x1f4e) = 0xff;
    }
    uVar5 = uVar5 + 1 & 0xff;
  } while (uVar5 < 4);
  return;
}

