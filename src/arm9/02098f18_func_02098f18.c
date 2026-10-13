/* Decompiled C draft; module arm9; ROM address 02098f18. No matching claim. */
#include "types.h"
#include "deps/02098f18_func_02098f18.h"

void func_02098f18(uint param_1,undefined4 param_2)

{
  longlong lVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar6;
  uint uVar7;
  uint uVar5;
  
  func_02100138(uRam02099000);
  iVar2 = func_0209bbfc();
  if (iVar2 != 0) {
    *(ushort *)(iVar2 + 2) = *(ushort *)(iVar2 + 2) & 0xfffe;
    *(ushort *)(iVar2 + 2) = *(ushort *)(iVar2 + 2) & 0xfff7;
    *(ushort *)(iVar2 + 2) = *(ushort *)(iVar2 + 2) & 0xfffd;
    *(ushort *)(iVar2 + 2) = *(ushort *)(iVar2 + 2) & 0xfff7;
    *(undefined2 *)(iVar2 + 0x66) = 0x1f;
    *(undefined2 *)(iVar2 + 0xa8) = *(undefined2 *)(param_1 + 8);
    *(uint *)(iVar2 + 0xa0) =
         *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
         *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
    func_020d90a8(iVar2 + 0xa0,0,1);
    *(undefined4 *)(iVar2 + 0xa4) = 0x7800;
    uVar6 = iVar2 + 0xa0U & 3;
    uVar4 = *(uint *)(iVar2 + 0xa0U & 0xfffffffc);
    uVar5 = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
    uVar6 = iVar2 + 0xacU & 3;
    uVar7 = *(uint *)(iVar2 + 0xacU & 0xfffffffc);
    uVar4 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar6 = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) * 0x54 +
            (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) + 0x34;
    uVar4 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
    lVar1 = (ulonglong)uVar6 * 0x7800;
    *(uint *)(iVar2 + 0xb0) =
         (uint)lVar1 >> 0xc |
         (((int)uVar6 >> 0x1f) * 0x7800 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
    *(undefined4 *)(iVar2 + 0xc4) = param_2;
    *(undefined4 *)(iVar2 + 200) = 0xffffb000;
    *(undefined4 *)(iVar2 + 0xcc) = 0;
    uVar3 = func_0208b7bc(0x33,iVar2 + 4);
    *(undefined4 *)(iVar2 + 0xd0) = uVar3;
    return;
  }
  return;
}

