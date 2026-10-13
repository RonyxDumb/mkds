/* Decompiled C draft; module arm9; ROM address 02120404. No matching claim. */
#include "types.h"
#include "deps/02120404_func_02120404.h"

void func_02120404(void)

{
  char cVar1;
  undefined1 uVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  cVar3 = '\0';
  uVar4 = *(uint *)(uRam021204c8 & 0xfffffffc) >> (uRam021204c8 & 3) * 8 |
          *(uint *)(uRam021204c8 & 0xfffffffc) << (uRam021204c8 & 3) * -8 + 0x20;
  if (0x3b < *(byte *)(uVar4 + 0x1f57)) {
    *(undefined1 *)(uVar4 + 0x1f57) = 0;
  }
  uVar6 = *(uint *)(uRam021204c8 & 0xfffffffc) >> (uRam021204c8 & 3) * 8 |
          *(uint *)(uRam021204c8 & 0xfffffffc) << (uRam021204c8 & 3) * -8 + 0x20;
  uVar2 = func_0x0219daa8((uint)*(byte *)(uVar6 + 0x1f57) * 0xc + uVar6 + iRam021204cc,0);
  uVar4 = uRam021204c8;
  uVar5 = 0;
  *(undefined1 *)(uVar6 + *(byte *)(uVar6 + 0x1f57) + 0x1cc0) = uVar2;
  uVar6 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
          *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
  *(char *)(uVar6 + 0x1f57) = *(char *)(uVar6 + 0x1f57) + '\x01';
  uVar4 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
          *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
  do {
    cVar1 = *(char *)(uVar4 + uVar5 + 0x1cc0);
    if ((cVar1 != '\x02') && (cVar1 == '\x04')) {
      cVar3 = cVar3 + '\x01';
    }
    uVar5 = uVar5 + 1 & 0xff;
  } while (uVar5 < 0x3c);
  *(char *)(uVar4 + 0x194d) = cVar3;
  return;
}

