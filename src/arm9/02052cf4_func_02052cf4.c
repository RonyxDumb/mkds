/* Decompiled C draft; module arm9; ROM address 02052cf4. No matching claim. */
#include "types.h"
#include "deps/02052cf4_func_02052cf4.h"

void func_02052cf4(void)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  
  uVar1 = uRam02052d9c;
  bVar3 = true;
  *(undefined4 *)
   ((*(uint *)(uRam02052d9c & 0xfffffffc) >> (uRam02052d9c & 3) * 8 |
    *(uint *)(uRam02052d9c & 0xfffffffc) << (uRam02052d9c & 3) * -8 + 0x20) + 0xc) = 0x26;
  bVar2 = false;
  *(undefined4 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10) = 1;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
  if ((*(ushort *)(uVar1 + 0x454) & 0x40) != 0) {
    if (uVar1 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
              *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
    }
    if ((uVar1 != 1) && (*psRam02052da0 != 2)) {
      bVar3 = false;
    }
    if (bVar3) {
      bVar2 = true;
    }
  }
  if (bVar2) {
    func_0204bcec();
    uVar1 = *(uint *)(uRam02052d9c & 0xfffffffc) >> (uRam02052d9c & 3) * 8 |
            *(uint *)(uRam02052d9c & 0xfffffffc) << (uRam02052d9c & 3) * -8 + 0x20;
    *(ushort *)(uVar1 + 0x454) = *(ushort *)(uVar1 + 0x454) & 0xfeff;
  }
  *(undefined4 *)
   ((*(uint *)(uRam02052d9c & 0xfffffffc) >> (uRam02052d9c & 3) * 8 |
    *(uint *)(uRam02052d9c & 0xfffffffc) << (uRam02052d9c & 3) * -8 + 0x20) + 0x10) = 0;
  return;
}

