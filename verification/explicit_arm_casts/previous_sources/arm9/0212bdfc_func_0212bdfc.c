/* Decompiled C draft; module arm9; ROM address 0212bdfc. No matching claim. */
#include "types.h"
#include "deps/0212bdfc_func_0212bdfc.h"

int func_0212bdfc(int param_1)

{
  int iVar1;
  
  iVar1 = IntrusiveListWrapper_NextItem(uRam0212be70,0);
  if (iVar1 == 0) {
    iVar1 = IntrusiveListWrapper_NextItem(uRam0212be74,0);
    if (param_1 < (int)(uint)*(byte *)(iVar1 + 0x3d)) {
      return 0;
    }
    func_0212be78(iVar1);
  }
  IntrusiveListWrapper_RemoveItem(uRam0212be70,iVar1);
  *(char *)(iVar1 + 0x3d) = (char)param_1;
  func_0212beb4(iVar1);
  return iVar1;
}

