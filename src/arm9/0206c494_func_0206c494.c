/* Decompiled C draft; module arm9; ROM address 0206c494. No matching claim. */
#include "types.h"
#include "deps/0206c494_func_0206c494.h"

undefined4 func_0206c494(int param_1)

{
  uint uVar1;
  ushort uVar2;
  bool bVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  short unaff_r4;
  undefined4 uVar9;
  bool bVar10;
  
  uVar1 = param_1 + 0x2a4U & 3;
  uVar6 = *(uint *)(param_1 + 0x2a4U & 0xfffffffc);
  uVar9 = 0;
  bVar3 = true;
  if (((int)(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) < 0x1800) &&
     (uVar1 = param_1 + 0x48U & 3, uVar6 = *(uint *)(param_1 + 0x48U & 0xfffffffc),
     ((uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) & 0x80) != 0)) {
    *(undefined4 *)(param_1 + 0x2c4) = 0;
    uVar1 = param_1 + 0x78U & 3;
    uVar6 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
    uVar9 = 1;
    uVar2 = *(ushort *)(iRam0206c5e0 + (uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) * 0x5c);
    bVar3 = false;
    bVar10 = (uVar2 & 0x20) != 0;
    if (bVar10) {
      *(undefined4 *)(param_1 + 0x2c4) = 0xffffffff;
      unaff_r4 = 500;
    }
    else if ((uVar2 & 0x10) != 0) {
      bVar10 = true;
      *(undefined4 *)(param_1 + 0x2c4) = 1;
      unaff_r4 = -500;
    }
    uVar1 = param_1 + 0x44U & 3;
    uVar6 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    if (((uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) & 0x10) != 0) {
      iVar4 = func_0208c5b8(*(undefined2 *)(param_1 + 0x74));
      uVar1 = iVar4 + 0x3cU & 3;
      uVar6 = *(uint *)(iVar4 + 0x3cU & 0xfffffffc);
      if ((uVar6 >> uVar1 * 8 == 0 && uVar6 << uVar1 * -8 + 0x20 == 0) &&
         (uVar1 = param_1 + 0x4cU & 3, uVar6 = *(uint *)(param_1 + 0x4cU & 0xfffffffc),
         ((uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) & 0x8000) != 0)) {
        uVar5 = func_0208c5b8(*(undefined2 *)(param_1 + 0x74));
        func_0208ccf0();
        func_0208d6b0(uVar5);
      }
      uVar1 = param_1 + 0x48U & 3;
      uVar6 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
      *(uint *)(param_1 + 0x48) = uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20 | 0x100;
      uVar1 = param_1 + 0x2c4U & 3;
      uVar6 = *(uint *)(param_1 + 0x2c4U & 0xfffffffc);
      if (uVar6 >> uVar1 * 8 != 0 || uVar6 << uVar1 * -8 + 0x20 != 0) {
        uVar1 = param_1 + 0x44U & 3;
        uVar6 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
        *(uint *)(param_1 + 0x44) = uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20 | 0x8000000;
        *(short *)(param_1 + 0x236) = *(short *)(param_1 + 0x236) + unaff_r4;
        func_0206cc60(param_1,1);
      }
    }
    uVar1 = param_1 + 0x3e0U & 3;
    uVar7 = *(uint *)(param_1 + 0x3e0U & 0xfffffffc);
    uVar6 = param_1 + 0x3e4U & 3;
    uVar8 = *(uint *)(param_1 + 0x3e4U & 0xfffffffc);
    func_0210b4e0(param_1,bVar10,uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20,
                  uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20);
  }
  if (bVar3) {
    func_0208c5b8(*(undefined2 *)(param_1 + 0x74));
    func_0208d650();
  }
  return uVar9;
}

