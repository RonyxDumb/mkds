/* Decompiled C draft; module arm9; ROM address 02129994. No matching claim. */
#include "types.h"
#include "deps/02129994_Keyboard_SwitchFn2_from_thumb.h"

void Keyboard_SwitchFn2_from_thumb(void)

{
  bool bVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  
  bVar2 = false;
  iVar7 = -1;
  bVar1 = false;
  if ((*(short *)(iRam02129aac + 0x2e0) == 0) && (*(ushort *)(iRam02129ab0 + 0x2e0) < 5)) {
    bVar1 = true;
  }
  if (((!bVar1) && (*(short *)(iRam02129ab4 + 0x2e0) == 0)) &&
     (*(short *)(iRam02129aac + 0x2e0) != 0)) {
    bVar2 = true;
  }
  if (bVar2) {
    iVar7 = func_0201ea84(*(undefined4 *)(*piRam02129ab8 + 0xa4),
                          *(undefined2 *)(iRam02129abc + 0x2e0),
                          *(undefined2 *)(iRam02129ac0 + 0x2e0));
  }
  iVar4 = *piRam02129ab8;
  iVar6 = *(int *)(iVar4 + 4);
  uVar5 = func_020ab798();
  CopyMemory16(uVar5,iVar4 + 0x2c + iVar6 * 0x18,0x18);
  func_02129b60();
  if ((iVar7 != 1) &&
     ((iVar4 = func_020ab8c4(), iVar4 != 1 || ((*(ushort *)(iRam02129ac4 + 0x2e0) & 1) == 0)))) {
    if ((iVar7 == 0) ||
       ((iVar7 = func_020ab8c4(), iVar7 == 2 && ((*(ushort *)(iRam02129ac4 + 0x2e0) & 1) != 0)))) {
      piVar3 = piRam02129ab8;
      *(undefined4 *)(*piRam02129ab8 + 0x10) = 3;
      *(undefined4 *)(*piVar3 + 0x6c) = 0;
      TextSystem_CloseDialog_from_thumb();
      func_020ab8cc(2);
      *(undefined4 *)(*piRam02129ab8 + 0x24) = 0;
      NNSi_MaybeSndPlayerStartSeq(uRam02129ac8,0,0xe);
    }
    return;
  }
  piVar3 = piRam02129ab8;
  if (*(int *)(*piRam02129ab8 + 0x1c) != 0) {
    *(undefined4 *)(*piRam02129ab8 + 0x10) = 3;
    *(undefined4 *)(*piVar3 + 0x6c) = 1;
    TextSystem_CloseDialog_from_thumb();
    func_020ab8cc(1);
    *(undefined4 *)(*piRam02129ab8 + 0x24) = 0;
    NNSi_MaybeSndPlayerStartSeq(uRam02129ac8,0,4);
    return;
  }
  NNSi_MaybeSndPlayerStartSeq(uRam02129ac8,0,0x16);
  return;
}

