/* Decompiled C draft; module arm9; ROM address 02112bb4. No matching claim. */
#include "types.h"
#include "deps/02112bb4_func_02112bb4.h"

void func_02112bb4(undefined4 param_1)

{
  short sVar1;
  ushort *puVar2;
  ushort *puVar3;
  int *piVar4;
  undefined2 uVar5;
  short sVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  short *psVar12;
  undefined2 *puVar13;
  undefined2 *puVar14;
  undefined2 *puVar15;
  int local_54;
  undefined2 *local_50;
  undefined2 *local_4c;
  undefined2 *local_48;
  short *local_44;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  
  puVar2 = puRam02112f98;
  *puRam02112f98 = *puRam02112f98 & 0xfffc | 2;
  puVar3 = puRam02112f9c;
  *puRam02112f9c = *puRam02112f9c & 0xfffc | 1;
  *puVar2 = *puVar2 & 0x43 | (ushort)uRam02112fa0;
  *puVar3 = *puVar3 & 0x43 | (ushort)uRam02112fa4;
  *puRam02112fa8 = *puRam02112fa8 & 0x43 | (ushort)uRam02112fac;
  iVar7 = Mem_AllocateHeap(param_1,0x94);
  *piRam02112fb0 = iVar7;
  *(undefined4 *)(iVar7 + 0x48) = param_1;
  uVar5 = func_02111418();
  *(undefined2 *)(*piRam02112fb0 + 0x6a) = uVar5;
  uVar5 = func_02111408();
  piVar4 = piRam02112fb0;
  *(undefined2 *)(*piRam02112fb0 + 0x68) = uVar5;
  iVar7 = 0;
  *(undefined4 *)(*piVar4 + 0x6c) = 0;
  *(undefined4 *)(*piVar4 + 0x70) = 0;
  *(undefined2 *)(*piVar4 + 0x74) = *(undefined2 *)(*piVar4 + 0x68);
  *(undefined4 *)(*piVar4 + 0x40) = 0;
  *(undefined4 *)(*piVar4 + 0x88) = 0;
  *(undefined4 *)(*piVar4 + 0x8c) = 0;
  iVar11 = 0;
  do {
    *(undefined4 *)(*piVar4 + iVar11 + 0x80) = 0;
    iVar11 = iVar11 + 4;
    iVar7 = iVar7 + 1;
  } while (iVar7 < 2);
  ReadEmblemPalette_from_thumb(param_1);
  func_02113f34();
  iVar7 = *piRam02112fb0;
  func_02124ed0(param_1,*(undefined4 *)(iVar7 + 8),*(undefined4 *)(iVar7 + 0xc),iVar7 + 0x14);
  iVar7 = *piRam02112fb0;
  func_02124ed0(param_1,*(undefined4 *)(iVar7 + 0x18),*(undefined4 *)(iVar7 + 0x1c),iVar7 + 0x24);
  iVar7 = *piRam02112fb0;
  func_02124ed0(param_1,*(undefined4 *)(iVar7 + 0x30),*(undefined4 *)(iVar7 + 0x38),iVar7 + 0x3c);
  uVar8 = find_buf_fn_from_thumb(uRam02112fb4);
  piVar4 = piRam02112fb0;
  *(undefined4 *)(*piRam02112fb0 + 0x44) = uVar8;
  iVar7 = iRam02112fb8;
  iVar11 = *piVar4;
  iVar11 = func_021243ac(param_1,0,*(undefined4 *)(iVar11 + 0xc),0x8c,0x10,0,
                         *(undefined4 *)(iVar11 + 4),*(undefined4 *)(iVar11 + 8),
                         *(undefined4 *)(iVar11 + 0x14),iRam02112fb8);
  iVar10 = *piRam02112fb0;
  iVar10 = func_021243ac(param_1,1,*(undefined4 *)(iVar10 + 0xc),0xaa,0xe,1,
                         *(undefined4 *)(iVar10 + 4),*(undefined4 *)(iVar10 + 8),
                         *(undefined4 *)(iVar10 + 0x14),iVar7 - iVar11);
  iVar10 = (iVar7 - iVar11) - iVar10;
  iVar7 = *piRam02112fb0;
  uVar8 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(iVar7 + 0x44),0);
  func_0212426c(0,1,*(undefined4 *)(*piRam02112fb0 + 0xc),uVar8,*(undefined4 *)(iVar7 + 8),
                *(undefined4 *)(iVar7 + 0x14));
  iVar7 = *piRam02112fb0;
  iVar7 = func_021243ac(param_1,0xb,*(undefined4 *)(iVar7 + 0xc),0x96,0xe,2,
                        *(undefined4 *)(iVar7 + 4),*(undefined4 *)(iVar7 + 8),
                        *(undefined4 *)(iVar7 + 0x14),iVar10);
  iVar10 = iVar10 - iVar7;
  iVar7 = *piRam02112fb0;
  uVar8 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(iVar7 + 0x44),1);
  func_0212426c(0,0xb,*(undefined4 *)(*piRam02112fb0 + 0xc),uVar8,*(undefined4 *)(iVar7 + 8),
                *(undefined4 *)(iVar7 + 0x14));
  iVar7 = *piRam02112fb0;
  iVar7 = func_021243ac(param_1,0xc,*(undefined4 *)(iVar7 + 0xc),0x46,0x10,3,
                        *(undefined4 *)(iVar7 + 4),*(undefined4 *)(iVar7 + 8),
                        *(undefined4 *)(iVar7 + 0x14),iVar10);
  iVar10 = iVar10 - iVar7;
  sVar6 = 4;
  sVar1 = *(short *)(*(int *)(*piRam02112fb0 + 8) + 6);
  local_30 = 0;
  local_4c = puRam02112fbc;
  local_48 = puRam02112fc0;
  local_44 = psRam02112fc4;
  do {
    local_54 = 0;
    psVar12 = local_44;
    puVar13 = local_4c;
    puVar14 = local_48;
    do {
      iVar7 = *piRam02112fb0;
      iVar7 = func_021243ac(param_1,*psVar12,*(undefined4 *)(iVar7 + 0xc),*puVar14,*puVar13,sVar6,
                            *(undefined4 *)(iVar7 + 4),*(undefined4 *)(iVar7 + 8),
                            *(undefined4 *)(iVar7 + 0x14),iVar10);
      iVar10 = iVar10 - iVar7;
      sVar6 = sVar1 + *psVar12;
      puVar13 = puVar13 + 1;
      puVar14 = puVar14 + 1;
      psVar12 = psVar12 + 1;
      local_54 = local_54 + 1;
    } while (local_54 < 3);
    local_4c = local_4c + 3;
    local_48 = local_48 + 3;
    local_44 = local_44 + 3;
    local_30 = local_30 + 1;
  } while (local_30 < 3);
  local_34 = 0;
  puVar13 = puRam02112fc8;
  psVar12 = psRam02112fc4;
  do {
    iVar7 = *piRam02112fb0;
    uVar8 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(iVar7 + 0x44),*puVar13);
    func_0212426c(0,*psVar12,*(undefined4 *)(*piRam02112fb0 + 0xc),uVar8,*(undefined4 *)(iVar7 + 8),
                  *(undefined4 *)(iVar7 + 0x14));
    puVar13 = puVar13 + 1;
    psVar12 = psVar12 + 1;
    local_34 = local_34 + 1;
  } while (local_34 < 3);
  iVar7 = *piRam02112fb0;
  iVar7 = func_021243ac(param_1,0,*(undefined4 *)(iVar7 + 0x1c),0x8c,0x10,0,
                        *(undefined4 *)(iVar7 + 4),*(undefined4 *)(iVar7 + 0x18),
                        *(undefined4 *)(iVar7 + 0x24),iVar10);
  iVar11 = *piRam02112fb0;
  iVar11 = func_021243ac(param_1,1,*(undefined4 *)(iVar11 + 0x1c),0x70,0x10,1,
                         *(undefined4 *)(iVar11 + 4),*(undefined4 *)(iVar11 + 0x18),
                         *(undefined4 *)(iVar11 + 0x24),iVar10 - iVar7);
  iVar11 = (iVar10 - iVar7) - iVar11;
  iVar7 = *piRam02112fb0;
  uVar8 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(iVar7 + 0x44),0xb);
  func_0212426c(0,1,*(undefined4 *)(*piRam02112fb0 + 0x1c),uVar8,*(undefined4 *)(iVar7 + 0x18),
                *(undefined4 *)(iVar7 + 0x24));
  iVar7 = *piRam02112fb0;
  iVar7 = func_021243ac(param_1,0xe,*(undefined4 *)(iVar7 + 0x1c),0xe0,0x38,2,
                        *(undefined4 *)(iVar7 + 4),*(undefined4 *)(iVar7 + 0x18),
                        *(undefined4 *)(iVar7 + 0x24),iVar11);
  iVar11 = iVar11 - iVar7;
  iVar7 = *piRam02112fb0;
  uVar8 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(iVar7 + 0x44),0xc);
  func_0212426c(0,0xe,*(undefined4 *)(*piRam02112fb0 + 0x1c),uVar8,*(undefined4 *)(iVar7 + 0x18),
                *(undefined4 *)(iVar7 + 0x24));
  local_38 = 0;
  puVar13 = puRam02112fcc;
  puVar14 = puRam02112fd0;
  puVar15 = puRam02112fd4;
  do {
    iVar7 = *piRam02112fb0;
    iVar7 = func_021243ac(param_1,*puVar15,*(undefined4 *)(iVar7 + 0x1c),*puVar14,*puVar13,
                          local_38 + 3,*(undefined4 *)(iVar7 + 4),*(undefined4 *)(iVar7 + 0x18),
                          *(undefined4 *)(iVar7 + 0x24),iVar11);
    iVar11 = iVar11 - iVar7;
    puVar13 = puVar13 + 1;
    puVar14 = puVar14 + 1;
    puVar15 = puVar15 + 1;
    local_38 = local_38 + 1;
  } while (local_38 < 0xc);
  iVar7 = func_02148ca0();
  local_3c = 0;
  local_50 = puRam02112fe4;
  puVar13 = puRam02112fd8;
  puVar14 = puRam02112fdc;
  puVar15 = puRam02112fe0;
  do {
    iVar11 = *piRam02112fb0;
    iVar11 = func_021243ac(param_1,*local_50,*(undefined4 *)(iVar11 + 0x38),*puVar15,*puVar14,
                           *puVar13,*(undefined4 *)(iVar11 + 0x2c),*(undefined4 *)(iVar11 + 0x30),
                           *(undefined4 *)(iVar11 + 0x3c),iVar7);
    iVar7 = iVar7 - iVar11;
    puVar13 = puVar13 + 1;
    puVar14 = puVar14 + 1;
    puVar15 = puVar15 + 1;
    local_50 = local_50 + 1;
    local_3c = local_3c + 1;
  } while (local_3c < 5);
  iVar11 = *piRam02112fb0;
  func_021243ac(param_1,5,*(undefined4 *)(iVar11 + 0x38),0x98,0x10,0x19,
                *(undefined4 *)(iVar11 + 0x2c),*(undefined4 *)(iVar11 + 0x30),
                *(undefined4 *)(iVar11 + 0x3c),iVar7);
  iVar7 = *piRam02113154;
  uVar8 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(iVar7 + 0x44),3);
  func_0212426c(1,5,*(undefined4 *)(*piRam02113154 + 0x38),uVar8,*(undefined4 *)(iVar7 + 0x30),
                *(undefined4 *)(iVar7 + 0x3c));
  iVar7 = 0;
  puVar13 = puRam0211315c;
  puVar14 = puRam02113158;
  puVar15 = puRam02113160;
  do {
    CellBank_ResetSomeMetatileObjectsMode_from_thumb
              (*puVar14,0,*(undefined4 *)(*piRam02113154 + 0x2c),
               *(undefined4 *)(*piRam02113154 + 0x30));
    CellBank_ResetSomeMetatileObjectsMode_from_thumb
              (*puVar13,0,*(undefined4 *)(*piRam02113154 + 0x2c),
               *(undefined4 *)(*piRam02113154 + 0x30));
    iVar11 = *piRam02113154;
    func_02124140(*puVar15,0,*(undefined4 *)(iVar11 + 0x38),*(undefined4 *)(iVar11 + 0x3c),
                  *(undefined4 *)(iVar11 + 0x30));
    puVar14 = puVar14 + 1;
    puVar13 = puVar13 + 1;
    puVar15 = puVar15 + 1;
    iVar7 = iVar7 + 1;
  } while (iVar7 < 5);
  CellBank_ResetSomeMetatileObjectsMode_from_thumb
            (0x18,0,*(undefined4 *)(*piRam02113154 + 0x2c),*(undefined4 *)(*piRam02113154 + 0x30));
  CellBank_ResetSomeMetatileObjectsMode_from_thumb
            (0x19,0,*(undefined4 *)(*piRam02113154 + 0x2c),*(undefined4 *)(*piRam02113154 + 0x30));
  iVar7 = *piRam02113154;
  func_02124140(5,0,*(undefined4 *)(iVar7 + 0x38),*(undefined4 *)(iVar7 + 0x3c),
                *(undefined4 *)(iVar7 + 0x30));
  uVar8 = Mem_AllocateHeap(param_1,uRam02113164);
  *(undefined4 *)(*piRam02113154 + 0x78) = uVar8;
  uVar8 = Mem_AllocateHeap(param_1,uRam02113168);
  *(undefined4 *)(*piRam02113154 + 0x7c) = uVar8;
  iVar7 = func_0211147c();
  if (iVar7 == 4) {
    iVar7 = func_021143b4();
    if (iVar7 == 0) {
      *(undefined4 *)(*piRam02113154 + 0x4c) = 8;
      func_021132e4();
      iVar7 = func_0211146c();
      if (iVar7 == 0xc) {
        *(undefined4 *)(*piRam02113154 + 0x90) = 6;
      }
      else {
        *(undefined4 *)(*piRam02113154 + 0x90) = 0;
      }
    }
    else {
      *(undefined4 *)(*piRam02113154 + 0x4c) = 0xb;
      func_02113174();
    }
  }
  else {
    *(undefined4 *)(*piRam02113154 + 0x4c) = 0;
    func_021134d4();
    uVar8 = func_02111318();
    uVar9 = func_0211130c();
    OamBuffer_SomeFn_from_thumb(uVar8,uVar9);
  }
  piVar4 = piRam02113154;
  *(undefined4 *)(*(int *)(*piRam02113154 + 0x3c) + iRam0211316c) = 0;
  *(undefined4 *)(*(int *)(*piVar4 + 0x3c) + iRam02113170) = 0;
  return;
}

