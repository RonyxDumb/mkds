/* Decompiled C draft; module arm9; ROM address 02116ef8. No matching claim. */
#include "types.h"
#include "deps/02116ef8_func_02116ef8.h"

void func_02116ef8(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  bool bVar4;
  uint uVar5;
  uint uVar6;
  undefined4 local_18;
  
  local_18 = 0xffffffff;
  if (*(int *)(*piRam02116fa0 + 0x20) == 0) {
    uVar5 = 1;
  }
  else {
    bVar4 = true;
    iVar3 = *(int *)(*piRam02116fa4 + 4);
    if ((iVar3 != 8) && (iVar3 != 9)) {
      bVar4 = false;
    }
    if (bVar4) {
      uVar5 = Math_CountPopulation(*(undefined1 *)(*piRam02116fa4 + iRam02116fa8));
    }
    else {
      uVar5 = 0;
    }
    uVar5 = uVar5 & 0xff;
  }
  puVar1 = puRam02116fac;
  uVar6 = 0;
  if (uVar5 != 0) {
    do {
      uVar2 = func_020296c0(uVar6 & 0xffff);
      func_0203be88(*(undefined4 *)*puVar1,uVar6 & 0xff,uVar2);
      uVar6 = uVar6 + 1;
    } while ((int)uVar6 < (int)uVar5);
  }
  func_0203bc64(*(undefined4 *)*puRam02116fac);
  puVar1 = puRam02116fac;
  if (uVar5 < 8) {
    do {
      func_0203be48(*(undefined4 *)*puVar1,uVar5 & 0xff,0,&local_18);
      func_020294e8(uVar5 & 0xffff,local_18);
      func_020294ac(uVar5 & 0xffff,1);
      uVar5 = uVar5 + 1;
    } while ((int)uVar5 < 8);
  }
  return;
}

