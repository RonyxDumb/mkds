/* Decompiled C draft; module arm9; ROM address 02052ecc. No matching claim. */
#include "types.h"
#include "deps/02052ecc_func_02052ecc.h"

void func_02052ecc(void)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = uRam02052f94;
  bVar1 = true;
  *(undefined4 *)
   ((*(uint *)(uRam02052f94 & 0xfffffffc) >> (uRam02052f94 & 3) * 8 |
    *(uint *)(uRam02052f94 & 0xfffffffc) << (uRam02052f94 & 3) * -8 + 0x20) + 0xc) = 0x24;
  bVar2 = false;
  *(undefined4 *)
   ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
    *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x10) = 1;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
          *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
  if ((*(ushort *)(uVar4 + 0x454) & 0x40) != 0) {
    if (uVar4 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
              *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
    }
    if ((uVar3 != 1) && (*psRam02052f98 != 2)) {
      bVar1 = false;
    }
    if (bVar1) {
      bVar2 = true;
    }
  }
  if (bVar2) {
    if (uVar4 == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
              *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
    }
    func_0204bf48(uVar4 == 1,4,0x154,uRam02052fa0,uRam02052f9c,0);
  }
  *(undefined4 *)
   ((*(uint *)(uRam02052f94 & 0xfffffffc) >> (uRam02052f94 & 3) * 8 |
    *(uint *)(uRam02052f94 & 0xfffffffc) << (uRam02052f94 & 3) * -8 + 0x20) + 0x10) = 0;
  func_0204f5e4();
  return;
}

