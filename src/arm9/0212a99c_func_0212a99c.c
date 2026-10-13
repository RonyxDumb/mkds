/* Decompiled C draft; module arm9; ROM address 0212a99c. No matching claim. */
#include "types.h"
#include "deps/0212a99c_func_0212a99c.h"

void func_0212a99c(void)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  bool bVar8;
  
  piVar3 = piRam0212aa94;
  iVar4 = 0;
  iVar2 = 0;
  do {
    *(undefined4 *)(*piVar3 + iVar2 + 0x14) = 0xffffffff;
    *(undefined4 *)(*piVar3 + iVar2 + 0x1c) = 0;
    iVar2 = iVar2 + 4;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 2);
  bVar8 = *(int *)(*piVar3 + 4) != 0;
  if (bVar8) {
    *(undefined4 *)(*piVar3 + 0x14) = 1;
    uVar1 = func_021205e8();
    *(undefined4 *)(*piRam0212aa94 + 0x1c) = uVar1;
  }
  uVar7 = (uint)bVar8;
  piVar3 = (int *)*piRam0212aa94;
  if (*piVar3 == 0) {
    if (piVar3[4] != 0) {
      bVar8 = false;
      if ((-1 < (int)((uint)*(byte *)(*(int *)*puRam0212aa9c + 0x31) << 0x1b)) &&
         (iVar2 = func_021213f4(), iVar2 != 0)) {
        bVar8 = true;
      }
      if (bVar8) {
        *(undefined4 *)(*piRam0212aa94 + uVar7 * 4 + 0x14) = 4;
      }
    }
  }
  else {
    uVar1 = 0;
    piVar3[uVar7 + 5] = 0;
    if (*(int *)(*piRam0212aa98 + 4) != 0) {
      uVar1 = func_021431d8();
    }
    *(undefined4 *)(*piRam0212aa94 + uVar7 * 4 + 0x1c) = uVar1;
  }
  iVar2 = 0;
  iVar4 = 0;
  do {
    iVar6 = *piRam0212aa94;
    iVar5 = *(int *)(iVar6 + iVar4 + 0x14);
    if (iVar5 == -1) {
      AllocateReserveTEQSub(0x13,(iRam0212aaa0 + (iVar2 + 1) * -4) * 0x20,iVar6 + 0x3c,0x80);
    }
    else {
      AllocateReserveTEQSub
                (0x13,(iRam0212aaa0 + (iVar2 + 1) * -4) * 0x20,
                 *(undefined4 *)(*(int *)(iVar6 + iVar4 + 0x1c) * 4 + iVar6 + iVar5 * 0x10 + 0xbc),
                 0x80);
    }
    iVar4 = iVar4 + 4;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 2);
  return;
}

