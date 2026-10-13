/* Decompiled C draft; module arm9; ROM address 02117060. No matching claim. */
#include "types.h"
#include "deps/02117060_func_02117060.h"

void func_02117060(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  bool bVar4;
  uint uVar5;
  uint uVar6;
  
  StructKTB_SomeFn_from_thumb((undefined1 *)(uintptr_t)(*(undefined4 *)*puRam021170e8));
  if (*(int *)(*piRam021170ec + 0x20) == 0) {
    uVar5 = 1;
  }
  else {
    bVar4 = true;
    iVar2 = *(int *)(*piRam021170f0 + 4);
    if ((iVar2 != 8) && (iVar2 != 9)) {
      bVar4 = false;
    }
    if (bVar4) {
      uVar5 = Math_CountPopulation(*(undefined1 *)(*piRam021170f0 + iRam021170f4));
    }
    else {
      uVar5 = 0;
    }
    uVar5 = uVar5 & 0xff;
  }
  puVar1 = puRam021170e8;
  uVar6 = 0;
  do {
    uVar3 = func_020296d4(uVar6 & 0xffff);
    func_0203bea4(*(undefined4 *)*puVar1,uVar6 & 0xff,uVar3);
    uVar6 = uVar6 + 1;
  } while ((int)uVar6 < 8);
  if (uVar5 < 8) {
    do {
      func_020294e8(uVar5 & 0xffff,0xffffffff);
      func_020294ac(uVar5 & 0xffff,0);
      uVar5 = uVar5 + 1;
    } while ((int)uVar5 < 8);
  }
  return;
}

