/* Decompiled C draft; module arm9; ROM address 02009ae8. No matching claim. */
#include "types.h"
#include "deps/02009ae8_func_02009ae8.h"

void func_02009ae8(uint param_1)

{
  byte bVar1;
  ushort uVar2;
  int *piVar3;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  ushort *puVar8;
  
  func_021436d0(uRam02009bcc,param_1);
  piVar3 = piRam02009bd0;
  if ((param_1 != 0) && (param_1 < 0x10)) {
    iVar7 = param_1 - 1;
    *(undefined2 *)(*piRam02009bd0 + iVar7 * 2 + iRam02009bd4) = 0;
    Mem_CpuFill8(*piVar3 + iRam02009bd8 + iVar7 * 4,0,4);
    Mem_CpuFill8(*piRam02009bd0 + iRam02009bdc + iVar7 * 0x16,0);
    func_0200c3fc(param_1);
    piVar3 = piRam02009bd0;
    *(undefined2 *)(*piRam02009bd0 + iVar7 * 2 + iRam02009be0) = 0;
    bVar1 = *(byte *)(*piVar3 + iVar7 + iRam02009be4);
    if (bVar1 != 0xff) {
      iVar6 = iRam02009be8 * (uint)bVar1;
      puVar8 = (ushort *)(*piVar3 + iVar6 + iRam02009bec);
      uVar2 = (ushort)(1 << (param_1 & 0xff));
      *puVar8 = *puVar8 & ~uVar2;
      puVar8 = (ushort *)(*piVar3 + iVar6 + iRam02009bf0);
      *puVar8 = *puVar8 | uVar2;
      *(undefined1 *)(*piVar3 + (param_1 - 1) + iRam02009be4) = 0xff;
      puVar8 = (ushort *)(*piVar3 + iVar6 + iRam02009bf4);
      *puVar8 = *puVar8 & ~uVar2;
    }
    iVar6 = iRam02009bf8;
    piVar3 = piRam02009bd0;
    uVar4 = 1 << (param_1 & 0xff);
    if ((*(ushort *)(*piRam02009bd0 + iRam02009bf8) & uVar4) != 0) {
      pcVar5 = (char *)(*piRam02009bd0 + iRam02009bfc);
      *pcVar5 = *pcVar5 + -1;
      *(ushort *)(*piVar3 + iVar6) = *(ushort *)(*piVar3 + iVar6) & ~(ushort)uVar4;
    }
    *(undefined4 *)(*piRam02009bd0 + iVar7 * 4 + iRam02009c00) = 0;
  }
  return;
}

