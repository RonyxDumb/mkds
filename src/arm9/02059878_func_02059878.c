/* Decompiled C draft; module arm9; ROM address 02059878. No matching claim. */
#include "types.h"
#include "deps/02059878_func_02059878.h"

void func_02059878(void)

{
  undefined1 uVar1;
  int iVar2;
  int *piVar3;
  
  StateDualHandler_Create((undefined4 *)(uintptr_t)(*piRam020598f0 + iRam020598f4),uRam020598f8,0x17,0);
  piVar3 = piRam020598f0;
  iVar2 = 0;
  *(undefined1 *)(*piRam020598f0 + iRam020598fc) = 0;
  *(undefined2 *)(*piVar3 + iRam02059900) = 0;
  *(undefined1 *)(*piVar3 + iRam02059904) = 0;
  *(undefined1 *)(*piVar3 + iRam02059908) = 0;
  *(undefined1 *)(*piVar3 + iRam0205990c) = 0;
  *(undefined1 *)(*piVar3 + iRam02059910) = 0;
  piVar3 = (int *)*piVar3;
  if (piVar3 != (int *)0x0) {
    iVar2 = *piVar3;
  }
  if (iVar2 == 1) {
    if ((*(ushort *)((int)piVar3 + iRam02059914) & 0x40) == 0) {
      uVar1 = *(undefined1 *)((int)piVar3 + 0x87);
    }
    else {
      uVar1 = *(undefined1 *)((int)piVar3 + iRam02059918);
    }
    *(undefined1 *)((int)piVar3 + 0x86) = uVar1;
  }
  *(undefined4 *)(*piRam020598f0 + iRam0205991c) = 0;
  return;
}

