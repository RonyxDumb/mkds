/* Decompiled C draft; module arm9_ov000; ROM address 02184d4c. No matching claim. */
#include "types.h"
#include "deps/02184d4c_FUN_02184d4c.h"

void FUN_02184d4c(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  iVar2 = func_0x02125f88();
  if ((iVar2 != 0) && (iVar2 = func_0x02128274(), piVar1 = DAT_02184db8, iVar2 != 0)) {
    *(undefined4 *)(*DAT_02184db8 + 4) = 7;
    uVar3 = func_0x020b3f7c(*(undefined4 *)(*piVar1 + 0x38),0x10);
    uVar4 = func_0x020b3f7c(*(undefined4 *)(*DAT_02184db8 + 0x3c),0);
    uVar5 = func_0x020b3f7c(*(undefined4 *)(*DAT_02184db8 + 0x3c),1);
    func_0x02126454(uVar3,uVar4,uVar5,0);
    return;
  }
  iVar2 = func_0x02125f54();
  if (iVar2 != 0) {
    func_0x02125fc0();
  }
  return;
}

