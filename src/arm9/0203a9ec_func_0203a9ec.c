/* Decompiled C draft; module arm9; ROM address 0203a9ec. No matching claim. */
#include "types.h"
#include "deps/0203a9ec_func_0203a9ec.h"

undefined4 func_0203a9ec(uint param_1)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  
  if (uRam0203aaa0 < param_1) {
    return 1;
  }
  iVar4 = Bright_IsBothScreensFadedIn(param_1);
  if (iVar4 == 0) {
    return 0;
  }
  bVar3 = 0;
  do {
    bVar2 = 0;
    do {
      iVar4 = CupHasRecord(bVar3,bVar2);
      if (iVar4 != 0) {
        bVar1 = true;
        goto LAB_0203aa60;
      }
      bVar2 = bVar2 + 1;
    } while (bVar2 < 4);
    bVar3 = bVar3 + 1;
  } while (bVar3 < 8);
  bVar1 = false;
LAB_0203aa60:
  if ((bVar1) && ((*(ushort *)(iRam0203aaa4 + 0x2e0) & 1) != 0)) {
    return 1;
  }
  return 0;
}

