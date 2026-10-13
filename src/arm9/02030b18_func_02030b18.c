/* Decompiled C draft; module arm9; ROM address 02030b18. No matching claim. */
#include "types.h"
#include "deps/02030b18_func_02030b18.h"

undefined4 func_02030b18(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint *puVar6;
  int *piVar7;
  bool bVar8;
  bool bVar9;
  int iVar10;
  undefined4 local_38;
  int local_34;
  undefined1 auStack_2e [20];
  undefined2 local_1a;
  
  local_38 = 0xffffffff;
  iVar2 = GetDirectInputUnitIndex();
  local_34 = 0;
  iVar3 = *DAT_02030e68;
  if (0 < *(int *)(iVar3 + 0x9c)) {
    *(int *)(iVar3 + 0x9c) = *(int *)(iVar3 + 0x9c) + -1;
  }
  func_020317a0();
  iVar4 = *DAT_02030e68;
  iVar10 = *(int *)(iVar4 + 0x74);
  if ((*(int *)(iVar4 + 0x84) == 0) && (*(int *)(iVar4 + 0x8c) == 0)) {
    uVar5 = func_02032000();
    piVar1 = DAT_02030e68;
    *(undefined4 *)(*DAT_02030e68 + 0x74) = uVar5;
    if (*(int *)(*piVar1 + 0x74) != iVar10) {
      func_02031f5c();
      if (*(int *)(*DAT_02030e68 + 0x88) == 0) {
        iVar4 = *(int *)(*DAT_02030e68 + 0x74);
        if (iVar10 < iVar4) {
          Sound_MaybeSetActiveSdat(DAT_02030e6c);
          NNSi_MaybeSndPlayerStartSeq(DAT_02030e70,0,2);
          Sound_MaybeSetActiveSdat(DAT_02030e74);
        }
        else if (iVar4 < iVar10) {
          Sound_MaybeSetActiveSdat(DAT_02030e6c);
          NNSi_MaybeSndPlayerStartSeq(DAT_02030e70,0,3);
          Sound_MaybeSetActiveSdat(DAT_02030e74);
        }
        *(undefined4 *)(*DAT_02030e68 + 0x88) = 0;
      }
    }
    func_02031b6c();
  }
  if ((*(int *)(*DAT_02030e68 + 0x84) == 0) && (*(int *)(*DAT_02030e68 + 0x80) == 0)) {
    Mem_CpuFill16(0,(int)(uintptr_t)(auStack_2e),0x16);
    puVar6 = (uint *)func_0202f14c();
    iVar4 = func_0204ff14(*puVar6 & 0xffff,(int)(uintptr_t)(auStack_2e));
    if (iVar4 != 0) {
      local_1a = 0;
      func_0212426c(1,(int)*DAT_02030e78,*(undefined4 *)(iVar3 + 0x54),auStack_2e,
                    *(undefined4 *)(iVar3 + 0x4c),*(undefined4 *)(iVar3 + 0x58));
      *(undefined4 *)(*DAT_02030e68 + 0x80) = 1;
    }
  }
  func_02031ba4();
  iVar3 = DAT_02030e80;
  piVar1 = DAT_02030e68;
  if ((*(int *)(*DAT_02030e68 + DAT_02030e7c) != 0) &&
     (piVar7 = (int *)(*DAT_02030e68 + DAT_02030e80), *piVar7 = *piVar7 + 1,
     0x96 < *(int *)(*piVar1 + iVar3))) {
    func_02108ddc();
    *(undefined4 *)(*DAT_02030e68 + DAT_02030e7c) = 0;
  }
  iVar3 = *DAT_02030e68;
  switch(*(undefined4 *)(iVar3 + 0x94)) {
  case 0:
    iVar2 = func_02031268();
    if (iVar2 != 0) {
      *(undefined4 *)(*DAT_02030e68 + 0x94) = 1;
    }
    break;
  case 1:
    bVar8 = false;
    bVar9 = false;
    iVar2 = iVar2 * 0x5c;
    if ((*(short *)(DAT_02030e84 + iVar2) == 0) && (*(ushort *)(DAT_02030e88 + iVar2) < 5)) {
      bVar9 = true;
    }
    if (((!bVar9) && (*(short *)(DAT_02030e8c + iVar2) == 0)) &&
       (*(short *)(DAT_02030e84 + iVar2) != 0)) {
      bVar8 = true;
    }
    if (bVar8) {
      local_34 = func_02128210(*(undefined2 *)(DAT_02030e90 + iVar2),
                               *(undefined2 *)(DAT_02030e94 + iVar2));
    }
    piVar1 = DAT_02030e9c;
    iVar3 = *DAT_02030e68;
    if (*(int *)(iVar3 + 0x90) == 0) {
      switch(*(undefined4 *)(*DAT_02030e98 + 4)) {
      default:
        bVar9 = false;
        break;
      case 7:
      case 8:
      case 9:
      case 10:
      case 0xb:
        bVar9 = true;
      }
      if (bVar9) {
        func_021282c8();
        func_02025f14((int *)(uintptr_t)(*DAT_02030e68 + 0xa0),2);
        Sound_MaybeSetActiveSdat(DAT_02030e6c);
        NNSi_MaybeSndPlayerStartSeq(DAT_02030e70,0,6);
        Sound_MaybeSetActiveSdat(DAT_02030e74);
        piVar1 = DAT_02030e68;
        *(undefined4 *)(*DAT_02030e68 + DAT_02030e7c) = 1;
        *(undefined4 *)(*piVar1 + 0x90) = 1;
        break;
      }
    }
    if (*(int *)(iVar3 + 0x70) == 0xb) {
      *(undefined4 *)(*DAT_02030e9c + 4) = 1;
      *(undefined4 *)(*piVar1 + 8) = 4;
      if (param_1 != 0) {
        *(undefined2 *)(param_1 + 4) = 1;
      }
      *(undefined4 *)(*DAT_02030e68 + 0x94) = 7;
    }
    else if ((*(int *)(iVar3 + 0x90) == 0) &&
            (((*(ushort *)(DAT_02030ea0 + iVar2) & 2) != 0 || (local_34 != 0)))) {
      *(undefined4 *)(iVar3 + 0x6c) = 0;
      piVar1 = DAT_02030e68;
      *(undefined4 *)(*DAT_02030e68 + 0x94) = 3;
      *(undefined4 *)(*piVar1 + 0x7c) = 1;
      TextSystem_CloseDialog_from_thumb();
      func_02128310(0);
      Sound_MaybeSetActiveSdat(DAT_02030e6c);
      NNSi_MaybeSndPlayerStartSeq(DAT_02030e70,0,3);
      Sound_MaybeSetActiveSdat(DAT_02030e74);
    }
    break;
  case 3:
    if (*(int *)(iVar3 + 0x70) == 0xb) {
      func_02025f14((int *)(uintptr_t)(iVar3 + 0xa0),2);
      func_02025f14((int *)(uintptr_t)(*DAT_02030e68 + 0xb0),2);
      func_02025f14((int *)(uintptr_t)(*DAT_02030e68 + 0xc0),2);
      *(undefined4 *)(*DAT_02030e68 + 0x94) = 4;
    }
    break;
  case 4:
    iVar2 = func_02031250();
    if (iVar2 != 0) {
      *(undefined4 *)(*DAT_02030e68 + 0x94) = 6;
    }
    break;
  case 5:
    iVar2 = TextSystem_JustFadedIn_from_thumb();
    if (iVar2 != 0) {
      NNSi_MaybeSndPlayerStartSeq(DAT_02030e70,0,0x15);
    }
    iVar2 = TextSystem_WasAnyDialogButtonPressed_from_thumb();
    piVar1 = DAT_02030e68;
    if (iVar2 != 0) {
      *(undefined4 *)(*DAT_02030e68 + 0x6c) = 0;
      *(undefined4 *)(*piVar1 + 0x94) = 3;
      TextSystem_CloseDialog_from_thumb();
    }
    break;
  case 6:
    local_38 = *(undefined4 *)(iVar3 + 0x6c);
  }
  func_02031208();
  return local_38;
}

