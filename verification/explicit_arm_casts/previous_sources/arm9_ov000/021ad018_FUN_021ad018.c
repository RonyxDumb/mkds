/* Decompiled C draft; module arm9_ov000; ROM address 021ad018. No matching claim. */
#include "types.h"
#include "deps/021ad018_FUN_021ad018.h"

undefined4 FUN_021ad018(char *param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  char *local_1c [2];
  
  uVar3 = 0;
  iVar2 = 0;
  while( true ) {
    uVar1 = FUN_021ad07c(param_1,local_1c);
    if (param_1 == local_1c[0]) {
      return 0;
    }
    if (((0xff < uVar1) ||
        ((param_1 = local_1c[0], iVar2 != 3 && (param_1 = local_1c[0] + 1, *local_1c[0] != '.'))))
       || ((iVar2 == 3 && (*param_1 != '\0')))) break;
    uVar3 = uVar3 << 8 | uVar1;
    iVar2 = iVar2 + 1;
    if (3 < iVar2) {
      *param_2 = uVar3;
      return 1;
    }
  }
  return 0;
}

