/* Decompiled C draft; module arm9; ROM address 02051658. No matching claim. */
#include "types.h"
#include "deps/02051658_func_02051658.h"

void func_02051658(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = uRam0205172c;
  uVar3 = *(uint *)(uRam0205172c & 0xfffffffc) >> (uRam0205172c & 3) * 8 |
          *(uint *)(uRam0205172c & 0xfffffffc) << (uRam0205172c & 3) * -8 + 0x20;
  if (uVar3 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
            *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
  }
  if (uVar1 != 1) {
    return;
  }
  *(undefined4 *)(uVar3 + 0xc) = 0xf;
  *(undefined4 *)
   ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
    *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x10) = 1;
  uVar3 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
          *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
  uVar4 = uVar3 + 0x7c & 3;
  uVar1 = *(uint *)(uVar3 + 0x7c & 0xfffffffc);
  uVar4 = uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20;
  *(byte *)(uVar4 + 0x14) = *(byte *)(uVar4 + 0x14) & 0xf0 | *(byte *)(uVar3 + 0x84) & 0xf;
  uVar4 = uVar3 + 0x7c & 3;
  uVar3 = *(uint *)(uVar3 + 0x7c & 0xfffffffc);
  iVar2 = func_021455a0(uRam02051730,uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20,0x1c,0x25);
  if (iVar2 != 2) {
    *(undefined4 *)
     ((*(uint *)(uRam0205172c & 0xfffffffc) >> (uRam0205172c & 3) * 8 |
      *(uint *)(uRam0205172c & 0xfffffffc) << (uRam0205172c & 3) * -8 + 0x20) + 0x10) = 0;
  }
  return;
}

