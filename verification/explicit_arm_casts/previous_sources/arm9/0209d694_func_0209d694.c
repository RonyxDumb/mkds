/* Decompiled C draft; module arm9; ROM address 0209d694. No matching claim. */
#include "types.h"
#include "deps/0209d694_func_0209d694.h"

void func_0209d694(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  
  func_02100138(uRam0209d7d8);
  iVar1 = func_0209bbfc();
  if (iVar1 != 0) {
    *(short *)(iVar1 + 0xa0) = (short)uRam0209d7dc;
    uVar2 = param_1[1];
    uVar3 = param_1[2];
    *(undefined4 *)(iVar1 + 0xa8) = *param_1;
    *(undefined4 *)(iVar1 + 0xac) = uVar2;
    *(undefined4 *)(iVar1 + 0xb0) = uVar3;
    *(undefined4 *)(iVar1 + 4) = *(undefined4 *)(iVar1 + 0xa8);
    *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(iVar1 + 0xac);
    *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(iVar1 + 0xb0);
    uVar2 = param_2[1];
    uVar3 = param_2[2];
    *(undefined4 *)(iVar1 + 0x40) = *param_2;
    *(undefined4 *)(iVar1 + 0x44) = uVar2;
    *(undefined4 *)(iVar1 + 0x48) = uVar3;
    uVar4 = *(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
            *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20;
    *(uint *)(iVar1 + 0x10) = (uVar4 << 0xd) >> 0xc | (uVar4 >> 0x13) << 0x14;
    uVar4 = (uint)(param_2 + 1) & 3;
    uVar5 = *(uint *)((uint)(param_2 + 1) & 0xfffffffc);
    uVar4 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
    *(uint *)(iVar1 + 0x14) = (uVar4 << 0xd) >> 0xc | (uVar4 >> 0x13) << 0x14;
    uVar4 = (uint)(param_2 + 2) & 3;
    uVar5 = *(uint *)((uint)(param_2 + 2) & 0xfffffffc);
    uVar4 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
    *(uint *)(iVar1 + 0x18) = (uVar4 << 0xd) >> 0xc | (uVar4 >> 0x13) << 0x14;
    *(undefined4 *)(iVar1 + 0xa4) = 0;
    *(undefined4 *)(iVar1 + 0xb8) = 0;
    uVar2 = func_0208b7bc(0x35,(undefined4 *)(iVar1 + 4));
    *(undefined4 *)(iVar1 + 0xbc) = uVar2;
    uVar2 = func_0208b7bc(0x34,iVar1 + 4);
    *(undefined4 *)(iVar1 + 0xc0) = uVar2;
    uVar4 = iVar1 + 0xbcU & 3;
    uVar5 = *(uint *)(iVar1 + 0xbcU & 0xfffffffc);
    *(undefined2 *)((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) + 0x70) = 0x15;
    uVar4 = iVar1 + 0xc0U & 3;
    uVar5 = *(uint *)(iVar1 + 0xc0U & 0xfffffffc);
    *(undefined2 *)((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) + 0x70) = 0x15;
    uVar4 = iVar1 + 0xbcU & 3;
    uVar5 = *(uint *)(iVar1 + 0xbcU & 0xfffffffc);
    *(undefined1 *)((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) + 0x80) = 3;
    uVar4 = iVar1 + 0xc0U & 3;
    uVar5 = *(uint *)(iVar1 + 0xc0U & 0xfffffffc);
    *(undefined1 *)((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) + 0x80) = 3;
    *(ushort *)(iVar1 + 2) = *(ushort *)(iVar1 + 2) & 0xfffe;
    *(ushort *)(iVar1 + 2) = *(ushort *)(iVar1 + 2) & 0xfff7;
    *(ushort *)(iVar1 + 2) = *(ushort *)(iVar1 + 2) & 0xfffd;
    *(ushort *)(iVar1 + 2) = *(ushort *)(iVar1 + 2) & 0xfff7;
    *(undefined2 *)(iVar1 + 0x66) = 0x1f;
    return;
  }
  return;
}

