/* Decompiled C draft; module arm9; ROM address 02001000. No matching claim. */
#include "types.h"
#include "deps/02001000_func_02001000.h"

void func_02001000(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = *(uint *)(uRam02001048 & 0xfffffffc) >> (uRam02001048 & 3) * 8 |
          *(uint *)(uRam02001048 & 0xfffffffc) << (uRam02001048 & 3) * -8 + 0x20;
  cVar1 = *(char *)(uVar2 + 0x8a);
  if (cVar1 == '\0') {
    return;
  }
  iVar3 = func_02050320(7,*(undefined1 *)(uVar2 + 0x87),cVar1);
  if (iVar3 != 0) {
    func_020515b0(cVar1);
    return;
  }
  return;
}

