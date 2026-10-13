/* Decompiled C draft; module arm9_ov000; ROM address 021a6abc. No matching claim. */
#include "types.h"
#include "deps/021a6abc_FUN_021a6abc.h"

int FUN_021a6abc(undefined2 *param_1)

{
  int iVar1;
  undefined2 uVar2;
  int iVar3;
  
  iVar3 = 0;
  uVar2 = 0;
  iVar1 = FUN_021a5b30();
  func_0x0200fca0();
  if (((iVar1 != 0) && (*(int *)(iVar1 + DAT_021a6b00) == 9)) &&
     (*(char *)(iVar1 + DAT_021a6b04) == '\0')) {
    iVar3 = iVar1 + DAT_021a6b08;
    uVar2 = *(undefined2 *)(iVar1 + DAT_021a6b0c);
  }
  func_0x0200fcb4();
  if (param_1 != (undefined2 *)0x0) {
    *param_1 = uVar2;
  }
  return iVar3;
}

