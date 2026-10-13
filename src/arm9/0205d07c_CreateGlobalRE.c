/* Decompiled C draft; module arm9; ROM address 0205d07c. No matching claim. */
#include "types.h"
#include "deps/0205d07c_CreateGlobalRE.h"

void CreateGlobalRE(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = uRam0205d0b8;
  iVar3 = 0;
  do {
    *(undefined1 *)
     ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
      *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + iVar3) = 0xff;
    iVar2 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
            *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + iVar3;
    iVar3 = iVar3 + 1;
    *(undefined1 *)(iVar2 + 6) = 0xff;
  } while (iVar3 < 4);
  *(undefined1 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 5) = 0;
  return;
}

