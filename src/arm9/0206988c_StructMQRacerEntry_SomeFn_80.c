/* Decompiled C draft; module arm9; ROM address 0206988c. No matching claim. */
#include "types.h"
#include "deps/0206988c_StructMQRacerEntry_SomeFn_80.h"

void StructMQRacerEntry_SomeFn_80(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int extraout_r1;
  int iVar5;
  bool bVar6;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  uint uVar4;
  
  uVar4 = param_1 + 0x7cU & 3;
  uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if ((uVar4 & 0x400000) != 0) {
    return;
  }
  iVar5 = param_1 + iRam02069a90;
  if ((uVar4 & 1) == 0) {
    if (*(short *)(iVar5 + 0x16) < 0x50) {
      *(short *)(iVar5 + 0x16) = *(short *)(iVar5 + 0x16) + 1;
      *(short *)(iVar5 + 0x14) = *(short *)(iVar5 + 0x14) + 1;
      if (*(short *)(iVar5 + 0x18) < *(short *)(iVar5 + 0x14)) {
        *(undefined2 *)(iVar5 + 0x14) = 0;
        *(short *)(iVar5 + 0x12) = *(short *)(iVar5 + 0x12) + *(short *)(iVar5 + 0x1a);
        *(short *)(iVar5 + 0x18) = *(short *)(iVar5 + 0x1a) * 5 + *(short *)(iVar5 + 0x18);
      }
      _s32_div_f((int)*(short *)(iVar5 + 0x16),(int)*(short *)(iVar5 + 0x12));
      if (extraout_r1 == 0) {
        uVar4 = param_1 + 0x7cU & 3;
        uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
        *(uint *)(param_1 + 0x7c) = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0xffff7fff;
      }
      else {
        uVar4 = param_1 + 0x7cU & 3;
        uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
        *(uint *)(param_1 + 0x7c) = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20 | 0x8000;
      }
      if (0x4f < *(short *)(iVar5 + 0x16)) {
        uVar4 = param_1 + 0x7cU & 3;
        uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
        *(uint *)(param_1 + 0x7c) = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20 | 0x8000;
      }
    }
    bVar6 = *(short *)(iVar5 + 0x10) == iRam02069a94;
    iVar2 = iRam02069a94;
    if (bVar6) {
      iVar2 = -1;
    }
    if (bVar6) {
      *(short *)(iVar5 + 0x1a) = (short)iVar2;
      *(undefined2 *)(iVar5 + 0x16) = 0;
    }
    func_0208c5b8(*(undefined2 *)(param_1 + 0x74));
    func_0208c504();
  }
  iVar2 = iRam02069a98;
  *(short *)(iVar5 + 0x10) = *(short *)(iVar5 + 0x10) + 1;
  if ((iVar2 < *(short *)(iVar5 + 0x10)) &&
     (uVar4 = param_1 + 0x7cU & 3, uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc),
     ((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0x2000) != 0)) {
    uVar4 = param_1 + 0x7cU & 3;
    uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    *(uint *)(param_1 + 0x7c) = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0xffffdfff;
    uVar4 = param_1 + 0x7cU & 3;
    uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    *(uint *)(param_1 + 0x7c) = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0xffff3fff;
    *(undefined4 *)(param_1 + 0x29c) = 0;
    uVar4 = param_1 + 0x7cU & 3;
    uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if (((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 1) == 0) {
      func_0208c5b8(*(undefined2 *)(param_1 + 0x74));
      func_0208c4e8();
    }
    else {
      DriverContext_MaybeQueuePlaySfx(param_1,0xf9,0x7f);
    }
    uVar4 = param_1 + 0x7cU & 3;
    uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    func_0210fa40(0,((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 1) != 0);
  }
  uVar4 = param_1 + 0x7cU & 3;
  uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 1) == 0) {
    GetDriverMaybeSfxPosition
              (&iStack_28,
               (short)*(char *)((*(uint *)(uRam02069a9c & 0xfffffffc) >> (uRam02069a9c & 3) * 8 |
                                *(uint *)(uRam02069a9c & 0xfffffffc) <<
                                (uRam02069a9c & 3) * -8 + 0x20) + 0x62));
    GetDriverMaybeSfxPosition(&iStack_1c,*(undefined2 *)(param_1 + 0x74));
    iVar5 = iStack_24 - iStack_18 >> 0xc;
    iVar2 = iStack_28 - iStack_1c >> 0xc;
    iVar1 = iStack_20 - iStack_14 >> 0xc;
    func_0207a2d4(iVar1 * iVar1 + iVar2 * iVar2 + iVar5 * iVar5);
    return;
  }
  return;
}

