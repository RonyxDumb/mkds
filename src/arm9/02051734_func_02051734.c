/* Decompiled C draft; module arm9; ROM address 02051734. No matching claim. */
#include "types.h"
#include "deps/02051734_func_02051734.h"

void func_02051734(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = uRam020517cc;
  *(undefined4 *)
   ((*(uint *)(uRam020517cc & 0xfffffffc) >> (uRam020517cc & 3) * 8 |
    *(uint *)(uRam020517cc & 0xfffffffc) << (uRam020517cc & 3) * -8 + 0x20) + 0xc) = 0xe;
  *(undefined4 *)
   ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
    *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x10) = 1;
  uVar2 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
          *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x15bc;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  iVar3 = func_021450ec(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,0xc,0xff,8,1);
  uVar2 = uRam020517cc;
  *(undefined4 *)
   ((*(uint *)(uRam020517cc & 0xfffffffc) >> (uRam020517cc & 3) * 8 |
    *(uint *)(uRam020517cc & 0xfffffffc) << (uRam020517cc & 3) * -8 + 0x20) + 0x10) = 0;
  if (iVar3 != 0) {
    *(undefined4 *)
     ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
      *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 8) = 2;
    *(undefined4 *)
     ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
      *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x10) = 0;
    return;
  }
  func_02054208((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + iRam020517d0);
  return;
}

