/* Decompiled C draft; module arm9_ov000; ROM address 021812f4. No matching claim. */
#include "types.h"
#include "deps/021812f4_FUN_021812f4.h"

void FUN_021812f4(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  iVar2 = func_0x02125f54();
  if (iVar2 != 0) {
    func_0x02125fc0();
    return;
  }
  iVar2 = func_0x02125f88();
  piVar1 = DAT_02181348;
  if (iVar2 != 0) {
    *(undefined4 *)(*DAT_02181348 + 4) = 3;
    uVar3 = func_0x020b3f7c(*(undefined4 *)(*piVar1 + 0x38),0x21);
    uVar4 = func_0x020b3f7c(*(undefined4 *)(*DAT_02181348 + 0x3c),6);
    func_0x02126570(uVar3,uVar4);
    *(undefined4 *)(*DAT_02181348 + 0x10) = 0;
  }
  return;
}

