/* Decompiled C draft; module arm9; ROM address 02116d24. No matching claim. */
#include "types.h"
#include "deps/02116d24_func_02116d24.h"

void func_02116d24(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  piVar1 = piRam02116dbc;
  *(int *)(*piRam02116dbc + 0x28) = *(int *)(*piRam02116dbc + 0x28) + 1;
  iVar2 = *piVar1;
  if (3 < *(int *)(iVar2 + 0x28)) {
    *(short *)(iVar2 + 0x24) = *(short *)(iVar2 + 0x24) + 1;
    iVar2 = *piVar1;
    if (2 < *(ushort *)(iVar2 + 0x24)) {
      *(undefined2 *)(iVar2 + 0x24) = 0;
    }
    piVar1 = piRam02116dbc;
    *(undefined4 *)(*piRam02116dbc + 0x28) = 0;
    puVar4 = (undefined4 *)*piVar1;
    func_02124748(*(undefined2 *)(iRam02116dc0 + (uint)*(ushort *)(puVar4 + 9) * 2),*puVar4,
                  puVar4[1],puVar4[3],puVar4[8],puVar4[6],puVar4[4],puVar4[5]);
    iVar2 = *piRam02116dbc;
    iVar3 = *(int *)(*(int *)(iVar2 + 8) + 0xc);
    if (*(int *)(iVar2 + 0x20) == 0) {
      AllocateReserveTEQSub(0xe,(uint)*(ushort *)(iVar2 + 0x1c) << 5,iVar3 + iRam02116dc4,0x20);
      return;
    }
    if (*(int *)(iVar2 + 0x20) != 1) {
      return;
    }
    AllocateReserveTEQSub(0x1e,(uint)*(ushort *)(iVar2 + 0x1c) << 5,iVar3 + iRam02116dc4,0x20);
  }
  return;
}

