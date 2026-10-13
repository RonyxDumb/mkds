/* Decompiled C draft; module arm9_ov001; ROM address 02193514. No matching claim. */
#include "types.h"
#include "deps/02193514_FUN_02193514.h"

void FUN_02193514(void)

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
    if (iVar2 == 0) {
      func_0x02057130();
      piVar1 = DAT_02193574;
      *(undefined4 *)(*DAT_02193574 + 4) = 8;
      uVar3 = func_0x020b3f7c(*(undefined4 *)(*piVar1 + 0x38),5);
      func_0x02126248(uVar3,1,1,1,0,1);
      return;
    }
    *(undefined4 *)(*DAT_02193574 + 4) = 1;
  }
  return;
}

