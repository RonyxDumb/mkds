/* Decompiled C draft; module arm9_ov000; ROM address 02190988. No matching claim. */
#include "types.h"
#include "deps/02190988_FUN_02190988.h"

int FUN_02190988(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_20 [4];
  int local_1c [2];
  
  if (*(int *)(param_2 + 0x28) == 0) {
    func_0x0213442c(DAT_02190a18,DAT_02190a1c,0,0xfb);
  }
  iVar2 = 0;
  if (param_4 == 0) {
    return 0;
  }
  if ((*(int *)(param_2 + 0x30) == *(int *)(param_2 + 0x34)) &&
     (iVar1 = FUN_0218dc44(*(undefined4 *)(param_2 + 0x38)), iVar1 == 0)) {
    do {
      iVar1 = FUN_02190aa8(param_1,*(undefined4 *)(param_2 + 8),param_3 + iVar2,param_4,auStack_20,
                           local_1c,DAT_02190a20);
      if (iVar1 != 0) {
        return iVar1;
      }
      if (local_1c[0] == 0) break;
      iVar2 = iVar2 + local_1c[0];
      param_4 = param_4 - local_1c[0];
    } while (param_4 != 0);
  }
  if ((param_4 == 0) ||
     (iVar2 = FUN_02190ba0(param_1,param_2 + 0x28,param_3 + iVar2,param_4), iVar2 == 0)) {
    iVar2 = 0;
  }
  return iVar2;
}

