/* Decompiled C draft; module arm9; ROM address 02059ce8. No matching claim. */
#include "types.h"
#include "deps/02059ce8_func_02059ce8.h"

bool func_02059ce8(void)

{
  uint uVar1;
  uint uVar3;
  bool bVar4;
  uint uVar2;
  
  uVar3 = *(uint *)(uRam02059d7c & 0xfffffffc) >> (uRam02059d7c & 3) * 8 |
          *(uint *)(uRam02059d7c & 0xfffffffc) << (uRam02059d7c & 3) * -8 + 0x20;
  uVar2 = uVar3 + 4 & 3;
  uVar1 = *(uint *)(uVar3 + 4 & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  bVar4 = uVar2 == 2;
  if (bVar4) {
    return bVar4;
  }
  if (uVar2 == 1) {
    uVar2 = uVar3 + 100 & 3;
    uVar1 = *(uint *)(uVar3 + 100 & 0xfffffffc);
    if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 1) != 0 || bVar4) {
      return bVar4;
    }
    Fs_OverlayInfo_Start(uVar3 + 0x2c);
    Fs_File_Close((*(uint *)(uRam02059d7c & 0xfffffffc) >> (uRam02059d7c & 3) * 8 |
                  *(uint *)(uRam02059d7c & 0xfffffffc) << (uRam02059d7c & 3) * -8 + 0x20) + 0x58);
    *(undefined4 *)
     ((*(uint *)(uRam02059d7c & 0xfffffffc) >> (uRam02059d7c & 3) * 8 |
      *(uint *)(uRam02059d7c & 0xfffffffc) << (uRam02059d7c & 3) * -8 + 0x20) + 4) = 2;
    return true;
  }
  return bVar4;
}

