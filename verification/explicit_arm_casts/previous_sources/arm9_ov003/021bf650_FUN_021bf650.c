/* Decompiled C draft; module arm9_ov003; ROM address 021bf650. No matching claim. */
#include "types.h"
#include "deps/021bf650_FUN_021bf650.h"

int FUN_021bf650(int param_1)

{
  int iVar1;
  int iVar2;
  
  func_0x0213a228(DAT_021bf690,param_1,0x3f);
  if (*(char *)(param_1 + 5) == 'x') {
    return DAT_021bf690;
  }
  iVar1 = FUN_021c20d0();
  if ((*(char *)(param_1 + 5) == 'y') && (iVar1 != 0)) {
    return DAT_021bf690;
  }
  iVar2 = DAT_021bf690;
  *(undefined1 *)(DAT_021bf690 + 5) = *(undefined1 *)(DAT_021bf694 + iVar1);
  return iVar2;
}

