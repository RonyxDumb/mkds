/* Decompiled C draft; module arm9; ROM address 0212aaa4. No matching claim. */
#include "types.h"
#include "deps/0212aaa4_func_0212aaa4.h"

void func_0212aaa4(void)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined2 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  undefined1 *puVar12;
  byte *pbVar13;
  int local_40;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  
  puVar2 = (undefined4 *)GetGlobal2DObject();
  uVar6 = *puVar2;
  uVar7 = puVar2[1];
  iVar8 = puVar2[2];
  uVar9 = puVar2[3];
  iVar3 = puVar2[4];
  local_40 = 0;
  local_28 = iRam0212abb8;
  local_24 = 0;
  local_1c = 0;
  pbVar13 = pbRam0212abbc;
  do {
    iVar10 = local_1c;
    iVar11 = local_1c;
    if (*pbVar13 != 0) {
      do {
        iVar4 = func_0212497c(*(undefined1 *)(local_28 + iVar10),uVar9,uVar6);
        *(int *)(iVar11 + local_24 + *piRam0212abc0 + 0xbc) = *(int *)(iVar8 + 0x14) + iVar4 * 0x20;
        iVar10 = iVar10 + 1;
        iVar11 = iVar11 + 4;
      } while (iVar10 < (int)(uint)*pbVar13);
    }
    local_28 = local_28 + 4;
    local_24 = local_24 + 0x10;
    pbVar13 = pbVar13 + 1;
    local_40 = local_40 + 1;
  } while (local_40 < 5);
  local_20 = 0;
  iVar8 = 0;
  puVar12 = puRam0212abc4;
  do {
    puVar5 = (undefined2 *)func_0201ea30(uVar7,*puVar12);
    uVar6 = func_0201ebe8(*puVar5,0x10);
    *(undefined4 *)(*piRam0212abc0 + iVar8 + 0x28) = uVar6;
    uVar6 = func_0201eba0(puVar5[1],0x10);
    *(undefined4 *)(*piRam0212abc0 + iVar8 + 0x2c) = uVar6;
    iVar10 = iRam0212abc8;
    piVar1 = piRam0212abc0;
    puVar12 = puVar12 + 1;
    iVar8 = iVar8 + 8;
    local_20 = local_20 + 1;
  } while (local_20 < 2);
  iVar8 = 0;
  do {
    AllocateReserveTEQSub(0x13,(iVar10 + (iVar8 + 1) * -4) * 0x20,*piVar1 + 0x3c,0x80);
    iVar8 = iVar8 + 1;
  } while (iVar8 < 2);
  AllocateReserveTEQSub(0xe,iRam0212abcc,*(int *)(iVar3 + 0xc) + iRam0212abcc,0x20);
  return;
}

