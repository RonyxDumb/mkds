/* Decompiled C draft; module arm9_ov000; ROM address 02190a24. No matching claim. */
#include "types.h"
#include "deps/02190a24_FUN_02190a24.h"

int FUN_02190a24(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined1 auStack_24 [4];
  int local_20;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_8 = param_3;
  uStack_4 = param_4;
  if (*(int *)(param_2 + 0x28) == 0) {
    func_0x0213442c(DAT_02190a9c,DAT_02190aa0,0,0xde);
  }
  if ((*(int *)(param_2 + 0x30) == *(int *)(param_2 + 0x34)) &&
     (iVar1 = FUN_0218dc44((undefined4 *)(uintptr_t)(*(undefined4 *)(param_2 + 0x38))), iVar1 == 0)) {
    iVar1 = FUN_02190aa8(param_1,*(undefined4 *)(param_2 + 8),(undefined4)(uintptr_t)(&uStack_8),1,(undefined4 *)(void *)(auStack_24),&local_20,
                         (char *)(uintptr_t)(DAT_02190aa4));
    if (iVar1 != 0) {
      return iVar1;
    }
    if (local_20 != 0) {
      return 0;
    }
  }
  iVar1 = FUN_02190c64(param_1,(int *)(uintptr_t)(param_2 + 0x28),(int)(char)uStack_8);
  return iVar1;
}

