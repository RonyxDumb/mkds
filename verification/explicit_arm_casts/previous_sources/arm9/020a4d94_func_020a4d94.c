/* Decompiled C draft; module arm9; ROM address 020a4d94. No matching claim. */
#include "types.h"
#include "deps/020a4d94_func_020a4d94.h"

undefined4 func_020a4d94(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint local_20;
  int local_1c;
  uint local_18;
  
  iVar1 = func_020a2378();
  iVar1 = param_1 * 0x38 + iVar1;
  iVar2 = func_020a2204(param_1);
  if (iVar2 == 0) {
    uVar4 = 0;
  }
  else {
    iVar2 = func_020a1154(param_1);
    uVar4 = iVar1 + iVar2 * 4 + 0x10;
    uVar5 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  }
  iVar2 = func_020a1154(param_1);
  if (iVar2 == 0) {
    uVar5 = 0;
  }
  else {
    iVar2 = func_020a1154(param_1);
    uVar5 = iVar1 + (iVar2 + -1) * 4 + 0x10;
    uVar3 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar5 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
  }
  iVar2 = func_020a1154(param_1);
  if ((iVar2 != 0) && (uVar5 != 0)) {
    iVar2 = func_020a2204(param_1);
    if ((iVar2 == 0) || (uVar4 == 0)) {
      MaybeUpdateDriverBalloonShineCount(param_1,0xffffffff);
    }
    else {
      iVar2 = func_020a1154(param_1);
      *(uint *)(iVar1 + iVar2 * 4 + 0x10) = uVar5;
      MaybeUpdateDriverBalloonShineCount(param_1,0xffffffff);
      iVar2 = func_020a1154(param_1);
      *(uint *)(iVar1 + iVar2 * 4 + 0x10) = uVar4;
    }
  }
  if (uVar5 == 0) {
    return 0;
  }
  iVar1 = GetDriverEntry(param_1);
  func_020a2378();
  if (param_1 ==
      *(char *)((*(uint *)(uRam020a4f48 & 0xfffffffc) >> (uRam020a4f48 & 3) * 8 |
                *(uint *)(uRam020a4f48 & 0xfffffffc) << (uRam020a4f48 & 3) * -8 + 0x20) + 0x62)) {
    func_020a2ebc(uVar5,0);
  }
  else {
    uVar4 = iVar1 + 0x80U & 3;
    uVar3 = *(uint *)(iVar1 + 0x80U & 0xfffffffc);
    local_20 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    iVar2 = func_020a23a0(iVar1);
    uVar4 = iVar1 + 0x84U & 3;
    uVar3 = *(uint *)(iVar1 + 0x84U & 0xfffffffc);
    local_1c = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + iVar2 + iRam020a4f4c;
    uVar4 = iVar1 + 0x88U & 3;
    uVar3 = *(uint *)(iVar1 + 0x88U & 0xfffffffc);
    local_18 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    *(ushort *)(uVar5 + 2) = *(ushort *)(uVar5 + 2) & 0xfffb;
    *(ushort *)(uVar5 + 2) = *(ushort *)(uVar5 + 2) & 0xfffd;
    *(ushort *)(uVar5 + 2) = *(ushort *)(uVar5 + 2) & 0xfff7;
    *(undefined2 *)(uVar5 + 0x66) = 0x1f;
    func_020a2ebc(uVar5,&local_20);
  }
  func_020d26ec(iVar1,uRam020a4f50);
  iVar1 = func_020a1154(param_1);
  if (iVar1 == 0) {
    func_020a16d0(param_1);
  }
  return 1;
}

