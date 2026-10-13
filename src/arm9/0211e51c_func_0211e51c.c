/* Decompiled C draft; module arm9; ROM address 0211e51c. No matching claim. */
#include "types.h"
#include "deps/0211e51c_func_0211e51c.h"

undefined4 func_0211e51c(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  
  piVar1 = piRam0211e650;
  *(undefined4 *)(*piRam0211e650 + 0x2c) = *(undefined4 *)(*piRam0211e650 + 0x30);
  if (*(int *)(*piVar1 + 0x2c) == 0) {
    func_0211e7c0();
  }
  else if (*(int *)(*piVar1 + 0x2c) == 1) {
    func_0211e65c();
  }
  if (*psRam0211e654 == 2) {
    func_0211f39c();
  }
  else {
    if ((*(int *)(*piRam0211e650 + 0x38) != 0) && (iVar2 = func_020d0ec4(), iVar2 != 0)) {
      iVar2 = func_020d0e58();
      uVar3 = func_020d0ea0();
      AllocateReserveTEQSub(0xf,0,uVar3,0xe0);
      uVar3 = func_020d0e7c();
      AllocateReserveTEQSub(4,0x20,uVar3,uRam0211e658);
      iVar6 = 0;
      do {
        iVar4 = ((iVar6 + 8) * 0x20 + 0x16) * 2;
        AllocateReserveTEQSub(8,iVar4,iVar2 + iVar4,0x14);
        iVar6 = iVar6 + 1;
      } while (iVar6 < 0xb);
      uVar3 = func_020d0ea0();
      AllocateReserveTEQSub(0x1f,0,uVar3,0xe0);
      uVar3 = func_020d0e7c();
      AllocateReserveTEQSub(0x17,0x20,uVar3,uRam0211e658);
      iVar6 = 0;
      do {
        iVar4 = ((iVar6 + 8) * 0x20 + 0x16) * 2;
        AllocateReserveTEQSub(0x1b,iVar4,iVar2 + iVar4,0x14);
        iVar6 = iVar6 + 1;
      } while (iVar6 < 0xb);
      *(undefined4 *)(*piRam0211e650 + 0x38) = 0;
    }
    puVar5 = (undefined4 *)*piRam0211e650;
    func_02124c30(puVar5[1],*puVar5,puVar5[2],puVar5[0x12],puVar5[6]);
    iVar2 = *piRam0211e650;
    func_02124c30(*(undefined4 *)(iVar2 + 0x10),*(undefined4 *)(iVar2 + 0xc),
                  *(undefined4 *)(iVar2 + 0x14),*(undefined4 *)(iVar2 + 0x4c),
                  *(undefined4 *)(iVar2 + 0x1c));
  }
  iVar2 = *piRam0211e650;
  if ((*(int *)(iVar2 + 0x2c) == 0) && (10 < *(int *)(iVar2 + 0x34))) {
    return 1;
  }
  if ((*(int *)(iVar2 + 0x2c) == 1) && (10 < *(int *)(iVar2 + 0x34))) {
    return 2;
  }
  return 0;
}

