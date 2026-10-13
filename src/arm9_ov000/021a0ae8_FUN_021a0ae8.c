/* Decompiled C draft; module arm9_ov000; ROM address 021a0ae8. No matching claim. */
#include "types.h"
#include "deps/021a0ae8_FUN_021a0ae8.h"

undefined4
FUN_021a0ae8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 *param_5,int param_6)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  int local_22c;
  undefined1 auStack_228 [16];
  undefined1 local_218 [516];
  
  iVar5 = 0;
  iVar4 = *DAT_021a0bfc;
  if ((*(char *)(iVar4 + 0x15) == '\0') ||
     (((*(char *)(iVar4 + 0x15) == '\x03' || (*(char *)(iVar4 + DAT_021a0c00) != '\0')) &&
      (param_1 == 6)))) {
    uVar3 = FUN_021a0a40(param_1,param_3,param_4,(int)(uintptr_t)(param_5),param_6);
  }
  else {
    if ((param_5 != (undefined4 *)0x0) && (param_6 != 0)) {
      iVar5 = func_0x0200d9e0((undefined4)(uintptr_t)(local_218),DAT_021a0c04,DAT_021a0c08,*param_5);
      local_22c = 1;
      puVar1 = param_5;
      if (1 < param_6) {
        do {
          iVar4 = func_0x0200d9e0((undefined4)(uintptr_t)(auStack_228),0x10,DAT_021a0c0c,puVar1[1]);
          func_0x0214d1fc((ushort *)(void *)(auStack_228),(uint *)(void *)(local_218 + iVar5),iVar4);
          iVar5 = iVar5 + iVar4;
          local_22c = local_22c + 1;
          puVar1 = puVar1 + 1;
        } while (local_22c < param_6);
      }
    }
    local_218[iVar5] = 0;
    uVar3 = FUN_021a09d0(*(undefined4 *)*DAT_021a0bfc,param_1,param_2);
  }
  piVar2 = DAT_021a0bfc;
  if (((param_1 == 2) || (param_1 == 6)) || ((param_1 + 0xf8U & 0xff) < 2)) {
    *(char *)(*DAT_021a0bfc + DAT_021a0c10) = (char)param_1;
    *(short *)(*piVar2 + DAT_021a0c14) = (short)param_4;
    *(undefined4 *)(*piVar2 + DAT_021a0c18) = param_3;
    *(undefined4 *)(*piVar2 + DAT_021a0c1c) = param_2;
    *(int *)(*piVar2 + DAT_021a0c20) = param_6;
    iVar5 = *piVar2;
    uVar6 = FUN_021a350c();
    *(int *)(iVar5 + DAT_021a0c24) = (int)uVar6;
    *(int *)(iVar5 + DAT_021a0c28) = (int)((ulonglong)uVar6 >> 0x20);
    if ((param_5 != (undefined4 *)0x0) && (param_6 != 0)) {
      func_0x0214d02c(param_5,(undefined4 *)(uintptr_t)(iVar5 + DAT_021a0c2c),param_6 << 2);
    }
  }
  return uVar3;
}

