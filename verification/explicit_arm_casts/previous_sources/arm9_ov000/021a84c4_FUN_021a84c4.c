/* Decompiled C draft; module arm9_ov000; ROM address 021a84c4. No matching claim. */
#include "types.h"
#include "deps/021a84c4_FUN_021a84c4.h"

void FUN_021a84c4(int param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  bool bVar5;
  
  if (param_1 != 0) {
    *(undefined2 *)(param_1 + 0x70) = 0;
    piVar2 = DAT_021a8570;
    bVar5 = true;
    cVar1 = *(char *)(param_1 + 0x73);
    if ((cVar1 != '\0') && (cVar1 != '\x04')) {
      bVar5 = false;
    }
    if (bVar5) {
      FUN_021a8454(*(undefined4 *)(param_1 + 0x68));
      FUN_021a8454(*(undefined4 *)(param_1 + 100));
    }
    else if (cVar1 == '\x01') {
      piVar3 = *(int **)(*(int *)(param_1 + 100) + DAT_021a856c);
      while (piVar3 != (int *)0x0) {
        piVar3 = (int *)*piVar3;
        (**(code **)(*piVar2 + 0x1c))();
      }
      *(undefined2 *)(*(int *)(param_1 + 100) + DAT_021a8574) = 0;
      *(undefined4 *)(*(int *)(param_1 + 100) + DAT_021a8578) = 0;
      *(undefined4 *)(*(int *)(param_1 + 100) + DAT_021a856c) = 0;
      func_0x0200df9c(*(int *)(param_1 + 100) + DAT_021a857c);
      FUN_021a8454(*(undefined4 *)(param_1 + 100));
    }
    else if (cVar1 == '\x02') {
      FUN_021a8454(*(undefined4 *)(param_1 + 0x68));
    }
    uVar4 = func_0x0200fca0();
    FUN_021a8ae8(param_1);
    FUN_021a8aa8(param_1);
    (**(code **)(*DAT_021a8570 + 0x1c))(param_1);
    func_0x0200fcb4(uVar4);
  }
  return;
}

