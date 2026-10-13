/* Decompiled C draft; module arm9_ov001; ROM address 0219348c. No matching claim. */
#include "types.h"
#include "deps/0219348c_FUN_0219348c.h"

void FUN_0219348c(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = func_0x02125f6c();
  if (iVar1 != 0) {
    func_0x0212ecc0(DAT_02193504,0,0x22);
  }
  if (*(char *)(*DAT_02193508 + 0x28) == '\0') {
    if (*(int *)(*DAT_0219350c + 0xc) == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(*DAT_0219350c + 0x10);
    }
  }
  else {
    iVar1 = 1;
  }
  if ((iVar1 == 0) && (iVar1 = func_0x02125fa4(), iVar1 != 0)) {
    *(undefined4 *)(*DAT_02193510 + 4) = 9;
    func_0x02125ebc(0x21);
    uVar2 = func_0x020b3f7c(*(undefined4 *)(*DAT_02193510 + 0x38),6);
    uVar3 = func_0x020b3f7c(*(undefined4 *)(*DAT_02193510 + 0x3c),4);
    func_0x02126230(uVar2,uVar3);
  }
  return;
}

