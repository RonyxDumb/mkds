/* Decompiled C draft; module arm9; ROM address 02117e24. No matching claim. */
#include "types.h"
#include "deps/02117e24_Maybe_menu.h"

void Maybe_menu(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  ushort *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined2 *puVar7;
  undefined2 *puVar8;
  undefined2 *puVar9;
  int local_20;
  undefined2 *local_1c;
  
  puVar1 = puRam02117fe4;
  *puRam02117fe4 = *puRam02117fe4 & 0xfffc | 1;
  *puVar1 = *puVar1 & 0x43 | (ushort)uRam02117fe8;
  iVar3 = func_020cccb4();
  if ((iVar3 != 0x18) && (iVar3 = func_020cccb4(), iVar3 != 0xc)) {
    *puRam02117fec = *puRam02117fec & uRam02117ff0 | uRam02117ff4;
  }
  uVar4 = Mem_CreateOrphanChildHeap(param_1);
  iVar3 = Mem_AllocateHeap(uVar4,0x8c);
  piVar2 = piRam02117ff8;
  *piRam02117ff8 = iVar3;
  *(undefined4 *)(iVar3 + 0x2c) = uVar4;
  *(undefined4 *)(*piVar2 + 0x30) = 0;
  iVar3 = GetSelectedCup_from_thumb();
  piVar2 = piRam02117ff8;
  *(undefined4 *)(*piRam02117ff8 + 0x44) = *(undefined4 *)(iRam02117ffc + iVar3 * 4);
  *(undefined4 *)(*piVar2 + 0x68) = 1;
  *(undefined4 *)(*piVar2 + 0x6c) = 0;
  *(undefined4 *)(*piVar2 + 0x3c) = param_4;
  *(undefined4 *)(*piVar2 + 0x70) = *(undefined4 *)(*piVar2 + 0x44);
  *(undefined4 *)(*piVar2 + 0x7c) = 0;
  *(undefined4 *)(*piVar2 + 0x80) = param_2;
  *(undefined4 *)(*piVar2 + 0x84) = param_3;
  *(undefined4 *)(*piVar2 + 0x88) = 0;
  func_02118400();
  func_021189cc();
  func_02118b48();
  iVar3 = func_020cccb4();
  if ((iVar3 != 0x18) && (iVar3 = func_020cccb4(), iVar3 != 0xc)) {
    OamBuffer_SomeFn_from_thumb
              (*(undefined4 *)(*piRam02117ff8 + 0x80),*(undefined4 *)(*piRam02117ff8 + 0x84));
  }
  uVar4 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam02118000);
  piVar2 = piRam02117ff8;
  *(undefined4 *)(*piRam02117ff8 + 0x24) = uVar4;
  if (*psRam02118004 == 2) {
    func_0211f4b0(*(undefined4 *)(*piVar2 + 0x2c),*(undefined4 *)(*piVar2 + 0x84));
    iVar3 = func_020cccb4();
    if (iVar3 == 0xc) {
      func_0211f380();
    }
    else {
      func_0211f394();
    }
  }
  else {
    uVar4 = find_buf_fn_from_thumb(uRam02118008);
    piVar2 = piRam02117ff8;
    *(undefined4 *)(*piRam02117ff8 + 0x28) = uVar4;
    iVar3 = *piVar2;
    func_02124ed0(*(undefined4 *)(iVar3 + 0x2c),*(undefined4 *)(iVar3 + 4),
                  *(undefined4 *)(iVar3 + 8),(undefined4 *)(uintptr_t)(iVar3 + 0x18));
    iVar3 = *piRam02117ff8;
    func_02124ed0(*(undefined4 *)(iVar3 + 0x2c),*(undefined4 *)(iVar3 + 0x10),0,(undefined4 *)(uintptr_t)(iVar3 + 0x1c));
    local_20 = 0;
    local_1c = puRam0211801c;
    puVar7 = puRam02118010;
    iVar3 = iRam0211800c;
    puVar8 = puRam02118014;
    puVar9 = puRam02118018;
    do {
      puVar6 = (undefined4 *)*piRam02117ff8;
      iVar5 = func_021243ac(puVar6[0xb],*local_1c,puVar6[2],*puVar9,*puVar8,*puVar7,*puVar6,
                            puVar6[1],puVar6[6],iVar3);
      iVar3 = iVar3 - iVar5;
      puVar7 = puVar7 + 1;
      puVar8 = puVar8 + 1;
      puVar9 = puVar9 + 1;
      local_1c = local_1c + 1;
      local_20 = local_20 + 1;
    } while (local_20 < 4);
    func_0211de40(*(undefined4 *)(*piRam02117ff8 + 0x2c));
    func_0211df44(*(undefined4 *)(*piRam02117ff8 + 0x2c));
    func_0211f2b8(*(undefined4 *)(*piRam02117ff8 + 0x2c));
  }
  func_021188dc();
  func_02118624();
  func_021181fc();
  func_02036820(*(undefined4 *)(*piRam02117ff8 + 0x2c));
  if (*(int *)(*piRam02118020 + 0x20) == 2) {
    func_021281fc();
  }
  return;
}

