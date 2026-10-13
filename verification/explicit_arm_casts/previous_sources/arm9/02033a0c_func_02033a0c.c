/* Decompiled C draft; module arm9; ROM address 02033a0c. No matching claim. */
#include "types.h"
#include "deps/02033a0c_func_02033a0c.h"

void func_02033a0c(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined1 auStack_2e [26];
  
  iVar2 = func_02148cb8();
  piVar1 = piRam02033ab0;
  iVar4 = *piRam02033ab0;
  *(undefined2 *)(iVar4 + 0xcc) = 1;
  *(undefined2 *)(*piVar1 + 0xce) = 0xb;
  iVar5 = 0;
  iVar6 = iRam02033ab4;
  if (*(short *)(*(int *)(iVar4 + 0x5c) + 6) != 0) {
    do {
      iVar3 = func_02025a00(0,param_1,iVar4 + 0x48,iVar6,iVar2);
      iVar2 = iVar2 - iVar3;
      iVar5 = iVar5 + 1;
      iVar6 = iVar6 + 8;
    } while (iVar5 < (int)(uint)*(ushort *)(*(int *)(iVar4 + 0x5c) + 6));
  }
  Mem_CpuFill16(0,auStack_2e,0x16);
  FormatRacerNameString_from_thumb(*(uint *)(*piRam02033ab0 + 0xd0) & 0xffff,auStack_2e,1);
  func_0212426c(0,0,*(undefined4 *)(iVar4 + 0x5c),auStack_2e,*(undefined4 *)(iVar4 + 0x54),
                *(undefined4 *)(iVar4 + 0x60));
  func_02033ab8(0,*(undefined4 *)(*piRam02033ab0 + 0xd0),0,1);
  return;
}

