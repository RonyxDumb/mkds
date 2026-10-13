/* Decompiled C draft; module arm9; ROM address 02116244. No matching claim. */
#include "types.h"
#include "deps/02116244_func_02116244.h"

void func_02116244(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  short extraout_r1;
  undefined2 *puVar5;
  int iVar6;
  undefined1 auStack_38 [36];
  
  iVar2 = func_02116870();
  iVar6 = 0;
  puVar5 = puRam021162c4;
  do {
    iVar3 = func_021143b4();
    if (iVar2 + iVar6 < iVar3) {
      func_02114298(iVar2 + iVar6 & 0xffff,auStack_38,0x20);
      iVar3 = *piRam021162c8;
      func_0212426c(1,*puVar5,*(undefined4 *)(iVar3 + 0x38),auStack_38,*(undefined4 *)(iVar3 + 0x30)
                    ,*(undefined4 *)(iVar3 + 0x3c));
    }
    puVar5 = puVar5 + 1;
    iVar6 = iVar6 + 1;
  } while (iVar6 < 5);
  iVar6 = func_021143b4();
  if (iVar6 <= iVar2 + *(short *)(*piRam021162c8 + 0x74)) {
    uVar4 = func_021143b4();
    _s32_div_f(uVar4,5);
    piVar1 = piRam021162c8;
    *(short *)(*piRam021162c8 + 0x74) = extraout_r1 + -1;
    *(undefined2 *)(*piVar1 + 0x80) = *(undefined2 *)(*piVar1 + 0x74);
  }
  func_021162cc();
  return;
}

