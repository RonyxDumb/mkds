/* Decompiled C draft; module arm9_ov001; ROM address 02184874. No matching claim. */
#include "types.h"
#include "deps/02184874_FUN_02184874.h"

void FUN_02184874(ushort *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  undefined8 uVar7;
  uint local_38;
  uint local_34;
  uint local_30;
  int local_2c;
  int local_28;
  int local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  
  iVar1 = func_0x0207a974(*(undefined2 *)(param_2 + 0x74));
  if (((*(uint *)(iVar1 + 0x48) & 0x20) == 0) || (*(short *)(param_2 + DAT_02184c30) < 1)) {
    iVar1 = FUN_021871f8((int)(uintptr_t)(param_1),7);
    if ((iVar1 != 0) &&
       ((0 < *(int *)(*(int *)(param_1 + 0x50) + DAT_02184cac) ||
        (0 < *(int *)(*(int *)(param_1 + 0x50) + DAT_02184cb0))))) {
      local_1c = 0;
      uVar2 = *(uint *)(param_2 + 0xa4);
      local_18 = *(int *)(param_2 + 0xac);
      local_20 = uVar2;
      lVar4 = func_0x02133048(local_18,(int)local_18 >> 0x1f,local_18,(int)local_18 >> 0x1f);
      lVar5 = func_0x02133048(uVar2,(int)uVar2 >> 0x1f,uVar2,(int)uVar2 >> 0x1f);
      lVar6 = func_0x02133048(0,0,0,0);
      lVar4 = lVar4 + lVar5 + lVar6;
      if ((int)(uint)((uint)lVar4 < 0x10) <= (int)((ulonglong)lVar4 >> 0x20)) {
        func_0x02039860((uint)(uintptr_t)(&local_20),&local_20);
      }
      iVar3 = *(int *)(*(int *)(param_1 + 0x50) + DAT_02184cb0);
      iVar1 = iVar3 >> 0x1f;
      uVar7 = func_0x02133048(local_20,(int)local_20 >> 0x1f,iVar3,iVar1);
      local_20 = (uint)uVar7 >> 0xc | (int)((ulonglong)uVar7 >> 0x20) << 0x14;
      uVar7 = func_0x02133048(local_1c,(int)local_1c >> 0x1f,iVar3,iVar1);
      local_1c = (uint)uVar7 >> 0xc | (int)((ulonglong)uVar7 >> 0x20) << 0x14;
      uVar7 = func_0x02133048(local_18,(int)local_18 >> 0x1f,iVar3,iVar1);
      local_18 = (uint)uVar7 >> 0xc | (int)((ulonglong)uVar7 >> 0x20) << 0x14;
      local_1c = *(undefined4 *)(*(int *)(param_1 + 0x50) + DAT_02184cac);
      FUN_02187218((int)(uintptr_t)(param_1),7,0);
      FUN_02188d64((int)(uintptr_t)(param_1),*(undefined4 *)(*(int *)(param_1 + 0x50) + DAT_02184cb4),
                   *(undefined4 *)(*(int *)(param_1 + 0x50) + DAT_02184cb8));
      FUN_02188a8c((int)(uintptr_t)(param_1),*(undefined4 *)(*(int *)(param_1 + 0x50) + DAT_02184cbc),DAT_02184c48);
      FUN_02188950((int)(uintptr_t)(param_1),&local_20);
      FUN_02188dcc((int)(uintptr_t)(param_1),0);
      FUN_02188cec((int)(uintptr_t)(param_1),0);
    }
  }
  else {
    iVar1 = FUN_021871f8((int)(uintptr_t)(param_1),8);
    if (iVar1 != 0) {
      if ((0 < *(int *)(*(int *)(param_1 + 0x50) + DAT_02184c34)) ||
         (0 < *(int *)(*(int *)(param_1 + 0x50) + DAT_02184c38))) {
        local_34 = 0;
        uVar2 = *(uint *)(param_2 + 0xa4);
        local_30 = *(int *)(param_2 + 0xac);
        local_38 = uVar2;
        lVar4 = func_0x02133048(local_30,(int)local_30 >> 0x1f,local_30,(int)local_30 >> 0x1f);
        lVar5 = func_0x02133048(uVar2,(int)uVar2 >> 0x1f,uVar2,(int)uVar2 >> 0x1f);
        lVar6 = func_0x02133048(0,0,0,0);
        lVar4 = lVar4 + lVar5 + lVar6;
        if ((int)(uint)((uint)lVar4 < 0x10) <= (int)((ulonglong)lVar4 >> 0x20)) {
          func_0x02039860((uint)(uintptr_t)(&local_38),&local_38);
        }
        iVar3 = *(int *)(*(int *)(param_1 + 0x50) + DAT_02184c38);
        iVar1 = iVar3 >> 0x1f;
        uVar7 = func_0x02133048(local_38,(int)local_38 >> 0x1f,iVar3,iVar1);
        local_38 = (uint)uVar7 >> 0xc | (int)((ulonglong)uVar7 >> 0x20) << 0x14;
        uVar7 = func_0x02133048(local_34,(int)local_34 >> 0x1f,iVar3,iVar1);
        local_34 = (uint)uVar7 >> 0xc | (int)((ulonglong)uVar7 >> 0x20) << 0x14;
        uVar7 = func_0x02133048(local_30,(int)local_30 >> 0x1f,iVar3,iVar1);
        local_30 = (uint)uVar7 >> 0xc | (int)((ulonglong)uVar7 >> 0x20) << 0x14;
        local_34 = *(undefined4 *)(*(int *)(param_1 + 0x50) + DAT_02184c34);
        FUN_02187218((int)(uintptr_t)(param_1),7,0);
        FUN_02188d64((int)(uintptr_t)(param_1),*(undefined4 *)(*(int *)(param_1 + 0x50) + DAT_02184c3c),
                     *(undefined4 *)(*(int *)(param_1 + 0x50) + DAT_02184c40));
        FUN_02188a8c((int)(uintptr_t)(param_1),*(undefined4 *)(*(int *)(param_1 + 0x50) + DAT_02184c44),DAT_02184c48);
        FUN_02188950((int)(uintptr_t)(param_1),&local_38);
        FUN_02188dcc((int)(uintptr_t)(param_1),DAT_02184c4c);
        FUN_02188cec((int)(uintptr_t)(param_1),0);
      }
      func_0x021484d0((uint)(uintptr_t)(param_1 + 2),param_2 + DAT_02184c50,&local_2c);
      lVar4 = func_0x02133048(local_24,local_24 >> 0x1f,local_24,local_24 >> 0x1f);
      lVar5 = func_0x02133048(local_2c,local_2c >> 0x1f,local_2c,local_2c >> 0x1f);
      lVar6 = func_0x02133048(local_28,local_28 >> 0x1f,local_28,local_28 >> 0x1f);
      lVar4 = lVar4 + lVar5 + lVar6;
      if ((int)(uint)((uint)lVar4 < 0x10) <= (int)((ulonglong)lVar4 >> 0x20)) {
        func_0x02039860((uint)(uintptr_t)(&local_2c),&local_2c);
      }
      func_0x02147fd8(*(undefined4 *)(param_2 + DAT_02184c54),(uint)(uintptr_t)(&local_2c),param_2 + DAT_02184c50,
                      &local_2c);
      if (*param_1 == DAT_02184c58) {
        *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | *DAT_02184c5c;
        func_0x02109060(*(undefined4 *)(param_1 + 0x4a),DAT_02184c60);
        func_0x020d2774(param_1,DAT_02184c64);
        func_0x0208b7bc(DAT_02184c68,&local_2c);
        func_0x0208b7bc(DAT_02184c6c,&local_2c);
        func_0x0208b7bc(DAT_02184c70,&local_2c);
        FUN_02187518(param_1,DAT_02184c78,0,DAT_02184c7c,DAT_02184c74,0);
        FUN_02187518(param_1,DAT_02184c80,0,DAT_02184c7c,DAT_02184c74,0);
      }
      else if (*param_1 == DAT_02184c84) {
        *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | *DAT_02184c5c;
        func_0x02109060(*(undefined4 *)(param_1 + 0x4a),DAT_02184c88);
        func_0x020d2774(param_1,DAT_02184c8c);
        func_0x0208b7bc(DAT_02184c90,&local_2c);
        func_0x0208b7bc(DAT_02184c94,&local_2c);
        func_0x0208b7bc(DAT_02184c98,&local_2c);
        FUN_02187518(param_1,DAT_02184ca0,0,DAT_02184ca4,DAT_02184c9c,0);
        FUN_02187518(param_1,DAT_02184ca8,0,DAT_02184ca4,DAT_02184c9c,0);
      }
    }
  }
  FUN_02188200(param_1,DAT_02184cc0);
  *(undefined4 *)((int)param_1 + DAT_02184cc4) = 0xd;
  return;
}

