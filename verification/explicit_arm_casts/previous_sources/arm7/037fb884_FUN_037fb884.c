/* Decompiled C draft; module arm7; ROM address 037fb884. No matching claim. */
#include "types.h"
#include "deps/037fb884_FUN_037fb884.h"

undefined4 FUN_037fb884(void)

{
  int iVar1;
  undefined4 uVar2;
  longlong lVar3;
  
  iVar1 = FUN_037fa3b0();
  if ((iVar1 == 0) || (iVar1 = FUN_037fa824(), iVar1 == 0)) {
    uVar2 = 0;
  }
  else if (*(uint *)((uint)DAT_037fb914 & 0xfffffffc) >> ((uint)DAT_037fb914 & 3) * 8 == 0 &&
           *(uint *)((uint)DAT_037fb914 & 0xfffffffc) << ((uint)DAT_037fb914 & 3) * -8 + 0x20 == 0)
  {
    FUN_037fa814(DAT_037fb918);
    lVar3 = FUN_037fa278();
    FUN_037fa5f4(DAT_037fb918,(int)(lVar3 + (ulonglong)DAT_037fb920),
                 (int)(lVar3 + (ulonglong)DAT_037fb920 >> 0x20),DAT_037fb920,0,DAT_037fb91c,0);
    uVar2 = 1;
    *DAT_037fb914 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

