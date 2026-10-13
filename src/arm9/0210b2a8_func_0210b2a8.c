/* Decompiled C draft; module arm9; ROM address 0210b2a8. No matching claim. */
#include "types.h"
#include "deps/0210b2a8_func_0210b2a8.h"

void func_0210b2a8(int param_1,int param_2,undefined4 param_3,undefined4 param_4,uint param_5)

{
  longlong lVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  
  if ((*(ushort *)(param_1 + 0x34) & 1) == 0) {
    return;
  }
  uVar8 = param_1 + 0x4cU & 3;
  uVar3 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if (((uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20) & 0x10000000) != 0) {
    return;
  }
  uVar8 = param_1 + 0x458U & 3;
  uVar3 = *(uint *)(param_1 + 0x458U & 0xfffffffc);
  iVar4 = (uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20) << 4;
  iVar5 = iVar4 >> 0x10;
  if (iVar5 < 0x1fd) {
    uVar8 = iVar4 >> 0x12;
  }
  else {
    uVar8 = 0x7f;
  }
  if (param_2 == 1) {
    if (param_5 == 0) {
      iVar5 = (iVar5 + -2000) * 0x10000 >> 0x12;
    }
    else {
      iVar5 = (iVar5 + 0x1c0) * 0x10000 >> 0x10;
    }
  }
  if (param_5 != 0) {
    iVar4 = 0;
    uVar3 = (uint)((uint)*(ushort *)(param_1 + 0x74) ==
                  (int)*(char *)((*(uint *)(uRam0210b4bc & 0xfffffffc) >> (uRam0210b4bc & 3) * 8 |
                                 *(uint *)(uRam0210b4bc & 0xfffffffc) <<
                                 (uRam0210b4bc & 3) * -8 + 0x20) + 0x62));
    if (uRam0210b4c0 < param_5) {
      iVar4 = 900;
      if (uVar3 != 0) {
        iVar4 = (int)(((*(uint *)(uRam0210b4c4 & 0xfffffffc) >> (uRam0210b4c4 & 3) * 8 |
                       *(uint *)(uRam0210b4c4 & 0xfffffffc) << (uRam0210b4c4 & 3) * -8 + 0x20) + 900
                      ) * 0x10000) >> 0x10;
      }
    }
    else if ((uRam0210b4c8 < param_5) && (param_5 <= uRam0210b4c0)) {
      lVar1 = (longlong)
              (int)(*(uint *)(uRam0210b4cc & 0xfffffffc) >> (uRam0210b4cc & 3) * 8 |
                   *(uint *)(uRam0210b4cc & 0xfffffffc) << (uRam0210b4cc & 3) * -8 + 0x20) *
              (longlong)(int)((param_5 + iRam0210b4d0) * 0x1000) + 0x800;
      bVar9 = uVar3 != 0;
      if (bVar9) {
        uVar3 = uRam0210b4c4;
      }
      if (bVar9) {
        uVar3 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
      }
      iVar4 = (int)(((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000) << 4) >> 0x10;
      if (bVar9) {
        iVar4 = (iVar4 + ((int)uVar3 >> 1)) * 0x10000 >> 0x10;
      }
    }
    func_02109078(param_1,0x74,uVar8 & 0xff,(iVar5 - iVar4) * 0x10000 >> 0x10);
    return;
  }
  uVar3 = func_0210bb74(param_2,param_3,param_4);
  if (uVar3 == uRam0210b4d4) {
    return;
  }
  if ((uVar3 != uRam0210b4d8) && (uVar3 != uRam0210b4dc)) {
    func_02109078(param_1,uVar3,uVar8 & 0xff,iVar5);
    return;
  }
  iVar5 = Maybe_helper_03c5ac(*(undefined2 *)(param_1 + 0x74));
  uVar8 = param_1 + 0x478U & 3;
  uVar7 = *(uint *)(param_1 + 0x478U & 0xfffffffc);
  iVar4 = iVar5 - (uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20);
  if (iVar4 < 0) {
    iVar4 = -iVar4;
  }
  iVar6 = func_02110590(uVar3 & 1);
  if (iVar6 < iVar4) {
    sVar2 = func_0211057c(uVar3 & 1);
    *(char *)(param_1 + 0x47c) = *(char *)(param_1 + 0x47c) + '\x01';
    DriverContext_MaybeQueuePlaySfx(param_1,(*(byte *)(param_1 + 0x47c) & 1) + sVar2,0x7f,0);
    *(int *)(param_1 + 0x478) = iVar5;
    return;
  }
  return;
}

