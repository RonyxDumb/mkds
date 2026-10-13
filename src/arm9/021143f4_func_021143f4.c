/* Decompiled C draft; module arm9; ROM address 021143f4. No matching claim. */
#include "types.h"
#include "deps/021143f4_func_021143f4.h"

void func_021143f4(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  piVar1 = piRam021144b0;
  uVar6 = 0;
  *(undefined2 *)*piRam021144b0 = 0;
  uVar4 = 0;
  do {
    iVar2 = func_02060b34(uVar4 & 0xff);
    if (iVar2 != 0) {
      *(short *)*piVar1 = *(short *)*piVar1 + 1;
      iVar2 = func_02060afc(uVar4 & 0xff);
      if (iVar2 != 0) {
        uVar6 = uVar6 + 1 & 0xffff;
      }
    }
    uVar4 = uVar4 + 1;
  } while ((int)uVar4 < 0x3c);
  if (*(short *)*piRam021144b0 != 0) {
    uVar4 = 0;
    iVar2 = 0;
    iVar5 = uVar6 << 1;
    do {
      iVar3 = func_02060b34(uVar4 & 0xff);
      if (iVar3 != 0) {
        iVar3 = func_02060afc(uVar4 & 0xff);
        if (iVar3 == 0) {
          *(ushort *)(*(int *)(*piRam021144b0 + 4) + iVar5) = (ushort)uVar4 & 0xff;
          iVar5 = iVar5 + 2;
        }
        else {
          *(ushort *)(*(int *)(*piRam021144b0 + 4) + iVar2) = (ushort)uVar4 & 0xff;
          iVar2 = iVar2 + 2;
        }
      }
      uVar4 = uVar4 + 1;
    } while ((int)uVar4 < 0x3c);
    func_02114504(0,uVar6);
    func_02114504(uVar6,*(ushort *)*piRam021144b0 - uVar6 & 0xffff);
  }
  return;
}

