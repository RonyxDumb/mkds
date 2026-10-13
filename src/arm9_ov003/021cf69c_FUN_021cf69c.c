/* Decompiled C draft; module arm9_ov003; ROM address 021cf69c. No matching claim. */
#include "types.h"
#include "deps/021cf69c_FUN_021cf69c.h"

void FUN_021cf69c(void)

{
  ushort uVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  FUN_021cf36c(3);
  piVar2 = DAT_021cf728;
  uVar5 = 1;
  do {
    uVar3 = 1 << (uVar5 & 0xff);
    iVar4 = *piVar2;
    if (((*(ushort *)(iVar4 + 2) & uVar3) != 0) && ((*(ushort *)(iVar4 + 4) & uVar3) == 0)) {
      if ((*(ushort *)(iVar4 + 6) & uVar3) == 0) {
        uVar1 = ~(ushort)uVar3;
        func_0x0200fca0();
        *(ushort *)(*piVar2 + 2) = *(ushort *)(*piVar2 + 2) & uVar1;
        *(ushort *)(*piVar2 + 4) = *(ushort *)(*piVar2 + 4) & uVar1;
        *(ushort *)(*piVar2 + 6) = *(ushort *)(*piVar2 + 6) & uVar1;
        *(ushort *)(*piVar2 + 8) = *(ushort *)(*piVar2 + 8) & uVar1;
        *(ushort *)(*piVar2 + 10) = *(ushort *)(*piVar2 + 10) & uVar1;
        *(ushort *)(*piVar2 + 0xc) = *(ushort *)(*piVar2 + 0xc) & uVar1;
        func_0x0200fcb4();
        func_0x02009ae8(uVar5);
      }
      else {
        FUN_021cf72c(uVar5);
      }
    }
    uVar5 = uVar5 + 1 & 0xffff;
  } while (uVar5 < 0x10);
  return;
}

