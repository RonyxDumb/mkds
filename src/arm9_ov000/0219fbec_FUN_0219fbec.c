/* Decompiled C draft; module arm9_ov000; ROM address 0219fbec. No matching claim. */
#include "types.h"
#include "deps/0219fbec_FUN_0219fbec.h"

void FUN_0219fbec(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  bool bVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined8 uVar12;
  uint local_248;
  undefined1 auStack_23c [2];
  undefined1 auStack_23a [6];
  undefined4 local_234;
  undefined1 auStack_230 [12];
  undefined1 auStack_224 [4];
  int local_220;
  undefined1 auStack_21c [520];
  
  iVar11 = DAT_0219fd98;
  piVar3 = DAT_0219fd94;
  if (param_2 == 0) {
    local_248 = (uint)*(byte *)(*DAT_0219fd94 + DAT_0219fd98);
    if ((int)local_248 < *(int *)(*DAT_0219fd94 + DAT_0219fd9c) + -1) {
      local_248 = local_248 + 1;
    }
    else {
      local_248 = 0;
    }
  }
  else {
    local_248 = (uint)*(byte *)(*DAT_0219fd94 + DAT_0219fd98);
  }
  bVar2 = false;
  do {
    do {
      do {
        if ((param_2 == 0) || (bVar2)) {
          *(char *)(*piVar3 + iVar11) = *(char *)(*piVar3 + iVar11) + '\x01';
          iVar9 = *piVar3;
          if (*(int *)(iVar9 + DAT_0219fd9c) <= (int)(uint)*(byte *)(iVar9 + iVar11)) {
            *(undefined1 *)(iVar9 + iVar11) = 0;
          }
        }
        if ((bVar2) && (*(byte *)(*piVar3 + iVar11) == local_248)) {
          *(undefined4 *)(*piVar3 + DAT_0219fda4) = DAT_0219fda0;
          iVar11 = *piVar3;
          uVar12 = func_0x0200f5ac();
          *(int *)(iVar11 + DAT_0219fda8) = (int)uVar12;
          *(int *)(iVar11 + DAT_0219fdac) = (int)((ulonglong)uVar12 >> 0x20);
          *(undefined4 *)(iVar11 + DAT_0219fdb0) = 0;
          return;
        }
        bVar2 = true;
        iVar9 = *piVar3;
        uVar4 = FUN_0219c9c4();
        iVar9 = func_0x02152520(uVar4,*(int *)(iVar9 + DAT_0219fdb4) +
                                      (uint)*(byte *)(iVar9 + (uint)*(byte *)(iVar9 + iVar11) +
                                                     DAT_0219fdb8) * 0xc);
      } while ((iVar9 == 0) || (iVar9 == -1));
      iVar10 = *piVar3;
      iVar10 = func_0x02152698(*(int *)(iVar10 + DAT_0219fdb4) +
                               (uint)*(byte *)(iVar10 + (uint)*(byte *)(iVar10 + iVar11) +
                                              DAT_0219fdb8) * 0xc);
    } while (iVar10 == 0);
    iVar10 = 1;
    puVar5 = (undefined4 *)*piVar3;
    puVar1 = puVar5;
    if (*(byte *)((int)puVar5 + 0xd) != 0) {
      do {
        if (iVar9 == puVar1[0x3e]) break;
        iVar10 = iVar10 + 1;
        puVar1 = puVar1 + 1;
      } while (iVar10 <= (int)(uint)*(byte *)((int)puVar5 + 0xd));
    }
    if ((int)(uint)*(byte *)((int)puVar5 + 0xd) < iVar10) {
      iVar10 = FUN_0218ebe8((int *)(uintptr_t)(*puVar5),iVar9,&local_234);
      iVar6 = FUN_0218ec44((int *)(uintptr_t)(*(undefined4 *)*piVar3),local_234,(undefined4 *)(void *)(auStack_224));
      if ((iVar10 == 0 && iVar6 == 0) && (local_220 == 4)) {
        iVar10 = FUN_021a3530(DAT_0219fdbc,(int)(uintptr_t)(auStack_230),(undefined4)(uintptr_t)(auStack_21c),0x2f);
        iVar6 = FUN_021a3530(DAT_0219fdc0,(int)(uintptr_t)(auStack_23a),(undefined4)(uintptr_t)(auStack_21c),0x2f);
        iVar7 = FUN_021a3530(DAT_0219fdc4,(int)(uintptr_t)(auStack_23c),(undefined4)(uintptr_t)(auStack_21c),0x2f);
        if (((0 < iVar10) &&
            (((0 < iVar6 && (0 < iVar7)) &&
             (iVar10 = func_0x0213c074((int)(uintptr_t)(auStack_230),0,10), iVar10 == 3)))) &&
           (uVar8 = func_0x0213c074((int)(uintptr_t)(auStack_23a),0,10), *(byte *)(*piVar3 + 0x16) == uVar8)) {
          FUN_0219fdc8(iVar9,param_1);
          return;
        }
      }
    }
  } while( true );
}

