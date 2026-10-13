/* Decompiled C draft; module arm9; ROM address 02032028. No matching claim. */
#include "types.h"
#include "deps/02032028_func_02032028.h"

void func_02032028(void)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar2 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam02032068 + 100),0xb);
  uVar3 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam02032068 + 0x68),4);
  piVar1 = piRam02032068;
  *(undefined4 *)(*piRam02032068 + 0x70) = 8;
  *(undefined4 *)(*piVar1 + 0x94) = 5;
  TextSystem_DisplaySingleButtonDialog_Simple_from_thumb(uVar2,uVar3);
  func_021282c8();
  return;
}

