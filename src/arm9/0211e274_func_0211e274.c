/* Decompiled C draft; module arm9; ROM address 0211e274. No matching claim. */
#include "types.h"
#include "deps/0211e274_func_0211e274.h"

undefined4 func_0211e274(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = 0xffffffff;
  switch(param_1) {
  case 0:
    iVar3 = *(int *)*DAT_0211e2f0;
    iVar1 = GetCourseIdFromInternalId(((int *)*DAT_0211e2f0)[3]);
    uVar2 = func_0206169c(iVar3 + iVar1 * 0x30);
    break;
  case 1:
    uVar2 = func_0206169c(*(int *)(*DAT_0211e2f0 + 4) +
                          DAT_0211e2f4 * ((int)*(short *)(*DAT_0211e2f0 + 0x10) & 0xffU));
    break;
  case 2:
    iVar3 = *(int *)(*DAT_0211e2f0 + 8);
    iVar1 = GetCourseIdFromInternalId(*(undefined4 *)(*DAT_0211e2f0 + 0xc));
    uVar2 = func_0206169c(iVar3 + DAT_0211e2f4 * iVar1);
    break;
  case 4:
  }
  return uVar2;
}

