/* Decompiled C draft; module arm9; ROM address 0205cbe4. No matching claim. */
#include "types.h"
#include "deps/0205cbe4_E7FnList4_Fn2.h"

void E7FnList4_Fn2(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = uRam0205cce8;
  uVar2 = 0;
  do {
    iVar4 = uVar2 * 0x38;
    iVar3 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
            *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x18;
    *(undefined4 *)(iVar3 + iVar4) = 0;
    iVar3 = iVar3 + iVar4;
    *(undefined4 *)(iVar3 + 4) = 0;
    *(undefined4 *)(iVar3 + 8) = 0;
    *(undefined4 *)(iVar3 + 0xc) = 0;
    *(undefined4 *)(iVar3 + 0x10) = 0;
    *(undefined4 *)(iVar3 + 0x14) = 0;
    *(undefined4 *)(iVar3 + 0x18) = 0;
    *(undefined4 *)(iVar3 + 0x1c) = 0;
    *(undefined4 *)(iVar3 + 0x20) = 0;
    uVar2 = uVar2 + 1 & 0xff;
    iVar3 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
            *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + iVar4;
    *(undefined4 *)(iVar3 + 0x3c) = 0;
    *(undefined4 *)(iVar3 + 0x40) = 0;
    *(undefined1 *)(iVar3 + 0x48) = 0;
    *(undefined1 *)
     ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
      *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + iVar4 + 0x49) = 0;
    *(undefined1 *)
     ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
      *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + iVar4 + 0x4a) = 0;
  } while (uVar2 < 4);
  *(undefined2 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0xf8) = 0;
  *(undefined1 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0xfb) = 0;
  *(undefined1 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0xfd) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0xf4) = 0;
  *(undefined2 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x736) = 0x7f;
  *(undefined4 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x758) = 1;
  uVar2 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
  *(ushort *)(uVar2 + 0x75c) = *(ushort *)(uVar2 + 0x75c) & 0xfffd;
  uVar2 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
  *(ushort *)(uVar2 + 0x75c) = *(ushort *)(uVar2 + 0x75c) | 0x80;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
  *(ushort *)(uVar1 + 0x75c) = *(ushort *)(uVar1 + 0x75c) & 0xffef;
  return;
}

