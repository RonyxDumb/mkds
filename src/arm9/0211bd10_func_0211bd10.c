/* Decompiled C draft; module arm9; ROM address 0211bd10. No matching claim. */
#include "types.h"
#include "deps/0211bd10_func_0211bd10.h"

void func_0211bd10(void)

{
  ushort uVar1;
  int iVar2;
  bool bVar3;
  
  switch(*(undefined4 *)(*DAT_0211bd78 + 0x2c)) {
  case 0:
  case 1:
    *(undefined2 *)(*DAT_0211bd78 + 0xac) = 1;
    return;
  case 2:
  case 3:
  case 4:
  case 5:
    bVar3 = true;
    iVar2 = *(int *)(*DAT_0211bd7c + 4);
    if ((iVar2 != 8) && (iVar2 != 9)) {
      bVar3 = false;
    }
    if (bVar3) {
      uVar1 = Math_CountPopulation(*(undefined1 *)(*DAT_0211bd7c + DAT_0211bd80));
    }
    else {
      uVar1 = 0;
    }
    *(ushort *)(*DAT_0211bd78 + 0xac) = uVar1 & 0xff;
  }
  return;
}

