/* Decompiled C draft; module arm9; ROM address 02116fb0. No matching claim. */
#include "types.h"
#include "deps/02116fb0_func_02116fb0.h"

void func_02116fb0(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  bool bVar4;
  uint uVar5;
  uint uVar6;
  undefined4 local_18;
  
  local_18 = 0xffffffff;
  if (*(int *)(*piRam02117050 + 0x20) == 0) {
    uVar5 = 1;
  }
  else {
    bVar4 = true;
    iVar3 = *(int *)(*piRam02117054 + 4);
    if ((iVar3 != 8) && (iVar3 != 9)) {
      bVar4 = false;
    }
    if (bVar4) {
      uVar5 = Math_CountPopulation(*(undefined1 *)(*piRam02117054 + iRam02117058));
    }
    else {
      uVar5 = 0;
    }
    uVar5 = uVar5 & 0xff;
  }
  puVar1 = puRam0211705c;
  uVar6 = 0;
  if (uVar5 != 0) {
    do {
      uVar2 = func_020296d4(uVar6 & 0xffff);
      func_0203bea4(*(undefined4 *)*puVar1,uVar6 & 0xff,uVar2);
      uVar6 = uVar6 + 1;
    } while ((int)uVar6 < (int)uVar5);
  }
  func_0203ba84(*(undefined4 *)*puRam0211705c);
  puVar1 = puRam0211705c;
  if (uVar5 < 8) {
    do {
      func_0203be48(*(undefined4 *)*puVar1,uVar5 & 0xff,&local_18,0);
      func_020294fc(uVar5 & 0xffff,local_18);
      uVar5 = uVar5 + 1;
    } while ((int)uVar5 < 8);
  }
  return;
}

