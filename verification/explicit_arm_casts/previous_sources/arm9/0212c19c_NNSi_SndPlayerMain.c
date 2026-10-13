/* Decompiled C draft; module arm9; ROM address 0212c19c. No matching claim. */
#include "types.h"
#include "deps/0212c19c_NNSi_SndPlayerMain.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void NNSi_SndPlayerMain(void)

{
  uint uVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  
  uVar6 = func_020218bc();
  iVar7 = IntrusiveListWrapper_NextItem(uRam0212c304,0);
  iVar5 = iRam0212c308;
  if (iVar7 == 0) {
    return;
  }
  do {
    iVar8 = IntrusiveListWrapper_NextItem(uRam0212c304,iVar7);
    if ((*(char *)(iVar7 + 0x2d) == '\0') &&
       (uVar1 = iVar7 + 0x30U & 3, uVar9 = *(uint *)(iVar7 + 0x30U & 0xfffffffc),
       iVar10 = func_020210c0(uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20), iVar10 != 0)) {
      *(undefined1 *)(iVar7 + 0x2d) = 1;
    }
    if ((*(char *)(iVar7 + 0x2d) == '\0') || ((uVar6 & 1 << *(sbyte *)(iVar7 + 0x3c)) != 0)) {
      NNS_Snd_func_02068a34(iVar7 + 0x1c);
      uVar1 = iVar7 + 4U & 3;
      uVar9 = *(uint *)(iVar7 + 4U & 0xfffffffc);
      sVar2 = *(short *)(iVar5 + (uint)*(byte *)(iVar7 + 0x41) * 2);
      sVar3 = *(short *)(iVar5 + (uint)*(byte *)(iVar7 + 0x40) * 2);
      sVar4 = *(short *)(iVar5 + (uint)*(byte *)((uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20) +
                                                0x20) * 2);
      iVar10 = func_0212f7f8(iVar7 + 0x1c);
      iVar11 = (int)*(short *)(iVar5 + (iVar10 >> 8) * 2) + (int)sVar4 + (int)sVar3 + (int)sVar2;
      iVar10 = iRam0212c30c;
      if ((iRam0212c30c <= iVar11) && (iVar10 = iVar11, 0 < iVar11)) {
        iVar10 = 0;
      }
      if (iVar10 != *(short *)(iVar7 + 0x3e)) {
        func_02020d80(*(undefined1 *)(iVar7 + 0x3c),iVar10);
        *(short *)(iVar7 + 0x3e) = (short)iVar10;
      }
      if ((*(char *)(iVar7 + 0x2c) == '\x02') &&
         (iVar10 = NNS_Snd_func_02068a4c(iVar7 + 0x1c), iVar10 != 0)) {
        func_0212be78(iVar7);
      }
      if (*(char *)(iVar7 + 0x2f) != '\0') {
        func_02020db0(*(undefined1 *)(iVar7 + 0x3c));
        *(undefined1 *)(iVar7 + 0x2f) = 0;
      }
    }
    else {
      func_0212bd6c(iVar7);
    }
    iVar7 = iVar8;
  } while (iVar8 != 0);
  return;
}

