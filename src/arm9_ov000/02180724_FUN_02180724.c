/* Decompiled C draft; module arm9_ov000; ROM address 02180724. No matching claim. */
#include "types.h"
#include "deps/02180724_FUN_02180724.h"

void FUN_02180724(void)

{
  int *piVar1;
  undefined4 uVar2;
  code *pcVar3;
  
  if (*(code **)(*DAT_02180810 + 0x24) != (code *)0x0) {
    (**(code **)(*DAT_02180810 + 0x24))();
  }
  if (*(int *)(*DAT_02180810 + 0xc) != -1) {
    (**(code **)(*DAT_02180810 + 0x20))();
    FUN_02180be8();
    func_0x02036ab0(*(undefined4 *)(*DAT_02180810 + 4));
    uVar2 = func_0x020369fc(*(undefined4 *)*DAT_02180810);
    piVar1 = DAT_02180810;
    *(undefined4 *)(*DAT_02180810 + 4) = uVar2;
    switch(*(undefined4 *)(*piVar1 + 0xc)) {
    case 0:
      FUN_02180c04();
      break;
    case 1:
      FUN_02181714();
      break;
    case 2:
      FUN_02181fcc();
      break;
    case 3:
      FUN_0218330c();
      break;
    case 4:
      FUN_021848c8();
      break;
    case 5:
      FUN_021849e0();
      break;
    case 6:
      FUN_02184aa4();
      break;
    case 7:
      FUN_021857b8();
      break;
    case 8:
      FUN_02184ba8();
      break;
    case 9:
      FUN_02185344();
    }
    piVar1 = DAT_02180810;
    *(undefined4 *)(*DAT_02180810 + 0x10) = *(undefined4 *)(*DAT_02180810 + 8);
    *(undefined4 *)(*piVar1 + 8) = *(undefined4 *)(*piVar1 + 0xc);
    *(undefined4 *)(*piVar1 + 0xc) = 0xffffffff;
    pcVar3 = *(code **)(*piVar1 + 0x1c);
    if (pcVar3 != (code *)0x0) {
      (*pcVar3)(*(undefined4 *)(*piVar1 + 4));
    }
  }
  func_0x02125928();
  func_0x0212a920();
  piVar1 = DAT_02180810;
  *(int *)(*DAT_02180810 + 0x14) = *(int *)(*DAT_02180810 + 0x14) + 1;
  if (0 < *(int *)(*piVar1 + 0x14)) {
    *(undefined4 *)(*piVar1 + 0x14) = 0;
  }
  return;
}

