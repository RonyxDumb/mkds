/* Decompiled C draft; module arm9_ov000; ROM address 021a797c. No matching claim. */
#include "types.h"
#include "deps/021a797c_FUN_021a797c.h"

uint FUN_021a797c(int param_1,undefined4 param_2,uint param_3,undefined2 *param_4,int *param_5,
                 int param_6)

{
  ushort uVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  uint local_24;
  uint local_18;
  
  iVar5 = *(int *)(param_1 + 100);
  uVar3 = func_0x0200fca0(*(undefined4 *)(iVar5 + DAT_021a7a58));
  piVar6 = *(int **)(iVar5 + DAT_021a7a58);
  do {
    if (piVar6 != (int *)0x0) {
LAB_021a79e4:
      if (piVar6 != (int *)0x0) {
        local_24 = param_3;
        if ((int)(uint)*(ushort *)(piVar6 + 1) < (int)param_3) {
          local_24 = (uint)*(ushort *)(piVar6 + 1);
        }
        func_0x0214d1fc((ushort *)(void *)(piVar6 + 3),(uint *)(uintptr_t)(param_2),local_24);
        if (param_4 != (undefined2 *)0x0) {
          *param_4 = *(undefined2 *)((int)piVar6 + 6);
        }
        if (param_5 != (int *)0x0) {
          *param_5 = piVar6[2];
        }
        uVar1 = *(ushort *)(piVar6 + 1);
        local_18 = (uint)uVar1;
        if (*(char *)(iVar5 + 0xfe) == '\0') {
          *(int *)(iVar5 + DAT_021a7a58) = *piVar6;
          if (*piVar6 == 0) {
            *(undefined4 *)(iVar5 + DAT_021a7a60) = 0;
          }
          (**(code **)(*DAT_021a7a64 + 0x1c))(piVar6);
          *(short *)(iVar5 + DAT_021a7a68) = *(short *)(iVar5 + DAT_021a7a68) - uVar1;
        }
      }
      func_0x0200fcb4(uVar3);
      return local_18;
    }
    if (param_6 == 0) {
      local_18 = 0xfffffffa;
      goto LAB_021a79e4;
    }
    func_0x0200e01c(iVar5 + DAT_021a7a5c);
    iVar4 = FUN_021a8a80(param_1);
    if (iVar4 != 0) {
LAB_021a79d4:
      local_18 = 0xffffffc8;
      goto LAB_021a79e4;
    }
    bVar2 = false;
    if ((param_1 != 0) && ((*(ushort *)(param_1 + 0x70) & 1) != 0)) {
      bVar2 = true;
    }
    if (!bVar2) goto LAB_021a79d4;
    piVar6 = *(int **)(iVar5 + DAT_021a7a58);
  } while( true );
}

