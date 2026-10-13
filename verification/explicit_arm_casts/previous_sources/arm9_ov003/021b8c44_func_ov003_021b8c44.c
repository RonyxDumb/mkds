/* Decompiled C draft; module arm9_ov003; ROM address 021b8c44. No matching claim. */
#include "types.h"
#include "deps/021b8c44_func_ov003_021b8c44.h"

undefined4 func_ov003_021b8c44(int param_1,undefined4 param_2)

{
  bool bVar1;
  char *pcVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar3 = 0;
  bVar1 = false;
  iVar4 = 0;
  pcVar2 = pcRam021b8c84;
  do {
    if (*pcVar2 != '\0') {
      bVar1 = true;
      break;
    }
    pcVar2 = pcVar2 + 1;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 6);
  if (bVar1) {
    iVar4 = func_ov003_021b7da0(pcRam021b8c84,param_2,6);
    if (iVar4 != 0) {
      uVar3 = 1;
    }
  }
  else if (param_1 != iRam021b8c88) {
    uVar3 = 2;
  }
  return uVar3;
}

