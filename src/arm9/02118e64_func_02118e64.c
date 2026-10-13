/* Decompiled C draft; module arm9; ROM address 02118e64. No matching claim. */
#include "types.h"
#include "deps/02118e64_func_02118e64.h"

undefined4 func_02118e64(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  
  piVar1 = DAT_02118f8c;
  *(undefined4 *)(*DAT_02118f8c + 0x34) = *(undefined4 *)(*DAT_02118f8c + 0x38);
  switch(*(undefined4 *)(*piVar1 + 0x34)) {
  case 0:
    func_021196dc();
    break;
  case 1:
    func_02119544();
    break;
  case 2:
    func_0211952c();
    break;
  case 3:
    func_02119340();
    break;
  case 4:
    func_021192c4();
    break;
  case 5:
    func_02119260();
    break;
  case 6:
    func_02119208();
    break;
  case 7:
    func_0211913c();
    break;
  case 8:
    func_02118f98();
  }
  func_0211a07c();
  if (*DAT_02118f90 == 2) {
    func_0211f39c();
  }
  else {
    if ((*(int *)(*DAT_02118f8c + 0x60) != 0) && (iVar2 = func_020d0ec4(), iVar2 != 0)) {
      iVar2 = func_020d0e58();
      uVar3 = func_020d0ea0();
      AllocateReserveTEQSub(0x1f,0,uVar3,0xe0);
      uVar3 = func_020d0e7c();
      AllocateReserveTEQSub(0x17,0x20,uVar3,DAT_02118f94);
      iVar6 = 0;
      do {
        iVar4 = ((iVar6 + 8) * 0x20 + 0x16) * 2;
        AllocateReserveTEQSub(0x1b,iVar4,iVar2 + iVar4,0x14);
        iVar6 = iVar6 + 1;
      } while (iVar6 < 0xb);
      *(undefined4 *)(*DAT_02118f8c + 0x60) = 0;
    }
    puVar5 = (undefined4 *)*DAT_02118f8c;
    func_02124c30(puVar5[1],*puVar5,puVar5[2],puVar5[0x19],puVar5[7]);
    iVar2 = *DAT_02118f8c;
    func_02124c30(*(undefined4 *)(iVar2 + 0x10),*(undefined4 *)(iVar2 + 0xc),
                  *(undefined4 *)(iVar2 + 0x18),*(undefined4 *)(iVar2 + 0x68),
                  *(undefined4 *)(iVar2 + 0x20));
  }
  iVar2 = *DAT_02118f8c;
  if ((*(int *)(iVar2 + 0x34) == 8) && (9 < *(int *)(iVar2 + 0x3c))) {
    return *(undefined4 *)(iVar2 + 0x6c);
  }
  return 0;
}

