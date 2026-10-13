/* Decompiled C draft; module arm9; ROM address 0211e38c. No matching claim. */
#include "types.h"
#include "deps/0211e38c_func_0211e38c.h"

void func_0211e38c(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  switch(param_1) {
  case 0:
    iVar2 = *(int *)*DAT_0211e410;
    iVar1 = GetCourseIdFromInternalId(((int *)*DAT_0211e410)[3]);
    func_02061704(iVar2 + iVar1 * 0x30,param_2);
    return;
  case 1:
    func_02061704(*(int *)(*DAT_0211e410 + 4) +
                  DAT_0211e414 * ((int)*(short *)(*DAT_0211e410 + 0x10) & 0xffU));
    return;
  case 2:
    iVar2 = *(int *)(*DAT_0211e410 + 8);
    iVar1 = GetCourseIdFromInternalId(*(undefined4 *)(*DAT_0211e410 + 0xc));
    func_02061704(iVar2 + DAT_0211e414 * iVar1,param_2);
  }
  return;
}

