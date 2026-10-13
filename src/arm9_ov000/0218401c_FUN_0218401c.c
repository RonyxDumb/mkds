/* Decompiled C draft; module arm9_ov000; ROM address 0218401c. No matching claim. */
#include "types.h"
#include "deps/0218401c_FUN_0218401c.h"

void FUN_0218401c(void)

{
  int *piVar1;
  undefined2 uVar2;
  int iVar3;
  
  piVar1 = DAT_021840bc;
  *(int *)(*DAT_021840bc + 8) = *(int *)(*DAT_021840bc + 8) + 1;
  iVar3 = *piVar1;
  *(int *)(iVar3 + 8) = *(int *)(iVar3 + 8) + 1;
  uVar2 = func_0x020ae4c0(1,DAT_021840c0,0,*(undefined4 *)(*piVar1 + 8),10);
  piVar1 = DAT_021840bc;
  *(undefined2 *)(*DAT_021840bc + 0x10) = uVar2;
  if (9 < *(int *)(*piVar1 + 8)) {
    *(undefined4 *)(*piVar1 + 8) = 10;
  }
  if ((9 < *(int *)(*DAT_021840bc + 8)) &&
     (iVar3 = func_0x02125fa4(), piVar1 = DAT_021840bc, iVar3 != 0)) {
    *(undefined4 *)(*DAT_021840bc + 4) = 1;
    *(undefined4 *)(*piVar1 + 8) = 0;
    iVar3 = func_ov000_02180644();
    if (iVar3 == 0) {
      func_0x02121190(*(undefined1 *)(*DAT_021840c4 + 0x54),1,0);
      *(undefined4 *)(*DAT_021840bc + 0x3c) = 1;
    }
    else {
      func_0x02121190(*(undefined1 *)(*DAT_021840c4 + 0x54),0,0);
      *(undefined4 *)(*DAT_021840bc + 0x3c) = 0;
    }
    func_0x02108b2c();
  }
  return;
}

