/* Decompiled C draft; module arm9; ROM address 02102eb8. No matching claim. */
#include "types.h"
#include "deps/02102eb8_func_02102eb8.h"

void func_02102eb8(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  bool bVar8;
  uint uVar4;
  
  uVar7 = (uint)*(char *)((*(uint *)(uRam02103008 & 0xfffffffc) >> (uRam02103008 & 3) * 8 |
                          *(uint *)(uRam02103008 & 0xfffffffc) << (uRam02103008 & 3) * -8 + 0x20) +
                         0x62);
  iVar1 = GetGlobalHD5();
  func_020f82a4(0);
  uVar4 = uVar7;
  if ((int)uVar7 < 0) {
    uVar4 = *(ushort *)(param_1 + 0x78) & 0xffff00ff;
  }
  uVar2 = GetDriverEntry(uVar4);
  *(undefined4 *)(param_1 + 300) = uVar2;
  uVar4 = param_1 + 300U & 3;
  uVar3 = *(uint *)(param_1 + 300U & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  uVar2 = *(undefined4 *)(uVar4 + 0x9c);
  uVar6 = *(undefined4 *)(uVar4 + 0xa0);
  *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(uVar4 + 0x98);
  *(undefined4 *)(param_1 + 0x54) = uVar2;
  *(undefined4 *)(param_1 + 0x58) = uVar6;
  VecFx32_AddScale1(0x5800,iVar1,(undefined4 *)(param_1 + 0x50));
  iVar5 = func_0203c5e4();
  bVar8 = iVar5 != 0;
  if (bVar8) {
    iVar5 = 0x5800;
  }
  if (!bVar8) {
    iVar5 = 0xa800;
  }
  VecFx32_AddScale1(iVar5,iVar1 + 0x15c,param_1 + 0x50,param_1 + 0x50);
  VecFx32_Subtract(param_1 + 0x50,iVar1 + 0x24,param_1 + 0x13c);
  MTX_MultVec33(param_1 + 0x13c,iVar1 + 0x30,param_1 + 0x13c);
  if (param_2 == 0) {
    func_0210300c(param_1);
  }
  else {
    uVar4 = param_1 + 0x74U & 3;
    uVar3 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
    if (((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0x10000000) != 0) {
      func_0210300c(param_1);
      uVar4 = param_1 + 0x16cU & 3;
      uVar3 = *(uint *)(param_1 + 0x16cU & 0xfffffffc);
      *(uint *)(param_1 + 0x16c) = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) - 1;
    }
  }
  uVar4 = param_1 + 0x154U & 3;
  uVar3 = *(uint *)(param_1 + 0x154U & 0xfffffffc);
  *(uint *)(param_1 + 0x148) = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  uVar4 = param_1 + 0x158U & 3;
  uVar3 = *(uint *)(param_1 + 0x158U & 0xfffffffc);
  *(uint *)(param_1 + 0x14c) = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  uVar4 = param_1 + 0x174U & 3;
  uVar3 = *(uint *)(param_1 + 0x174U & 0xfffffffc);
  *(uint *)(param_1 + 0x180) = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  uVar4 = param_1 + 0x178U & 3;
  uVar3 = *(uint *)(param_1 + 0x178U & 0xfffffffc);
  *(uint *)(param_1 + 0x184) = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if ((*(ushort *)(param_1 + 0x78) & 0x8000) == 0) {
    uVar4 = *(ushort *)(param_1 + 0x78) & 0xffff00ff;
  }
  else {
    uVar4 = 8;
  }
  *(uint *)(param_1 + 0x198) = (uint)(uVar7 == uVar4);
  func_020f9c40(param_1);
  LightInfo_SomeFn(param_1 + 0x7c,1);
  return;
}

