/* Decompiled C draft; module arm9; ROM address 0204f19c. No matching claim. */
#include "types.h"
#include "deps/0204f19c_func_0204f19c.h"

void func_0204f19c(int param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  char *pcVar4;
  byte *pbVar5;
  int iVar6;
  
  iVar3 = iRam0204f218;
  piVar2 = piRam0204f214;
  iVar6 = *(int *)(param_1 + 4);
  if (iVar6 == 10) {
    func_0204f220((int *)(uintptr_t)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x1d));
    return;
  }
  pcVar4 = (char *)(*piRam0204f214 + iRam0204f218);
  cVar1 = *pcVar4;
  if (cVar1 == '\0') {
    if (iVar6 == 2) {
      *pcVar4 = '\x01';
      return;
    }
  }
  else if (cVar1 == '\x01') {
    if (iVar6 == 8) {
      *pcVar4 = '\x02';
      return;
    }
  }
  else {
    if (cVar1 != '\x02') {
      return;
    }
    if (iVar6 == 8) {
      pbVar5 = (byte *)(*piRam0204f214 + iRam0204f21c);
      *pbVar5 = *pbVar5 | 4;
      *(undefined1 *)(*piVar2 + iVar3) = 0;
    }
  }
  return;
}

