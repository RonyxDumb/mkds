/* Decompiled C draft; module arm9_ov003; ROM address 021cfed8. No matching claim. */
#include "types.h"
#include "deps/021cfed8_FUN_021cfed8.h"

undefined2 FUN_021cfed8(void)

{
  int *piVar1;
  undefined2 uVar2;
  
  if (*(int *)(*DAT_021cff28 + 0x40) != 7) {
    func_0x0200fd1c();
  }
  FUN_021d07b0(1);
  uVar2 = FUN_021cfe40(*(undefined2 *)(*DAT_021cff28 + 0x60));
  piVar1 = DAT_021cff28;
  *(undefined2 *)(*DAT_021cff28 + 0x5c) = uVar2;
  if ((code *)*DAT_021cff2c != (code *)0x0) {
    (*(code *)*DAT_021cff2c)(DAT_021cff30,DAT_021cff34,*(undefined2 *)(*piVar1 + 0x5c));
  }
  return *(undefined2 *)(*DAT_021cff28 + 0x5c);
}

