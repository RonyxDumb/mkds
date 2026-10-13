/* Decompiled C draft; module arm9; ROM address 021139b4. No matching claim. */
#include "types.h"
#include "deps/021139b4_func_021139b4.h"

void func_021139b4(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  short extraout_r1;
  undefined2 *puVar5;
  int iVar6;
  undefined1 auStack_38 [36];
  
  iVar2 = func_02113f1c();
  iVar6 = 0;
  puVar5 = puRam02113a34;
  do {
    iVar3 = func_021143b4();
    if (iVar2 + iVar6 < iVar3) {
      func_02114298(iVar2 + iVar6 & 0xffff,auStack_38,0x20);
      iVar3 = *piRam02113a38;
      func_0212426c(1,*puVar5,*(undefined4 *)(iVar3 + 0x38),auStack_38,*(undefined4 *)(iVar3 + 0x30)
                    ,*(undefined4 *)(iVar3 + 0x3c));
    }
    puVar5 = puVar5 + 1;
    iVar6 = iVar6 + 1;
  } while (iVar6 < 5);
  iVar6 = func_021143b4();
  if (iVar6 <= iVar2 + *(short *)(*piRam02113a38 + 0x68)) {
    uVar4 = func_021143b4();
    _s32_div_f(uVar4,5);
    piVar1 = piRam02113a38;
    *(short *)(*piRam02113a38 + 0x68) = extraout_r1 + -1;
    *(undefined2 *)(*piVar1 + 0x74) = *(undefined2 *)(*piVar1 + 0x68);
  }
  func_02113a3c();
  return;
}

