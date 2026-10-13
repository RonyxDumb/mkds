/* Decompiled C draft; module arm9_ov000; ROM address 02182474. No matching claim. */
#include "types.h"
#include "deps/02182474_FUN_02182474.h"

void FUN_02182474(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = func_0x02125f54();
  if (iVar2 != 0) {
    func_0x02125fc0();
    return;
  }
  iVar2 = func_0x02125f88();
  if (iVar2 != 0) {
    iVar2 = func_0x02125f60();
    piVar1 = DAT_021824e0;
    if (iVar2 == 0) {
      *(undefined4 *)(*DAT_021824e0 + 4) = 10;
      uVar3 = func_0x020b3f7c(*(undefined4 *)(*piVar1 + DAT_021824e4),0x18);
      func_0x02126638(uVar3,1,1,1,0,1,0);
      return;
    }
    *(undefined4 *)(*DAT_021824e0 + 4) = 2;
    FUN_02182de8();
    *(undefined4 *)(*DAT_021824e0 + 8) = 1;
  }
  return;
}

