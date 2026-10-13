/* Decompiled C draft; module arm9_ov003; ROM address 021cf5ac. No matching claim. */
#include "types.h"
#include "deps/021cf5ac_FUN_021cf5ac.h"

void FUN_021cf5ac(void)

{
  ushort uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  piVar2 = DAT_021cf648;
  uVar6 = 0;
  uVar4 = 1;
  do {
    uVar5 = 1 << (uVar4 & 0xff);
    if ((*(ushort *)(*piVar2 + 10) & uVar5) != 0) {
      iVar3 = func_0x02007d50(uVar4,3);
      if (iVar3 == 0) {
        uVar1 = ~(ushort)uVar5;
        func_0x0200fca0();
        *(ushort *)(*piVar2 + 2) = *(ushort *)(*piVar2 + 2) & uVar1;
        *(ushort *)(*piVar2 + 4) = *(ushort *)(*piVar2 + 4) & uVar1;
        *(ushort *)(*piVar2 + 6) = *(ushort *)(*piVar2 + 6) & uVar1;
        *(ushort *)(*piVar2 + 8) = *(ushort *)(*piVar2 + 8) & uVar1;
        *(ushort *)(*piVar2 + 10) = *(ushort *)(*piVar2 + 10) & uVar1;
        *(ushort *)(*piVar2 + 0xc) = *(ushort *)(*piVar2 + 0xc) & uVar1;
        func_0x0200fcb4();
        func_0x02009ae8(uVar4);
      }
      else {
        uVar6 = uVar6 | uVar5 & 0xffff;
      }
    }
    uVar4 = uVar4 + 1 & 0xffff;
  } while (uVar4 < 0x10);
  if (uVar6 == 0) {
    FUN_021cf36c(7);
    return;
  }
  FUN_021cf36c(4);
  return;
}

