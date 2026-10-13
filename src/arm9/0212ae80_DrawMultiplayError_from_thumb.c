/* Decompiled C draft; module arm9; ROM address 0212ae80. No matching claim. */
#include "types.h"
#include "deps/0212ae80_DrawMultiplayError_from_thumb.h"

void DrawMultiplayError_from_thumb(void)

{
  int *piVar1;
  int iVar2;
  ushort *puVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  
  Clear1A44SomeTileData_from_thumb();
  if (*psRam0212af68 == 2) {
    iVar4 = GetGlobal2DObject();
    *(int *)(*piRam0212af6c + 0x38) = iVar4 + 0x14;
  }
  else {
    uVar5 = GetLoadedFont_from_thumb(0);
    *(undefined4 *)(*piRam0212af6c + 0x38) = uVar5;
  }
  G2d_Text_PrintString
            (*piRam0212af6c + 0x34,0x80,0x14,0xe,uRam0212af70,*(undefined4 *)(*piRam0212af6c + 8));
  CleanTemporaryMultiplayErrorBuffer_from_thumb();
  iVar2 = iRam0212af7c;
  iVar4 = iRam0212af78;
  uVar5 = uRam0212af74;
  piVar1 = piRam0212af6c;
  iVar7 = 0;
  iVar6 = 0;
  do {
    if ((iVar7 < iVar2) || (iRam0212af80 <= iVar7)) {
      *(short *)(*piVar1 + iVar6 + iVar4) = (short)uVar5;
    }
    else {
      *(ushort *)(*piVar1 + iVar6 + iVar4) = (short)iVar7 - (short)iVar2 | (ushort)uRam0212af84;
    }
    iVar6 = iVar6 + 2;
    iVar7 = iVar7 + 1;
  } while (iVar7 < iRam0212af88);
  *puRam0212af90 = (short)uRam0212af8c;
  *puRam0212af94 = 0;
  *puRam0212af98 = 0;
  puVar3 = puRam0212af9c;
  *puRam0212af9c = *puRam0212af9c & 0xfffc;
  *puVar3 = *puVar3 & 0xffbf;
  *puVar3 = *puVar3 & 0x43 | (ushort)uRam0212afa0;
  Arm_FlushRange(*piRam0212af6c + 0x44,uRam0212afa4);
  Arm_FlushRange(*piRam0212af6c + iRam0212af78,uRam0212afa8);
  CopyBgData_Bg1_Top(*piRam0212af6c + 0x44,0,uRam0212afa4);
  TEQSub_Fn9Impl(*piRam0212af6c + iRam0212af78,0,uRam0212afa8);
  return;
}

