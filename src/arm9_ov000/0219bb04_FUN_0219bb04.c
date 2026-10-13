/* Decompiled C draft; module arm9_ov000; ROM address 0219bb04. No matching claim. */
#include "types.h"
#include "deps/0219bb04_FUN_0219bb04.h"

undefined4 FUN_0219bb04(int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = DAT_0219bb44;
  if (*DAT_0219bb44 == 0) {
    return 0;
  }
  *param_1 = *DAT_0219bb44 + DAT_0219bb48;
  if ((*(char *)(*piVar1 + DAT_0219bb4c) != '\x02') && (*(char *)(*piVar1 + DAT_0219bb4c) != '\x03')
     ) {
    uVar2 = FUN_021a158c();
    return uVar2;
  }
  uVar2 = FUN_021a1514();
  return uVar2;
}

