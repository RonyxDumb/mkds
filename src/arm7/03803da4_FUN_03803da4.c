/* Decompiled C draft; module arm7; ROM address 03803da4. No matching claim. */
#include "types.h"
#include "deps/03803da4_FUN_03803da4.h"

undefined4 FUN_03803da4(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar3 = 1;
  uVar1 = FUN_037f8a1c();
  FUN_037f8b44(uVar1);
  iVar2 = 0;
  do {
    if (0x4d < iVar2) {
LAB_03803e30:
      thunk_FUN_037f8b24(uVar1);
      FUN_037f8ab4(uVar1);
      return uVar3;
    }
    uVar4 = (DAT_03803e4c ^ 0x84) & 0xffff;
    if ((iVar2 != 0x4c) && (uVar4 = DAT_03803e4c, iVar2 == 0x4d)) {
      uVar4 = (DAT_03803e4c ^ 3) & 0xffff;
    }
    if ((uVar4 & *(ushort *)(param_1 + iVar2 * 2)) != (uint)*(ushort *)(iVar2 * 2 + 0x8000004)) {
      uVar3 = 0;
      goto LAB_03803e30;
    }
    iVar2 = iVar2 + 1;
  } while( true );
}

