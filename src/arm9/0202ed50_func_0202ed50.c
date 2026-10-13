/* Decompiled C draft; module arm9; ROM address 0202ed50. No matching claim. */
#include "types.h"
#include "deps/0202ed50_func_0202ed50.h"

void func_0202ed50(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ushort *puVar5;
  int iVar6;
  
  piVar1 = piRam0202edbc;
  iVar3 = 1;
  do {
    iVar4 = 0x1c;
    do {
      iVar6 = (iVar4 + iVar3 * 0x20) * 2;
      iVar2 = *piVar1 + iVar6;
      puVar5 = (ushort *)(iVar2 + 0x58);
      *puVar5 = *(ushort *)(iVar2 + 0x58) & (ushort)uRam0202edc0;
      iVar6 = *piVar1 + iVar6;
      *(ushort *)(iVar6 + 0x58) = *(ushort *)(iVar6 + 0x58) | (ushort)(param_1 << 0xc);
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x20);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x13);
  *(undefined4 *)(*piVar1 + iRam0202edc4) = 5;
  *(int *)(*piVar1 + iRam0202edc8) = param_1;
  AllocateReserveTEQSub(0x1b,0,*piVar1 + 0x58,uRam0202edcc,param_1,puVar5);
  return;
}

