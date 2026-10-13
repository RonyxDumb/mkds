/* Decompiled C draft; module arm9_ov000; ROM address 0218c794. No matching claim. */
#include "types.h"
#include "deps/0218c794_FUN_0218c794.h"

undefined4 FUN_0218c794(int param_1,char *param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = FUN_0218dc44((undefined4 *)(uintptr_t)(*(undefined4 *)(param_1 + 8)));
  iVar4 = 0;
  if (0 < iVar2) {
    do {
      iVar3 = FUN_0218dbf8((int *)(uintptr_t)(*(undefined4 *)(param_1 + 8)),iVar4);
      iVar3 = *(int *)(iVar3 + 4);
      if (iVar3 == 0) {
        if (param_3 < 1) {
          return 0;
        }
        cVar1 = *param_2;
        param_2 = param_2 + 1;
        param_3 = param_3 + -1;
        if (cVar1 == -1) {
          iVar3 = FUN_0218d0c8((int)(uintptr_t)(param_2),param_3);
          if (iVar3 == -1) {
            return 0;
          }
          param_2 = param_2 + iVar3;
          param_3 = param_3 - iVar3;
        }
      }
      else if (iVar3 == 1) {
        param_2 = param_2 + 1;
        param_3 = param_3 + -1;
      }
      else {
        if (iVar3 != 2) {
          func_0x0213442c(DAT_0218c840,DAT_0218c844,0,DAT_0218c848);
          return 0;
        }
        param_2 = param_2 + 2;
        param_3 = param_3 + -2;
      }
      if (param_3 < 0) {
        return 0;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar2);
  }
  return 1;
}

