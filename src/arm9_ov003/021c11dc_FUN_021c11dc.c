/* Decompiled C draft; module arm9_ov003; ROM address 021c11dc. No matching claim. */
#include "types.h"
#include "deps/021c11dc_FUN_021c11dc.h"

void FUN_021c11dc(int param_1)

{
  char cVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  
  piVar3 = DAT_021c1260;
  cVar1 = *(char *)(*DAT_021c1260 + 99);
  *(undefined1 *)(*DAT_021c1260 + 99) = *(undefined1 *)(param_1 + DAT_021c1264 + cVar1 * 4);
  iVar4 = *piVar3;
  cVar2 = *(char *)(iVar4 + 99);
  if ((cVar2 == '\r') && ((param_1 == 1 || (param_1 == 3)))) {
    *(char *)(iVar4 + 100) = cVar1;
  }
  else if (cVar2 == -1) {
    if ((*(char *)(iVar4 + 100) == '\x01') || (*(char *)(iVar4 + 100) == '\n')) {
      *(undefined1 *)(iVar4 + 99) = 10;
    }
    else {
      *(undefined1 *)(iVar4 + 99) = 0xb;
    }
  }
  else if (cVar2 == -2) {
    if ((*(char *)(iVar4 + 100) == '\x01') || (*(char *)(iVar4 + 100) == '\n')) {
      *(undefined1 *)(iVar4 + 99) = 1;
    }
    else {
      *(undefined1 *)(iVar4 + 99) = 2;
    }
  }
  FUN_021c1268();
  FUN_021cdc10(8);
  return;
}

