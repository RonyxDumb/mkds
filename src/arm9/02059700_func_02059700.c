/* Decompiled C draft; module arm9; ROM address 02059700. No matching claim. */
#include "types.h"
#include "deps/02059700_func_02059700.h"

undefined4 func_02059700(void)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  iVar3 = *DAT_02059778;
  puVar2 = (undefined4 *)(iVar3 + DAT_0205977c);
  switch(*puVar2) {
  case 0:
    *puVar2 = 6;
    break;
  case 1:
    uVar4 = 1;
    break;
  case 6:
    if (*(byte *)(iVar3 + 0x87) == (*(byte *)(iVar3 + 0x87) & *(byte *)(iVar3 + DAT_02059780))) {
      *puVar2 = 7;
    }
    break;
  case 7:
    iVar3 = func_020505a8(5,0xff);
    piVar1 = DAT_02059778;
    if (iVar3 != 0) {
      *(undefined1 *)(*DAT_02059778 + DAT_02059780) = 0;
      *(undefined4 *)(*piVar1 + DAT_0205977c) = 1;
    }
  }
  return uVar4;
}

