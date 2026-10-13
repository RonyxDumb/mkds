/* Decompiled C draft; module arm9_ov000; ROM address 0218a854. No matching claim. */
#include "types.h"
#include "deps/0218a854_FUN_0218a854.h"

void FUN_0218a854(int param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  
  iVar1 = DAT_0218a884;
  *(undefined1 *)(param_1 + DAT_0218a884) = 1;
  *(undefined1 *)(param_1 + DAT_0218a888) = 3;
  *(undefined1 *)(param_1 + DAT_0218a88c) = 5;
  *(undefined1 *)(param_1 + DAT_0218a890) = 7;
  *(undefined1 *)(param_1 + DAT_0218a894) = 0xb;
  iVar3 = 0;
  cVar2 = -1;
  do {
    *(char *)(param_1 + iVar3) = cVar2;
    iVar3 = iVar3 + 1;
    cVar2 = cVar2 + -1;
  } while (iVar3 < iVar1);
  return;
}

