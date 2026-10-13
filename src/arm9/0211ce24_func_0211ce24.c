/* Decompiled C draft; module arm9; ROM address 0211ce24. No matching claim. */
#include "types.h"
#include "deps/0211ce24_func_0211ce24.h"

undefined4 func_0211ce24(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  
  switch(*(undefined4 *)(*DAT_0211ce9c + 0x2c)) {
  case 0:
  case 1:
    iVar1 = func_0211d650();
    if (iVar1 == 1) {
      return 1;
    }
    break;
  case 2:
  case 3:
  case 4:
  case 5:
    bVar4 = true;
    iVar1 = *(int *)(*DAT_0211cea0 + 4);
    if ((iVar1 != 8) && (iVar1 != 9)) {
      bVar4 = false;
    }
    if (bVar4) {
      uVar2 = Math_CountPopulation(*(undefined1 *)(*DAT_0211cea0 + DAT_0211cea4));
    }
    else {
      uVar2 = 0;
    }
    uVar3 = func_0211d650();
    if ((uVar2 & 0xff) == uVar3) {
      return 1;
    }
  }
  return 0;
}

