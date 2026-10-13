/* Decompiled C draft; module arm9; ROM address 0202afe4. No matching claim. */
#include "types.h"
#include "deps/0202afe4_func_0202afe4.h"

void func_0202afe4(void)

{
  int iVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  int extraout_r1;
  int extraout_r1_00;
  int extraout_r1_01;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  
  iVar7 = 0;
  iVar3 = *piRam0202b0e4;
  func_02025edc(iVar3 + 0xec);
  uVar2 = func_02025ebc(*piRam0202b0e4 + 0xec);
  iVar1 = iRam0202b0e8;
  *(undefined2 *)(*(int *)(iVar3 + 0x60) + iRam0202b0e8) = uVar2;
  *(undefined2 *)(*(int *)(iVar3 + 0x60) + iRam0202b0ec) =
       *(undefined2 *)(*(int *)(iVar3 + 0x60) + iVar1);
  iVar1 = iRam0202b0f0;
  iVar4 = *(int *)(*piRam0202b0e4 + 0xac);
  if (((iVar4 == 0) || (iVar4 == 1)) || (iVar4 == 2)) {
    piVar6 = (int *)(*piRam0202b0e4 + iRam0202b0f0);
    iVar4 = *piVar6;
    if (iVar4 != 0) {
      *piVar6 = iVar4 + -1;
      iVar7 = _s32_div_f(*(int *)(*piRam0202b0e4 + iVar1) + 0x3c,0x3c);
      *(uint *)(*(int *)(iVar3 + 0x60) + iRam0202b0f4) = (uint)(9 < iVar7);
      if (*(int *)(*piRam0202b0e4 + iRam0202b0f0) == 0) {
        NNSi_MaybeSndPlayerStartSeq(uRam0202b0f8,0,0x51);
      }
      else {
        _s32_div_f(*(int *)(*piRam0202b0e4 + iRam0202b0f0) + 0x3c,0x3c);
        if ((extraout_r1 == 0) && (iVar7 < 5)) {
          NNSi_MaybeSndPlayerStartSeq(uRam0202b0f8,0,0x50);
        }
      }
    }
    uVar8 = *(undefined4 *)(iVar3 + 0x54);
    uVar9 = *(undefined4 *)(iVar3 + 0x50);
    uVar5 = _s32_div_f(iVar7,10);
    _s32_div_f(uVar5,10);
    func_02124748(*(undefined2 *)(iRam0202b0fc + extraout_r1_00 * 2),uVar9,
                  *(undefined4 *)(iVar3 + 0x48),uVar8,0,0xf,uVar9,uVar8);
    uVar5 = *(undefined4 *)(iVar3 + 0x54);
    uVar8 = *(undefined4 *)(iVar3 + 0x50);
    _s32_div_f(iVar7,10);
    func_02124748(*(undefined2 *)(iRam0202b0fc + extraout_r1_01 * 2),uVar8,
                  *(undefined4 *)(iVar3 + 0x48),uVar5,0,0x10,uVar8,uVar5);
  }
  return;
}

