/* Decompiled C draft; module arm7; ROM address 037f846c. No matching claim. */
#include "types.h"
#include "deps/037f846c_FUN_037f846c.h"

void FUN_037f846c(void)

{
  undefined4 uVar1;
  int iVar2;
  
  FUN_027e0000();
  FUN_037f9ab4();
  FUN_037f93cc();
  FUN_037f8228();
  thunk_FUN_037fb72c();
  uVar1 = FUN_037f83c0();
  FUN_037fc3d0(6);
  FUN_037fb884();
  FUN_037f8944(1,DAT_037f851c);
  FUN_037f888c(1);
  *DAT_037f8520 = *DAT_037f8520 | 8;
  *DAT_037f8524 = 1;
  FUN_037faf5c();
  FUN_037ffdc0(0xffffffff);
  FUN_037ffe4c(0xf);
  FUN_038056c0(0xc);
  FUN_0380687c(uVar1);
  FUN_03801610(2);
  do {
    thunk_FUN_038011be();
    iVar2 = FUN_037fb0d4();
    if (iVar2 != 0) {
      FUN_037fb014();
    }
    FUN_03803c90();
    FUN_03800f58();
  } while( true );
}

