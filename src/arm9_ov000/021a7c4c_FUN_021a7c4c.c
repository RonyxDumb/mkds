/* Decompiled C draft; module arm9_ov000; ROM address 021a7c4c. No matching claim. */
#include "types.h"
#include "deps/021a7c4c_FUN_021a7c4c.h"

int FUN_021a7c4c(int param_1,undefined4 param_2,int param_3,undefined2 *param_4,undefined4 *param_5)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined2 local_24;
  undefined2 local_22;
  int local_20;
  undefined4 local_1c [2];
  
  uVar2 = func_0x0200fca0();
  iVar3 = FUN_021a7bfc(param_1,&local_20,&local_24,&local_22,local_1c);
  if (iVar3 == 0) {
    if (local_20 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = -0x1c;
    }
    *(ushort *)(param_1 + 0x70) = *(ushort *)(param_1 + 0x70) & 0xfff9;
  }
  else if (local_20 == 0) {
    iVar4 = -6;
  }
  else {
    if (local_20 < param_3) {
      param_3 = local_20;
    }
    bVar1 = true;
    if ((*(char *)(param_1 + 0x73) != '\0') && (*(char *)(param_1 + 0x73) != '\x04')) {
      bVar1 = false;
    }
    iVar4 = local_20;
    if (bVar1) {
      iVar4 = param_3;
    }
    func_0x0214d1fc((ushort *)(uintptr_t)(iVar3),(uint *)(uintptr_t)(param_2),param_3);
    iVar3 = *(int *)(param_1 + 100);
    if (*(char *)(iVar3 + 0xfe) == '\0') {
      *(int *)(iVar3 + 0xf8) = *(int *)(iVar3 + 0xf8) + iVar4;
    }
  }
  if (-1 < iVar4) {
    if ((param_4 != (undefined2 *)0x0) && (param_5 != (undefined4 *)0x0)) {
      *param_4 = local_22;
      *param_5 = local_1c[0];
    }
    if (*(short *)(param_1 + 0x74) == 0) {
      *(undefined2 *)(param_1 + 0x74) = local_24;
    }
  }
  func_0x0200fcb4(uVar2);
  return iVar4;
}

