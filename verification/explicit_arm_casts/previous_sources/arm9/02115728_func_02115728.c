/* Decompiled C draft; module arm9; ROM address 02115728. No matching claim. */
#include "types.h"
#include "deps/02115728_func_02115728.h"

void func_02115728(undefined4 param_1)

{
  short sVar1;
  ushort *puVar2;
  int *piVar3;
  undefined2 uVar4;
  short sVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  short *psVar10;
  undefined2 *puVar11;
  undefined2 *puVar12;
  undefined2 *puVar13;
  undefined2 *puVar14;
  int local_64;
  undefined2 *local_60;
  undefined2 *local_5c;
  undefined2 *local_58;
  undefined2 *local_54;
  short *local_50;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  
  puVar2 = puRam02115b10;
  *puRam02115b10 = *puRam02115b10 & 0xfffc | 1;
  *puRam02115b14 = *puRam02115b14 & 0x43 | (ushort)uRam02115b18;
  *puVar2 = *puVar2 & 0x43 | (ushort)uRam02115b1c;
  iVar6 = Mem_AllocateHeap(param_1,0xa4);
  piVar3 = piRam02115b20;
  *piRam02115b20 = iVar6;
  *(undefined4 *)(iVar6 + 0x50) = param_1;
  *(undefined4 *)(*piVar3 + 0x54) = 3;
  uVar4 = func_02111418();
  *(undefined2 *)(*piRam02115b20 + 0x76) = uVar4;
  uVar4 = func_02111408();
  piVar3 = piRam02115b20;
  *(undefined2 *)(*piRam02115b20 + 0x74) = uVar4;
  iVar6 = 0;
  *(undefined4 *)(*piVar3 + 0x78) = 0;
  *(undefined4 *)(*piVar3 + 0x7c) = 0;
  *(undefined2 *)(*piVar3 + 0x80) = *(undefined2 *)(*piVar3 + 0x74);
  *(undefined4 *)(*piVar3 + 0x40) = 0;
  *(undefined4 *)(*piVar3 + 0x84) = 0;
  *(undefined4 *)(*piVar3 + 0x98) = 0;
  *(undefined4 *)(*piVar3 + 0x9c) = 0;
  iVar9 = 0;
  do {
    *(undefined4 *)(*piVar3 + iVar9 + 0x90) = 0;
    iVar9 = iVar9 + 4;
    iVar6 = iVar6 + 1;
  } while (iVar6 < 2);
  ReadEmblemPalette_from_thumb(param_1);
  func_02116888();
  iVar6 = *piRam02115b20;
  func_02124ed0(param_1,*(undefined4 *)(iVar6 + 8),*(undefined4 *)(iVar6 + 0xc),iVar6 + 0x14);
  iVar6 = *piRam02115b20;
  func_02124ed0(param_1,*(undefined4 *)(iVar6 + 0x18),*(undefined4 *)(iVar6 + 0x1c),iVar6 + 0x24);
  iVar6 = *piRam02115b20;
  func_02124ed0(param_1,*(undefined4 *)(iVar6 + 0x30),*(undefined4 *)(iVar6 + 0x38),iVar6 + 0x3c);
  uVar7 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam02115b24);
  *(undefined4 *)(*piRam02115b20 + 0x44) = uVar7;
  uVar7 = find_buf_fn_from_thumb(uRam02115b28);
  piVar3 = piRam02115b20;
  *(undefined4 *)(*piRam02115b20 + 0x48) = uVar7;
  iVar6 = iRam02115b2c;
  iVar9 = *piVar3;
  iVar9 = func_021243ac(param_1,0,*(undefined4 *)(iVar9 + 0xc),0x8c,0x10,0,
                        *(undefined4 *)(iVar9 + 4),*(undefined4 *)(iVar9 + 8),
                        *(undefined4 *)(iVar9 + 0x14),iRam02115b2c);
  iVar8 = *piRam02115b20;
  iVar8 = func_021243ac(param_1,1,*(undefined4 *)(iVar8 + 0xc),0xaa,0xe,1,*(undefined4 *)(iVar8 + 4)
                        ,*(undefined4 *)(iVar8 + 8),*(undefined4 *)(iVar8 + 0x14),iVar6 - iVar9);
  iVar8 = (iVar6 - iVar9) - iVar8;
  iVar6 = *piRam02115b20;
  uVar7 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(iVar6 + 0x48),0);
  func_0212426c(0,1,*(undefined4 *)(*piRam02115b20 + 0xc),uVar7,*(undefined4 *)(iVar6 + 8),
                *(undefined4 *)(iVar6 + 0x14));
  iVar6 = *piRam02115b20;
  iVar6 = func_021243ac(param_1,0xb,*(undefined4 *)(iVar6 + 0xc),0x96,0xe,2,
                        *(undefined4 *)(iVar6 + 4),*(undefined4 *)(iVar6 + 8),
                        *(undefined4 *)(iVar6 + 0x14),iVar8);
  iVar8 = iVar8 - iVar6;
  iVar6 = *piRam02115b20;
  uVar7 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(iVar6 + 0x48),1);
  func_0212426c(0,0xb,*(undefined4 *)(*piRam02115b20 + 0xc),uVar7,*(undefined4 *)(iVar6 + 8),
                *(undefined4 *)(iVar6 + 0x14));
  iVar6 = *piRam02115b20;
  iVar6 = func_021243ac(param_1,0xc,*(undefined4 *)(iVar6 + 0xc),0x46,0x10,3,
                        *(undefined4 *)(iVar6 + 4),*(undefined4 *)(iVar6 + 8),
                        *(undefined4 *)(iVar6 + 0x14),iVar8);
  iVar8 = iVar8 - iVar6;
  sVar5 = 4;
  sVar1 = *(short *)(*(int *)(*piRam02115b20 + 8) + 6);
  local_38 = 0;
  local_58 = puRam02115b30;
  local_54 = puRam02115b34;
  local_50 = psRam02115b38;
  do {
    local_64 = 0;
    psVar10 = local_50;
    puVar11 = local_58;
    puVar12 = local_54;
    do {
      iVar6 = *piRam02115b20;
      iVar6 = func_021243ac(param_1,*psVar10,*(undefined4 *)(iVar6 + 0xc),*puVar12,*puVar11,sVar5,
                            *(undefined4 *)(iVar6 + 4),*(undefined4 *)(iVar6 + 8),
                            *(undefined4 *)(iVar6 + 0x14),iVar8);
      iVar8 = iVar8 - iVar6;
      sVar5 = sVar1 + *psVar10;
      puVar11 = puVar11 + 1;
      puVar12 = puVar12 + 1;
      psVar10 = psVar10 + 1;
      local_64 = local_64 + 1;
    } while (local_64 < 3);
    local_58 = local_58 + 3;
    local_54 = local_54 + 3;
    local_50 = local_50 + 3;
    local_38 = local_38 + 1;
  } while (local_38 < 3);
  local_3c = 0;
  puVar11 = puRam02115b3c;
  psVar10 = psRam02115b38;
  do {
    iVar6 = *piRam02115b20;
    uVar7 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(iVar6 + 0x48),*puVar11);
    func_0212426c(0,*psVar10,*(undefined4 *)(*piRam02115b20 + 0xc),uVar7,*(undefined4 *)(iVar6 + 8),
                  *(undefined4 *)(iVar6 + 0x14));
    puVar11 = puVar11 + 1;
    psVar10 = psVar10 + 1;
    local_3c = local_3c + 1;
  } while (local_3c < 3);
  iVar6 = *piRam02115b20;
  iVar6 = func_021243ac(param_1,0,*(undefined4 *)(iVar6 + 0x1c),0x8c,0x10,0,
                        *(undefined4 *)(iVar6 + 4),*(undefined4 *)(iVar6 + 0x18),
                        *(undefined4 *)(iVar6 + 0x24),iVar8);
  iVar9 = *piRam02115b20;
  iVar9 = func_021243ac(param_1,1,*(undefined4 *)(iVar9 + 0x1c),0x70,0x10,1,
                        *(undefined4 *)(iVar9 + 4),*(undefined4 *)(iVar9 + 0x18),
                        *(undefined4 *)(iVar9 + 0x24),iVar8 - iVar6);
  iVar9 = (iVar8 - iVar6) - iVar9;
  iVar6 = *piRam02115b20;
  uVar7 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(iVar6 + 0x48),0xb);
  func_0212426c(0,1,*(undefined4 *)(*piRam02115b20 + 0x1c),uVar7,*(undefined4 *)(iVar6 + 0x18),
                *(undefined4 *)(iVar6 + 0x24));
  iVar6 = *piRam02115b20;
  iVar6 = func_021243ac(param_1,0xe,*(undefined4 *)(iVar6 + 0x1c),0xe0,0x38,2,
                        *(undefined4 *)(iVar6 + 4),*(undefined4 *)(iVar6 + 0x18),
                        *(undefined4 *)(iVar6 + 0x24),iVar9);
  iVar9 = iVar9 - iVar6;
  iVar6 = *piRam02115b20;
  uVar7 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(iVar6 + 0x48),0xc);
  func_0212426c(0,0xe,*(undefined4 *)(*piRam02115b20 + 0x1c),uVar7,*(undefined4 *)(iVar6 + 0x18),
                *(undefined4 *)(iVar6 + 0x24));
  local_40 = 0;
  puVar11 = puRam02115b40;
  puVar12 = puRam02115b44;
  puVar13 = puRam02115b48;
  do {
    iVar6 = *piRam02115b20;
    iVar6 = func_021243ac(param_1,*puVar13,*(undefined4 *)(iVar6 + 0x1c),*puVar12,*puVar11,
                          local_40 + 3,*(undefined4 *)(iVar6 + 4),*(undefined4 *)(iVar6 + 0x18),
                          *(undefined4 *)(iVar6 + 0x24),iVar9);
    iVar9 = iVar9 - iVar6;
    puVar11 = puVar11 + 1;
    puVar12 = puVar12 + 1;
    puVar13 = puVar13 + 1;
    local_40 = local_40 + 1;
  } while (local_40 < 0xc);
  iVar6 = func_02148ca0();
  local_44 = 0;
  local_5c = puRam02115b58;
  puVar11 = puRam02115b4c;
  puVar12 = puRam02115b50;
  puVar13 = puRam02115b54;
  do {
    iVar9 = *piRam02115b20;
    iVar9 = func_021243ac(param_1,*local_5c,*(undefined4 *)(iVar9 + 0x38),*puVar13,*puVar12,*puVar11
                          ,*(undefined4 *)(iVar9 + 0x2c),*(undefined4 *)(iVar9 + 0x30),
                          *(undefined4 *)(iVar9 + 0x3c),iVar6);
    iVar6 = iVar6 - iVar9;
    puVar11 = puVar11 + 1;
    puVar12 = puVar12 + 1;
    puVar13 = puVar13 + 1;
    local_5c = local_5c + 1;
    local_44 = local_44 + 1;
  } while (local_44 < 5);
  iVar9 = *piRam02115b20;
  func_021243ac(param_1,5,*(undefined4 *)(iVar9 + 0x38),0xfa,0x10,5,*(undefined4 *)(iVar9 + 0x2c),
                *(undefined4 *)(iVar9 + 0x30),*(undefined4 *)(iVar9 + 0x3c),iVar6);
  iVar6 = *piRam02115c6c;
  uVar7 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(iVar6 + 0x48),2);
  func_0212426c(1,5,*(undefined4 *)(*piRam02115c6c + 0x38),uVar7,*(undefined4 *)(iVar6 + 0x30),
                *(undefined4 *)(iVar6 + 0x3c));
  local_48 = 0;
  local_60 = puRam02115c80;
  puVar11 = puRam02115c74;
  puVar12 = puRam02115c70;
  puVar13 = puRam02115c78;
  puVar14 = puRam02115c7c;
  do {
    CellBank_ResetSomeMetatileObjectsMode_from_thumb
              (*puVar12,0,*(undefined4 *)(*piRam02115c6c + 0x2c),
               *(undefined4 *)(*piRam02115c6c + 0x30));
    CellBank_ResetSomeMetatileObjectsMode_from_thumb
              (*puVar11,0,*(undefined4 *)(*piRam02115c6c + 0x2c),
               *(undefined4 *)(*piRam02115c6c + 0x30));
    CellBank_ResetSomeMetatileObjectsMode_from_thumb
              (*puVar13,0,*(undefined4 *)(*piRam02115c6c + 0x2c),
               *(undefined4 *)(*piRam02115c6c + 0x30));
    CellBank_ResetSomeMetatileObjectsMode_from_thumb
              (*puVar14,0,*(undefined4 *)(*piRam02115c6c + 0x2c),
               *(undefined4 *)(*piRam02115c6c + 0x30));
    iVar6 = *piRam02115c6c;
    func_02124140(*local_60,0,*(undefined4 *)(iVar6 + 0x38),*(undefined4 *)(iVar6 + 0x3c),
                  *(undefined4 *)(iVar6 + 0x30));
    puVar12 = puVar12 + 1;
    puVar11 = puVar11 + 1;
    puVar13 = puVar13 + 1;
    puVar14 = puVar14 + 1;
    local_60 = local_60 + 1;
    local_48 = local_48 + 1;
  } while (local_48 < 5);
  iVar6 = *piRam02115c6c;
  func_02124140(5,0,*(undefined4 *)(iVar6 + 0x38),*(undefined4 *)(iVar6 + 0x3c),
                *(undefined4 *)(iVar6 + 0x30));
  uVar7 = Mem_AllocateHeap(param_1,uRam02115c84);
  *(undefined4 *)(*piRam02115c6c + 0x88) = uVar7;
  uVar7 = Mem_AllocateHeap(param_1,uRam02115c88);
  *(undefined4 *)(*piRam02115c6c + 0x8c) = uVar7;
  func_02115e74();
  return;
}

