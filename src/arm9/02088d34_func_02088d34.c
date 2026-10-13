/* Decompiled C draft; module arm9; ROM address 02088d34. No matching claim. */
#include "types.h"
#include "deps/02088d34_func_02088d34.h"

void func_02088d34(uint param_1)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  uVar2 = uRam02088e3c;
  *(undefined4 *)(param_1 + 0xc4) = 0;
  uVar3 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar3 = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 0x18;
  uVar2 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if (uVar3 >> uVar2 * 8 != 0 || uVar3 << uVar2 * -8 + 0x20 != 0) {
    return;
  }
  iVar4 = func_01ffc67c(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                        *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20);
  if (iVar4 != 0) {
    func_020a228c(*(undefined2 *)(param_1 + 4));
    return;
  }
  iVar4 = func_020a1154(*(undefined2 *)(param_1 + 4));
  iVar5 = func_020a10d4(*(undefined2 *)(param_1 + 4));
  if (*(short *)(param_1 + 0xc0) <= iVar4) {
    return;
  }
  bVar1 = false;
  iVar4 = (int)*(short *)((*(uint *)(uRam02088e40 & 0xfffffffc) >> (uRam02088e40 & 3) * 8 |
                          *(uint *)(uRam02088e40 & 0xfffffffc) << (uRam02088e40 & 3) * -8 + 0x20) +
                         0x1a);
  if ((iVar4 < iVar5) ||
     ((iVar5 == iVar4 && (iVar4 = func_020a2204(*(undefined2 *)(param_1 + 4)), iVar4 != 0)))) {
    bVar1 = true;
  }
  uVar3 = uRam02088e40;
  if (bVar1) {
    *(short *)(param_1 + 0xc2) = *(short *)(param_1 + 0xc2) + 1;
    uVar2 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    if (*(short *)((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) + 0x18) <
        *(short *)(param_1 + 0xc2)) {
      func_020a22ac(*(undefined2 *)(param_1 + 4));
      *(undefined2 *)(param_1 + 0xc2) = 0;
    }
    *(undefined4 *)(param_1 + 0xc4) = 1;
    return;
  }
  return;
}

