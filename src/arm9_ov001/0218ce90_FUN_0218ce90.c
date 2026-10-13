/* Decompiled C draft; module arm9_ov001; ROM address 0218ce90. No matching claim. */
#include "types.h"
#include "deps/0218ce90_FUN_0218ce90.h"

void FUN_0218ce90(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 != (int *)0x0) {
    iVar4 = 0;
    for (iVar3 = 0; iVar3 < (int)(uint)*(ushort *)(param_1 + 1); iVar3 = iVar3 + 1) {
      iVar2 = *(int *)(*param_1 + iVar4);
      if (iVar2 == 0) {
        return;
      }
      iVar1 = func_0x02062ec4();
      if (iVar1 == 0) {
        if (iVar3 == 0) {
          FUN_0218d074(iVar2);
        }
        else {
          FUN_0218cfe8(iVar2);
        }
      }
      else {
        FUN_0218d01c(iVar2);
      }
      iVar4 = iVar4 + 4;
    }
  }
  return;
}

