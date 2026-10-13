/* Decompiled C draft; module arm9_ov000; ROM address 0219981c. No matching claim. */
#include "types.h"
#include "deps/0219981c_FUN_0219981c.h"

undefined4 FUN_0219981c(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  while( true ) {
    iVar1 = FUN_0218dc44(*(undefined4 *)(param_1 + 0x5c));
    do {
      iVar1 = iVar1 + -1;
      if (iVar1 < 0) {
        return 1;
      }
      piVar2 = (int *)FUN_0218dbf8(*(undefined4 *)(param_1 + 0x5c),iVar1);
    } while ((short)piVar2[3] != *(short *)(param_1 + 0x66));
    iVar3 = FUN_02199a0c(param_1,piVar2[2],*(int *)(param_1 + 0x44) + *piVar2,piVar2[1]);
    if (iVar3 == 0) break;
    FUN_02199878(param_1,piVar2,iVar1);
  }
  return 0;
}

