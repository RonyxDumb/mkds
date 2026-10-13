/* Decompiled C draft; module arm9; ROM address 02008aa0. No matching claim. */
#include "types.h"
#include "deps/02008aa0_func_02008aa0.h"

void func_02008aa0(uint param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  iVar6 = *piRam02008bdc + 0x10 + iRam02008be0 * param_1;
  cVar1 = *(char *)(*piRam02008be4 + 6);
  if (*(char *)(iVar6 + iRam02008be8) == cVar1) {
    if (*(short *)(iVar6 + iRam02008bf0) == *(short *)(*piRam02008be4 + 0xc)) {
      return;
    }
  }
  else {
    if ((char)(*(char *)(iVar6 + iRam02008be8) + '\x01') == cVar1) {
      uVar4 = 0;
      iVar7 = iVar6 + iRam02008bec;
      do {
        if (((uint)*(ushort *)(*piRam02008be4 + 0xe) & 2 << (uVar4 & 0xff)) != 0) {
          Mem_CpuFill16(0,iVar7,0x16);
        }
        iVar7 = iVar7 + 0x16;
        uVar4 = uVar4 + 1;
      } while ((int)uVar4 < 0xf);
      *(ushort *)(iVar6 + iRam02008bf0) =
           *(ushort *)(iVar6 + iRam02008bf0) & ~*(ushort *)(*piRam02008be4 + 0xe);
      *(ushort *)(*piRam02008bdc + 4) =
           *(ushort *)(*piRam02008bdc + 4) & ~(ushort)(1 << (param_1 & 0xff));
    }
    else {
      Mem_CpuFill16(0,iVar6 + iRam02008bec,uRam02008bf4);
      *(undefined2 *)(iVar6 + iRam02008bf0) = 0;
      *(ushort *)(*piRam02008bdc + 4) =
           *(ushort *)(*piRam02008bdc + 4) & ~(ushort)(1 << (param_1 & 0xff));
    }
    *(undefined1 *)(iVar6 + iRam02008be8) = *(undefined1 *)(*piRam02008be4 + 6);
  }
  piVar2 = piRam02008be4;
  *(undefined1 *)(iVar6 + iRam02008bf8) = *(undefined1 *)(*piRam02008be4 + 10);
  *(undefined2 *)(iVar6 + iRam02008bfc) = *(undefined2 *)(*piVar2 + 0xc);
  *(undefined2 *)(iVar6 + iRam02008c00) = *(undefined2 *)(*piVar2 + 0xe);
  *(ushort *)(iVar6 + iRam02008bf0) = *(ushort *)(iVar6 + iRam02008bf0) | 1;
  iVar7 = iRam02008c04;
  iVar3 = 0;
  do {
    *(undefined1 *)(iVar6 + iVar3 + iVar7) = *(undefined1 *)(*piVar2 + iVar3 + 0x68);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 8);
  uVar4 = 0;
  iVar7 = 0;
  do {
    uVar5 = ((uint)*(byte *)(*piRam02008be4 + 0x10 + iVar7) << 0x18) >> 0x1c;
    if (uVar5 != 0) {
      CopyMemory16(*piRam02008be4 + 0x10 + iVar7,iVar6 + iRam02008bec + (uVar5 - 1) * 0x16,0x16);
      *(ushort *)(iVar6 + iRam02008bf0) = *(ushort *)(iVar6 + iRam02008bf0) | (ushort)(1 << uVar5);
    }
    iVar7 = iVar7 + 0x16;
    uVar4 = uVar4 + 1;
  } while (uVar4 < 4);
  return;
}

