/* Decompiled C draft; module arm9; ROM address 02151374. No matching claim. */
#include "types.h"
#include "deps/02151374_func_02151374.h"

int func_02151374(void)

{
  int iVar1;
  uint uVar2;
  int unaff_r4;
  int unaff_r5;
  int unaff_r6;
  int unaff_r7;
  bool bVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined4 in_stack_00000000;
  undefined4 in_stack_00000004;
  undefined4 in_stack_00000008;
  undefined4 in_stack_00000010;
  undefined4 in_stack_00000014;
  undefined4 in_stack_0000001c;
  undefined4 in_stack_00000020;
  undefined4 in_stack_00000024;
  undefined4 in_stack_00000028;
  undefined4 in_stack_0000002c;
  undefined4 in_stack_00000030;
  undefined4 in_stack_00000034;
  undefined4 in_stack_00000038;
  undefined4 in_stack_0000003c;
  int in_stack_00000040;
  undefined4 in_stack_00000044;
  int in_stack_00000048;
  undefined4 in_stack_0000004c;
  int in_stack_00000050;
  undefined4 in_stack_00000054;
  int in_stack_00000058;
  undefined4 in_stack_0000005c;
  int in_stack_00000060;
  undefined4 in_stack_00000064;
  int in_stack_00000068;
  int in_stack_0000006c;
  int in_stack_00000070;
  undefined4 in_stack_00000074;
  int in_stack_00000078;
  undefined4 in_stack_0000007c;
  int in_stack_00000080;
  undefined4 in_stack_00000084;
  int in_stack_00000088;
  undefined4 in_stack_0000008c;
  int in_stack_00000090;
  int in_stack_00000094;
  undefined4 in_stack_00000098;
  int in_stack_0000009c;
  undefined4 in_stack_000000a0;
  int in_stack_000000a4;
  int in_stack_000000a8;
  int in_stack_000000ac;
  int in_stack_000000b0;
  undefined4 in_stack_000000b4;
  
  lVar4 = CONCAT44(in_stack_00000010,in_stack_00000014);
code_r0x02151374:
  *DAT_02151600 = unaff_r7;
  switch(unaff_r6) {
  case 1:
    iVar1 = Fifo_SendWord(unaff_r5,in_stack_0000001c,unaff_r7);
    unaff_r4 = in_stack_00000040;
    if (((((-1 < iVar1) &&
          (iVar1 = Fifo_SendWord(unaff_r5,in_stack_00000000,in_stack_00000044),
          unaff_r4 = in_stack_00000048, -1 < iVar1)) &&
         (iVar1 = Fifo_SendWord(unaff_r5,DAT_021515e8,in_stack_0000004c),
         unaff_r4 = in_stack_00000050, -1 < iVar1)) &&
        ((iVar1 = Fifo_SendWord(unaff_r5,in_stack_00000020,in_stack_00000054),
         unaff_r4 = in_stack_00000058, -1 < iVar1 &&
         (iVar1 = Fifo_SendWord(unaff_r5,in_stack_00000024,in_stack_0000005c),
         unaff_r4 = in_stack_00000060, -1 < iVar1)))) &&
       (iVar1 = Fifo_SendWord(unaff_r5,in_stack_00000028,in_stack_00000064),
       unaff_r4 = in_stack_00000068, -1 < iVar1)) {
      unaff_r4 = 1;
    }
    break;
  case 2:
    iVar1 = Fifo_SendWord(unaff_r5,uRam02151604,unaff_r7);
    unaff_r4 = in_stack_0000006c;
    if (-1 < iVar1) {
      unaff_r4 = 1;
    }
    break;
  case 3:
    iVar1 = Fifo_SendWord(unaff_r5,in_stack_0000002c,unaff_r7);
    unaff_r4 = in_stack_00000070;
    if (((-1 < iVar1) &&
        (iVar1 = Fifo_SendWord(unaff_r5,in_stack_00000000,in_stack_00000074),
        unaff_r4 = in_stack_00000078, -1 < iVar1)) &&
       ((iVar1 = Fifo_SendWord(unaff_r5,in_stack_00000004,in_stack_0000007c),
        unaff_r4 = in_stack_00000080, -1 < iVar1 &&
        ((iVar1 = Fifo_SendWord(unaff_r5,in_stack_00000030,in_stack_00000084),
         unaff_r4 = in_stack_00000088, -1 < iVar1 &&
         (iVar1 = Fifo_SendWord(unaff_r5,in_stack_00000008,in_stack_0000008c),
         unaff_r4 = in_stack_00000090, -1 < iVar1)))))) {
      unaff_r4 = 1;
    }
    lVar4 = Os_GetTick();
    break;
  case 4:
  case 5:
    iVar1 = Fifo_SendWord(unaff_r5,in_stack_00000034,unaff_r7);
    unaff_r4 = in_stack_00000094;
    if (((-1 < iVar1) &&
        (iVar1 = Fifo_SendWord(unaff_r5,in_stack_00000038,in_stack_00000098),
        unaff_r4 = in_stack_0000009c, -1 < iVar1)) &&
       (iVar1 = Fifo_SendWord(unaff_r5,in_stack_0000003c,in_stack_000000a0),
       unaff_r4 = in_stack_000000a4, -1 < iVar1)) {
      unaff_r4 = 1;
    }
    break;
  case 6:
    iVar1 = Fifo_SendWord(unaff_r5,uRam02151608,unaff_r7);
    unaff_r4 = in_stack_000000a8;
    if (-1 < iVar1) {
      unaff_r4 = 1;
    }
    break;
  case 7:
    iVar1 = Fifo_SendWord(unaff_r5,uRam0215160c,unaff_r7);
    unaff_r4 = in_stack_000000ac;
    if (-1 < iVar1) {
      unaff_r4 = 1;
    }
  }
switchD_02151388_caseD_0:
  do {
    if (unaff_r4 == 0) goto code_r0x02151374;
    if (*DAT_02151600 == 1) {
      iVar1 = in_stack_000000b0;
      if (*psRam02151610 == 0) {
        unaff_r4 = in_stack_000000b0;
        switch(unaff_r6) {
        default:
          goto switchD_02151388_caseD_0;
        case 1:
          return 1;
        case 2:
          unaff_r6 = unaff_r5;
          goto switchD_02151388_caseD_0;
        case 3:
          unaff_r6 = 5;
          goto switchD_02151388_caseD_0;
        case 4:
        case 5:
          DC_InvalidateRangeNoClean(DAT_021515f0,1);
          if (unaff_r6 == 4) {
            if ((*DAT_021515f0 & 2) == 0) {
              return 0;
            }
            unaff_r6 = 3;
            goto switchD_02151388_caseD_0;
          }
          iVar1 = 1;
          if ((*DAT_021515f0 & 1) != 0) {
            if ((*DAT_021515f0 & 0x20) == 0) {
              lVar5 = Os_GetTick();
              uVar2 = (uint)(lVar5 - lVar4);
              uVar6 = _ll_udiv(uVar2 * 0x40,
                               (int)((ulonglong)(lVar5 - lVar4) >> 0x20) * 0x40 | uVar2 >> 0x1a,
                               uRam02151614,in_stack_000000b4);
              iVar1 = (int)((ulonglong)uVar6 >> 0x20);
              bVar3 = (uint)uVar6 <= uRam02151618;
              if ((uint)-iVar1 < (uint)bVar3) {
                WaitByLoop(uRam0215161c,-(uint)!bVar3 - iVar1);
                goto switchD_02151388_caseD_0;
              }
            }
            unaff_r6 = 6;
            goto switchD_02151388_caseD_0;
          }
          break;
        case 6:
          return in_stack_000000b0;
        case 7:
          return 1;
        }
      }
      return iVar1;
    }
  } while( true );
}

