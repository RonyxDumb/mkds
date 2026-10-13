/* Decompiled C draft; module arm9; ROM address 020297bc. No matching claim. */
#include "types.h"
#include "deps/020297bc_func_020297bc.h"

void func_020297bc(void)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = 0;
  func_0202991c(0);
  uVar3 = 0;
  do {
    iVar2 = func_02122794(uVar3 & 0xff);
    if (iVar2 != 0) {
      iVar2 = *piRam0202988c + uVar3 * 0x18;
      StructCO_ConfigureRacerDefault
                (uVar1,*(undefined4 *)(*piRam0202988c + uVar3 * 0x18),*(undefined4 *)(iVar2 + 4),
                 *(undefined4 *)(iVar2 + 8),0xffffffff,3);
      uVar1 = uVar1 + 1;
    }
    uVar3 = uVar3 + 1 & 0xffff;
  } while (uVar3 < 4);
  for (; uVar1 < 8; uVar1 = uVar1 + 1) {
    StructCO_ConfigureRacerDefault(uVar1,0xffffffff,0xffffffff,4,0xffffffff,3);
  }
  func_02029908(5);
  func_020298f4(*(undefined4 *)(*piRam0202988c + 0xd0));
  func_020298e0(1);
  func_020298cc(0);
  func_020298b8(0);
  func_020298a4(0);
  func_02029890(0);
  uVar4 = 0;
  uVar3 = 0;
  do {
    iVar2 = func_021227f8(uVar3);
    if (iVar2 != 0) {
      uVar4 = uVar4 | 1 << uVar3 & 0xffU;
    }
    uVar3 = uVar3 + 1 & 0xff;
  } while (uVar3 < 4);
  func_0205cfd4(uVar4);
  return;
}

