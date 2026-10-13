/* Decompiled C draft; module arm9_ov000; ROM address 021837b8. No matching claim. */
#include "types.h"
#include "deps/021837b8_FUN_021837b8.h"

void FUN_021837b8(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_0218380c;
  *(int *)(*DAT_0218380c + 8) = *(int *)(*DAT_0218380c + 8) + 1;
  if ((*(int *)(DAT_02183810 + *(int *)(*piVar1 + 0x30) * 4) <= *(int *)(*piVar1 + 8)) &&
     (iVar2 = func_0x02128274(), piVar1 = DAT_0218380c, iVar2 != 0)) {
    *(undefined4 *)(*DAT_0218380c + 4) = 0xb;
    *(undefined4 *)(*piVar1 + 0x20) = 4;
    *(undefined4 *)(*piVar1 + 8) = 0;
    func_0x02125fc0();
    func_0x02036f10(0x1e);
    func_0x0212ecc0(DAT_02183814,0,DAT_02183818);
  }
  return;
}

