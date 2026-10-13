/* Decompiled C draft; module arm9_ov000; ROM address 02180534. No matching claim. */
#include "types.h"
#include "deps/02180534_func_ov000_02180534.h"

void func_ov000_02180534(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  
  func_0x020ae6ac(*piRam02180580,*piRam02180580 + iRam02180584);
  FUN_02180724();
  func_0x020ae630(*piRam02180580,*piRam02180580 + iRam02180584);
  if ((param_1 != 0) && (iVar2 = func_ov000_021806c4(), iVar2 != -1)) {
    iVar2 = func_ov000_021806c4();
    if (iVar2 == 0) {
      *(undefined4 *)(*piRam02180588 + 0x20) = 0;
    }
    uVar1 = func_ov000_021806c4();
    *(undefined2 *)(param_1 + 4) = uVar1;
  }
  return;
}

