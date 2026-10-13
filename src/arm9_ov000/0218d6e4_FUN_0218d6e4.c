/* Decompiled C draft; module arm9_ov000; ROM address 0218d6e4. No matching claim. */
#include "types.h"
#include "deps/0218d6e4_FUN_0218d6e4.h"

void FUN_0218d6e4(undefined4 param_1)

{
  int *piVar1;
  char *pcVar2;
  int iVar3;
  char acStack_50 [68];
  
  func_0x0213a2d0((uint *)(uintptr_t)(DAT_0218d76c),param_1);
  *DAT_0218d770 = -1;
  FUN_0218e8b8();
  pcVar2 = DAT_0218d774;
  if (*DAT_0218d774 == '\0') {
    func_0x02135014(acStack_50,DAT_0218d778,param_1);
    pcVar2 = acStack_50;
  }
  iVar3 = FUN_0218d7bc((undefined4)(uintptr_t)(pcVar2),DAT_0218d77c,DAT_0218d780);
  if (iVar3 != 0) {
    iVar3 = FUN_0218e554(2,2,0);
    piVar1 = DAT_0218d770;
    *DAT_0218d770 = iVar3;
    if (iVar3 != -1) {
      *(undefined1 *)(piVar1 + 3) = 9;
      iVar3 = func_0x0213a434(param_1);
      func_0x02134eb8((uint *)(uintptr_t)(DAT_0218d784),param_1,iVar3 + 1);
      DAT_0218d770[0x13] = iVar3 + 6;
      FUN_0218d788();
      DAT_0218d770[0x15] = 0;
    }
  }
  return;
}

