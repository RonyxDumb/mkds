/* Decompiled C draft; module arm9_ov003; ROM address 021cf844. No matching claim. */
#include "types.h"
#include "deps/021cf844_FUN_021cf844.h"

void FUN_021cf844(uint param_1)

{
  ushort uVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = func_0x02007d50(param_1,1);
  if (iVar3 == 0) {
    uVar1 = ~(ushort)(1 << (param_1 & 0xff));
    func_0x0200fca0();
    piVar2 = DAT_021cf8a8;
    *(ushort *)(*DAT_021cf8a8 + 2) = *(ushort *)(*DAT_021cf8a8 + 2) & uVar1;
    *(ushort *)(*piVar2 + 4) = *(ushort *)(*piVar2 + 4) & uVar1;
    *(ushort *)(*piVar2 + 6) = *(ushort *)(*piVar2 + 6) & uVar1;
    *(ushort *)(*piVar2 + 8) = *(ushort *)(*piVar2 + 8) & uVar1;
    *(ushort *)(*piVar2 + 10) = *(ushort *)(*piVar2 + 10) & uVar1;
    *(ushort *)(*piVar2 + 0xc) = *(ushort *)(*piVar2 + 0xc) & uVar1;
    func_0x0200fcb4();
    func_0x02009ae8(param_1);
  }
  return;
}

