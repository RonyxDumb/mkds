/* Decompiled C draft; module arm9_ov000; ROM address 02198658. No matching claim. */
#include "types.h"
#include "deps/02198658_FUN_02198658.h"

undefined4 FUN_02198658(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = FUN_0218dc44(*(undefined4 *)(param_1 + 0x60));
  iVar3 = 0;
  if (0 < iVar1) {
    do {
      iVar2 = FUN_0218dbf8(*(undefined4 *)(param_1 + 0x60),iVar3);
      if ((DAT_021986a8 < (uint)(param_2 - *(int *)(iVar2 + 0xc))) &&
         (iVar2 = FUN_02198af4(param_1), iVar2 == 0)) {
        return 0;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  return 1;
}

