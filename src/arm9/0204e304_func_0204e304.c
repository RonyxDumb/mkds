/* Decompiled C draft; module arm9; ROM address 0204e304. No matching claim. */
#include "types.h"
#include "deps/0204e304_func_0204e304.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void func_0204e304(int param_1)

{
  int *piVar1;
  undefined2 uVar2;
  ulonglong uVar3;
  
  piVar1 = DAT_0204e3a8;
  switch(param_1) {
  case 0:
  case 1:
  case 2:
  case 5:
  case 8:
  case 9:
  case 10:
    return;
  case 3:
  case 6:
    *(undefined4 *)(*DAT_0204e3a8 + _func_0204e3b0) = 0;
    *(undefined4 *)(*piVar1 + 0x10) = 0;
    return;
  case 4:
    func_02050e60(5);
    return;
  case 7:
    *(undefined4 *)(*DAT_0204e3a8 + _func_0204e3b0) = 1;
    *(undefined4 *)(*piVar1 + 4) = 6;
    return;
  case 0xb:
    *(undefined4 *)(*DAT_0204e3a8 + 0x10) = 0;
    return;
  }
  if (param_1 != 0x14) {
    return;
  }
  uVar3 = Os_GetTick();
  uVar2 = _ull_mod((int)(uVar3 >> 10),(int)((uVar3 >> 10) >> 0x20),0x28,0);
  piVar1 = DAT_0204e3a8;
  *(undefined2 *)(*DAT_0204e3a8 + DAT_0204e3ac) = uVar2;
  *(undefined4 *)(*piVar1 + 0x10) = 0;
  return;
}

