/* Decompiled C draft; module arm9_ov001; ROM address 02196058. No matching claim. */
#include "types.h"
#include "deps/02196058_FUN_02196058.h"

void FUN_02196058(void)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = DAT_021960a0;
  *(int *)(*DAT_021960a0 + 0x58) = *(int *)(*DAT_021960a0 + 0x58) + 1;
  uVar2 = func_0x020ae4c0(1,0,0xffffff40,*(undefined4 *)(*piVar1 + 0x58),10);
  piVar1 = DAT_021960a0;
  *(undefined4 *)(*DAT_021960a0 + 0x5c) = uVar2;
  *(undefined4 *)(*piVar1 + 100) = uVar2;
  *(short *)(*(int *)(*piVar1 + 0x38) + 6) = (short)uVar2;
  if (9 < *(int *)(*piVar1 + 0x58)) {
    func_0x02111488(*(undefined4 *)(*piVar1 + 0x90));
  }
  return;
}

