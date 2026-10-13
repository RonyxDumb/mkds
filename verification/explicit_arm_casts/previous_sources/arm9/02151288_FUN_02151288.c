/* Decompiled C draft; module arm9; ROM address 02151288. No matching claim. */
#include "types.h"
#include "deps/02151288_FUN_02151288.h"

undefined4 FUN_02151288(int param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  bool bVar14;
  bool bVar15;
  longlong lVar16;
  longlong lVar17;
  undefined8 uVar18;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  
  lVar16 = CONCAT44(uStack_c0,uStack_bc);
  uVar1 = param_2 >> 0x10 & 0xff;
  uVar2 = uVar1 | DAT_021515cc;
  uVar6 = param_2 & DAT_021515d0 | DAT_021515d4;
  uVar7 = param_3 & DAT_021515d0 | DAT_021515d8;
  uVar8 = param_4 >> 0x10 | DAT_021515dc;
  uVar9 = param_4 & DAT_021515d0 | DAT_021515e0;
  uVar1 = uVar1 | DAT_021515e4;
  param_3 = param_3 | DAT_021515e8;
  uVar10 = param_4 >> 0x10 | DAT_021515d8;
  uVar11 = param_4 & DAT_021515d0 | DAT_021515ec;
  uVar12 = (uint)DAT_021515f0 >> 0x18 | DAT_021515f4;
  uVar13 = (uint)DAT_021515f0 >> 8 & DAT_021515d0 | DAT_021515d4;
  uVar3 = (int)DAT_021515f0 << 8 & DAT_021515f8 | DAT_021515fc;
  bVar15 = false;
  do {
    do {
      while (!bVar15) {
        *DAT_02151600 = 0;
        switch(param_1) {
        case 1:
          iVar4 = Fifo_SendWord(4,uVar2,0);
          if (iVar4 < 0) {
            bVar15 = false;
          }
          else {
            iVar4 = Fifo_SendWord(4,uVar6,0);
            if (iVar4 < 0) {
              bVar15 = false;
            }
            else {
              iVar4 = Fifo_SendWord(4,DAT_021515e8,0);
              if (iVar4 < 0) {
                bVar15 = false;
              }
              else {
                iVar4 = Fifo_SendWord(4,uVar7,0);
                if (iVar4 < 0) {
                  bVar15 = false;
                }
                else {
                  iVar4 = Fifo_SendWord(4,uVar8,0);
                  if (iVar4 < 0) {
                    bVar15 = false;
                  }
                  else {
                    iVar4 = Fifo_SendWord(4,uVar9,0);
                    if (iVar4 < 0) {
                      bVar15 = false;
                    }
                    else {
                      bVar15 = true;
                    }
                  }
                }
              }
            }
          }
          break;
        case 2:
          iVar4 = Fifo_SendWord(4,uRam02151604,0);
          if (iVar4 < 0) {
            bVar15 = false;
          }
          else {
            bVar15 = true;
          }
          break;
        case 3:
          iVar4 = Fifo_SendWord(4,uVar1,0);
          bVar15 = false;
          if (-1 < iVar4) {
            iVar4 = Fifo_SendWord(4,uVar6,0);
            if (iVar4 < 0) {
              bVar15 = false;
            }
            else {
              iVar4 = Fifo_SendWord(4,param_3,0);
              if (iVar4 < 0) {
                bVar15 = false;
              }
              else {
                iVar4 = Fifo_SendWord(4,uVar10,0);
                if (iVar4 < 0) {
                  bVar15 = false;
                }
                else {
                  iVar4 = Fifo_SendWord(4,uVar11,0);
                  if (iVar4 < 0) {
                    bVar15 = false;
                  }
                  else {
                    bVar15 = true;
                  }
                }
              }
            }
          }
          lVar16 = Os_GetTick();
          break;
        case 4:
        case 5:
          iVar4 = Fifo_SendWord(4,uVar12,0);
          if (iVar4 < 0) {
            bVar15 = false;
          }
          else {
            iVar4 = Fifo_SendWord(4,uVar13,0);
            if (iVar4 < 0) {
              bVar15 = false;
            }
            else {
              iVar4 = Fifo_SendWord(4,uVar3,0);
              if (iVar4 < 0) {
                bVar15 = false;
              }
              else {
                bVar15 = true;
              }
            }
          }
          break;
        case 6:
          iVar4 = Fifo_SendWord(4,uRam02151608,0);
          if (iVar4 < 0) {
            bVar15 = false;
          }
          else {
            bVar15 = true;
          }
          break;
        case 7:
          iVar4 = Fifo_SendWord(4,uRam0215160c,0);
          if (iVar4 < 0) {
            bVar15 = false;
          }
          else {
            bVar15 = true;
          }
        }
      }
    } while (*DAT_02151600 != 1);
    bVar14 = false;
    if (*psRam02151610 != 0) {
      return 0;
    }
    bVar15 = false;
    switch(param_1) {
    case 1:
      return 1;
    case 2:
      param_1 = 4;
      bVar15 = bVar14;
      break;
    case 3:
      param_1 = 5;
      bVar15 = bVar14;
      break;
    case 4:
    case 5:
      DC_InvalidateRangeNoClean(DAT_021515f0,1);
      if (param_1 == 4) {
        if ((*DAT_021515f0 & 2) == 0) {
          return 0;
        }
        param_1 = 3;
        bVar15 = bVar14;
        break;
      }
      if ((*DAT_021515f0 & 1) == 0) {
        return 1;
      }
      if ((*DAT_021515f0 & 0x20) == 0) {
        lVar17 = Os_GetTick();
        uVar5 = (uint)(lVar17 - lVar16);
        uVar18 = _ll_udiv(uVar5 * 0x40,
                          (int)((ulonglong)(lVar17 - lVar16) >> 0x20) * 0x40 | uVar5 >> 0x1a,
                          uRam02151614,0);
        iVar4 = (int)((ulonglong)uVar18 >> 0x20);
        bVar15 = (uint)uVar18 <= uRam02151618;
        if ((uint)-iVar4 < (uint)bVar15) {
          WaitByLoop(uRam0215161c,-(uint)!bVar15 - iVar4);
          bVar15 = bVar14;
          break;
        }
      }
      param_1 = 6;
      bVar15 = bVar14;
      break;
    case 6:
      return 0;
    case 7:
      return 1;
    }
  } while( true );
}

