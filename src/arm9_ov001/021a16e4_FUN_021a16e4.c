/* Decompiled C draft; module arm9_ov001; ROM address 021a16e4. No matching claim. */
#include "types.h"
#include "deps/021a16e4_FUN_021a16e4.h"

void FUN_021a16e4(void)

{
  undefined2 uVar1;
  int *piVar2;
  short sVar3;
  int iVar4;
  ushort *puVar5;
  ushort *puVar6;
  int iVar7;
  ushort *local_2c;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  
  piVar2 = DAT_021a180c;
  *(int *)(*DAT_021a180c + 0x2c) = *(int *)(*DAT_021a180c + 0x2c) + 1;
  sVar3 = func_0x020ae4c0(1,0xe0,0,*(undefined4 *)(*piVar2 + 0x2c),10);
  iVar4 = func_0x020ae4c0(1,0xffffff40,0,*(undefined4 *)(*DAT_021a180c + 0x2c),10);
  piVar2 = DAT_021a180c;
  *(int *)(*DAT_021a180c + 0x30) = -iVar4;
  iVar7 = 0;
  puVar5 = DAT_021a1810;
  do {
    uVar1 = (undefined2)-iVar4;
    *(undefined2 *)(*(int *)(*piVar2 + 0x14) + (uint)*puVar5 * 0x40 + 6) = uVar1;
    puVar5 = puVar5 + 1;
    iVar7 = iVar7 + 1;
  } while (iVar7 < 6);
  *(short *)(*(int *)(*piVar2 + 0x14) + DAT_021a1814) = (short)iVar4;
  piVar2 = DAT_021a180c;
  local_24 = 0;
  local_2c = DAT_021a1818;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  puVar5 = DAT_021a181c;
  do {
    *(undefined2 *)(*(int *)(*piVar2 + 0x14) + (uint)*local_2c * 0x40 + 6) = uVar1;
    iVar7 = func_0x02056dec(0x10);
    iVar4 = local_18;
    puVar6 = puVar5;
    if (iVar7 == 0) {
      do {
        *(short *)(*(int *)(*piVar2 + 0x18) + (uint)*puVar6 * 0x40 + 4) = sVar3;
        iVar4 = iVar4 + 1;
        puVar6 = puVar6 + 1;
      } while (iVar4 < 3);
    }
    else {
      switch(local_24) {
      case 0:
      case 2:
        iVar4 = local_20;
        do {
          *(short *)(*(int *)(*piVar2 + 0x18) + (uint)*puVar6 * 0x40 + 4) = -sVar3;
          puVar6 = puVar6 + 1;
          iVar4 = iVar4 + 1;
        } while (iVar4 < 3);
        break;
      case 1:
      case 3:
        iVar4 = local_1c;
        do {
          *(short *)(*(int *)(*piVar2 + 0x18) + (uint)*puVar6 * 0x40 + 4) = sVar3;
          puVar6 = puVar6 + 1;
          iVar4 = iVar4 + 1;
        } while (iVar4 < 3);
      }
    }
    local_2c = local_2c + 1;
    puVar5 = puVar5 + 3;
    local_24 = local_24 + 1;
  } while (local_24 < 4);
  if (9 < *(int *)(*DAT_021a180c + 0x2c)) {
    FUN_021a19dc();
  }
  return;
}

