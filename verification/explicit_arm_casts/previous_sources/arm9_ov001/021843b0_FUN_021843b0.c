/* Decompiled C draft; module arm9_ov001; ROM address 021843b0. No matching claim. */
#include "types.h"
#include "deps/021843b0_FUN_021843b0.h"

void FUN_021843b0(ushort *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  uint local_3c;
  undefined4 local_38;
  uint local_34;
  int local_30;
  int local_2c;
  int local_28;
  uint local_24;
  undefined4 local_20;
  uint local_1c;
  
  iVar1 = func_0x0207a974(*(undefined2 *)(param_2 + 0x74));
  if (((*(uint *)(iVar1 + 0x48) & 0x20) == 0) || (*(short *)(param_2 + DAT_0218479c) < 1)) {
    iVar1 = FUN_021871f8(param_1,7);
    if (iVar1 != 0) {
      iVar1 = *(int *)(param_1 + 0x50);
      if ((0 < *(int *)(iVar1 + DAT_0218481c)) || (0 < *(int *)(iVar1 + DAT_02184820))) {
        iVar2 = (int)*(short *)(DAT_021847a8 +
                               ((int)(*(uint *)((int)param_1 + DAT_021847a0) & 0xffff) >> 4) * 4);
        uVar6 = func_0x02133048(-*(int *)(iVar1 + DAT_02184820),
                                -*(int *)(iVar1 + DAT_02184820) >> 0x1f,iVar2,iVar2 >> 0x1f);
        local_24 = (uint)uVar6 >> 0xc | (int)((ulonglong)uVar6 >> 0x20) << 0x14;
        local_20 = *(undefined4 *)(*(int *)(param_1 + 0x50) + DAT_0218481c);
        iVar1 = (int)*(short *)(DAT_021847a8 +
                               (((int)(*(uint *)((int)param_1 + DAT_021847a0) & 0xffff) >> 4) * 2 +
                               1) * 2);
        uVar6 = func_0x02133048(-*(int *)(*(int *)(param_1 + 0x50) + DAT_02184820),
                                -*(int *)(*(int *)(param_1 + 0x50) + DAT_02184820) >> 0x1f,iVar1,
                                iVar1 >> 0x1f);
        local_1c = (uint)uVar6 >> 0xc | (int)((ulonglong)uVar6 >> 0x20) << 0x14;
        FUN_02187218(param_1,7,0);
        FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0x50) + DAT_02184824),
                     *(undefined4 *)(*(int *)(param_1 + 0x50) + DAT_02184828));
        FUN_02188a8c(param_1,*(undefined4 *)(*(int *)(param_1 + 0x50) + DAT_0218482c),DAT_021847b8);
        FUN_02188950(param_1,&local_24);
        FUN_02188dcc(param_1,DAT_02184830);
        FUN_02188cec(param_1,0);
      }
      iVar1 = (int)*(short *)(DAT_021847a8 +
                             ((int)(*(uint *)((int)param_1 + DAT_021847a0) & 0xffff) >> 4) * 4);
      uVar6 = func_0x02133048(*(int *)(*(int *)(param_1 + 0x50) + DAT_02184834),
                              *(int *)(*(int *)(param_1 + 0x50) + DAT_02184834) >> 0x1f,iVar1,
                              iVar1 >> 0x1f);
      *(uint *)(param_1 + 8) = (uint)uVar6 >> 0xc | (int)((ulonglong)uVar6 >> 0x20) << 0x14;
      param_1[10] = 0;
      param_1[0xb] = 0;
      iVar1 = (int)*(short *)(DAT_021847a8 +
                             (((int)(*(uint *)((int)param_1 + DAT_021847a0) & 0xffff) >> 4) * 2 + 1)
                             * 2);
      uVar6 = func_0x02133048(*(int *)(*(int *)(param_1 + 0x50) + DAT_02184834),
                              *(int *)(*(int *)(param_1 + 0x50) + DAT_02184834) >> 0x1f,iVar1,
                              iVar1 >> 0x1f);
      *(uint *)(param_1 + 0xc) = (uint)uVar6 >> 0xc | (int)((ulonglong)uVar6 >> 0x20) << 0x14;
      *(int *)(param_1 + 2) = *(int *)(param_1 + 2) - *(int *)(param_1 + 8);
      *(int *)(param_1 + 4) = *(int *)(param_1 + 4) - *(int *)(param_1 + 10);
      *(int *)(param_1 + 6) = *(int *)(param_1 + 6) - *(int *)(param_1 + 0xc);
      *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | *DAT_021847cc;
      func_0x020d2774(param_1,DAT_02184838);
    }
  }
  else {
    iVar1 = FUN_021871f8(param_1,8);
    if (iVar1 != 0) {
      iVar1 = *(int *)(param_1 + 0x50);
      if ((0 < *(int *)(iVar1 + DAT_021847a0)) || (0 < *(int *)(iVar1 + DAT_021847a4))) {
        iVar2 = (int)*(short *)(DAT_021847a8 +
                               ((int)(*(uint *)((int)param_1 + DAT_021847a0) & 0xffff) >> 4) * 4);
        uVar6 = func_0x02133048(-*(int *)(iVar1 + DAT_021847a4),
                                -*(int *)(iVar1 + DAT_021847a4) >> 0x1f,iVar2,iVar2 >> 0x1f);
        local_3c = (uint)uVar6 >> 0xc | (int)((ulonglong)uVar6 >> 0x20) << 0x14;
        local_38 = *(undefined4 *)(*(int *)(param_1 + 0x50) + DAT_021847a0);
        iVar1 = (int)*(short *)(DAT_021847a8 +
                               (((int)(*(uint *)((int)param_1 + DAT_021847a0) & 0xffff) >> 4) * 2 +
                               1) * 2);
        uVar6 = func_0x02133048(-*(int *)(*(int *)(param_1 + 0x50) + DAT_021847a4),
                                -*(int *)(*(int *)(param_1 + 0x50) + DAT_021847a4) >> 0x1f,iVar1,
                                iVar1 >> 0x1f);
        local_34 = (uint)uVar6 >> 0xc | (int)((ulonglong)uVar6 >> 0x20) << 0x14;
        FUN_02187218(param_1,7,0);
        FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0x50) + DAT_021847ac),
                     *(undefined4 *)(*(int *)(param_1 + 0x50) + DAT_021847b0));
        FUN_02188a8c(param_1,*(undefined4 *)(*(int *)(param_1 + 0x50) + DAT_021847b4),DAT_021847b8);
        FUN_02188950(param_1,&local_3c);
        FUN_02188dcc(param_1,DAT_021847bc);
        FUN_02188cec(param_1,0);
      }
      func_0x021484d0(param_1 + 2,param_2 + DAT_021847c0,&local_30);
      lVar3 = func_0x02133048(local_28,local_28 >> 0x1f,local_28,local_28 >> 0x1f);
      lVar4 = func_0x02133048(local_30,local_30 >> 0x1f,local_30,local_30 >> 0x1f);
      lVar5 = func_0x02133048(local_2c,local_2c >> 0x1f,local_2c,local_2c >> 0x1f);
      lVar3 = lVar3 + lVar4 + lVar5;
      if ((int)(uint)((uint)lVar3 < 0x10) <= (int)((ulonglong)lVar3 >> 0x20)) {
        func_0x02039860(&local_30,&local_30);
      }
      func_0x02147fd8(*(undefined4 *)(param_2 + DAT_021847c4),&local_30,param_2 + DAT_021847c0,
                      &local_30);
      if (*param_1 == DAT_021847c8) {
        *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | *DAT_021847cc;
        func_0x02109060(*(undefined4 *)(param_1 + 0x4a),DAT_021847d0);
        func_0x020d2774(param_1,DAT_021847d4);
        func_0x0208b7bc(DAT_021847d8,&local_30);
        func_0x0208b7bc(DAT_021847dc,&local_30);
        func_0x0208b7bc(DAT_021847e0,&local_30);
        FUN_02187518(param_1,DAT_021847e8,0,DAT_021847ec,DAT_021847e4,0);
        FUN_02187518(param_1,DAT_021847f0,0,DAT_021847ec,DAT_021847e4,0);
      }
      else if (*param_1 == DAT_021847f4) {
        *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | *DAT_021847cc;
        func_0x02109060(*(undefined4 *)(param_1 + 0x4a),DAT_021847f8);
        func_0x020d2774(param_1,DAT_021847fc);
        func_0x0208b7bc(DAT_02184800,&local_30);
        func_0x0208b7bc(DAT_02184804,&local_30);
        func_0x0208b7bc(DAT_02184808,&local_30);
        FUN_02187518(param_1,DAT_02184810,0,DAT_02184814,DAT_0218480c,0);
        FUN_02187518(param_1,DAT_02184818,0,DAT_02184814,DAT_0218480c,0);
      }
      iVar1 = (int)*(short *)(DAT_021847a8 +
                             ((int)(*(uint *)((int)param_1 + DAT_021847a0) & 0xffff) >> 4) * 4);
      uVar6 = func_0x02133048(*(int *)(*(int *)(param_1 + 0x50) + DAT_021847c0),
                              *(int *)(*(int *)(param_1 + 0x50) + DAT_021847c0) >> 0x1f,iVar1,
                              iVar1 >> 0x1f);
      *(uint *)(param_1 + 8) = (uint)uVar6 >> 0xc | (int)((ulonglong)uVar6 >> 0x20) << 0x14;
      param_1[10] = 0;
      param_1[0xb] = 0;
      iVar1 = (int)*(short *)(DAT_021847a8 +
                             (((int)(*(uint *)((int)param_1 + DAT_021847a0) & 0xffff) >> 4) * 2 + 1)
                             * 2);
      uVar6 = func_0x02133048(*(int *)(*(int *)(param_1 + 0x50) + DAT_021847c0),
                              *(int *)(*(int *)(param_1 + 0x50) + DAT_021847c0) >> 0x1f,iVar1,
                              iVar1 >> 0x1f);
      *(uint *)(param_1 + 0xc) = (uint)uVar6 >> 0xc | (int)((ulonglong)uVar6 >> 0x20) << 0x14;
      *(int *)(param_1 + 2) = *(int *)(param_1 + 2) - *(int *)(param_1 + 8);
      *(int *)(param_1 + 4) = *(int *)(param_1 + 4) - *(int *)(param_1 + 10);
      *(int *)(param_1 + 6) = *(int *)(param_1 + 6) - *(int *)(param_1 + 0xc);
    }
  }
  FUN_02188200(param_1,DAT_02184864);
  *(undefined4 *)((int)param_1 + DAT_02184868) = 0xd;
  func_0x02073fb0(*(uint *)(param_1 + 0x3c) & DAT_0218486c,DAT_02184870);
  return;
}

