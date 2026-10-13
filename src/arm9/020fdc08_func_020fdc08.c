/* Decompiled C draft; module arm9; ROM address 020fdc08. No matching claim. */
#include "types.h"
#include "deps/020fdc08_func_020fdc08.h"

void func_020fdc08(int param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar3 = param_2 + 0xd4U & 3;
  uVar8 = *(uint *)(param_2 + 0xd4U & 0xfffffffc);
  *(uint *)(param_2 + 0xd4) =
       uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20 |
       *(uint *)(uRam020fdd6c & 0xfffffffc) >> (uRam020fdd6c & 3) * 8 |
       *(uint *)(uRam020fdd6c & 0xfffffffc) << (uRam020fdd6c & 3) * -8 + 0x20;
  StateDualHandler_Execute(param_1 + 0x184);
  if ((*(ushort *)(param_3 + 2) & 0x100) != 0) {
    *(undefined4 *)(param_1 + 0x198) = 0;
    uVar3 = param_1 + 0x44U & 3;
    uVar8 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    func_020f0f70((uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20) * 0x44 +
                  (*(uint *)(uRam020fdd70 & 0xfffffffc) >> (uRam020fdd70 & 3) * 8 |
                  *(uint *)(uRam020fdd70 & 0xfffffffc) << (uRam020fdd70 & 3) * -8 + 0x20),param_1);
    return;
  }
  uVar3 = param_2 + 0x74U & 3;
  uVar8 = *(uint *)(param_2 + 0x74U & 0xfffffffc);
  if (((uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20) & 0x8000) == 0) {
    uVar4 = *(undefined4 *)(param_2 + 0x54);
    uVar6 = *(undefined4 *)(param_2 + 0x58);
    *(undefined4 *)(param_3 + 4) = *(undefined4 *)(param_2 + 0x50);
    *(undefined4 *)(param_3 + 8) = uVar4;
    *(undefined4 *)(param_3 + 0xc) = uVar6;
    uVar3 = param_1 + 0x19cU & 3;
    uVar5 = *(uint *)(param_1 + 0x19cU & 0xfffffffc);
    uVar8 = param_2 + 0xdcU & 3;
    uVar2 = *(uint *)(param_2 + 0xdcU & 0xfffffffc);
    uVar1 = param_3 + 8U & 3;
    uVar7 = *(uint *)(param_3 + 8U & 0xfffffffc);
    *(uint *)(param_3 + 8) =
         (uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20) +
         ((uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) -
         (uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20));
  }
  uVar3 = param_1 + 0x170U & 3;
  uVar8 = *(uint *)(param_1 + 0x170U & 0xfffffffc);
  uVar3 = uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20;
  if ((int)uVar3 < 1) {
    uVar3 = param_2 + 0x74U & 3;
    uVar8 = *(uint *)(param_2 + 0x74U & 0xfffffffc);
    if (((uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20) & 0x8000) == 0) {
      return;
    }
    *(undefined4 *)(param_1 + 0x198) = 0;
    uVar3 = param_1 + 0x44U & 3;
    uVar8 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    func_020f0f70((uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20) * 0x44 +
                  (*(uint *)(uRam020fdd70 & 0xfffffffc) >> (uRam020fdd70 & 3) * 8 |
                  *(uint *)(uRam020fdd70 & 0xfffffffc) << (uRam020fdd70 & 3) * -8 + 0x20),param_1);
    return;
  }
  *(uint *)(param_1 + 0x170) = uVar3 - 1;
  uVar3 = param_1 + 0x170U & 3;
  uVar8 = *(uint *)(param_1 + 0x170U & 0xfffffffc);
  uVar3 = uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20;
  if ((int)uVar3 < (int)(uint)*(ushort *)(param_3 + 0x66)) {
    *(short *)(param_3 + 0x66) = (short)uVar3;
  }
  uVar3 = param_1 + 0x170U & 3;
  uVar8 = *(uint *)(param_1 + 0x170U & 0xfffffffc);
  if ((int)(uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20) < 0x10) {
    *(ushort *)(param_3 + 2) = *(ushort *)(param_3 + 2) | *puRam020fdd74;
  }
  uVar3 = param_1 + 0x170U & 3;
  uVar8 = *(uint *)(param_1 + 0x170U & 0xfffffffc);
  if (uVar8 >> uVar3 * 8 != 0 || uVar8 << uVar3 * -8 + 0x20 != 0) {
    return;
  }
  uVar3 = param_1 + 0x198U & 3;
  uVar8 = *(uint *)(param_1 + 0x198U & 0xfffffffc);
  uVar3 = uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20;
  *(ushort *)(uVar3 + 2) = *(ushort *)(uVar3 + 2) & 0xfffe;
  func_020d2398();
  *(undefined4 *)(param_1 + 0x198) = 0;
  uVar3 = param_1 + 0x44U & 3;
  uVar8 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  func_020f0f70((uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20) * 0x44 +
                (*(uint *)(uRam020fdd70 & 0xfffffffc) >> (uRam020fdd70 & 3) * 8 |
                *(uint *)(uRam020fdd70 & 0xfffffffc) << (uRam020fdd70 & 3) * -8 + 0x20),param_1);
  return;
}

