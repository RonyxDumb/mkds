/* Decompiled C draft; module arm9; ROM address 02117418. No matching claim. */
#include "types.h"
#include "deps/02117418_func_02117418.h"

undefined4 func_02117418(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  
  piVar1 = DAT_02117560;
  *(undefined4 *)(*DAT_02117560 + 0x30) = *(undefined4 *)(*DAT_02117560 + 0x34);
  switch(*(undefined4 *)(*piVar1 + 0x30)) {
  case 0:
    func_02117d98();
    break;
  case 1:
    func_02117bf8();
    break;
  case 2:
    func_02117be0();
    break;
  case 3:
    func_021178b0();
    break;
  case 4:
    func_0211784c();
    break;
  case 5:
    func_02117830();
    break;
  case 6:
    func_02117814();
    break;
  case 7:
    func_021177c0();
    break;
  case 8:
    func_021177a4();
    break;
  case 9:
    func_0211775c();
    break;
  case 10:
    func_02117700();
    break;
  case 0xb:
    func_0211756c();
  }
  func_02118814();
  func_02118458();
  if (*DAT_02117564 == 2) {
    func_0211f39c();
  }
  else {
    if ((*(int *)(*DAT_02117560 + 0x7c) != 0) && (iVar2 = func_020d0ec4(), iVar2 != 0)) {
      iVar2 = func_020d0e58();
      uVar3 = func_020d0ea0();
      AllocateReserveTEQSub(0xf,0,uVar3,0xe0);
      uVar3 = func_020d0e7c();
      AllocateReserveTEQSub(4,0x20,uVar3,DAT_02117568);
      iVar6 = 0;
      do {
        iVar4 = ((iVar6 + 8) * 0x20 + 0x16) * 2;
        AllocateReserveTEQSub(8,iVar4,iVar2 + iVar4,0x14);
        iVar6 = iVar6 + 1;
      } while (iVar6 < 0xb);
      *(undefined4 *)(*DAT_02117560 + 0x7c) = 0;
    }
    puVar5 = (undefined4 *)*DAT_02117560;
    func_02124c30(puVar5[1],*puVar5,puVar5[2],puVar5[0x20],puVar5[6]);
    iVar2 = *DAT_02117560;
    func_02124c30(*(undefined4 *)(iVar2 + 0x10),*(undefined4 *)(iVar2 + 0xc),0,
                  *(undefined4 *)(iVar2 + 0x84),*(undefined4 *)(iVar2 + 0x1c));
  }
  iVar2 = *DAT_02117560;
  if ((*(int *)(iVar2 + 0x30) == 0xb) && (9 < *(int *)(iVar2 + 0x38))) {
    return *(undefined4 *)(iVar2 + 0x88);
  }
  return 0;
}

