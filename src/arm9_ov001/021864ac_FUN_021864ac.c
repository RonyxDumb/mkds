/* Decompiled C draft; module arm9_ov001; ROM address 021864ac. No matching claim. */
#include "types.h"
#include "deps/021864ac_FUN_021864ac.h"

void FUN_021864ac(undefined4 param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  longlong lVar12;
  longlong lVar13;
  longlong lVar14;
  undefined4 local_60;
  int local_5c;
  undefined4 local_58;
  int local_54;
  int local_50;
  int local_4c;
  undefined1 auStack_48 [12];
  int local_3c;
  int local_38;
  int local_34;
  undefined1 auStack_30 [4];
  undefined4 local_2c;
  undefined1 auStack_24 [16];
  
  if (*(int *)(param_2 + DAT_02186824) == 0) {
    piVar1 = (int *)(param_2 + DAT_02186828);
    iVar6 = *piVar1;
    if (iVar6 != 0) {
      *(int *)(param_2 + DAT_02186824) = iVar6;
      *piVar1 = 0;
    }
  }
  if ((*(code **)(param_2 + DAT_02186824) != (code *)0x0) &&
     (iVar6 = (**(code **)(param_2 + DAT_02186824))(param_2), iVar6 != 0)) {
    *(undefined4 *)(param_2 + DAT_02186824) = 0;
    *(undefined4 *)(param_2 + DAT_0218682c) = 0;
    *(undefined4 *)(param_2 + 0xb0) = 0;
    *(undefined4 *)(param_2 + DAT_02186830) = 0;
  }
  switch(*(undefined4 *)(param_2 + DAT_02186834)) {
  case 1:
    *(undefined4 *)(param_2 + DAT_0218683c) = *(undefined4 *)(param_2 + DAT_02186838);
    break;
  case 2:
    if (0 < *(int *)(param_2 + DAT_02186840)) {
      uVar2 = FUN_02187074(*(undefined4 *)(param_2 + DAT_02186844),*(int *)(param_2 + DAT_02186840),
                           *(undefined4 *)(param_2 + DAT_02186848));
      *(undefined4 *)(param_2 + DAT_02186848) = uVar2;
    }
    if (0 < *(int *)(param_2 + DAT_02186848)) {
      uVar2 = FUN_02187024((int *)(uintptr_t)(param_2 + DAT_0218684c),(int *)(uintptr_t)(param_2 + 4),*(int *)(param_2 + DAT_02186848),
                           *(undefined4 *)(param_2 + DAT_0218683c));
      *(undefined4 *)(param_2 + DAT_0218683c) = uVar2;
    }
    break;
  case 3:
    if (0 < *(int *)(param_2 + DAT_02186840)) {
      uVar2 = FUN_02187074(*(undefined4 *)(param_2 + DAT_02186844),*(int *)(param_2 + DAT_02186840),
                           *(undefined4 *)(param_2 + DAT_02186848));
      *(undefined4 *)(param_2 + DAT_02186848) = uVar2;
    }
    if (0 < *(int *)(param_2 + DAT_02186848)) {
      uVar2 = FUN_02187024((int *)(uintptr_t)(param_2 + 4),(int *)(uintptr_t)(param_2 + DAT_0218684c),*(int *)(param_2 + DAT_02186848),
                           *(undefined4 *)(param_2 + DAT_0218683c));
      *(undefined4 *)(param_2 + DAT_0218683c) = uVar2;
    }
    break;
  case 4:
    if (0 < *(int *)(param_2 + DAT_02186840)) {
      uVar2 = FUN_02187074(*(undefined4 *)(param_2 + DAT_02186844),*(int *)(param_2 + DAT_02186840),
                           *(undefined4 *)(param_2 + DAT_02186848));
      *(undefined4 *)(param_2 + DAT_02186848) = uVar2;
    }
    if (0 < *(int *)(param_2 + DAT_02186848)) {
      uVar2 = FUN_02186fb4((int *)(uintptr_t)(param_2 + DAT_0218684c),(int *)(uintptr_t)(param_2 + 4),*(int *)(param_2 + DAT_02186848),
                           *(undefined4 *)(param_2 + DAT_02186850),
                           *(undefined4 *)(param_2 + DAT_0218683c));
      *(undefined4 *)(param_2 + DAT_0218683c) = uVar2;
    }
    break;
  case 5:
    if (0 < *(int *)(param_2 + DAT_02186840)) {
      uVar2 = FUN_02187074(*(undefined4 *)(param_2 + DAT_02186844),*(int *)(param_2 + DAT_02186840),
                           *(undefined4 *)(param_2 + DAT_02186848));
      *(undefined4 *)(param_2 + DAT_02186848) = uVar2;
    }
    if (0 < *(int *)(param_2 + DAT_02186848)) {
      *(int *)(param_2 + DAT_0218683c) =
           *(int *)(param_2 + DAT_0218683c) + *(int *)(param_2 + DAT_02186848);
    }
    break;
  case 6:
  case 7:
  case 8:
    if (0 < *(int *)(param_2 + DAT_02186840)) {
      uVar2 = FUN_02187074(*(undefined4 *)(param_2 + DAT_02186844),*(int *)(param_2 + DAT_02186840),
                           *(undefined4 *)(param_2 + DAT_02186848));
      *(undefined4 *)(param_2 + DAT_02186848) = uVar2;
    }
    if (*(int *)(param_2 + DAT_02186834) == 6) {
      iVar6 = FUN_02187024((int *)(uintptr_t)(param_2 + DAT_0218684c),(int *)(uintptr_t)(param_2 + 4),
                           *(undefined4 *)(param_2 + DAT_02186848),
                           *(undefined4 *)(param_2 + DAT_0218683c));
      if (iVar6 - *(int *)(param_2 + DAT_0218683c) < 0) {
        *(undefined4 *)(param_2 + DAT_02186834) = 7;
      }
      else {
        *(undefined4 *)(param_2 + DAT_02186834) = 8;
      }
    }
    if (*(int *)(param_2 + DAT_02186834) == 8) {
      *(int *)(param_2 + DAT_0218683c) =
           *(int *)(param_2 + DAT_0218683c) + *(int *)(param_2 + DAT_02186848);
    }
    else if (*(int *)(param_2 + DAT_02186834) == 7) {
      *(int *)(param_2 + DAT_0218683c) =
           *(int *)(param_2 + DAT_0218683c) - *(int *)(param_2 + DAT_02186848);
    }
  }
  switch(*(undefined4 *)(param_2 + DAT_02186854)) {
  case 1:
    *(undefined4 *)(param_2 + DAT_02186838) = *(undefined4 *)(param_2 + DAT_0218683c);
    break;
  case 2:
    if (0 < *(int *)(param_2 + DAT_02186858)) {
      uVar2 = FUN_02187074(*(undefined4 *)(param_2 + DAT_0218685c),*(int *)(param_2 + DAT_02186858),
                           *(undefined4 *)(param_2 + DAT_02186860));
      *(undefined4 *)(param_2 + DAT_02186860) = uVar2;
    }
    if (0 < *(int *)(param_2 + DAT_02186860)) {
      uVar2 = FUN_02187024((int *)(uintptr_t)(param_2 + DAT_02186864),(int *)(uintptr_t)(param_2 + 4),*(int *)(param_2 + DAT_02186860),
                           *(undefined4 *)(param_2 + DAT_02186838));
      *(undefined4 *)(param_2 + DAT_02186838) = uVar2;
    }
    break;
  case 3:
    if (0 < *(int *)(param_2 + DAT_02186858)) {
      uVar2 = FUN_02187074(*(undefined4 *)(param_2 + DAT_0218685c),*(int *)(param_2 + DAT_02186858),
                           *(undefined4 *)(param_2 + DAT_02186860));
      *(undefined4 *)(param_2 + DAT_02186860) = uVar2;
    }
    if (0 < *(int *)(param_2 + DAT_02186860)) {
      uVar2 = FUN_02187024((int *)(uintptr_t)(param_2 + 4),(int *)(uintptr_t)(param_2 + DAT_02186864),*(int *)(param_2 + DAT_02186860),
                           *(undefined4 *)(param_2 + DAT_02186838));
      *(undefined4 *)(param_2 + DAT_02186838) = uVar2;
    }
    break;
  case 4:
    if (0 < *(int *)(param_2 + DAT_02186858)) {
      uVar2 = FUN_02187074(*(undefined4 *)(param_2 + DAT_0218685c),*(int *)(param_2 + DAT_02186858),
                           *(undefined4 *)(param_2 + DAT_02186860));
      *(undefined4 *)(param_2 + DAT_02186860) = uVar2;
    }
    if (0 < *(int *)(param_2 + DAT_02186860)) {
      uVar2 = FUN_02186fb4((int *)(uintptr_t)(param_2 + DAT_02186864),(int *)(uintptr_t)(param_2 + 4),*(int *)(param_2 + DAT_02186860),
                           *(undefined4 *)(param_2 + DAT_02186868),
                           *(undefined4 *)(param_2 + DAT_02186838));
      *(undefined4 *)(param_2 + DAT_02186838) = uVar2;
    }
  }
  if (0 < *(int *)(param_2 + DAT_0218686c)) {
    uVar2 = FUN_02187074(*(undefined4 *)(param_2 + DAT_02186870),*(int *)(param_2 + DAT_0218686c),
                         *(undefined4 *)(param_2 + DAT_02186874));
    *(undefined4 *)(param_2 + DAT_02186874) = uVar2;
  }
  if (0 < *(int *)(param_2 + DAT_02186878)) {
    uVar2 = FUN_02187074(*(undefined4 *)(param_2 + DAT_0218687c),*(int *)(param_2 + DAT_02186878),
                         *(undefined4 *)(param_2 + DAT_02186880));
    *(undefined4 *)(param_2 + DAT_02186880) = uVar2;
    uVar2 = FUN_02187074(*(undefined4 *)(param_2 + DAT_02186884),
                         *(undefined4 *)(param_2 + DAT_02186878),
                         *(undefined4 *)(param_2 + DAT_02186888));
    *(undefined4 *)(param_2 + DAT_02186888) = uVar2;
    uVar2 = FUN_02187074(*(undefined4 *)(param_2 + DAT_0218688c),
                         *(undefined4 *)(param_2 + DAT_02186878),
                         *(undefined4 *)(param_2 + DAT_02186890));
    *(undefined4 *)(param_2 + DAT_02186890) = uVar2;
  }
  if (0 < *(int *)(param_2 + DAT_02186894)) {
    uVar2 = FUN_02187074(*(undefined4 *)(param_2 + DAT_02186898),*(int *)(param_2 + DAT_02186894),
                         *(undefined4 *)(param_2 + DAT_0218689c));
    *(undefined4 *)(param_2 + DAT_0218689c) = uVar2;
    uVar2 = FUN_02187074(*(undefined4 *)(param_2 + DAT_021868a0),
                         *(undefined4 *)(param_2 + DAT_02186894),
                         *(undefined4 *)(param_2 + DAT_021868a4));
    *(undefined4 *)(param_2 + DAT_021868a4) = uVar2;
    uVar2 = FUN_02187074(*(undefined4 *)(param_2 + DAT_021868a8),
                         *(undefined4 *)(param_2 + DAT_02186894),
                         *(undefined4 *)(param_2 + DAT_021868ac));
    *(undefined4 *)(param_2 + DAT_021868ac) = uVar2;
  }
  if (0 < *(int *)(param_2 + DAT_021868b0)) {
    uVar2 = FUN_02187074(*(undefined4 *)(param_2 + DAT_021868b4),*(int *)(param_2 + DAT_021868b0),
                         *(undefined4 *)(param_2 + DAT_021868b8));
    *(undefined4 *)(param_2 + DAT_021868b8) = uVar2;
    uVar2 = FUN_02187074(*(undefined4 *)(param_2 + DAT_021868bc),
                         *(undefined4 *)(param_2 + DAT_021868b0),
                         *(undefined4 *)(param_2 + DAT_021868c0));
    *(undefined4 *)(param_2 + DAT_021868c0) = uVar2;
    uVar2 = FUN_02187074(*(undefined4 *)(param_2 + DAT_021868c4),
                         *(undefined4 *)(param_2 + DAT_021868b0),
                         *(undefined4 *)(param_2 + DAT_021868c8));
    *(undefined4 *)(param_2 + DAT_021868c8) = uVar2;
  }
  if (0 < *(int *)(param_2 + DAT_021868cc)) {
    uVar2 = FUN_02187074(*(undefined4 *)(param_2 + DAT_021868d0),*(int *)(param_2 + DAT_021868cc),
                         *(undefined4 *)(param_2 + DAT_021868d4));
    *(undefined4 *)(param_2 + DAT_021868d4) = uVar2;
    uVar2 = FUN_02187074(*(undefined4 *)(param_2 + DAT_02186c70),
                         *(undefined4 *)(param_2 + DAT_02186c74),
                         *(undefined4 *)(param_2 + DAT_02186c78));
    *(undefined4 *)(param_2 + DAT_02186c78) = uVar2;
    uVar2 = FUN_02187074(*(undefined4 *)(param_2 + DAT_02186c7c),
                         *(undefined4 *)(param_2 + DAT_02186c74),
                         *(undefined4 *)(param_2 + DAT_02186c80));
    *(undefined4 *)(param_2 + DAT_02186c80) = uVar2;
  }
  if (*(int *)(param_2 + DAT_02186c84) != 0) {
    *(int *)(param_2 + DAT_02186c88) =
         *(int *)(param_2 + DAT_02186c88) - *(int *)(*(int *)(param_2 + 0xa0) + 0x1c);
  }
  iVar8 = *(int *)(param_2 + DAT_02186c8c);
  iVar7 = *(int *)(param_2 + 0xa0);
  iVar6 = *(int *)(iVar7 + 0x18);
  if ((-iVar6 < iVar8) && (iVar8 < iVar6)) {
    piVar1 = (int *)(param_2 + DAT_02186c90);
    iVar8 = *piVar1;
    if ((-iVar6 < iVar8) && (iVar8 < iVar6)) {
      *(int *)(param_2 + DAT_02186c8c) = 0;
      *piVar1 = 0;
      goto LAB_021869f0;
    }
  }
  if ((*(uint *)(param_2 + DAT_02186c94) & DAT_02186c98) == 0) {
    iVar6 = *(int *)(iVar7 + 0x14);
    iVar7 = iVar6 >> 0x1f;
    uVar10 = func_0x02133048(*(int *)(param_2 + DAT_02186c8c),
                             *(int *)(param_2 + DAT_02186c8c) >> 0x1f,iVar6,iVar7);
    *(uint *)(param_2 + DAT_02186c8c) =
         (uint)uVar10 >> 0xc | (int)((ulonglong)uVar10 >> 0x20) << 0x14;
    uVar10 = func_0x02133048(*(int *)(param_2 + DAT_02186c88),
                             *(int *)(param_2 + DAT_02186c88) >> 0x1f,iVar6,iVar7);
    *(uint *)(param_2 + DAT_02186c88) =
         (uint)uVar10 >> 0xc | (int)((ulonglong)uVar10 >> 0x20) << 0x14;
    uVar10 = func_0x02133048(*(int *)(param_2 + DAT_02186c90),
                             *(int *)(param_2 + DAT_02186c90) >> 0x1f,iVar6,iVar7);
    *(uint *)(param_2 + DAT_02186c90) =
         (uint)uVar10 >> 0xc | (int)((ulonglong)uVar10 >> 0x20) << 0x14;
  }
  else {
    iVar6 = *(int *)(iVar7 + 0x10);
    iVar7 = iVar6 >> 0x1f;
    uVar10 = func_0x02133048(*(int *)(param_2 + DAT_02186c8c),
                             *(int *)(param_2 + DAT_02186c8c) >> 0x1f,iVar6,iVar7);
    *(uint *)(param_2 + DAT_02186c8c) =
         (uint)uVar10 >> 0xc | (int)((ulonglong)uVar10 >> 0x20) << 0x14;
    uVar10 = func_0x02133048(*(int *)(param_2 + DAT_02186c88),
                             *(int *)(param_2 + DAT_02186c88) >> 0x1f,iVar6,iVar7);
    *(uint *)(param_2 + DAT_02186c88) =
         (uint)uVar10 >> 0xc | (int)((ulonglong)uVar10 >> 0x20) << 0x14;
    uVar10 = func_0x02133048(*(int *)(param_2 + DAT_02186c90),
                             *(int *)(param_2 + DAT_02186c90) >> 0x1f,iVar6,iVar7);
    *(uint *)(param_2 + DAT_02186c90) =
         (uint)uVar10 >> 0xc | (int)((ulonglong)uVar10 >> 0x20) << 0x14;
  }
LAB_021869f0:
  iVar6 = (int)(*(uint *)(param_2 + DAT_02186c9c) & 0xffff) >> 4;
  iVar7 = *(int *)(param_2 + DAT_02186ca0);
  iVar9 = *(int *)(param_2 + DAT_02186c88);
  iVar8 = (int)*(short *)(DAT_02186ca4 + (iVar6 * 2 + 1) * 2);
  uVar10 = func_0x02133048(iVar7,iVar7 >> 0x1f,iVar8,iVar8 >> 0x1f);
  iVar8 = *(int *)(param_2 + DAT_02186c90);
  iVar6 = (int)*(short *)(DAT_02186ca4 + iVar6 * 4);
  uVar11 = func_0x02133048(iVar7,iVar7 >> 0x1f,iVar6,iVar6 >> 0x1f);
  *(uint *)(param_2 + 4) =
       *(int *)(param_2 + 4) +
       *(int *)(param_2 + DAT_02186c8c) +
       ((uint)uVar11 >> 0xc | (int)((ulonglong)uVar11 >> 0x20) << 0x14);
  *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + iVar9;
  *(uint *)(param_2 + 0xc) =
       *(int *)(param_2 + 0xc) +
       iVar8 + ((uint)uVar10 >> 0xc | (int)((ulonglong)uVar10 >> 0x20) << 0x14);
  local_60 = *(undefined4 *)(param_2 + 4);
  local_5c = *(int *)(param_2 + 8) + DAT_02186ca8;
  local_58 = *(undefined4 *)(param_2 + 0xc);
  *(undefined4 *)(param_2 + DAT_02186c94) = 0;
  if (*(int *)(param_2 + DAT_02186cac) == 1) {
    uVar2 = 4;
  }
  else {
    uVar2 = 1;
  }
  iVar6 = func_0x01ffdee4(&local_60,0,0,DAT_02186ca8,uVar2,0xfffffffe,&local_54,(int *)(void *)(auStack_48),&local_3c
                          ,(uint *)(uintptr_t)(param_2 + DAT_02186c94),0,0,0,0);
  if (iVar6 != 0) {
    if (*(int *)(param_2 + DAT_02186cac) - 2U < 2) {
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + local_50;
    }
    else {
      *(int *)(param_2 + 4) = *(int *)(param_2 + 4) + local_54;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + local_50;
      *(int *)(param_2 + 0xc) = *(int *)(param_2 + 0xc) + local_4c;
    }
  }
  if ((*(int *)(param_2 + DAT_02186cac) != 2) &&
     ((*(uint *)(param_2 + DAT_02186c94) & DAT_02186cb0) != 0)) {
    lVar12 = func_0x02133048(local_34,local_34 >> 0x1f,local_34,local_34 >> 0x1f);
    lVar13 = func_0x02133048(local_3c,local_3c >> 0x1f,local_3c,local_3c >> 0x1f);
    lVar14 = func_0x02133048(local_38,local_38 >> 0x1f,local_38,local_38 >> 0x1f);
    lVar12 = lVar12 + lVar13 + lVar14;
    if ((int)(uint)((uint)lVar12 < 0x10) <= (int)((ulonglong)lVar12 >> 0x20)) {
      func_0x02039860((uint)(uintptr_t)(&local_3c),(int *)(void *)(auStack_30));
    }
    local_2c = 0;
    func_0x02147fd8(*(undefined4 *)(*(int *)(param_2 + 0xa0) + 0x30),auStack_30,
                    param_2 + DAT_02186c8c,param_2 + DAT_02186c8c);
  }
  uVar4 = *(uint *)(param_2 + DAT_02186c94);
  if ((uVar4 & DAT_02186c98) != 0) {
    iVar6 = *(int *)(param_2 + DAT_02186c88);
    if (iVar6 < 1) {
      if (*(int *)(param_2 + DAT_02186cb8) == 0) {
        *(int *)(param_2 + DAT_02186c88) = 0;
      }
      else {
        iVar7 = -*(int *)(*(int *)(param_2 + 0xa0) + 0x20);
        uVar10 = func_0x02133048(iVar6,iVar6 >> 0x1f,iVar7,iVar7 >> 0x1f);
        puVar5 = (uint *)(param_2 + DAT_02186c88);
        *puVar5 = (uint)uVar10 >> 0xc | (int)((ulonglong)uVar10 >> 0x20) << 0x14;
        if ((int)*puVar5 < *(int *)(*(int *)(param_2 + 0xa0) + 0x18)) {
          *(undefined4 *)(param_2 + DAT_02186cb8) = 0;
          *puVar5 = 0;
        }
      }
    }
    else {
      *(uint *)(param_2 + DAT_02186c94) = uVar4 & DAT_02186cb4;
    }
  }
  if (*(int *)(param_2 + 8) < 0) {
    *(undefined4 *)(param_2 + 8) = 0;
    *(uint *)(param_2 + DAT_02186c94) = *(uint *)(param_2 + DAT_02186c94) | *DAT_02186cbc;
  }
  if (0 < *(int *)(param_2 + DAT_02186cc0)) {
    iVar6 = FUN_02187074(*(undefined4 *)(param_2 + DAT_02186cc4),*(int *)(param_2 + DAT_02186cc0),
                         *(undefined4 *)(param_2 + DAT_02186cc8));
    piVar1 = (int *)(param_2 + DAT_02186cc8);
    *piVar1 = iVar6;
    if (*piVar1 == *(int *)(param_2 + DAT_02186cc4)) {
      *(undefined4 *)(param_2 + DAT_02186cc0) = 0;
    }
  }
  if (0 < *(int *)(param_2 + DAT_02186ccc)) {
    uVar2 = FUN_02187074(*(undefined4 *)(param_2 + DAT_02186cd0),*(int *)(param_2 + DAT_02186ccc),
                         *(undefined4 *)(param_2 + 0x1c));
    *(undefined4 *)(param_2 + 0x24) = uVar2;
    *(undefined4 *)(param_2 + 0x20) = *(undefined4 *)(param_2 + 0x24);
    *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(param_2 + 0x20);
  }
  if (*(int *)(param_2 + DAT_02186cd4) == 1) {
    iVar6 = (int)(*(uint *)(param_2 + DAT_02186cd8) & 0xffff) >> 4;
    func_0x02146d44(param_2 + 0x28,(int)*(short *)(DAT_02186ca4 + iVar6 * 4),
                    (int)*(short *)(DAT_02186ca4 + (iVar6 * 2 + 1) * 2));
    func_0x02146d78(param_2 + DAT_02186cdc,param_2 + 0x28,param_2 + DAT_02186ce0);
    func_0x02148504(param_2 + DAT_02186ce0,param_2 + 4,param_2 + DAT_02186ce0);
  }
  else {
    *(int *)(param_2 + DAT_02186ce0) = *(int *)(param_2 + 4) + *(int *)(param_2 + DAT_02186cdc);
    *(int *)(param_2 + DAT_02186f38) = *(int *)(param_2 + 8) + *(int *)(param_2 + DAT_02186ce4);
    *(int *)(param_2 + DAT_02186f40) = *(int *)(param_2 + 0xc) + *(int *)(param_2 + DAT_02186f3c);
  }
  *(short *)(param_2 + 0x7e) = (short)*(undefined4 *)(param_2 + DAT_02186f44);
  if (*(int *)(param_2 + DAT_02186f48) != 0) {
    uVar4 = func_0x0209b620();
    FUN_0219b250(*(undefined4 *)(param_2 + DAT_02186f48));
    uVar3 = func_0x0209b620(*(undefined4 *)(param_2 + DAT_02186f48));
    iVar6 = *(int *)(param_2 + DAT_02186f4c);
    if (iVar6 != 0) {
      if (((int)uVar4 < iVar6) && (iVar6 <= (int)uVar3)) {
        FUN_02188e94(param_2,param_2 + DAT_02186f50);
      }
      else if ((uVar3 < uVar4) && ((iVar6 <= (int)uVar3 || ((int)uVar4 < iVar6)))) {
        FUN_02188e94(param_2,param_2 + DAT_02186f50);
      }
    }
    iVar6 = *(int *)(param_2 + DAT_02186f54);
    if (iVar6 != 0) {
      if (((int)uVar4 < iVar6) && (iVar6 <= (int)uVar3)) {
        (**(code **)(param_2 + DAT_02186f58))(param_2);
      }
      else if ((uVar3 < uVar4) && ((iVar6 <= (int)uVar3 || ((int)uVar4 < iVar6)))) {
        (**(code **)(param_2 + DAT_02186f58))(param_2);
      }
    }
    iVar6 = *(int *)(param_2 + DAT_02186f5c);
    if (iVar6 != 0) {
      if (((int)uVar4 < iVar6) && (iVar6 <= (int)uVar3)) {
        (**(code **)(param_2 + DAT_02186f60))(param_2);
      }
      else if ((uVar3 < uVar4) && ((iVar6 <= (int)uVar3 || ((int)uVar4 < iVar6)))) {
        (**(code **)(param_2 + DAT_02186f60))(param_2);
      }
    }
    iVar6 = FUN_0219b240(*(undefined4 *)(param_2 + DAT_02186f48));
    if (iVar6 == 0) {
      FUN_02188e94(param_2,param_2 + DAT_02186f64);
    }
  }
  *(int *)(param_2 + 0xb0) = *(int *)(param_2 + 0xb0) + 1;
  iVar6 = *(int *)(param_2 + DAT_02186f68);
  if ((iVar6 != 0) && (*(int *)(param_2 + 0xb0) == iVar6)) {
    *(int *)(param_2 + DAT_02186f68) = 0;
    *(undefined4 *)(param_2 + 0xb0) = 0;
    FUN_02188e94(param_2,param_2 + DAT_02186f6c);
  }
  if ((*(int *)(param_2 + DAT_02186f70) != 0) &&
     (iVar6 = FUN_021881a8(param_2,param_2 + DAT_02186f74,*(undefined4 *)(param_2 + DAT_02186f78),
                           *(undefined4 *)(param_2 + DAT_02186f7c)), iVar6 != 0)) {
    FUN_02188e94(param_2,param_2 + DAT_02186f70);
  }
  if ((*(int *)(param_2 + DAT_02186f80) != 0) &&
     (iVar6 = FUN_021881a8(param_2,param_2 + DAT_02186f84,*(undefined4 *)(param_2 + DAT_02186f88),
                           *(undefined4 *)(param_2 + DAT_02186f8c)), iVar6 == 0)) {
    FUN_02188e94(param_2,param_2 + DAT_02186f80);
  }
  if ((*(int *)(param_2 + DAT_02186f90) != 0) && (*(int *)(param_2 + DAT_02186f94) == 0)) {
    iVar7 = *(int *)(*(int *)(param_2 + 0xa0) + 0x18);
    iVar6 = -iVar7;
    if (((iVar6 < *(int *)(param_2 + DAT_02186f98)) &&
        ((((*(int *)(param_2 + DAT_02186f98) < iVar7 && (iVar6 < *(int *)(param_2 + DAT_02186f9c)))
          && (*(int *)(param_2 + DAT_02186f9c) < iVar7)) &&
         ((iVar6 < *(int *)(param_2 + DAT_02186fa0) && (*(int *)(param_2 + DAT_02186fa0) < iVar7))))
        )) && ((*(uint *)(param_2 + DAT_02186fa4) & DAT_02186fa8) != 0)) {
      FUN_02188e94(param_2);
    }
  }
  if (((*(int *)(param_2 + DAT_02186fac) != 0) && (*(int *)(param_2 + DAT_02186f94) < 1)) &&
     ((*(uint *)(param_2 + DAT_02186fa4) & DAT_02186fa8) != 0)) {
    FUN_02188e94(param_2);
  }
  iVar7 = 0;
  iVar8 = param_2 + 0xd0;
  iVar6 = param_2;
  do {
    FUN_02187684(param_2,iVar7,auStack_24);
    if (*(int *)(iVar6 + 0xd0) != 0) {
      if ((*(int *)(iVar6 + 0xc0) < 1) ||
         (*(int *)(iVar6 + 0xc0) = *(int *)(iVar6 + 0xc0) + -1, *(int *)(iVar6 + 0xc0) != 0)) {
        func_0x0208b5b0(*(undefined4 *)(iVar6 + 0xd0),auStack_24);
      }
      else {
        func_0x0208b6b0(iVar8);
      }
    }
    iVar6 = iVar6 + 0x18;
    iVar8 = iVar8 + 0x18;
    iVar7 = iVar7 + 1;
  } while (iVar7 < 5);
  iVar6 = *(int *)(param_2 + DAT_02186fb0);
  if (0 < iVar6) {
    *(int *)(param_2 + DAT_02186fb0) = iVar6 + -1;
  }
  return;
}

