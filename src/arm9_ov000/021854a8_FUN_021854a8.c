/* Decompiled C draft; module arm9_ov000; ROM address 021854a8. No matching claim. */
#include "types.h"
#include "deps/021854a8_FUN_021854a8.h"

void FUN_021854a8(void)

{
  int *piVar1;
  undefined2 uVar2;
  int iVar3;
  
  piVar1 = DAT_021854f4;
  *(int *)(*DAT_021854f4 + 8) = *(int *)(*DAT_021854f4 + 8) + 1;
  uVar2 = func_0x020ae4c0(1,0x50,0,*(undefined4 *)(*piVar1 + 8),0xf);
  piVar1 = DAT_021854f4;
  *(undefined2 *)(*DAT_021854f4 + 0xc) = uVar2;
  if ((0xe < *(int *)(*piVar1 + 8)) &&
     (iVar3 = func_0x02125fa4(), piVar1 = DAT_021854f4, iVar3 != 0)) {
    *(undefined4 *)(*DAT_021854f4 + 4) = 1;
    *(undefined4 *)(*piVar1 + 8) = 0;
  }
  return;
}

