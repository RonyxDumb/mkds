/* Decompiled C draft; module arm9; ROM address 0200c6b8. No matching claim. */
#include "types.h"
#include "deps/0200c6b8_func_0200c6b8.h"

void func_0200c6b8(void)

{
  undefined2 uVar1;
  short sVar2;
  short *psVar3;
  int iVar4;
  undefined2 *puVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [12];
  
  if ((*piRam0200c7b4 == 0) && (*piRam0200c7b4 = 1, (*puRam0200c7b8 & 1) != 0)) {
    uVar7 = SetIE(uRam0200c7bc);
    uVar1 = *puRam0200c7c0;
    *puRam0200c7c0 = 1;
    func_0200c4c0(psRam0200c7c4[1],(uint *)(void *)(auStack_28));
    uVar8 = *puRam0200c7c8 & uRam0200c7cc;
    ReadSomeExmemcntData_from_thumb((int *)(void *)(auStack_20));
    *puRam0200c7c8 = *puRam0200c7c8 & (ushort)uRam0200c7d0;
    DC_InvalidateRangeNoClean(iRam0200c7d4 + 0x80,0x40);
    MI_DmaCopy16(1,uRam0200c7d8,iRam0200c7d4 + 0x80,0x40);
    *puRam0200c7c8 = *puRam0200c7c8 & (ushort)uRam0200c7d0 | (ushort)(((int)uVar8 >> 0xf) << 0xf);
    func_0200c508((int *)(void *)(auStack_20));
    func_0200c4a4(psRam0200c7c4[1],(int *)(void *)(auStack_28));
    iVar4 = iRam0200c7d4;
    *puRam0200c7e0 = *(undefined2 *)(iRam0200c7dc + 0x3e);
    iVar6 = iRam0200c7e4;
    iVar9 = 0;
    do {
      *(undefined1 *)(iVar9 + iVar6) = *(undefined1 *)(iVar4 + iVar9 + 0xb5);
      puVar5 = puRam0200c7e0;
      iVar9 = iVar9 + 1;
    } while (iVar9 < 3);
    puRam0200c7e0[3] = *(undefined2 *)(iVar4 + 0xb0);
    *(undefined4 *)(puVar5 + 4) = *(undefined4 *)(iVar4 + 0xac);
    Mem_CpuCopy32((undefined4 *)(uintptr_t)(uRam0200c7e8),(undefined4 *)(uintptr_t)(uRam0200c7ec),0x9c);
    DC_FlushAll();
    func_0200c46c(((uint)(iRam0200c7d4 - iRam0200c7f0) >> 5) << 6 | 1);
    psVar3 = psRam0200c7c4;
    sVar2 = *psRam0200c7c4;
    while (sVar2 != 1) {
      WaitByLoop(1);
      sVar2 = *psVar3;
    }
    *puRam0200c7c0 = uVar1;
    SetIE(uVar7);
  }
  return;
}

