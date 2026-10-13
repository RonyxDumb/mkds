/* Decompiled C draft; module arm9; ROM address 02052da4. No matching claim. */
#include "types.h"
#include "deps/02052da4_func_02052da4.h"

void func_02052da4(void)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  bool bVar4;
  
  uVar2 = uRam02052e5c;
  bVar4 = true;
  *(undefined4 *)
   ((*(uint *)(uRam02052e5c & 0xfffffffc) >> (uRam02052e5c & 3) * 8 |
    *(uint *)(uRam02052e5c & 0xfffffffc) << (uRam02052e5c & 3) * -8 + 0x20) + 0xc) = 0x25;
  bVar3 = false;
  *(undefined4 *)
   ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
    *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x10) = 1;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
          *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
  if ((*(ushort *)(uVar2 + 0x454) & 0x40) != 0) {
    if (uVar2 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
              *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
    }
    if ((uVar2 != 1) && (*psRam02052e60 != 2)) {
      bVar4 = false;
    }
    if (bVar4) {
      bVar3 = true;
    }
  }
  if (bVar3) {
    func_0204be0c();
    uVar1 = uRam02052e5c;
    *(undefined4 *)
     ((*(uint *)(uRam02052e5c & 0xfffffffc) >> (uRam02052e5c & 3) * 8 |
      *(uint *)(uRam02052e5c & 0xfffffffc) << (uRam02052e5c & 3) * -8 + 0x20) + 0x1e34) = 0;
    uVar2 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    *(ushort *)(uVar2 + 0x454) = *(ushort *)(uVar2 + 0x454) | 0x100;
  }
  *(undefined4 *)
   ((*(uint *)(uRam02052e5c & 0xfffffffc) >> (uRam02052e5c & 3) * 8 |
    *(uint *)(uRam02052e5c & 0xfffffffc) << (uRam02052e5c & 3) * -8 + 0x20) + 0x10) = 0;
  return;
}

