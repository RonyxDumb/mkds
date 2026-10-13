/* Decompiled C draft; module arm9_ov001; ROM address 021a1a04. No matching claim. */
#include "types.h"
#include "deps/021a1a04_FUN_021a1a04.h"

void FUN_021a1a04(void)

{
  int *piVar1;
  int iVar2;
  ushort *puVar3;
  ushort *puVar4;
  int iVar5;
  ushort *local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  
  piVar1 = DAT_021a1af4;
  iVar5 = 0;
  *(undefined4 *)(*DAT_021a1af4 + 0x28) = 0;
  *(undefined4 *)(*piVar1 + 0x2c) = 0;
  *(undefined4 *)(*piVar1 + 0x30) = 0xc0;
  puVar4 = DAT_021a1af8;
  do {
    *(undefined2 *)(*(int *)(*piVar1 + 0x14) + (uint)*puVar4 * 0x40 + 6) = 0xc0;
    puVar4 = puVar4 + 1;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 6);
  *(undefined2 *)(*(int *)(*piVar1 + 0x14) + DAT_021a1afc) = 0xff40;
  piVar1 = DAT_021a1af4;
  local_24 = 0;
  local_28 = DAT_021a1b00;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  puVar4 = DAT_021a1b04;
  do {
    *(undefined2 *)(*(int *)(*piVar1 + 0x14) + (uint)*local_28 * 0x40 + 6) = 0xc0;
    iVar2 = func_0x02056dec(0x10);
    iVar5 = local_18;
    puVar3 = puVar4;
    if (iVar2 == 0) {
      do {
        *(undefined2 *)(*(int *)(*piVar1 + 0x18) + (uint)*puVar3 * 0x40 + 4) = 0xe0;
        iVar5 = iVar5 + 1;
        puVar3 = puVar3 + 1;
      } while (iVar5 < 3);
    }
    else {
      switch(local_24) {
      case 0:
      case 2:
        iVar5 = local_20;
        do {
          *(undefined2 *)(*(int *)(*piVar1 + 0x18) + (uint)*puVar3 * 0x40 + 4) = 0xff20;
          puVar3 = puVar3 + 1;
          iVar5 = iVar5 + 1;
        } while (iVar5 < 3);
        break;
      case 1:
      case 3:
        iVar5 = local_1c;
        do {
          *(undefined2 *)(*(int *)(*piVar1 + 0x18) + (uint)*puVar3 * 0x40 + 4) = 0xe0;
          puVar3 = puVar3 + 1;
          iVar5 = iVar5 + 1;
        } while (iVar5 < 3);
      }
    }
    local_28 = local_28 + 1;
    puVar4 = puVar4 + 3;
    local_24 = local_24 + 1;
  } while (local_24 < 4);
  return;
}

