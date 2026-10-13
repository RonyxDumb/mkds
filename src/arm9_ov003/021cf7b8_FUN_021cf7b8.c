/* Decompiled C draft; module arm9_ov003; ROM address 021cf7b8. No matching claim. */
#include "types.h"
#include "deps/021cf7b8_FUN_021cf7b8.h"

void FUN_021cf7b8(uint param_1)

{
  ushort uVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = func_0x02007d50(param_1,0);
  if (iVar3 == 0) {
    uVar1 = ~(ushort)(1 << (param_1 & 0xff));
    func_0x0200fca0();
    piVar2 = DAT_021cf840;
    *(ushort *)(*DAT_021cf840 + 2) = *(ushort *)(*DAT_021cf840 + 2) & uVar1;
    *(ushort *)(*piVar2 + 4) = *(ushort *)(*piVar2 + 4) & uVar1;
    *(ushort *)(*piVar2 + 6) = *(ushort *)(*piVar2 + 6) & uVar1;
    *(ushort *)(*piVar2 + 8) = *(ushort *)(*piVar2 + 8) & uVar1;
    *(ushort *)(*piVar2 + 10) = *(ushort *)(*piVar2 + 10) & uVar1;
    *(ushort *)(*piVar2 + 0xc) = *(ushort *)(*piVar2 + 0xc) & uVar1;
    func_0x0200fcb4();
    func_0x02009ae8(param_1);
    return;
  }
  func_0x0200fca0();
  piVar2 = DAT_021cf840;
  uVar1 = (ushort)(1 << (param_1 & 0xff));
  *(ushort *)(*DAT_021cf840 + 4) = *(ushort *)(*DAT_021cf840 + 4) & ~uVar1;
  *(ushort *)(*piVar2 + 2) = *(ushort *)(*piVar2 + 2) & ~uVar1;
  func_0x0200fcb4();
  return;
}

