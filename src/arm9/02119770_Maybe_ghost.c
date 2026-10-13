/* Decompiled C draft; module arm9; ROM address 02119770. No matching claim. */
#include "types.h"
#include "deps/02119770_Maybe_ghost.h"

void Maybe_ghost(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  ushort *puVar1;
  ushort *puVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined2 *puVar9;
  undefined2 *puVar10;
  undefined2 *puVar11;
  undefined2 *puVar12;
  int local_20;
  int local_1c;
  
  puVar1 = puRam021199c0;
  *puRam021199c0 = *puRam021199c0 & 0xfffc | 1;
  puVar2 = puRam021199c4;
  *puRam021199c4 = *puRam021199c4 & 0xfffc | 1;
  *puVar1 = *puVar1 & 0x43 | (ushort)uRam021199c8;
  *puVar2 = *puVar2 & 0x43 | (ushort)uRam021199cc;
  uVar4 = Mem_CreateOrphanChildHeap();
  iVar5 = Mem_AllocateHeap(uVar4,0x70);
  piVar3 = piRam021199d0;
  *piRam021199d0 = iVar5;
  *(undefined4 *)(iVar5 + 0x30) = uVar4;
  *(undefined4 *)(*piVar3 + 0x34) = 0;
  iVar5 = func_020296e4();
  piVar3 = piRam021199d0;
  *(undefined2 *)(*piRam021199d0 + 0x50) = *(undefined2 *)(iRam021199d4 + iVar5 * 2);
  *(undefined4 *)(*piVar3 + 0x54) = 1;
  *(undefined4 *)(*piVar3 + 0x58) = 0;
  *(undefined4 *)(*piVar3 + 0x40) = param_4;
  *(undefined2 *)(*piVar3 + 0x5c) = *(undefined2 *)(*piVar3 + 0x50);
  *(undefined4 *)(*piVar3 + 0x60) = 0;
  *(undefined4 *)(*piVar3 + 100) = param_2;
  *(undefined4 *)(*piVar3 + 0x68) = param_3;
  *(undefined4 *)(*piVar3 + 0x6c) = 0;
  func_0211a3bc();
  uVar4 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam021199d8);
  piVar3 = piRam021199d0;
  *(undefined4 *)(*piRam021199d0 + 0x28) = uVar4;
  if (*psRam021199dc == 2) {
    uVar4 = find_buf_fn_from_thumb(uRam021199f4);
    piVar3 = piRam021199d0;
    *(undefined4 *)(*piRam021199d0 + 0x2c) = uVar4;
    func_0211f4b0(*(undefined4 *)(*piVar3 + 0x30),*(undefined4 *)(*piVar3 + 0x68));
    func_0211f380();
  }
  else {
    iVar5 = *piVar3;
    func_02124ed0(*(undefined4 *)(iVar5 + 0x30),*(undefined4 *)(iVar5 + 4),
                  *(undefined4 *)(iVar5 + 8),(undefined4 *)(uintptr_t)(iVar5 + 0x1c));
    iVar5 = *piRam021199d0;
    func_02124ed0(*(undefined4 *)(iVar5 + 0x30),*(undefined4 *)(iVar5 + 0x10),
                  *(undefined4 *)(iVar5 + 0x18),(undefined4 *)(uintptr_t)(iVar5 + 0x20));
    iVar5 = iRam021199e0;
    puVar8 = (undefined4 *)*piRam021199d0;
    iVar6 = func_021243ac(puVar8[0xc],0,puVar8[2],0xb4,0xd,0,*puVar8,puVar8[1],puVar8[7],
                          iRam021199e0);
    puVar8 = (undefined4 *)*piRam021199d0;
    iVar7 = func_021243ac(puVar8[0xc],1,puVar8[2],0xb4,0xd,1,*puVar8,puVar8[1],puVar8[7],
                          iVar5 - iVar6);
    iVar7 = (iVar5 - iVar6) - iVar7;
    puVar8 = (undefined4 *)*piRam021199d0;
    iVar5 = func_021243ac(puVar8[0xc],2,puVar8[2],0x96,0xd,2,*puVar8,puVar8[1],puVar8[7],iVar7);
    iVar7 = iVar7 - iVar5;
    puVar8 = (undefined4 *)*piRam021199d0;
    iVar5 = func_021243ac(puVar8[0xc],3,puVar8[2],0x50,0xd,3,*puVar8,puVar8[1],puVar8[7],iVar7);
    iVar7 = iVar7 - iVar5;
    puVar8 = (undefined4 *)*piRam021199d0;
    iVar5 = func_021243ac(puVar8[0xc],4,puVar8[2],0x96,0xd,4,*puVar8,puVar8[1],puVar8[7],iVar7);
    puVar8 = (undefined4 *)*piRam021199d0;
    func_021243ac(puVar8[0xc],5,puVar8[2],0x50,0xd,5,*puVar8,puVar8[1],puVar8[7],iVar7 - iVar5);
    local_1c = func_02148ca0();
    local_20 = 0;
    puVar9 = puRam021199e8;
    puVar10 = puRam021199e4;
    puVar11 = puRam021199ec;
    puVar12 = puRam021199f0;
    do {
      iVar5 = *piRam021199d0;
      iVar5 = func_021243ac(*(undefined4 *)(iVar5 + 0x30),*puVar12,*(undefined4 *)(iVar5 + 0x18),
                            *puVar11,*puVar9,*puVar10,*(undefined4 *)(iVar5 + 0xc),
                            *(undefined4 *)(iVar5 + 0x10),*(undefined4 *)(iVar5 + 0x20),local_1c);
      local_1c = local_1c - iVar5;
      puVar10 = puVar10 + 1;
      puVar9 = puVar9 + 1;
      puVar11 = puVar11 + 1;
      puVar12 = puVar12 + 1;
      local_20 = local_20 + 1;
    } while (local_20 < 4);
    func_0211de40(*(undefined4 *)(*piRam021199d0 + 0x30));
    func_0211df44(*(undefined4 *)(*piRam021199d0 + 0x30));
  }
  func_0211a100();
  func_02119e88();
  func_02119c20();
  func_02036820(*(undefined4 *)(*piRam021199d0 + 0x30));
  return;
}

