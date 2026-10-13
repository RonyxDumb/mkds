/* Decompiled C draft; module arm9; ROM address 0202fd2c. No matching claim. */
#include "types.h"
#include "deps/0202fd2c_func_0202fd2c.h"

void func_0202fd2c(void)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint local_78;
  int local_60;
  uint local_5c;
  int local_4c;
  undefined1 auStack_30 [20];
  undefined2 local_1c;
  
  iVar3 = *DAT_02030028;
  local_78 = 0;
  switch(*(undefined4 *)(iVar3 + 0x50)) {
  case 0:
    iVar3 = func_0205579c(0,0);
    if (iVar3 == 1) {
      *(undefined4 *)(*DAT_02030028 + 0x50) = 1;
      return;
    }
    break;
  case 1:
    if (*(int *)(iVar3 + 0x88) != 0) {
      if (3 < *(int *)(iVar3 + 0x48)) {
        *(undefined4 *)(iVar3 + 0x54) = 1;
        *(undefined4 *)(*DAT_02030028 + 0x50) = 5;
        return;
      }
      iVar3 = 0;
      do {
        iVar4 = func_0202f14c();
        iVar4 = func_0204ff14(local_78 & 0xffff,iVar4 + 4 + iVar3);
        if (iVar4 == 0) {
          iVar4 = func_0202f14c();
          Mem_CpuFill16(0,iVar4 + 4 + iVar3,0x16);
        }
        else {
          iVar4 = func_0202f14c();
          *(undefined2 *)(iVar4 + iVar3 + 0x18) = 0;
        }
        iVar3 = iVar3 + 0x16;
        local_78 = local_78 + 1;
      } while ((int)local_78 < 4);
      iVar3 = func_0204ff14(*(uint *)(*DAT_02030028 + 0x48) & 0xffff,0);
      if (iVar3 != 0) {
        puVar5 = (undefined4 *)func_0202f14c();
        piVar2 = DAT_02030028;
        *puVar5 = *(undefined4 *)(*DAT_02030028 + 0x48);
        *(undefined4 *)(*piVar2 + 0x54) = 3;
        *(undefined4 *)(*piVar2 + 0x50) = 0xb;
        return;
      }
      *(undefined4 *)(*DAT_02030028 + *(int *)(*DAT_02030028 + 0x48) * 0xc + 0x58) = 0;
      return;
    }
    if (*(int *)(iVar3 + 0x4c) == 1) {
      iVar11 = 0;
      local_5c = 0;
      local_60 = DAT_0203002c;
      local_4c = 0;
      iVar4 = iVar3;
      do {
        iVar4 = iVar4 + iVar11;
        iVar6 = *(int *)(iVar4 + 0x58);
        iVar7 = *(int *)(iVar4 + 0x60);
        iVar8 = *(int *)(iVar4 + 0x5c);
        Mem_CpuFill16(0,auStack_30,0x16);
        uVar9 = func_0204ff14(local_5c & 0xffff,auStack_30);
        *(undefined4 *)(*DAT_02030028 + iVar11 + 0x58) = uVar9;
        if (*(int *)(*DAT_02030028 + iVar11 + 0x58) == 0) {
          uVar9 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*DAT_02030028 + 0xa0),8);
          func_0212426c(1,*(undefined2 *)(local_60 + 0x30),*(undefined4 *)(iVar3 + 0x38),uVar9,
                        *(undefined4 *)(iVar3 + 0x30),*(undefined4 *)(iVar3 + 0x3c));
          *(undefined4 *)(*DAT_02030028 + iVar11 + 0x60) = 0;
          *(undefined4 *)(*DAT_02030028 + iVar11 + 0x5c) = 0;
        }
        else {
          local_1c = 0;
          func_0212426c(1,*(undefined2 *)(local_60 + 0x30),*(undefined4 *)(iVar3 + 0x38),auStack_30,
                        *(undefined4 *)(iVar3 + 0x30),*(undefined4 *)(iVar3 + 0x3c));
          uVar9 = func_0204fe1c(local_5c & 0xffff);
          *(undefined4 *)(*DAT_02030028 + iVar11 + 0x60) = uVar9;
          uVar9 = func_0204fe90(local_5c & 0xffff);
          *(undefined4 *)(*DAT_02030028 + iVar11 + 0x5c) = uVar9;
        }
        if ((iVar6 == 0) && (*(int *)(*DAT_02030028 + iVar11 + 0x58) != 0)) {
          bVar1 = true;
          iVar4 = local_4c;
          iVar12 = local_4c;
          do {
            iVar10 = func_0202f14c();
            iVar10 = func_0213ed2c(auStack_30,iVar10 + 4 + iVar4,0xb);
            if (iVar10 == 0) {
              bVar1 = false;
            }
            iVar4 = iVar4 + 0x16;
            iVar12 = iVar12 + 1;
          } while (iVar12 < 4);
          if (bVar1) {
            Sound_MaybeSetActiveSdat(DAT_02030030);
            NNSi_MaybeSndPlayerStartSeq(DAT_02030034,0,4);
            Sound_MaybeSetActiveSdat(DAT_02030038);
          }
        }
        else if ((iVar6 != 0) && (*(int *)(*DAT_02030028 + iVar11 + 0x58) == 0)) {
          Sound_MaybeSetActiveSdat(DAT_02030030);
          NNSi_MaybeSndPlayerStartSeq(DAT_02030034,0,5);
          Sound_MaybeSetActiveSdat(DAT_02030038);
        }
        iVar4 = *DAT_02030028;
        iVar12 = iVar4 + iVar11;
        local_78 = local_78 | iVar6 != *(int *)(iVar12 + 0x58) |
                   (uint)(iVar7 != *(int *)(iVar12 + 0x60)) |
                   (uint)(iVar8 != *(int *)(iVar12 + 0x5c));
        iVar11 = iVar11 + 0xc;
        local_60 = local_60 + 0x32;
        local_5c = local_5c + 1;
      } while ((int)local_5c < 4);
      if (local_78 != 0) {
        func_0203003c(1);
        return;
      }
    }
    break;
  case 5:
  case 8:
    iVar3 = func_02054f58();
    if (iVar3 == 1) {
      *(undefined4 *)(*DAT_02030028 + 0x50) = 0xb;
    }
  }
  return;
}

