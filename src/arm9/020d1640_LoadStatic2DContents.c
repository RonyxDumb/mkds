/* Decompiled C draft; module arm9; ROM address 020d1640. No matching claim. */
#include "types.h"
#include "deps/020d1640_LoadStatic2DContents.h"

void LoadStatic2DContents(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar2 = Mem_AllocateHeap(param_1,0x2c);
  *DAT_020d1888 = uVar2;
  uVar2 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(DAT_020d188c);
  *(undefined4 *)
   (*(uint *)((uint)DAT_020d1888 & 0xfffffffc) >> ((uint)DAT_020d1888 & 3) * 8 |
   *(uint *)((uint)DAT_020d1888 & 0xfffffffc) << ((uint)DAT_020d1888 & 3) * -8 + 0x20) = uVar2;
  uVar2 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(DAT_020d1890);
  *(undefined4 *)
   ((*(uint *)((uint)DAT_020d1888 & 0xfffffffc) >> ((uint)DAT_020d1888 & 3) * 8 |
    *(uint *)((uint)DAT_020d1888 & 0xfffffffc) << ((uint)DAT_020d1888 & 3) * -8 + 0x20) + 4) = uVar2
  ;
  uVar2 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(DAT_020d1894);
  Gfx_ReadCharGraphics
            ((int *)(uintptr_t)((*(uint *)((uint)DAT_020d1888 & 0xfffffffc) >> ((uint)DAT_020d1888 & 3) * 8 |
             *(uint *)((uint)DAT_020d1888 & 0xfffffffc) << ((uint)DAT_020d1888 & 3) * -8 + 0x20) + 8)
             ,uVar2);
  uVar2 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(DAT_020d1898);
  LoadCellBankFrom((int *)(uintptr_t)((*(uint *)((uint)DAT_020d1888 & 0xfffffffc) >> ((uint)DAT_020d1888 & 3) * 8 |
                   *(uint *)((uint)DAT_020d1888 & 0xfffffffc) <<
                   ((uint)DAT_020d1888 & 3) * -8 + 0x20) + 0xc),uVar2);
  uVar2 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(DAT_020d189c);
  Gfx_ReadPalette((int *)(uintptr_t)((*(uint *)((uint)DAT_020d1888 & 0xfffffffc) >> ((uint)DAT_020d1888 & 3) * 8 |
                  *(uint *)((uint)DAT_020d1888 & 0xfffffffc) << ((uint)DAT_020d1888 & 3) * -8 + 0x20
                  ) + 0x10),uVar2);
  uVar3 = (*(uint *)(DAT_020d18a0 & 0xfffffffc) >> (DAT_020d18a0 & 3) * 8 |
          *(uint *)(DAT_020d18a0 & 0xfffffffc) << (DAT_020d18a0 & 3) * -8 + 0x20) + 4;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  switch(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) {
  case 0:
  default:
switchD_020d16e4_default:
    uVar2 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(DAT_020d18a4);
    NFTR_Load((*(uint *)((uint)DAT_020d1888 & 0xfffffffc) >> ((uint)DAT_020d1888 & 3) * 8 |
              *(uint *)((uint)DAT_020d1888 & 0xfffffffc) << ((uint)DAT_020d1888 & 3) * -8 + 0x20) +
              0x14,uVar2);
    break;
  case 1:
    goto switchD_020d16e4_default;
  case 2:
    uVar2 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(DAT_020d18a8);
    NFTR_Load((*(uint *)((uint)DAT_020d1888 & 0xfffffffc) >> ((uint)DAT_020d1888 & 3) * 8 |
              *(uint *)((uint)DAT_020d1888 & 0xfffffffc) << ((uint)DAT_020d1888 & 3) * -8 + 0x20) +
              0x14,uVar2);
    break;
  case 3:
    uVar2 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(DAT_020d18ac);
    NFTR_Load((*(uint *)((uint)DAT_020d1888 & 0xfffffffc) >> ((uint)DAT_020d1888 & 3) * 8 |
              *(uint *)((uint)DAT_020d1888 & 0xfffffffc) << ((uint)DAT_020d1888 & 3) * -8 + 0x20) +
              0x14,uVar2);
    break;
  case 4:
    uVar2 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(DAT_020d18b0);
    NFTR_Load((*(uint *)((uint)DAT_020d1888 & 0xfffffffc) >> ((uint)DAT_020d1888 & 3) * 8 |
              *(uint *)((uint)DAT_020d1888 & 0xfffffffc) << ((uint)DAT_020d1888 & 3) * -8 + 0x20) +
              0x14,uVar2);
    break;
  case 5:
    uVar2 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(DAT_020d18b4);
    NFTR_Load((*(uint *)((uint)DAT_020d1888 & 0xfffffffc) >> ((uint)DAT_020d1888 & 3) * 8 |
              *(uint *)((uint)DAT_020d1888 & 0xfffffffc) << ((uint)DAT_020d1888 & 3) * -8 + 0x20) +
              0x14,uVar2);
  }
  uVar3 = (*(uint *)(DAT_020d18a0 & 0xfffffffc) >> (DAT_020d18a0 & 3) * 8 |
          *(uint *)(DAT_020d18a0 & 0xfffffffc) << (DAT_020d18a0 & 3) * -8 + 0x20) + 4;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  switch(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) {
  case 0:
  default:
switchD_020d17b0_default:
    uVar2 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(DAT_020d18b8);
    *(undefined4 *)
     ((*(uint *)((uint)DAT_020d1888 & 0xfffffffc) >> ((uint)DAT_020d1888 & 3) * 8 |
      *(uint *)((uint)DAT_020d1888 & 0xfffffffc) << ((uint)DAT_020d1888 & 3) * -8 + 0x20) + 0x20) =
         uVar2;
    break;
  case 1:
    goto switchD_020d17b0_default;
  case 2:
    uVar2 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(DAT_020d18bc);
    *(undefined4 *)
     ((*(uint *)((uint)DAT_020d1888 & 0xfffffffc) >> ((uint)DAT_020d1888 & 3) * 8 |
      *(uint *)((uint)DAT_020d1888 & 0xfffffffc) << ((uint)DAT_020d1888 & 3) * -8 + 0x20) + 0x20) =
         uVar2;
    break;
  case 3:
    uVar2 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(DAT_020d18c0);
    *(undefined4 *)
     ((*(uint *)((uint)DAT_020d1888 & 0xfffffffc) >> ((uint)DAT_020d1888 & 3) * 8 |
      *(uint *)((uint)DAT_020d1888 & 0xfffffffc) << ((uint)DAT_020d1888 & 3) * -8 + 0x20) + 0x20) =
         uVar2;
    break;
  case 4:
    uVar2 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(DAT_020d18c4);
    *(undefined4 *)
     ((*(uint *)((uint)DAT_020d1888 & 0xfffffffc) >> ((uint)DAT_020d1888 & 3) * 8 |
      *(uint *)((uint)DAT_020d1888 & 0xfffffffc) << ((uint)DAT_020d1888 & 3) * -8 + 0x20) + 0x20) =
         uVar2;
    break;
  case 5:
    uVar2 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(DAT_020d18c8);
    *(undefined4 *)
     ((*(uint *)((uint)DAT_020d1888 & 0xfffffffc) >> ((uint)DAT_020d1888 & 3) * 8 |
      *(uint *)((uint)DAT_020d1888 & 0xfffffffc) << ((uint)DAT_020d1888 & 3) * -8 + 0x20) + 0x20) =
         uVar2;
  }
  uVar2 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(DAT_020d18cc);
  Gfx_ReadCharGraphicsV2
            ((*(uint *)((uint)DAT_020d1888 & 0xfffffffc) >> ((uint)DAT_020d1888 & 3) * 8 |
             *(uint *)((uint)DAT_020d1888 & 0xfffffffc) << ((uint)DAT_020d1888 & 3) * -8 + 0x20) +
             0x24,uVar2);
  uVar2 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(DAT_020d18d0);
  Gfx_ReadPalette((*(uint *)((uint)DAT_020d1888 & 0xfffffffc) >> ((uint)DAT_020d1888 & 3) * 8 |
                  *(uint *)((uint)DAT_020d1888 & 0xfffffffc) << ((uint)DAT_020d1888 & 3) * -8 + 0x20
                  ) + 0x28,uVar2);
  return;
}

