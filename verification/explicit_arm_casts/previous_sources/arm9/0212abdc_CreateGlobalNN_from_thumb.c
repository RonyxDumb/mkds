/* Decompiled C draft; module arm9; ROM address 0212abdc. No matching claim. */
#include "types.h"
#include "deps/0212abdc_CreateGlobalNN_from_thumb.h"

void CreateGlobalNN_from_thumb(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar2 = Mem_AllocateHeap(param_1,DAT_0212ad08);
  piVar1 = DAT_0212ad0c;
  *DAT_0212ad0c = iVar2;
  *(undefined4 *)(iVar2 + 0x38) = param_2;
  Mem_CpuFill8(*piVar1 + 0x3c,0,0x20);
  piVar1 = DAT_0212ad0c;
  iVar6 = 0;
  *(undefined4 *)(*DAT_0212ad0c + 0x24) = 0;
  iVar2 = 0;
  do {
    *(undefined4 *)(*piVar1 + iVar2) = 0;
    iVar2 = iVar2 + 4;
    iVar6 = iVar6 + 1;
  } while (iVar6 < 5);
  uVar3 = GetCurrentSceneId();
  piVar1 = DAT_0212ad0c;
  switch(uVar3) {
  case 1:
    if (*(int *)(*DAT_0212ad10 + 0x20) - 1U < 2) {
      *(undefined4 *)*DAT_0212ad0c = 1;
    }
    break;
  case 6:
  case 0xd:
    *(undefined4 *)*DAT_0212ad0c = 1;
    break;
  case 8:
    if (*(int *)(*DAT_0212ad10 + 0x20) == 3) {
      *(undefined4 *)(*DAT_0212ad0c + 4) = 1;
      *(undefined4 *)(*piVar1 + 0x10) = 1;
    }
    break;
  case 10:
    if (*(int *)(*DAT_0212ad10 + 0x20) == 3) {
      *(undefined4 *)(*DAT_0212ad0c + 4) = 1;
      *(undefined4 *)(*piVar1 + 0x10) = 1;
    }
    else if (*(int *)(*DAT_0212ad10 + 0x20) - 1U < 2) {
      *(undefined4 *)*DAT_0212ad0c = 1;
    }
    break;
  case 0xc:
    *(undefined4 *)(*DAT_0212ad0c + 0x10) = 1;
  }
  piVar1 = DAT_0212ad0c;
  iVar2 = 0;
  iVar6 = 0;
  do {
    *(undefined4 *)(*piVar1 + iVar6 + 0x14) = 0xffffffff;
    iVar6 = iVar6 + 4;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 2);
  func_0212aaa4();
  piVar1 = DAT_0212ad0c;
  iVar2 = 0;
  iVar6 = 0;
  do {
    iVar5 = *piVar1 + DAT_0212ad14;
    iVar4 = *piVar1 + iVar6;
    *(uint *)(iVar5 + iVar6) =
         (*(uint *)(iVar4 + 0x28) & DAT_0212ad18) << 0x10 |
         *(uint *)(iVar4 + 0x2c) & 0xff | DAT_0212ad1c;
    iVar2 = iVar2 + 1;
    *(ushort *)(iVar5 + iVar6 + 4) = (short)DAT_0212ad20 + (short)iVar2 * -4 | (ushort)DAT_0212ad24;
    iVar6 = iVar6 + 8;
  } while (iVar2 < 2);
  return;
}

