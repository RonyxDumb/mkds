/* Decompiled C draft; module arm9; ROM address 0207e668. No matching claim. */
#include "types.h"
#include "deps/0207e668_func_0207e668.h"

void func_0207e668(uint param_1)

{
  uint uVar1;
  short sVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  
  bVar6 = false;
  *(short *)(param_1 + 0xac) = *(short *)(param_1 + 0xac) + -1;
  sVar2 = *(short *)(param_1 + 0xac);
  if (sVar2 < 1) {
    *(undefined2 *)(param_1 + 0xac) = 0;
  }
  uVar5 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  uVar4 = uVar5 + 0x44;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if ((((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) & 0xc0) == 0) ||
     (uVar5 = uVar5 + 0x2a4, uVar4 = uVar5 & 3, uVar5 = *(uint *)(uVar5 & 0xfffffffc),
     0x2fff < (int)(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20))) {
    bVar3 = false;
  }
  else {
    bVar3 = true;
  }
  if (bVar3) {
    *(undefined2 *)(param_1 + 0xac) = 10;
  }
  if (bVar3 || 0 < sVar2) {
    *(short *)(param_1 + 0x78) = *(short *)(param_1 + 0x78) + 1;
    bVar6 = *(ushort *)(param_1 + 0x7a) <= *(ushort *)(param_1 + 0x78);
    if (bVar6) {
      *(undefined2 *)(param_1 + 0x78) = 0;
    }
  }
  else if (*(short *)(param_1 + 0xac) < 1) {
    *(undefined2 *)(param_1 + 0x78) = 0;
    *(undefined4 *)(param_1 + 0xa8) = 0;
    *(undefined2 *)(param_1 + 0x7a) = 0x14;
  }
  if (!bVar6) {
    return;
  }
  uVar4 = param_1 + 0xa8 & 3;
  uVar5 = *(uint *)(param_1 + 0xa8 & 0xfffffffc);
  switch(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) {
  case 0:
    *(undefined4 *)(param_1 + 0xa8) = 1;
    *(undefined2 *)(param_1 + 0x7a) = 0x78;
    return;
  case 1:
    break;
  case 2:
    *(undefined4 *)(param_1 + 0xa8) = 3;
    uVar4 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
            *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 0x310;
    uVar5 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    func_0208c1f4(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20);
    *(undefined2 *)(param_1 + 0x7a) = 0xb4;
    return;
  case 3:
    *(undefined4 *)(param_1 + 0xa8) = 4;
    func_02063a68(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                  *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20);
  default:
    return;
  }
  uVar4 = (*(uint *)(DAT_0207e7ec & 0xfffffffc) >> (DAT_0207e7ec & 3) * 8 |
          *(uint *)(DAT_0207e7ec & 0xfffffffc) << (DAT_0207e7ec & 3) * -8 + 0x20) + 8;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if ((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) == 2) {
    *(undefined4 *)(param_1 + 0xa8) = 3;
    uVar4 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
            *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 0x310;
    uVar5 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    func_0208c1f4(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20);
    *(undefined2 *)(param_1 + 0x7a) = 0xb4;
    return;
  }
  *(undefined4 *)(param_1 + 0xa8) = 2;
  *(undefined2 *)(param_1 + 0x7a) = 0xb4;
  func_02080ac0(param_1 + 8);
  return;
}

