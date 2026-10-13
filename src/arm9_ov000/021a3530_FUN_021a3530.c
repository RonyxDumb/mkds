/* Decompiled C draft; module arm9_ov000; ROM address 021a3530. No matching claim. */
#include "types.h"
#include "deps/021a3530_FUN_021a3530.h"

int FUN_021a3530(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_2 == 0) {
    return -1;
  }
  iVar1 = func_0x02139ffc(param_3,param_4);
  if (iVar1 != 0) {
    do {
      uVar2 = func_0x0213a434(param_1);
      iVar3 = func_0x0213a038(iVar1 + 1,param_1,uVar2);
      if ((iVar3 == 0) &&
         (iVar3 = func_0x0213a434(param_1), param_4 == *(char *)(iVar3 + iVar1 + 1))) {
        iVar1 = func_0x02139ffc(iVar1 + 1,param_4);
        if (iVar1 != 0) {
          iVar3 = func_0x02139ffc(iVar1 + 1,param_4);
          if (iVar3 == 0) {
            iVar3 = func_0x0213a434(iVar1 + 1);
          }
          else {
            iVar3 = iVar3 - (iVar1 + 1);
          }
          func_0x0213a228((uint *)(uintptr_t)(param_2),iVar1 + 1,iVar3);
          *(undefined1 *)(param_2 + iVar3) = 0;
          return iVar3;
        }
        return -1;
      }
      iVar1 = func_0x02139ffc(iVar1 + 1,param_4);
      if (iVar1 == 0) {
        return -1;
      }
      iVar1 = func_0x02139ffc(iVar1 + 1,param_4);
    } while (iVar1 != 0);
    return -1;
  }
  return -1;
}

