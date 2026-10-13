/* Decompiled C draft; module arm9; ROM address 0204b344. No matching claim. */
#include "types.h"
#include "deps/0204b344_func_0204b344.h"

void func_0204b344(undefined4 param_1)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  
  bVar2 = true;
  iVar3 = *(int *)*DAT_0204b3a0;
  if ((iVar3 == 1) || (iVar3 == 2)) {
    bVar2 = false;
  }
  *(int *)*DAT_0204b3a0 = 4;
  piVar1 = DAT_0204b3a0;
  *(undefined4 *)(*DAT_0204b3a0 + 4) = param_1;
  switch(*(undefined4 *)(*piVar1 + 4)) {
  case 1:
  case 2:
    if (bVar2) {
      func_02049980(1);
      return;
    }
    func_02049980(2);
  }
  return;
}

