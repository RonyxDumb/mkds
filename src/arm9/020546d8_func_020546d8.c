/* Decompiled C draft; module arm9; ROM address 020546d8. No matching claim. */
#include "types.h"
#include "deps/020546d8_func_020546d8.h"

undefined4 func_020546d8(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = uRam02054750;
  bVar1 = false;
  uVar5 = *(uint *)(uRam02054750 & 0xfffffffc) >> (uRam02054750 & 3) * 8 |
          *(uint *)(uRam02054750 & 0xfffffffc) << (uRam02054750 & 3) * -8 + 0x20;
  if (uVar5 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
            *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
  }
  if ((uVar2 != 0) &&
     (uVar2 = uVar5 + 4 & 3, uVar3 = *(uint *)(uVar5 + 4 & 0xfffffffc),
     (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) != 0xd)) {
    bVar1 = true;
  }
  if (bVar1) {
    *(undefined4 *)(uVar5 + 4) = 7;
    uVar5 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
            *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
    *(byte *)(uVar5 + 0x8b) = *(byte *)(uVar5 + 0x8b) & 0xfe;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
            *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
    if (*(char *)(uVar4 + 0x15ec) == '\0') {
      *(undefined1 *)(uVar4 + 0x15ec) = 1;
    }
    else {
      *(undefined1 *)(uVar4 + 0x15ec) = 0;
    }
  }
  return 1;
}

