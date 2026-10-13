/* Decompiled C draft; module arm9; ROM address 0204f814. No matching claim. */
#include "types.h"
#include "deps/0204f814_func_0204f814.h"

void func_0204f814(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  char cVar5;
  int iVar6;
  
  uVar1 = uRam0204f898;
  uVar3 = *(uint *)(uRam0204f898 & 0xfffffffc) >> (uRam0204f898 & 3) * 8 |
          *(uint *)(uRam0204f898 & 0xfffffffc) << (uRam0204f898 & 3) * -8 + 0x20;
  cVar5 = -1;
  iVar4 = 1;
  iVar6 = iRam0204f89c;
  do {
    iVar2 = (int)*(short *)(uVar3 + iVar4 * 2 + 0x8c);
    if ((iVar2 != -1) && (iVar2 < iVar6)) {
      cVar5 = (char)iVar4;
      iVar6 = iVar2;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0xe);
  if (cVar5 == -1) {
    *(undefined1 *)(uVar3 + 0x88) = 0xff;
    *(undefined4 *)
     ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
      *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 8) = 3;
    *(undefined4 *)
     ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
      *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10) = 0;
    return;
  }
  *(char *)(uVar3 + 0x88) = cVar5;
  return;
}

