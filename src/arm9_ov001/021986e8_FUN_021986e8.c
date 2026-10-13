/* Decompiled C draft; module arm9_ov001; ROM address 021986e8. No matching claim. */
#include "types.h"
#include "deps/021986e8_FUN_021986e8.h"

void FUN_021986e8(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  iVar2 = func_0x02125f54();
  if (iVar2 != 0) {
    func_0x02125fc0();
    return;
  }
  iVar2 = func_0x02125f88();
  if (iVar2 != 0) {
    iVar2 = func_0x02125f60();
    piVar1 = DAT_02198764;
    if (iVar2 == 0) {
      *(undefined4 *)(*DAT_02198764 + 4) = 2;
      uVar3 = func_0x020b3f7c(*(undefined4 *)(*piVar1 + 0x14),0xd);
      uVar4 = func_0x020b3f7c(*(undefined4 *)(*DAT_02198764 + 0x14),0);
      uVar5 = func_0x020b3f7c(*(undefined4 *)(*DAT_02198764 + 0x14),1);
      func_0x0212611c(uVar3,uVar4,uVar5,0);
      return;
    }
    *(undefined2 *)(*DAT_02198764 + 0xe) = 0xe;
  }
  return;
}

