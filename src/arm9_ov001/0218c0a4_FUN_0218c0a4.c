/* Decompiled C draft; module arm9_ov001; ROM address 0218c0a4. No matching claim. */
#include "types.h"
#include "deps/0218c0a4_FUN_0218c0a4.h"

void FUN_0218c0a4(int param_1)

{
  int iVar1;
  longlong *plVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint extraout_r1;
  uint extraout_r1_00;
  int iVar6;
  uint uVar7;
  uint uVar8;
  longlong lVar9;
  undefined8 uVar10;
  uint local_50;
  int local_30;
  int local_2c;
  int local_28;
  uint local_24;
  undefined4 local_20;
  uint local_1c;
  
  iVar6 = *(int *)(param_1 + 0xa0);
  iVar1 = func_0x02133068(*(undefined4 *)(param_1 + DAT_0218c318),2);
  uVar8 = *(int *)(param_1 + DAT_0218c31c) - iVar1 * *(int *)(iVar6 + DAT_0218c320);
  uVar7 = *(uint *)(iVar6 + DAT_0218c324);
  if (uVar7 == DAT_0218c328) {
    plVar2 = (longlong *)func_0x020d22d0();
    lVar9 = func_0x02133048((int)plVar2[1],*(undefined4 *)((int)plVar2 + 0xc),(int)*plVar2,
                            *(undefined4 *)((int)plVar2 + 4));
    *plVar2 = lVar9 + plVar2[2];
    uVar7 = *(uint *)((int)plVar2 + 4) >> 0x10;
  }
  else {
    plVar2 = (longlong *)func_0x020d22d0();
    if ((uVar7 & 0xffff) == 0) {
      uVar7 = 0;
    }
    else {
      lVar9 = func_0x02133048((int)plVar2[1],*(undefined4 *)((int)plVar2 + 0xc),(int)*plVar2,
                              *(undefined4 *)((int)plVar2 + 4));
      *plVar2 = lVar9 + plVar2[2];
      if ((uVar7 & 0xffff) == 0) {
        uVar7 = *(uint *)((int)plVar2 + 4);
      }
      else {
        func_0x02133048(*(undefined4 *)((int)plVar2 + 4),0,uVar7 & 0xffff,0);
        uVar7 = extraout_r1;
      }
    }
    uVar7 = uVar7 & 0xffff;
  }
  if (uVar7 == 0) {
    uVar7 = *(uint *)(param_1 + DAT_0218c318);
    if (uVar7 == DAT_0218c328) {
      plVar2 = (longlong *)func_0x020d22d0();
      lVar9 = func_0x02133048((int)plVar2[1],*(undefined4 *)((int)plVar2 + 0xc),(int)*plVar2,
                              *(undefined4 *)((int)plVar2 + 4));
      *plVar2 = lVar9 + plVar2[2];
      local_50 = *(uint *)((int)plVar2 + 4) >> 0x10;
    }
    else {
      plVar2 = (longlong *)func_0x020d22d0();
      if ((uVar7 & 0xffff) == 0) {
        local_50 = 0;
      }
      else {
        lVar9 = func_0x02133048((int)plVar2[1],*(undefined4 *)((int)plVar2 + 0xc),(int)*plVar2,
                                *(undefined4 *)((int)plVar2 + 4));
        *plVar2 = lVar9 + plVar2[2];
        if ((uVar7 & 0xffff) == 0) {
          local_50 = *(uint *)((int)plVar2 + 4);
        }
        else {
          func_0x02133048(*(undefined4 *)((int)plVar2 + 4),0,uVar7 & 0xffff,0);
          local_50 = extraout_r1_00;
        }
      }
      local_50 = local_50 & 0xffff;
    }
  }
  else {
    local_50 = 0xffffffff;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0xa0) + DAT_0218c32c);
  uVar7 = 0;
  if (0 < *(int *)(param_1 + DAT_0218c318)) {
    do {
      local_24 = 0;
      local_20 = 0;
      local_1c = 0;
      iVar6 = (int)(uVar8 & 0xffff) >> 4;
      iVar3 = (int)*(short *)(DAT_0218c330 + iVar6 * 4);
      uVar10 = func_0x02133048(iVar1,iVar1 >> 0x1f,iVar3,iVar3 >> 0x1f);
      local_30 = *(int *)(param_1 + 4) +
                 ((uint)uVar10 >> 0xc | (int)((ulonglong)uVar10 >> 0x20) << 0x14);
      local_2c = *(int *)(param_1 + 8) + *(int *)(*(int *)(param_1 + 0xa0) + DAT_0218c334);
      iVar6 = (int)*(short *)(DAT_0218c330 + (iVar6 * 2 + 1) * 2);
      uVar10 = func_0x02133048(iVar1,iVar1 >> 0x1f,iVar6,iVar6 >> 0x1f);
      local_28 = *(int *)(param_1 + 0xc) +
                 ((uint)uVar10 >> 0xc | (int)((ulonglong)uVar10 >> 0x20) << 0x14);
      iVar4 = *(int *)(*(int *)(param_1 + 0xa0) + DAT_0218c338);
      uVar10 = func_0x02133048(iVar4,iVar4 >> 0x1f,iVar3,iVar3 >> 0x1f);
      local_24 = (uint)uVar10 >> 0xc | (int)((ulonglong)uVar10 >> 0x20) << 0x14;
      local_20 = *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218c33c);
      iVar3 = *(int *)(*(int *)(param_1 + 0xa0) + DAT_0218c338);
      uVar10 = func_0x02133048(iVar3,iVar3 >> 0x1f,iVar6,iVar6 >> 0x1f);
      local_1c = (uint)uVar10 >> 0xc | (int)((ulonglong)uVar10 >> 0x20) << 0x14;
      if (uVar7 == local_50) {
        uVar5 = func_0x020f4ee8();
        FUN_02187b2c(uVar5,(int)(uintptr_t)(&local_30),(int)(uintptr_t)(&local_24),
                     *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218c340));
      }
      else {
        uVar5 = FUN_02187dd4();
        FUN_02187b94(uVar5,(int)(uintptr_t)(&local_30),(int)(uintptr_t)(&local_24),
                     *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218c344));
      }
      uVar8 = uVar8 + *(int *)(*(int *)(param_1 + 0xa0) + DAT_0218c320);
      func_0x0208b7bc(DAT_0218c348,(uint)(uintptr_t)(&local_30));
      func_0x0208b7bc(DAT_0218c34c,(uint)(uintptr_t)(&local_30));
      uVar7 = uVar7 + 1;
    } while ((int)uVar7 < *(int *)(param_1 + DAT_0218c318));
  }
  func_0x020d2774(param_1,DAT_0218c350);
  return;
}

