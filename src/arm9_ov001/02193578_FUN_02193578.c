/* Decompiled C draft; module arm9_ov001; ROM address 02193578. No matching claim. */
#include "types.h"
#include "deps/02193578_FUN_02193578.h"

void FUN_02193578(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  iVar1 = func_0x02125f54();
  if (iVar1 != 0) {
    func_0x02125fc0();
    return;
  }
  iVar1 = func_0x02125f88();
  if (iVar1 != 0) {
    iVar1 = func_0x02125f60();
    if (iVar1 == 0) {
      uVar2 = func_0x020b3f7c(*(undefined4 *)(*DAT_021935f4 + 0x38),4);
      uVar3 = func_0x020b3f7c(*(undefined4 *)(*DAT_021935f4 + 0x3c),0);
      uVar4 = func_0x020b3f7c(*(undefined4 *)(*DAT_021935f4 + 0x3c),1);
      func_0x0212611c(uVar2,uVar3,uVar4,1);
      *(undefined4 *)(*DAT_021935f4 + 4) = 7;
      return;
    }
    *(undefined4 *)(*DAT_021935f4 + 4) = 1;
  }
  return;
}

