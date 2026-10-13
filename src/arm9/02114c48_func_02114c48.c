/* Decompiled C draft; module arm9; ROM address 02114c48. No matching claim. */
#include "types.h"
#include "deps/02114c48_func_02114c48.h"

void func_02114c48(void)

{
  short sVar1;
  int iVar2;
  
  sVar1 = func_02116870();
  iVar2 = TextSystem_WasAnyDialogButtonPressed_from_thumb();
  if (iVar2 != 0) {
    iVar2 = TextSystem_IsButton2Focused_from_thumb();
    if (iVar2 == 0) {
      func_02114174(sVar1 + *(short *)(*piRam02114c94 + 0x74));
      *(undefined4 *)(*piRam02114c94 + 0x84) = 1;
    }
    else {
      *(undefined4 *)(*piRam02114c94 + 0x84) = 0;
    }
    func_02115cc4();
  }
  return;
}

