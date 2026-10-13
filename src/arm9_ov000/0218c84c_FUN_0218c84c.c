/* Decompiled C draft; module arm9_ov000; ROM address 0218c84c. No matching claim. */
#include "types.h"
#include "deps/0218c84c_FUN_0218c84c.h"

bool FUN_0218c84c(char *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  while( true ) {
    if ((param_2 < 1) || (*param_1 == '\0')) {
      if (param_2 == 0) {
        return false;
      }
      return *param_1 == '\0';
    }
    iVar1 = FUN_0218d0c8((int)(uintptr_t)(param_1),param_2);
    if (iVar1 < 0) {
      return false;
    }
    iVar2 = FUN_0218d0c8((int)(uintptr_t)(param_1 + iVar1),param_2 - iVar1);
    if (iVar2 < 0) break;
    param_1 = param_1 + iVar1 + iVar2;
    param_2 = (param_2 - iVar1) - iVar2;
  }
  return false;
}

