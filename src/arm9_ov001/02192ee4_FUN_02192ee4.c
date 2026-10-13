/* Decompiled C draft; module arm9_ov001; ROM address 02192ee4. No matching claim. */
#include "types.h"
#include "deps/02192ee4_FUN_02192ee4.h"

void FUN_02192ee4(void)

{
  int *piVar1;
  undefined4 uVar2;
  code *pcVar3;
  
  if (*(code **)(*DAT_02192f88 + 0x20) != (code *)0x0) {
    (**(code **)(*DAT_02192f88 + 0x20))();
  }
  if (*(int *)(*DAT_02192f88 + 0xc) != -1) {
    (**(code **)(*DAT_02192f88 + 0x1c))();
    FUN_021932c8();
    func_0x02036ab0(*(undefined4 *)(*DAT_02192f88 + 4));
    uVar2 = func_0x020369fc(*(undefined4 *)*DAT_02192f88);
    piVar1 = DAT_02192f88;
    *(undefined4 *)(*DAT_02192f88 + 4) = uVar2;
    switch(*(undefined4 *)(*piVar1 + 0xc)) {
    case 0:
      FUN_021932e4();
      break;
    case 1:
      FUN_02198854();
      break;
    case 2:
      FUN_02199964();
      break;
    case 3:
      FUN_0219d5dc();
    }
    piVar1 = DAT_02192f88;
    *(undefined4 *)(*DAT_02192f88 + 0x10) = *(undefined4 *)(*DAT_02192f88 + 8);
    *(undefined4 *)(*piVar1 + 8) = *(undefined4 *)(*piVar1 + 0xc);
    *(undefined4 *)(*piVar1 + 0xc) = 0xffffffff;
    pcVar3 = *(code **)(*piVar1 + 0x18);
    if (pcVar3 != (code *)0x0) {
      (*pcVar3)(*(undefined4 *)(*piVar1 + 4));
    }
  }
  func_0x02125928();
  func_0x0212a920();
  return;
}

