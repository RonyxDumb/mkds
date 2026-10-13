/* Decompiled C draft; module arm9; ROM address 02007154. No matching claim. */
#include "types.h"
#include "deps/02007154_func_02007154.h"

void func_02007154(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  
  iVar3 = *piRam020071a0 + iRam0200719c * param_1;
  if ((*(char *)(iVar3 + iRam020071a4) != '\0') && (*(short *)(iVar3 + iRam020071a8) != 0)) {
    uVar1 = *(ushort *)(iVar3 + iRam020071ac);
    uVar2 = *(ushort *)(iVar3 + iRam020071b0);
    if (((uint)uVar2 <= (uint)uVar1) && ((uint)uVar1 <= uVar2 + 2)) {
      *(ushort *)(iVar3 + iRam020071ac) = uVar1 + 1;
      return;
    }
    *(ushort *)(iVar3 + iRam020071ac) = uVar2;
  }
  return;
}

