/* Decompiled C draft; module arm9; ROM address 0200e388. No matching claim. */
#include "types.h"
#include "deps/0200e388_Os_InitializeThread.h"

void Os_InitializeThread(void)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined2 *puVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  
  puVar6 = puRam0200e4b4;
  iVar4 = iRam0200e4b0;
  iVar3 = iRam0200e4ac;
  puVar2 = puRam0200e4a8;
  if (*(uint *)((uint)puRam0200e4a8 & 0xfffffffc) >> ((uint)puRam0200e4a8 & 3) * 8 == 0 &&
      *(uint *)((uint)puRam0200e4a8 & 0xfffffffc) << ((uint)puRam0200e4a8 & 3) * -8 + 0x20 == 0) {
    iVar9 = 0x10;
    *(int *)(puRam0200e4b4 + 4) = iRam0200e4b0;
    *(int *)(puVar6 + 2) = iVar4;
    if (iVar3 < 1) {
      puVar6 = puRam0200e4b8;
    }
    *(undefined4 *)(iVar4 + 0x70) = 0x10;
    if (iVar3 < 1) {
      iVar9 = (int)puVar6 - iVar3;
    }
    *(undefined4 *)(iVar4 + 0x6c) = 0;
    *(undefined4 *)(iVar4 + 100) = 1;
    *(undefined4 *)(iVar4 + 0x68) = 0;
    *(undefined4 *)(iVar4 + 0x74) = 0;
    iVar7 = iRam0200e4c0;
    iVar4 = iRam0200e4bc;
    if (0 < iVar3) {
      iVar9 = ((iRam0200e4bc + 0x3f80) - iRam0200e4c0) - iVar3;
    }
    *puRam0200e4c8 = uRam0200e4c4;
    iVar3 = iRam0200e4b0;
    *puVar2 = 1;
    uVar5 = uRam0200e4cc;
    iVar7 = (iVar4 + 0x3f80) - iVar7;
    *(int *)(iVar3 + 0x94) = iVar7;
    *(int *)(iVar3 + 0x90) = iVar9;
    *(undefined4 *)(iVar3 + 0x98) = 0;
    *(undefined4 *)(iVar7 + -4) = uVar5;
    puVar6 = puRam0200e4b4;
    uVar1 = iVar3 + 0x90U & 3;
    uVar8 = *(uint *)(iVar3 + 0x90U & 0xfffffffc);
    *(undefined4 *)(uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20) = uRam0200e4d0;
    puVar2 = puRam0200e4d4;
    *(undefined4 *)(iVar3 + 0xa0) = 0;
    *(undefined4 *)(iVar3 + 0x9c) = 0;
    *puVar6 = 0;
    puVar6[1] = 0;
    *puVar2 = puVar6;
    Os_SetThreadSwitchCallback();
    Os_Thread_Create(iRam0200e4d8,uRam0200e4dc,0,uRam0200e4e0);
    iVar3 = iRam0200e4d8;
    *(undefined4 *)(iRam0200e4d8 + 0x70) = 0x20;
    *(undefined4 *)(iVar3 + 100) = 1;
    return;
  }
  return;
}

