/* Decompiled C draft; module arm9; ROM address 020e4ea8. No matching claim. */
#include "types.h"
#include "deps/020e4ea8_func_020e4ea8.h"

void func_020e4ea8(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined2 uVar2;
  ushort uVar3;
  int *piVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  
  if (*(short *)(param_2 + 0x8e) == 0) {
    uVar3 = *(ushort *)(param_2 + 100);
    uVar6 = func_020e6cf8(param_2 + 4);
    piVar4 = piRam020e4fac;
    uVar10 = *(uint *)(uRam020e4fa8 & 0xfffffffc) >> (uRam020e4fa8 & 3) * 8 |
             *(uint *)(uRam020e4fa8 & 0xfffffffc) << (uRam020e4fa8 & 3) * -8 + 0x20;
    uVar1 = uVar10 + 0x14 & 3;
    uVar8 = *(uint *)(uVar10 + 0x14 & 0xfffffffc);
    *(uint *)(uVar10 + 0x14) = uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20 | 0xc0;
    iVar7 = *(int *)(param_2 + 0x20);
    iVar9 = *(int *)(param_2 + 0x24);
    *piVar4 = *(int *)(param_2 + 0x1c);
    piVar4[1] = iVar7;
    piVar4[2] = iVar9;
    piVar5 = piRam020e4fac;
    if ((uVar3 & 1) != 0) {
      *piVar4 = -(*(uint *)((uint)piVar4 & 0xfffffffc) >> ((uint)piVar4 & 3) * 8 |
                 *(uint *)((uint)piVar4 & 0xfffffffc) << ((uint)piVar4 & 3) * -8 + 0x20);
    }
    func_020e67c4(uVar10,uVar6,piVar5,0,param_4);
    return;
  }
  uVar3 = *(ushort *)(param_2 + 100);
  uVar2 = *(undefined2 *)(param_2 + 0xac);
  uVar6 = func_020e6cf8(param_2 + 4);
  piVar4 = piRam020e4fac;
  uVar10 = *(uint *)(uRam020e4fa8 & 0xfffffffc) >> (uRam020e4fa8 & 3) * 8 |
           *(uint *)(uRam020e4fa8 & 0xfffffffc) << (uRam020e4fa8 & 3) * -8 + 0x20;
  uVar1 = uVar10 + 0x14 & 3;
  uVar8 = *(uint *)(uVar10 + 0x14 & 0xfffffffc);
  *(uint *)(uVar10 + 0x14) = uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20 | 0xc0;
  iVar7 = *(int *)(param_2 + 0x20);
  iVar9 = *(int *)(param_2 + 0x24);
  *piVar4 = *(int *)(param_2 + 0x1c);
  piVar4[1] = iVar7;
  piVar4[2] = iVar9;
  if ((uVar3 & 1) != 0) {
    *piVar4 = -(*(uint *)((uint)piVar4 & 0xfffffffc) >> ((uint)piVar4 & 3) * 8 |
               *(uint *)((uint)piVar4 & 0xfffffffc) << ((uint)piVar4 & 3) * -8 + 0x20);
  }
  func_020e66e4(uVar10,uVar6,uVar2,piRam020e4fac,0,param_4);
  return;
}

