/* Decompiled C draft; module arm9_ov003; ROM address 021bd338. No matching claim. */
#include "types.h"
#include "deps/021bd338_FUN_021bd338.h"

/* WARNING: Removing unreachable block (ram,0x021bd3ca) */

undefined4 FUN_021bd338(void)

{
  undefined1 uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  int iVar7;
  undefined1 *puVar8;
  undefined4 *puVar9;
  undefined1 *puVar10;
  undefined4 *puVar11;
  int iVar12;
  undefined4 local_48;
  int local_44;
  undefined1 local_38 [4];
  undefined1 local_34;
  undefined1 local_18;
  
  local_48 = 1;
  func_0x0213a2d0((uint *)(uintptr_t)(DAT_021bd4b4),DAT_021bd4b8);
  iVar7 = DAT_021bd4b4;
  switch(*(undefined4 *)(DAT_021bd4b8 + 0x2c)) {
  case 0:
    *(undefined4 *)(DAT_021bd4b4 + 0x20) = 0;
    break;
  case 1:
    if (*(int *)(DAT_021bd4b8 + 0x30) == 0) {
      local_48 = 0xfffffff9;
    }
    else {
      *(int *)(DAT_021bd4b4 + 0x24) = *(int *)(DAT_021bd4b8 + 0x30);
      local_44 = 0;
      puVar10 = DAT_021bd4c0;
      iVar12 = DAT_021bd4bc;
      do {
        func_0x02134eb8((uint *)(void *)(local_38),iVar12,0x20);
        local_18 = 0;
        uVar2 = func_0x0213a434(local_38);
        if (uVar2 < 0x11) {
          if (uVar2 < 10) {
            if (uVar2 != 0) {
              if (uVar2 != 5) goto LAB_021bd460;
              *(undefined4 *)(iVar7 + 0x20) = 1;
              *puVar10 = local_38[0];
              puVar10[1] = local_38[1];
              puVar10[2] = local_38[2];
              puVar10[3] = local_38[3];
              puVar10[4] = local_34;
            }
          }
          else if (uVar2 == 10) {
            *(undefined4 *)(iVar7 + 0x20) = 1;
            FUN_021bd4cc((int)(uintptr_t)(puVar10),(int)(uintptr_t)(local_38),10);
          }
          else if (uVar2 == 0xd) {
            *(undefined4 *)(iVar7 + 0x20) = 2;
            iVar4 = 0xd;
            puVar6 = puVar10;
            puVar8 = local_38;
            do {
              uVar1 = *puVar8;
              puVar8 = puVar8 + 1;
              *puVar6 = uVar1;
              puVar6 = puVar6 + 1;
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
          else {
            if (uVar2 != 0x10) goto LAB_021bd460;
            *(undefined4 *)(iVar7 + 0x20) = 3;
            iVar4 = 0x10;
            puVar6 = puVar10;
            puVar8 = local_38;
            do {
              uVar1 = *puVar8;
              puVar8 = puVar8 + 1;
              *puVar6 = uVar1;
              puVar6 = puVar6 + 1;
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
        }
        else if (uVar2 < 0x1b) {
          if (uVar2 == 0x1a) {
            *(undefined4 *)(iVar7 + 0x20) = 2;
            FUN_021bd4cc((int)(uintptr_t)(puVar10),(int)(uintptr_t)(local_38),0x1a);
          }
          else {
LAB_021bd460:
            local_48 = 0xfffffff9;
          }
        }
        else {
          if (uVar2 != 0x20) goto LAB_021bd460;
          *(undefined4 *)(iVar7 + 0x20) = 3;
          FUN_021bd4cc((int)(uintptr_t)(puVar10),(int)(uintptr_t)(local_38),0x20);
        }
        iVar12 = iVar12 + 0x28;
        puVar10 = puVar10 + 0x20;
        local_44 = local_44 + 1;
      } while (local_44 < 4);
    }
    break;
  case 2:
    *(undefined4 *)(DAT_021bd4b4 + 0x20) = 4;
    iVar7 = 8;
    puVar9 = DAT_021bd4c8;
    puVar11 = DAT_021bd4c4;
    do {
      uVar3 = *puVar9;
      uVar5 = puVar9[1];
      puVar9 = puVar9 + 2;
      *puVar11 = uVar3;
      puVar11[1] = uVar5;
      puVar11 = puVar11 + 2;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    break;
  case 3:
    *(undefined4 *)(DAT_021bd4b4 + 0x20) = 5;
    iVar7 = 8;
    puVar9 = DAT_021bd4c8;
    puVar11 = DAT_021bd4c4;
    do {
      uVar3 = *puVar9;
      uVar5 = puVar9[1];
      puVar9 = puVar9 + 2;
      *puVar11 = uVar3;
      puVar11[1] = uVar5;
      puVar11 = puVar11 + 2;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    break;
  default:
    local_48 = 0xfffffff9;
  }
  return local_48;
}

