/* Decompiled C draft; module arm9; ROM address 020079c4. No matching claim. */
#include "types.h"
#include "deps/020079c4_func_020079c4.h"

void func_020079c4(int param_1,undefined2 *param_2)

{
  ushort uVar1;
  byte bVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  ushort *puVar11;
  code *pcVar12;
  int iVar13;
  
  piVar3 = DAT_02007cb4;
  if (param_1 < 0x1a) {
    if (param_1 < 0x19) {
      if (param_1 < 0x12) {
        if (((param_1 < 0x11) && (param_1 < 4)) && (-1 < param_1)) {
          if (param_1 == 0) {
            uVar1 = param_2[8];
            if ((uVar1 != 0) && (uVar1 < 0x10)) {
              func_02007d18(uVar1,2,param_2);
            }
          }
          else if (param_1 == 1) {
            uVar4 = (uint)(ushort)param_2[8];
            if ((uVar4 != 0) && (uVar4 < 0x10)) {
              *(undefined2 *)(*DAT_02007cb4 + (uVar4 - 1) * 2 + DAT_02007cb8) = 0;
              Mem_CpuFill8(*piVar3 + DAT_02007cbc + ((ushort)param_2[8] - 1) * 4,0,4);
              Mem_CpuFill8(*DAT_02007cb4 + DAT_02007cc0 + ((ushort)param_2[8] - 1) * 0x16,0);
              func_0200c3fc(param_2[8]);
              *(undefined2 *)(*DAT_02007cb4 + ((ushort)param_2[8] - 1) * 2 + DAT_02007cc4) = 0;
              iVar10 = (ushort)param_2[8] - 1;
              bVar2 = *(byte *)(*DAT_02007cb4 + iVar10 + DAT_02007cc8);
              if (bVar2 != 0xff) {
                iVar5 = DAT_02007ccc * (uint)bVar2;
                puVar11 = (ushort *)(*DAT_02007cb4 + iVar5 + DAT_02007cd0);
                uVar1 = (ushort)(1 << ((ushort)param_2[8] & 0xff));
                *puVar11 = *puVar11 & ~uVar1;
                puVar11 = (ushort *)(*DAT_02007cb4 + iVar5 + DAT_02007cd4);
                *puVar11 = *puVar11 | uVar1;
                *(undefined1 *)(*DAT_02007cb4 + iVar10 + DAT_02007cc8) = 0xff;
                puVar11 = (ushort *)(*DAT_02007cb4 + iVar5 + DAT_02007cd8);
                *puVar11 = *puVar11 & ~uVar1;
              }
              piVar3 = DAT_02007cb4;
              if (((uint)*(ushort *)(*DAT_02007cb4 + DAT_02007cdc) &
                  1 << ((ushort)param_2[8] & 0xff)) != 0) {
                pcVar6 = (char *)(*DAT_02007cb4 + DAT_02007ce0);
                *pcVar6 = *pcVar6 + -1;
                *(ushort *)(*piVar3 + DAT_02007cdc) =
                     *(ushort *)(*piVar3 + DAT_02007cdc) &
                     ~(ushort)(1 << ((ushort)param_2[8] & 0xff));
              }
              if (*(int *)(*DAT_02007cb4 + ((ushort)param_2[8] - 1) * 4 + DAT_02007ce4) == 8) {
                func_02007d18((uint)(ushort)param_2[8],9,0);
              }
              func_02007d18(param_2[8],3,param_2);
              *(undefined4 *)(*DAT_02007cb4 + ((ushort)param_2[8] - 1) * 4 + DAT_02007ce4) = 0;
            }
          }
          else if (param_1 == 3) {
            func_02007624(param_2);
          }
        }
      }
      else if (param_1 == 0x15) {
        func_02007d18(0,1,param_2);
      }
    }
    else {
      func_020071b4();
    }
  }
  else if (param_1 < 0x100) {
    if (param_1 < 0xff) {
      if (param_1 == 0x1c) {
        uVar4 = 0;
        do {
          iVar13 = *DAT_02007cb4;
          iVar5 = DAT_02007ccc * uVar4;
          iVar10 = iVar13 + iVar5;
          if ((*(char *)(iVar10 + DAT_02007ce8) != '\0') && (*(short *)(iVar10 + DAT_02007cd4) != 0)
             ) {
            func_0200973c(iVar13 + DAT_02007cec + iVar5,iVar13 + DAT_02007cc0,
                          *(undefined2 *)(iVar10 + DAT_02007cd0));
            *(undefined2 *)(*DAT_02007cb4 + iVar5 + DAT_02007cd4) = 0;
          }
          uVar4 = uVar4 + 1 & 0xff;
        } while (uVar4 < 0x10);
        uVar7 = func_020099cc();
        uVar8 = func_020099c0();
        uVar9 = func_02009974();
        func_0200964c(uVar7,uVar8,uVar9);
      }
    }
    else {
      switch(param_2[1]) {
      default:
        func_02007120(0,8);
        break;
      case 1:
      case 4:
      case 5:
      case 6:
      case 8:
      case 9:
        func_02007120(0,9);
      }
    }
  }
  else if (param_1 == DAT_02007cb0) {
    switch(*param_2) {
    case 0:
    case 7:
    case 8:
    case 0xd:
    case 0xe:
    case 0xf:
    case 0x11:
    case 0x12:
    case 0x15:
    case 0x19:
    case 0x1d:
      func_02007120(0,9);
      break;
    default:
      func_02007120(0,8);
    }
  }
  if (param_1 == 0x11) {
    pcVar12 = *(code **)(*DAT_02007cb4 + DAT_02007cf0);
    Mem_CpuFastMemorySet(0,*DAT_02007cb4,DAT_02007cf4);
    *DAT_02007cb4 = 0;
    if (pcVar12 != (code *)0x0) {
      (*pcVar12)(0,0xc,0);
    }
  }
  return;
}

