/* Decompiled C draft; module arm9; ROM address 0204ed84. No matching claim. */
#include "types.h"
#include "deps/0204ed84_func_0204ed84.h"

void func_0204ed84(undefined4 param_1,uint param_2,uint param_3)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)*piRam0204ee14;
  if ((*(byte *)((int)piVar1 + iRam0204ee18) & 1) == 0) {
    if (piVar1 == (int *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *piVar1;
    }
    if (iVar2 == 1) {
      *(short *)(iRam0204ee20 + 4) = (short)uRam0204ee1c;
      param_2 = func_02006954(*(undefined4 *)((int)piVar1 + iRam0204ee24));
      param_2 = param_2 & 0xffff;
      param_3 = (uint)*(byte *)(*piRam0204ee14 + 0x87);
    }
    else if (iVar2 == 2) {
      *(undefined2 *)(iRam0204ee20 + 4) = 0xe;
      param_2 = func_02006914(*(undefined4 *)((int)piVar1 + iRam0204ee24));
      param_2 = param_2 & 0xffff;
      param_3 = 1;
    }
    iVar2 = func_02050650(*(undefined4 *)(*piRam0204ee14 + iRam0204ee24),param_2,param_3,0,
                          iRam0204ee20);
    piVar1 = piRam0204ee14;
    if (iVar2 == 0) {
      *(undefined2 *)(*piRam0204ee14 + iRam0204ee2c) = *puRam0204ee28;
      *(byte *)(*piVar1 + iRam0204ee18) = *(byte *)(*piVar1 + iRam0204ee18) & 0xfe;
    }
  }
  return;
}

