/* Decompiled C draft; module arm9; ROM address 02128624. No matching claim. */
#include "types.h"
#include "deps/02128624_func_02128624.h"

void func_02128624(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  ushort uVar5;
  int iVar6;
  
  iVar3 = iRam02128690;
  uVar2 = uRam0212868c;
  piVar1 = piRam02128688;
  uVar5 = (ushort)uRam02128678;
  iVar4 = iRam02128684;
  iVar6 = iRam02128680;
  if (param_1 == 0) {
    uVar5 = (ushort)uRam0212867c;
  }
  do {
    *(ushort *)(*piVar1 + iVar4 + 0x10) = *(ushort *)(*piVar1 + iVar4 + 0x10) & (ushort)uVar2;
    *(ushort *)(*piVar1 + iVar4 + 0x10) = *(ushort *)(*piVar1 + iVar4 + 0x10) | uVar5;
    iVar6 = iVar6 + 1;
    iVar4 = iVar4 + 2;
  } while (iVar6 < iVar3);
  if (*psRam02128694 != 2) {
    AllocateReserveTEQSub(0x1a,iRam02128684,*piVar1 + iRam02128698,uRam0212869c);
  }
  return;
}

