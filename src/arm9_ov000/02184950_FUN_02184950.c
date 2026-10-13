/* Decompiled C draft; module arm9_ov000; ROM address 02184950. No matching claim. */
#include "types.h"
#include "deps/02184950_FUN_02184950.h"

void FUN_02184950(undefined4 param_1)

{
  int *piVar1;
  undefined1 uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  
  puVar3 = (undefined4 *)func_0x02036bec(param_1,4);
  *DAT_021849d0 = puVar3;
  *puVar3 = param_1;
  FUN_02184934();
  iVar4 = func_ov000_021806d4();
  if (iVar4 != 5) {
    func_0x02122728();
    FUN_0219bb50();
    uVar2 = func_0x02122778();
    func_0x02029454(uVar2);
    func_0x02029440(*(undefined1 *)(*DAT_021849d4 + DAT_021849d8));
  }
  uVar5 = func_ov000_021804f4();
  uVar6 = func_ov000_021804e0();
  func_0x02026910(param_1,2,uVar5,uVar6);
  func_0x0212a910(1,1);
  piVar1 = DAT_021849dc;
  iVar7 = 0;
  *(undefined4 *)(*DAT_021849dc + 0x6c) = 0;
  iVar4 = 0;
  do {
    *(undefined4 *)(*piVar1 + iVar4 + 0x5c) = 0;
    iVar4 = iVar4 + 4;
    iVar7 = iVar7 + 1;
  } while (iVar7 < 4);
  return;
}

