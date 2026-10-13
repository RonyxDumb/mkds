/* Decompiled C draft; module arm9; ROM address 020307b8. No matching claim. */
#include "types.h"
#include "deps/020307b8_Maybe_multi_select_NS_s_nce.h"

void Maybe_multi_select_NS_s_nce(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  
  uVar1 = Mem_CreateOrphanChildHeap();
  iVar2 = Mem_AllocateHeap(uVar1,0x40);
  *piRam020308f8 = iVar2;
  CARD_func_0054__mkds_3091c(iVar2,0x40);
  piVar7 = piRam020308f8;
  *(undefined4 *)(*piRam020308f8 + 0x3c) = uVar1;
  *(undefined4 *)(*piVar7 + 0x1c) = param_2;
  *(undefined4 *)(*piVar7 + 0x20) = param_3;
  uVar1 = find_buf_fn_from_thumb(uRam020308fc);
  piVar7 = piRam020308f8;
  *(undefined4 *)(*piRam020308f8 + 0x24) = uVar1;
  *(undefined4 *)(*piVar7 + 0x38) = 0xffffff40;
  iVar2 = func_02148ca0();
  piVar7 = (int *)*piRam020308f8;
  uVar1 = find_buf_fn_from_thumb(uRam02030900);
  Gfx_ReadCharGraphicsRelative(piVar7,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam02030904);
  func_020b48b4(piVar7 + 2,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam02030908);
  Gfx_ReadPaletteRelative(piVar7 + 1,uVar1);
  iVar3 = find_buf_fn_from_thumb(uRam0203090c);
  piVar7[3] = iVar3;
  iVar3 = find_buf_fn_from_thumb(uRam02030910);
  piVar7[4] = iVar3;
  iVar3 = find_buf_fn_from_thumb(uRam02030914);
  piVar7[5] = iVar3;
  func_02124ed0(*(undefined4 *)(*piRam020308f8 + 0x3c),piVar7[3],piVar7[5],piVar7 + 6);
  iVar3 = 0;
  do {
    iVar6 = iRam02030918 + iVar3 * 0xc;
    iVar4 = (int)*(short *)(iRam02030918 + iVar3 * 0xc);
    iVar5 = func_021243ac(*(undefined4 *)(*piRam020308f8 + 0x3c),iVar4,piVar7[5],
                          *(undefined2 *)(iVar6 + 2),*(undefined2 *)(iVar6 + 4),
                          (int)*(short *)(iVar6 + 6),piVar7[2],piVar7[3],piVar7[6],iVar2);
    iVar2 = iVar2 - iVar5;
    uVar1 = Bmg_GetRawStringPointer_from_thumb
                      (*(undefined4 *)(*piRam020308f8 + 0x24),*(undefined4 *)(iVar6 + 8));
    func_0212426c(1,iVar4,piVar7[5],uVar1,piVar7[3],piVar7[6]);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 2);
  AllocateReserveTEQSub(0x23,0,*(undefined4 *)(*piVar7 + 0x14),*(undefined4 *)(*piVar7 + 0x10));
  AllocateReserveTEQSub(0x1e,0,*(undefined4 *)(piVar7[1] + 0xc),*(undefined4 *)(piVar7[1] + 8));
  func_02030954(1);
  func_021281c8(0xe);
  func_0204f804();
  func_02036820(*(undefined4 *)(*piRam020308f8 + 0x3c));
  return;
}

