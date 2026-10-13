/* Decompiled C draft; module arm9_ov000; ROM address 021a2b9c. No matching claim. */
#include "types.h"
#include "deps/021a2b9c_FUN_021a2b9c.h"

uint FUN_021a2b9c(uint param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((param_2 == 0) || (param_3 == 0)) {
    return 0;
  }
  if ((param_1 < 100) || (*(char *)(DAT_021a2c4c + (param_1 - 100) * 0xc) == '\0')) {
    param_1 = FUN_0219eac8();
    if (param_1 == 0) {
      return 0;
    }
    iVar3 = (param_1 - 100) * 0xc;
    *(char *)(DAT_021a2c4c + iVar3) = (char)param_1;
    *(undefined1 *)(DAT_021a2c50 + iVar3) = 0;
    *(undefined2 *)(DAT_021a2c54 + iVar3) = 0;
    if (*(int *)(DAT_021a2c58 + iVar3) != 0) {
      FUN_021a3704(4);
    }
    iVar1 = func_0x0213a434(param_2);
    uVar2 = FUN_021a372c(4,iVar1 + 1);
    iVar1 = DAT_021a2c58;
    *(undefined4 *)(DAT_021a2c58 + iVar3) = uVar2;
    if (*(int *)(iVar1 + iVar3) == 0) {
      FUN_021a1a38(0xb,DAT_021a2c5c);
      return 0;
    }
    func_0x0213a2d0(*(int *)(iVar1 + iVar3),param_2);
    *(int *)(DAT_021a2c60 + iVar3) = param_3;
    FUN_021a4b84(param_1,param_2);
  }
  return param_1;
}

