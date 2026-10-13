/* Decompiled C draft; module arm9_ov000; ROM address 021a1ef4. No matching claim. */
#include "types.h"
#include "deps/021a1ef4_FUN_021a1ef4.h"

void FUN_021a1ef4(int param_1)

{
  int *piVar1;
  uint uVar2;
  char *pcVar3;
  undefined *extraout_r1;
  undefined *puVar4;
  undefined *extraout_r1_00;
  int iVar5;
  uint uVar6;
  int iVar7;
  bool bVar8;
  undefined8 uVar9;
  longlong lVar10;
  
  if (*DAT_021a2258 == 0) {
    return;
  }
  uVar9 = FUN_0219c39c();
  puVar4 = (undefined *)((ulonglong)uVar9 >> 0x20);
  if ((int)uVar9 != 0) {
    return;
  }
  if (param_1 == 0) {
    if (*(int *)(*DAT_021a2258 + 0x10) != 0) {
      FUN_021a49a0();
    }
    if (*(undefined4 **)(*DAT_021a2258 + 4) == (undefined4 *)0x0) {
      return;
    }
    FUN_02198a8c(**(undefined4 **)(*DAT_021a2258 + 4));
    return;
  }
  iVar7 = *DAT_021a2258;
  uVar2 = *(uint *)(iVar7 + DAT_021a225c);
  if (uVar2 == 0) {
    return;
  }
  if (0xd < uVar2) goto switchD_021a1f5a_caseD_1;
  puVar4 = &DAT_021a1f5c + *(short *)(&DAT_021a1f5c + uVar2 * 2);
  switch(uVar2) {
  case 2:
  case 3:
  case 5:
    puVar4 = *(undefined **)(iVar7 + 0xe8);
    if (0 < (int)puVar4) {
      if (uVar2 == 3) {
        uVar2 = DAT_021a227c * *(byte *)(iVar7 + 0xd) + DAT_021a227c;
      }
      else {
        uVar2 = DAT_021a227c;
        if (puVar4 == (undefined *)0x1) {
          uVar2 = DAT_021a2288;
        }
      }
      lVar10 = func_0x0200f5ac();
      lVar10 = lVar10 - *(longlong *)(iVar7 + 0xec);
      uVar6 = (uint)lVar10;
      uVar9 = func_0x02132e40(uVar6 * 0x40,(int)((ulonglong)lVar10 >> 0x20) * 0x40 | uVar6 >> 0x1a,
                              DAT_021a226c,0);
      puVar4 = (undefined *)((ulonglong)uVar9 >> 0x20);
      bVar8 = (uint)uVar9 <= uVar2;
      if ((uint)bVar8 <= (uint)-(int)puVar4) {
        FUN_021a0f20(*(undefined4 *)(iVar7 + DAT_021a228c),puVar4,-(uint)!bVar8 - (int)puVar4);
        iVar7 = FUN_0219e594();
        if (iVar7 != 0) {
          return;
        }
        puVar4 = (undefined *)0x0;
        *(undefined4 *)(*DAT_021a2258 + 0xe8) = 0;
      }
    }
    break;
  case 4:
    if (*(int *)(iVar7 + DAT_021a2260) != 0) {
      lVar10 = func_0x0200f5ac();
      lVar10 = lVar10 - CONCAT44(*(undefined4 *)(iVar7 + DAT_021a2268),
                                 *(undefined4 *)(iVar7 + DAT_021a2264));
      uVar2 = (uint)lVar10;
      uVar9 = func_0x02132e40(uVar2 * 0x40,(int)((ulonglong)lVar10 >> 0x20) * 0x40 | uVar2 >> 0x1a,
                              DAT_021a226c,0);
      puVar4 = (undefined *)((ulonglong)uVar9 >> 0x20);
      if ((uint)((uint)uVar9 <= *(uint *)(iVar7 + DAT_021a2260)) <= (uint)-(int)puVar4) {
        *(uint *)(iVar7 + DAT_021a2260) = 0;
        iVar7 = DAT_021a2270;
        piVar1 = DAT_021a2258;
        if (*(char *)(*DAT_021a2258 + 0x15) == '\x03') {
          pcVar3 = (char *)(*DAT_021a2258 + DAT_021a2270);
          *pcVar3 = *pcVar3 + '\x01';
          if (5 < *(byte *)(*piVar1 + iVar7)) {
            FUN_021a1a38(6,DAT_021a2274);
            return;
          }
          FUN_0219fdc8(*(undefined4 *)(*piVar1 + 0xf4),0);
          uVar9 = FUN_0219fee4();
          puVar4 = (undefined *)((ulonglong)uVar9 >> 0x20);
          if ((int)uVar9 != 0) {
            return;
          }
        }
        else {
          uVar9 = FUN_0219fb48();
          puVar4 = (undefined *)((ulonglong)uVar9 >> 0x20);
          if ((int)uVar9 == 0) {
            return;
          }
        }
      }
    }
    iVar7 = *DAT_021a2258;
    if (*(int *)(iVar7 + DAT_021a2278) != 0) {
      uVar6 = DAT_021a227c * *(byte *)(iVar7 + 0xd) + DAT_021a227c;
      lVar10 = func_0x0200f5ac();
      lVar10 = lVar10 - CONCAT44(*(undefined4 *)(iVar7 + DAT_021a2284),
                                 *(undefined4 *)(iVar7 + DAT_021a2280));
      uVar2 = (uint)lVar10;
      uVar9 = func_0x02132e40(uVar2 * 0x40,(int)((ulonglong)lVar10 >> 0x20) * 0x40 | uVar2 >> 0x1a,
                              DAT_021a226c,0);
      uVar2 = (uint)((ulonglong)uVar9 >> 0x20);
      bVar8 = uVar6 <= (uint)uVar9;
      puVar4 = (undefined *)(uVar2 - !bVar8);
      if (uVar2 != 0 || uVar2 < bVar8) {
        FUN_0219fdc8(*(undefined4 *)(iVar7 + 0xf4),0);
        uVar9 = FUN_0219fee4();
        puVar4 = (undefined *)((ulonglong)uVar9 >> 0x20);
        if ((int)uVar9 != 0) {
          return;
        }
      }
    }
    break;
  case 7:
    if (*(int *)(iVar7 + DAT_021a2294) == 0 && *(int *)(iVar7 + DAT_021a2290) == 0) {
      if (*(char *)(iVar7 + DAT_021a229c) == '\x06') {
        lVar10 = FUN_021a350c();
        iVar5 = DAT_021a22ac;
        lVar10 = lVar10 - CONCAT44(*(undefined4 *)(iVar7 + DAT_021a22a4),
                                   *(undefined4 *)(iVar7 + DAT_021a22a0));
        puVar4 = (undefined *)((ulonglong)lVar10 >> 0x20);
        if ((uint)((uint)lVar10 <= DAT_021a22a8) <= (uint)-(int)puVar4) {
          *(char *)(iVar7 + DAT_021a22ac) = *(char *)(iVar7 + DAT_021a22ac) + '\x01';
          iVar7 = *DAT_021a2258;
          if (*(byte *)(iVar7 + iVar5) < 6) {
            FUN_021a0ae8(6,*(undefined4 *)(iVar7 + DAT_021a22b8),
                         *(undefined4 *)(iVar7 + DAT_021a22bc),*(undefined2 *)(iVar7 + DAT_021a22c0)
                         ,(undefined4 *)(uintptr_t)(iVar7 + DAT_021a22b0),*(undefined4 *)(iVar7 + DAT_021a22b4));
            uVar9 = FUN_0219fee4();
            puVar4 = (undefined *)((ulonglong)uVar9 >> 0x20);
            if ((int)uVar9 != 0) {
              return;
            }
          }
          else {
            FUN_021a1ac0();
            uVar9 = FUN_0219f938(*(undefined4 *)(*DAT_021a2258 + 0xf4));
            puVar4 = (undefined *)((ulonglong)uVar9 >> 0x20);
            if ((int)uVar9 == 0) {
              return;
            }
          }
        }
      }
      else {
        puVar4 = (undefined *)0x0;
      }
    }
    else {
      lVar10 = FUN_021a350c();
      iVar5 = DAT_021a2294;
      lVar10 = lVar10 - CONCAT44(*(undefined4 *)(iVar7 + DAT_021a2294),
                                 *(undefined4 *)(iVar7 + DAT_021a2290));
      puVar4 = (undefined *)((ulonglong)lVar10 >> 0x20);
      if ((uint)((uint)lVar10 <= DAT_021a2298) <= (uint)-(int)puVar4) {
        iVar7 = *DAT_021a2258;
        *(undefined4 *)(iVar7 + DAT_021a2290) = 0;
        *(undefined4 *)(iVar7 + iVar5) = 0;
        uVar9 = FUN_0219f938(*(undefined4 *)(iVar7 + 0xf4));
        puVar4 = (undefined *)((ulonglong)uVar9 >> 0x20);
        if ((int)uVar9 == 0) {
          return;
        }
      }
    }
    break;
  case 0xb:
    if (*(char *)(iVar7 + DAT_021a229c) != '\x02') break;
    uVar2 = (uint)*(byte *)(iVar7 + 0x15);
    if (uVar2 == 0) {
      lVar10 = FUN_021a350c();
      lVar10 = lVar10 - CONCAT44(*(undefined4 *)(*DAT_021a2258 + DAT_021a22a4),
                                 *(undefined4 *)(*DAT_021a2258 + DAT_021a22a0));
      uVar6 = (uint)lVar10;
      puVar4 = (undefined *)((ulonglong)lVar10 >> 0x20);
      uVar2 = DAT_021a22a8 - uVar6;
      iVar7 = -(uint)(uVar6 > DAT_021a22a8) - (int)puVar4;
      if ((uint)-(int)puVar4 < (uint)(uVar6 <= DAT_021a22a8)) goto LAB_021a21d2;
    }
    else {
LAB_021a21d2:
      lVar10 = FUN_021a350c(uVar2);
      lVar10 = lVar10 - CONCAT44(*(undefined4 *)(*DAT_021a2258 + DAT_021a22a4),
                                 *(undefined4 *)(*DAT_021a2258 + DAT_021a22a0));
      uVar6 = (uint)lVar10;
      puVar4 = (undefined *)((ulonglong)lVar10 >> 0x20);
      uVar2 = DAT_021a22c4 - uVar6;
      iVar7 = -(uint)(uVar6 > DAT_021a22c4) - (int)puVar4;
      if ((uint)-(int)puVar4 < (uint)(uVar6 <= DAT_021a22c4)) break;
    }
    FUN_021a1ac0(uVar2,puVar4,iVar7);
    uVar9 = FUN_0219f9bc(*(undefined4 *)
                          (*DAT_021a2258 + (*(byte *)(*DAT_021a2258 + 0xd) + 1) * 4 + 0xf4));
    puVar4 = (undefined *)((ulonglong)uVar9 >> 0x20);
    if ((int)uVar9 == 0) {
      return;
    }
    break;
  case 0xd:
    if (*(char *)(iVar7 + DAT_021a229c) == '\b') {
      lVar10 = FUN_021a350c();
      iVar5 = DAT_021a22ac;
      lVar10 = lVar10 - CONCAT44(*(undefined4 *)(iVar7 + DAT_021a22a4),
                                 *(undefined4 *)(iVar7 + DAT_021a22a0));
      puVar4 = (undefined *)((ulonglong)lVar10 >> 0x20);
      if ((uint)((uint)lVar10 <= DAT_021a22c8) <= (uint)-(int)puVar4) {
        *(char *)(iVar7 + DAT_021a22ac) = *(char *)(iVar7 + DAT_021a22ac) + '\x01';
        iVar7 = *DAT_021a2258;
        if (*(char *)(iVar7 + iVar5) == '\0') {
          FUN_021a0ae8(8,*(undefined4 *)(iVar7 + DAT_021a2438),*(undefined4 *)(iVar7 + DAT_021a243c)
                       ,*(undefined2 *)(iVar7 + DAT_021a2440),(undefined4 *)(uintptr_t)(iVar7 + DAT_021a2430),
                       *(undefined4 *)(iVar7 + DAT_021a2434));
          uVar9 = FUN_0219fee4();
          puVar4 = (undefined *)((ulonglong)uVar9 >> 0x20);
          if ((int)uVar9 != 0) {
            return;
          }
        }
        else {
          FUN_021a1ac0();
          iVar7 = *DAT_021a2258;
          if (*(char *)(iVar7 + 0x15) == '\x02') {
            uVar9 = FUN_0219f9bc(*(undefined4 *)(iVar7 + (uint)*(byte *)(iVar7 + 0xd) * 4 + 0xf4));
            puVar4 = (undefined *)((ulonglong)uVar9 >> 0x20);
            if ((int)uVar9 == 0) {
              return;
            }
          }
          else {
            FUN_0219f214();
            puVar4 = extraout_r1;
          }
        }
      }
    }
  }
switchD_021a1f5a_caseD_1:
  iVar7 = *DAT_021a2444;
  if (((*(int *)(iVar7 + DAT_021a2448) == 0xb) || (*(int *)(iVar7 + DAT_021a2448) == 6)) &&
     (puVar4 = (undefined *)(*(uint *)(iVar7 + DAT_021a2450) | *(uint *)(iVar7 + DAT_021a244c)),
     puVar4 != (undefined *)0x0)) {
    lVar10 = FUN_021a350c();
    lVar10 = lVar10 - CONCAT44(*(undefined4 *)(iVar7 + DAT_021a2450),
                               *(undefined4 *)(iVar7 + DAT_021a244c));
    puVar4 = (undefined *)((ulonglong)lVar10 >> 0x20);
    if ((uint)((uint)lVar10 <= DAT_021a2454) <= (uint)-(int)puVar4) {
      FUN_0219db18(1,0,0,iVar7 + DAT_021a2458);
      puVar4 = extraout_r1_00;
    }
  }
  if (*(int *)(*DAT_021a2444 + 0xe4) != 0) {
    FUN_0218b4bc(*(int *)(*DAT_021a2444 + 0xe4),puVar4);
  }
  if (*(int *)(*DAT_021a2444 + 0x10) != 0) {
    FUN_021a49a0();
    iVar7 = *DAT_021a2444;
    if ((((*(int *)(*(int *)(iVar7 + 0x10) + 0xb4) == 0) &&
         ((*(char *)(iVar7 + 0x15) == '\0' || (*(char *)(iVar7 + 0x15) == '\x01')))) &&
        ((iVar5 = *(int *)(iVar7 + DAT_021a2448), iVar5 == 1 ||
         (((iVar5 == 2 || (iVar5 == 3)) || ((iVar5 == 4 || ((iVar5 == 6 || (iVar5 == 0xb))))))))))
       || ((*(char *)(iVar7 + 0x15) == '\x02' && (*(int *)(iVar7 + DAT_021a2448) == 0xb)))) {
      FUN_021a4818();
    }
  }
  FUN_0219aaec();
  if (*(undefined4 **)(*DAT_021a2444 + 4) != (undefined4 *)0x0) {
    FUN_02198a8c(**(undefined4 **)(*DAT_021a2444 + 4));
  }
  if (*(int *)(*DAT_021a2444 + DAT_021a2448) == 0x12) {
    lVar10 = FUN_021a350c();
    lVar10 = lVar10 - CONCAT44(*(undefined4 *)(*DAT_021a2444 + DAT_021a2460),
                               *(undefined4 *)(*DAT_021a2444 + DAT_021a245c));
    uVar2 = (uint)lVar10;
    iVar7 = (int)((ulonglong)lVar10 >> 0x20);
    if (((uint)(uVar2 <= DAT_021a2464) <= (uint)-iVar7) &&
       (iVar7 = FUN_0219f184(DAT_021a2464 - uVar2,iVar7,-(uint)(uVar2 > DAT_021a2464) - iVar7),
       iVar7 != 0)) {
      return;
    }
  }
  iVar7 = FUN_0219ee14();
  if ((iVar7 != 0) && (iVar7 = FUN_0219eaf4(), iVar7 != 0)) {
    FUN_0219e668();
  }
  return;
}

