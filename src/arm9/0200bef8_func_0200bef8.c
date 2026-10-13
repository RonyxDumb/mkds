/* Decompiled C draft; module arm9; ROM address 0200bef8. No matching claim. */
#include "types.h"
#include "deps/0200bef8_func_0200bef8.h"

void func_0200bef8(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined2 local_14;
  undefined2 local_12;
  undefined2 local_10;
  undefined2 local_e;
  
  piVar1 = piRam0200bf84;
  *(undefined4 *)(*piRam0200bf84 + 4) = param_1;
  *(undefined4 *)(*piVar1 + 8) = param_2;
  iVar2 = func_0214358c(1,uRam0200bf88,0);
  if (iVar2 == 0) {
    iVar2 = func_02144230(uRam0200bf8c,param_2,*(undefined2 *)(*piRam0200bf84 + 0x12),param_1,
                          *(undefined2 *)(*piRam0200bf84 + 0x10),1,0,0,0,1,1);
    if ((iVar2 != 2) && (*(int *)*piRam0200bf84 != 0)) {
      local_10 = 0xe;
      local_e = (undefined2)iVar2;
      (**(code **)*piRam0200bf84)(0xff,&local_10);
    }
  }
  else if (*(int *)*piRam0200bf84 != 0) {
    local_14 = 0xe;
    local_12 = (undefined2)iVar2;
    (**(code **)*piRam0200bf84)(0xff,&local_14);
    return;
  }
  return;
}

