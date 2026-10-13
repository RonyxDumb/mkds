/* Decompiled C draft; module arm9; ROM address 0208a218. No matching claim. */
#include "types.h"
#include "deps/0208a218_func_0208a218.h"

void func_0208a218(void)

{
  uint uVar1;
  uint uVar3;
  uint uVar4;
  ushort uVar5;
  uint uVar2;
  
  uVar4 = uRam0208a314;
  uVar3 = *(uint *)(uRam0208a314 & 0xfffffffc) >> (uRam0208a314 & 3) * 8 |
          *(uint *)(uRam0208a314 & 0xfffffffc) << (uRam0208a314 & 3) * -8 + 0x20;
  uVar2 = uVar3 + 0x73c & 3;
  uVar1 = *(uint *)(uVar3 + 0x73c & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if ((uVar2 == 1) || (uVar2 == 3)) {
    *(short *)(uVar3 + 0x740) = *(short *)(uVar3 + 0x740) + 1;
    uVar2 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar2 = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
    if (*(ushort *)(uVar2 + 0x742) < *(ushort *)(uVar2 + 0x740)) {
      *(undefined4 *)(uVar2 + 0x73c) = 9;
    }
  }
  uVar4 = *(uint *)(uRam0208a314 & 0xfffffffc) >> (uRam0208a314 & 3) * 8 |
          *(uint *)(uRam0208a314 & 0xfffffffc) << (uRam0208a314 & 3) * -8 + 0x20;
  uVar2 = uVar4 + 0x73c;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) != 9) {
    uVar4 = uVar4 + 0x20;
    uVar2 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar2 = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
    uVar5 = 0;
    if (*(short *)(uVar2 + 0x10) != 0) {
      do {
        uVar4 = uVar2 + 4 & 3;
        uVar1 = *(uint *)(uVar2 + 4 & 0xfffffffc);
        if (uVar1 >> uVar4 * 8 != 0 || uVar1 << uVar4 * -8 + 0x20 != 0) {
          Animation_Update();
        }
        uVar4 = uVar2 + 8 & 3;
        uVar1 = *(uint *)(uVar2 + 8 & 0xfffffffc);
        if (uVar1 >> uVar4 * 8 != 0 || uVar1 << uVar4 * -8 + 0x20 != 0) {
          Animation_Update();
        }
        uVar4 = uVar2 + 0xc & 3;
        uVar1 = *(uint *)(uVar2 + 0xc & 0xfffffffc);
        if (uVar1 >> uVar4 * 8 != 0 || uVar1 << uVar4 * -8 + 0x20 != 0) {
          Animation_Update();
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < *(ushort *)(uVar2 + 0x10));
    }
  }
  uVar1 = *(uint *)(uRam0208a314 & 0xfffffffc) >> (uRam0208a314 & 3) * 8 |
          *(uint *)(uRam0208a314 & 0xfffffffc) << (uRam0208a314 & 3) * -8 + 0x20;
  uVar2 = uVar1 + 0x78c & 3;
  uVar4 = *(uint *)(uVar1 + 0x78c & 0xfffffffc);
  if (uVar4 >> uVar2 * 8 != 0 || uVar4 << uVar2 * -8 + 0x20 != 0) {
    uVar2 = uVar1 + 0x798 & 3;
    uVar4 = *(uint *)(uVar1 + 0x798 & 0xfffffffc);
    (*(code *)(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20))(uVar1 + iRam0208a318);
    return;
  }
  return;
}

