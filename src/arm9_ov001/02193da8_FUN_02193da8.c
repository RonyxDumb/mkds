/* Decompiled C draft; module arm9_ov001; ROM address 02193da8. No matching claim. */
#include "types.h"
#include "deps/02193da8_FUN_02193da8.h"

void FUN_02193da8(void)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = DAT_02193de8;
  *(int *)(*DAT_02193de8 + 0x68) = *(int *)(*DAT_02193de8 + 0x68) + 1;
  uVar2 = func_0x020ae4c0(1,0,0xffffff40,*(undefined4 *)(*piVar1 + 0x68),10);
  piVar1 = DAT_02193de8;
  *(undefined4 *)(*DAT_02193de8 + 0x6c) = uVar2;
  if (9 < *(int *)(*piVar1 + 0x68)) {
    func_0x02111488(*(undefined4 *)(*piVar1 + 0x90));
  }
  return;
}

