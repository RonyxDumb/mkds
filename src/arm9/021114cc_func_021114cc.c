/* Decompiled C draft; module arm9; ROM address 021114cc. No matching claim. */
#include "types.h"
#include "deps/021114cc_func_021114cc.h"

void func_021114cc(void)

{
  int *piVar1;
  undefined4 uVar2;
  
  if (*(int *)(*DAT_02111580 + 0xc) != -1) {
    (**(code **)(*DAT_02111580 + 0x1c))();
    func_02111a98();
    Mem_DestroyHeap(*(undefined4 *)(*DAT_02111580 + 4));
    uVar2 = Mem_CreateChildExpHeap(*(undefined4 *)*DAT_02111580);
    piVar1 = DAT_02111580;
    *(undefined4 *)(*DAT_02111580 + 4) = uVar2;
    switch(*(undefined4 *)(*piVar1 + 0xc)) {
    case 0:
      if (*(int *)(*piVar1 + 8) == 3) {
        func_021143f4();
      }
      func_0x0219a050();
      break;
    case 1:
      func_0x02193c5c();
      break;
    case 2:
      func_0x021956dc();
      break;
    case 3:
      func_02111ab4();
      break;
    case 4:
      func_021145b4();
    }
    piVar1 = DAT_02111580;
    *(undefined4 *)(*DAT_02111580 + 0x10) = *(undefined4 *)(*DAT_02111580 + 8);
    *(undefined4 *)(*piVar1 + 8) = *(undefined4 *)(*piVar1 + 0xc);
    *(undefined4 *)(*piVar1 + 0xc) = 0xffffffff;
    *(undefined4 *)(*piVar1 + 0x2c) = 2;
    (**(code **)(*piVar1 + 0x18))(*(undefined4 *)(*piVar1 + 4));
  }
  (**(code **)(*DAT_02111580 + 0x20))();
  NavigationContext_OnSceneUpdate_from_thumb();
  func_0212a920();
  return;
}

