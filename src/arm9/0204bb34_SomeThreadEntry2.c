/* Decompiled C draft; module arm9; ROM address 0204bb34. No matching claim. */
#include "types.h"
#include "deps/0204bb34_SomeThreadEntry2.h"

void SomeThreadEntry2(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar12;
  uint uVar11;
  
  uVar2 = Fs_FindArchiveByMountName(uRam0204bc94,3);
  iVar1 = iRam0204bc98;
  do {
    uVar3 = Os_DisableIrq();
    iVar8 = iRam0204bc9c;
    uVar11 = iRam0204bc9c + 0x46c8U & 3;
    uVar10 = *(uint *)(iRam0204bc9c + 0x46c8U & 0xfffffffc);
    for (uVar11 = uVar10 >> uVar11 * 8 | uVar10 << uVar11 * -8 + 0x20; uVar11 == 0;
        uVar11 = uVar10 >> uVar11 * 8 | uVar10 << uVar11 * -8 + 0x20) {
      uVar11 = iVar1 + 0xcU & 3;
      uVar10 = *(uint *)(iVar1 + 0xcU & 0xfffffffc);
      if (uVar10 >> uVar11 * 8 == 0 && uVar10 << uVar11 * -8 + 0x20 == 0) {
        Os_RestoreIrq(uVar3);
        return;
      }
      Os_Thread_Sleep(0);
      uVar11 = iVar8 + 0x46c8U & 3;
      uVar10 = *(uint *)(iVar8 + 0x46c8U & 0xfffffffc);
    }
    Os_RestoreIrq(uVar3);
    uVar10 = uVar11 + 0x80 & 3;
    uVar4 = *(uint *)(uVar11 + 0x80 & 0xfffffffc);
    if ((uVar4 >> uVar10 * 8 | uVar4 << uVar10 * -8 + 0x20) == 1) {
      uVar10 = uVar11 + 0x90 & 3;
      uVar4 = *(uint *)(uVar11 + 0x90 & 0xfffffffc);
      uVar6 = uVar4 >> uVar10 * 8 | uVar4 << uVar10 * -8 + 0x20;
      uVar10 = uVar11 + 0x8c & 3;
      uVar5 = *(uint *)(uVar11 + 0x8c & 0xfffffffc);
      uVar4 = uVar11 + 0x94 & 3;
      uVar7 = *(uint *)(uVar11 + 0x94 & 0xfffffffc);
      Fs_File_OpenRaw(uVar11 + 0x38,uVar2,uVar6,
                      uVar6 + (uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20),
                      uVar5 >> uVar10 * 8 | uVar5 << uVar10 * -8 + 0x20);
      iVar12 = 0;
      iVar9 = 0;
      iVar8 = uVar11 + 0xc0;
      do {
        *(int *)(uVar11 + iVar12 * 4 + 0xa4) = iVar9;
        Fs_File_Read(uVar11 + 0x38,iVar8,0x400);
        iVar12 = iVar12 + 1;
        iVar9 = iVar9 + 0x400;
        iVar8 = iVar8 + 0x400;
      } while (iVar12 < 2);
      *(undefined4 *)(uVar11 + 0x98) = 0;
      *(undefined4 *)(uVar11 + 0xa0) = 1;
      *(undefined4 *)(uVar11 + 0x9c) = 2;
      uVar3 = Os_DisableIrq();
      func_0204d18c(iRam0204bc9c,uVar11,1);
      Os_RestoreIrq(uVar3);
    }
    else {
      Fs_File_Close(uVar11 + 0x38);
      uVar3 = Os_DisableIrq();
      func_0204d0bc(iRam0204bc9c,uVar11);
      Os_RestoreIrq(uVar3);
    }
  } while( true );
}

