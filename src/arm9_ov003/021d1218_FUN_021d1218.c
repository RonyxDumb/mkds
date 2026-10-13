/* Decompiled C draft; module arm9_ov003; ROM address 021d1218. No matching claim. */
#include "types.h"
#include "deps/021d1218_FUN_021d1218.h"

void FUN_021d1218(void)

{
  int *piVar1;
  undefined2 uVar2;
  short *psVar3;
  
  FUN_021d0128(*(undefined4 *)(*DAT_021d1270 + DAT_021d1274));
  *(undefined1 *)(*DAT_021d1270 + DAT_021d1278) = 1;
  uVar2 = func_0x02142eac();
  piVar1 = DAT_021d1270;
  *(undefined2 *)(*DAT_021d1270 + DAT_021d127c) = uVar2;
  func_0x0214d1fc((ushort *)(uintptr_t)(*(undefined4 *)(*piVar1 + DAT_021d1280)),(uint *)(uintptr_t)(*piVar1 + DAT_021d1284),0x40);
  piVar1 = DAT_021d1270;
  *(undefined1 *)(*DAT_021d1270 + DAT_021d1288) = 0;
  *(undefined4 *)(*piVar1 + DAT_021d128c) = 0;
  psVar3 = (short *)(*piVar1 + DAT_021d127c);
  *psVar3 = *psVar3 + 1;
  return;
}

