/* Decompiled C draft; module arm9_ov003; ROM address 021be028. No matching claim. */
#include "types.h"
#include "deps/021be028_FUN_021be028.h"

bool FUN_021be028(uint *param_1,uint *param_2,uint *param_3)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined1 *puVar9;
  uint *puVar10;
  uint *puVar11;
  uint uVar12;
  uint uVar13;
  uint local_68;
  uint local_60;
  undefined1 local_58 [34];
  undefined1 local_36 [34];
  
  bVar1 = false;
  puVar11 = param_1 + 1;
  local_68 = 0;
  if (*param_1 != 0) {
    local_60 = 0;
    do {
      puVar10 = param_2 + 1;
      puVar9 = local_58;
      iVar8 = 0x22;
      do {
        *puVar9 = 0;
        puVar9 = puVar9 + 1;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
      func_0x02134eb8(local_58,puVar11 + 1,0x20);
      local_58[*puVar11] = 0;
      uVar4 = *param_2;
      if (uVar4 != 0) {
        uVar12 = *puVar11;
        uVar13 = local_60;
        do {
          if (((uVar12 == 0) || (0x20 < uVar12)) ||
             ((uVar12 == 1 && (((char)puVar11[1] == '\0' || ((char)puVar11[1] == ' ')))))) break;
          uVar5 = func_0x0213a434(local_58);
          iVar8 = func_0x02134d30(local_58,puVar10 + 1,uVar5);
          if ((iVar8 == 0) &&
             (((iVar8 = func_0x02134d30(puVar11 + 10,puVar10 + 10,4), iVar8 == 0 &&
               (*(short *)((int)puVar11 + 0x2e) != *(short *)((int)puVar10 + 0x2e))) &&
              (*(short *)((int)puVar11 + 0x2e) == 0)))) {
            bVar1 = true;
            break;
          }
          puVar10 = puVar10 + 0xc;
          uVar13 = uVar13 + 1;
        } while (uVar13 < uVar4);
      }
      if (bVar1) break;
      puVar11 = puVar11 + 0xc;
      local_68 = local_68 + 1;
    } while (local_68 < *param_1);
  }
  if (!bVar1) {
    puVar9 = local_36;
    iVar8 = 0x22;
    do {
      *puVar9 = 0;
      puVar9 = puVar9 + 1;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    bVar2 = false;
    bVar3 = false;
    puVar10 = param_1 + 1;
    puVar11 = param_2 + 1;
    uVar4 = 0;
    if (*param_2 != 0) {
      do {
        func_0x02134eb8(local_36,puVar11 + 1,0x20);
        local_36[*puVar11] = 0;
        uVar5 = func_0x0213a434(DAT_021be1f8);
        iVar8 = func_0x02134d30(local_36,DAT_021be1f8,uVar5);
        if ((iVar8 == 0) && (*(short *)((int)puVar11 + 0x2e) == 0)) {
          bVar3 = true;
          break;
        }
        puVar11 = puVar11 + 0xc;
        uVar4 = uVar4 + 1;
      } while (uVar4 < *param_2);
    }
    uVar5 = DAT_021be1f8;
    local_68 = 0;
    if (*param_1 != 0) {
      do {
        func_0x02134eb8(local_36,puVar10 + 1,0x20);
        local_36[*puVar10] = 0;
        iVar8 = func_0x0213a434(local_36);
        iVar6 = func_0x0213a434(uVar5);
        if (iVar8 == iVar6) {
          uVar7 = func_0x0213a434(uVar5);
          iVar8 = func_0x02134d30(local_36,uVar5,uVar7);
          if ((iVar8 == 0) && (*(short *)((int)puVar10 + 0x2e) == 0)) {
            bVar2 = true;
            break;
          }
        }
        puVar10 = puVar10 + 0xc;
        local_68 = local_68 + 1;
      } while (local_68 < *param_1);
    }
    if ((bVar2) && (!bVar3)) {
      bVar1 = true;
    }
  }
  if (bVar1) {
    *param_3 = local_68;
  }
  return bVar1;
}

