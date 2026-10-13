/* Decompiled C draft; module arm9_ov000; ROM address 02180f80. No matching claim. */
#include "types.h"
#include "deps/02180f80_FUN_02180f80.h"

void FUN_02180f80(void)

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
    piVar1 = DAT_02180ff8;
    if (iVar2 == 0) {
      *(undefined4 *)(*DAT_02180ff8 + 4) = 7;
      uVar3 = func_0x020b3f7c(*(undefined4 *)(*piVar1 + 0x38),0x14);
      func_0x02126638(uVar3,1,1,1,0,1,0);
      func_0x0211fe24();
      *(undefined4 *)(*DAT_02180ff8 + 0x14) = 0;
      func_0x02108bb4();
      return;
    }
    *(undefined4 *)(*DAT_02180ff8 + 0xc) = 1;
    func_ov000_021806e0(*(undefined4 *)(*piVar1 + 0xc));
  }
  return;
}

