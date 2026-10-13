/* Decompiled C draft; module arm9; ROM address 02111324. No matching claim. */
#include "types.h"
#include "deps/02111324_func_02111324.h"

void func_02111324(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  
  OamBuffer_ResetValues16_from_thumb(*puRam02111360,*puRam02111364);
  func_021114cc();
  OamBuffer_SomeFn2_from_thumb(*puRam02111360,*puRam02111364);
  if ((param_1 != 0) && (iVar2 = func_0211145c(), iVar2 != -1)) {
    uVar1 = func_0211145c();
    *(undefined2 *)(param_1 + 4) = uVar1;
  }
  return;
}

