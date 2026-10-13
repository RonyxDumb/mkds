/* Decompiled C draft; module arm9; ROM address 0211cfd0. No matching claim. */
#include "types.h"
#include "deps/0211cfd0_func_0211cfd0.h"

void func_0211cfd0(void)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  longlong lVar8;
  
  uVar6 = 2;
  func_0211d650();
  piVar1 = DAT_0211d090;
  *(undefined2 *)(*DAT_0211d090 + 0xb0) = 0;
  *(undefined2 *)(*piVar1 + 0xb2) = 0;
  uVar3 = func_0211d650();
  iVar2 = DAT_0211d094;
  for (; (int)uVar3 < 8; uVar3 = uVar3 + 1) {
    switch(*(undefined4 *)(*DAT_0211d090 + 0x2c)) {
    case 0:
    case 1:
      uVar6 = func_020ae3b4(2);
      break;
    case 2:
    case 3:
    case 4:
    case 5:
      iVar7 = *DAT_0211d098;
      iVar5 = iVar7 + iVar2;
      lVar8 = Multiply64(*(undefined4 *)(iVar5 + 8),*(undefined4 *)(iVar5 + 0xc),
                         *(undefined4 *)(iVar7 + iVar2),*(undefined4 *)(iVar5 + 4));
      lVar8 = lVar8 + *(longlong *)(iVar5 + 0x10);
      *(int *)(iVar7 + iVar2) = (int)lVar8;
      *(int *)(iVar5 + 4) = (int)((ulonglong)lVar8 >> 0x20);
      uVar6 = *(uint *)(iVar5 + 4) >> 0x1f;
    }
    uVar4 = func_0211d478(uVar6);
    if (3 < uVar4) {
      uVar6 = func_0211d3f4(uVar6);
    }
    func_0211d428(uVar3 & 0xffff,uVar6);
    iVar5 = *DAT_0211d090 + uVar6 * 2;
    *(short *)(iVar5 + 0xb0) = *(short *)(iVar5 + 0xb0) + 1;
  }
  return;
}

