/* Decompiled C draft; module arm9_ov000; ROM address 02181458. No matching claim. */
#include "types.h"
#include "deps/02181458_FUN_02181458.h"

void FUN_02181458(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  iVar2 = FUN_02181684();
  piVar1 = DAT_02181518;
  if (iVar2 != 0) {
    *(undefined4 *)(*DAT_02181518 + 4) = 1;
    uVar3 = func_0x020b3f7c(*(undefined4 *)(*piVar1 + 0x38),0x1c);
    uVar4 = func_0x020b3f7c(*(undefined4 *)(*DAT_02181518 + 0x3c),6);
    func_0x02126570(uVar3,uVar4);
    *(undefined4 *)(*DAT_02181518 + 0x10) = 0;
    return;
  }
  iVar2 = thunk_EXT_FUN_02061290();
  piVar1 = DAT_02181518;
  if (iVar2 != 0) {
    *(undefined4 *)(*DAT_02181518 + 4) = 6;
    uVar3 = func_0x020b3f7c(*(undefined4 *)(*piVar1 + 0x38),0x13);
    uVar4 = func_0x020b3f7c(*(undefined4 *)(*DAT_02181518 + 0x3c),0);
    uVar5 = func_0x020b3f7c(*(undefined4 *)(*DAT_02181518 + 0x3c),1);
    func_0x02126454(uVar3,uVar4,uVar5,0);
    return;
  }
  *(undefined4 *)(*DAT_02181518 + 4) = 2;
  uVar3 = func_0x020b3f7c(*(undefined4 *)(*piVar1 + 0x38),0x20);
  uVar4 = func_0x020b3f7c(*(undefined4 *)(*DAT_02181518 + 0x3c),6);
  func_0x02126570(uVar3,uVar4);
  return;
}

