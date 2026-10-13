/* Decompiled C draft; module arm9; ROM address 0200a1bc. No matching claim. */
#include "types.h"
#include "deps/0200a1bc_func_0200a1bc.h"

void func_0200a1bc(ushort *param_1)

{
  ushort uVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  ushort *puVar8;
  undefined4 *puVar9;
  int iVar10;
  int iVar11;
  
  piVar3 = DAT_0200a554;
  piVar2 = DAT_0200a530;
  iVar10 = *DAT_0200a530;
  uVar1 = *param_1;
  if (uVar1 < 0x1e) {
    if (0x1c < uVar1) {
      if (param_1[1] != 0) {
        (**(code **)(iVar10 + DAT_0200a538))(DAT_0200a534,param_1);
        return;
      }
      *DAT_0200a554 = iVar10 + DAT_0200a550;
      if ((short)piVar3[1] == 0) {
        *(undefined2 *)(piVar3 + 1) = 1;
      }
      if (*(short *)((int)DAT_0200a554 + 6) == 0) {
        *(undefined2 *)((int)DAT_0200a554 + 6) = 200;
      }
      piVar2 = DAT_0200a554;
      *(undefined1 *)(DAT_0200a554 + 2) = 0xff;
      *(undefined1 *)((int)piVar2 + 9) = 0xff;
      *(undefined1 *)((int)piVar2 + 10) = 0xff;
      *(undefined1 *)((int)piVar2 + 0xb) = 0xff;
      *(undefined1 *)(piVar2 + 3) = 0xff;
      *(undefined1 *)((int)piVar2 + 0xd) = 0xff;
      *(undefined4 *)(iVar10 + DAT_0200a558) = 1;
      *(undefined4 *)(iVar10 + DAT_0200a55c) = 1;
      uVar4 = func_02143a78(DAT_0200a540);
      func_02009928(10,uVar4);
      return;
    }
    switch(uVar1) {
    case 0:
      if (param_1[1] != 0) {
        (**(code **)(iVar10 + DAT_0200a538))(DAT_0200a534,param_1);
        return;
      }
      (**(code **)(iVar10 + DAT_0200a538))(0x15,param_1);
      uVar4 = func_021454c4(DAT_0200a540,*DAT_0200a544,*DAT_0200a548,*DAT_0200a54c,*DAT_0200a53c);
      func_02009928(0x1d,uVar4);
      return;
    case 1:
      if (param_1[1] != 0) {
        *(undefined2 *)(iVar10 + DAT_0200a76c) = 0;
        (**(code **)(iVar10 + DAT_0200a758))(DAT_0200a764,param_1);
        return;
      }
      *(undefined2 *)(iVar10 + DAT_0200a75c) = 0;
      *(undefined2 *)(*piVar2 + DAT_0200a760) = 0;
      uVar4 = func_02143d88(DAT_0200a74c);
      func_02009928(2,uVar4);
      return;
    case 2:
      if (param_1[1] != 0) {
        *(undefined2 *)(iVar10 + DAT_0200a76c) = 0;
        (**(code **)(iVar10 + DAT_0200a758))(DAT_0200a764,param_1);
        return;
      }
      *(undefined1 *)(iVar10 + DAT_0200a770) = 0;
      *(undefined2 *)(*DAT_0200a774 + DAT_0200a778) = 0;
      (**(code **)(iVar10 + DAT_0200a758))(0x11,param_1);
      return;
    default:
      goto switchD_0200a1e2_caseD_3;
    case 10:
      if (param_1[1] != 0) {
        (**(code **)(iVar10 + DAT_0200a538))(DAT_0200a534,param_1);
        return;
      }
      uVar1 = param_1[4];
      if (uVar1 != 3) {
        if (uVar1 == 4) {
          (**(code **)(iVar10 + DAT_0200a538))(5,param_1);
          if (*(int *)(iVar10 + DAT_0200a558) != 0) {
            if ((*(int *)(iVar10 + DAT_0200a55c) != 0) &&
               (iVar10 = func_0200ada4(DAT_0200a554), iVar10 == 0)) {
              func_02009c34();
            }
            uVar4 = func_02143a78(DAT_0200a540,DAT_0200a554);
            func_02009928(10,uVar4);
            return;
          }
        }
        else {
          if (uVar1 != 5) {
            (**(code **)(iVar10 + DAT_0200a538))(DAT_0200a534,param_1);
            return;
          }
          iVar6 = iVar10 + DAT_0200a560;
          iVar11 = 0;
          if (*(ushort *)(iVar10 + DAT_0200a564) != 0) {
            iVar5 = iVar6;
LAB_0200a308:
            if ((((((char)param_1[5] != *(char *)(iVar5 + 0xca)) ||
                  (*(char *)((int)param_1 + 0xb) != *(char *)(iVar5 + 0xcb))) ||
                 ((char)param_1[6] != *(char *)(iVar5 + 0xcc))) ||
                ((*(char *)((int)param_1 + 0xd) != *(char *)(iVar5 + 0xcd) ||
                 ((char)param_1[7] != *(char *)(iVar5 + 0xce))))) ||
               (*(char *)((int)param_1 + 0xf) != *(char *)(iVar5 + 0xcf))) goto LAB_0200a39e;
            iVar5 = DAT_0200a568 * iVar11;
            iVar6 = iVar6 + iVar5;
            *(ushort *)(iVar6 + 0xf6) = param_1[0x1b];
            puVar8 = param_1 + 0x1c;
            puVar9 = (undefined4 *)(iVar6 + 0xf8);
            iVar6 = 0x10;
            do {
              uVar4 = *(undefined4 *)puVar8;
              uVar7 = *(undefined4 *)(puVar8 + 2);
              puVar8 = puVar8 + 4;
              *puVar9 = uVar4;
              puVar9[1] = uVar7;
              puVar9 = puVar9 + 2;
              iVar6 = iVar6 + -1;
            } while (iVar6 != 0);
            iVar5 = iVar10 + DAT_0200a560 + iVar5;
            DC_InvalidateRangeNoClean(iVar5,0xc0);
            MI_DmaCopy16(*DAT_0200a56c,iVar10 + DAT_0200a550,iVar5,0xc0);
            *(int *)(iVar10 + DAT_0200a570) = iVar11;
            goto LAB_0200a3e8;
          }
LAB_0200a3a8:
          if (iVar11 < 0x10) {
            *(short *)(iVar10 + DAT_0200a564) = (short)iVar11 + 1;
            iVar5 = DAT_0200a568 * iVar11;
            CopyMemory16(param_1,iVar6 + iVar5 + 0xc0,0xb8);
            iVar5 = iVar10 + DAT_0200a560 + iVar5;
            DC_InvalidateRangeNoClean(iVar5,0xc0);
            MI_DmaCopy16(*DAT_0200a56c,iVar10 + DAT_0200a550,iVar5,0xc0);
            *(int *)(iVar10 + DAT_0200a570) = iVar11;
          }
LAB_0200a3e8:
          (**(code **)(iVar10 + DAT_0200a538))(4,param_1);
          if (*(int *)(iVar10 + DAT_0200a558) != 0) {
            if ((*(int *)(iVar10 + DAT_0200a55c) != 0) &&
               (iVar10 = func_0200ada4(DAT_0200a554), iVar10 == 0)) {
              func_02009c34();
            }
            uVar4 = func_02143a78(DAT_0200a540,DAT_0200a554);
            func_02009928(10,uVar4);
            return;
          }
        }
      }
      break;
    case 0xb:
      if (param_1[1] != 0) {
        (**(code **)(iVar10 + DAT_0200a538))(DAT_0200a534,param_1);
        return;
      }
      uVar4 = func_021437d8(DAT_0200a540,*(undefined4 *)(iVar10 + DAT_0200a574),0,1,0);
      func_02009928(0xc,uVar4);
      return;
    case 0xc:
      if (param_1[1] != 0) {
        *(undefined2 *)(iVar10 + DAT_0200a564) = 0;
        (**(code **)(iVar10 + DAT_0200a538))(0xb,param_1);
        return;
      }
      uVar1 = param_1[4];
      if (uVar1 == 6) {
        *(undefined2 *)(iVar10 + DAT_0200a578) = 0;
        *(undefined2 *)(iVar10 + DAT_0200a57c) = 1;
        return;
      }
      if (uVar1 != 7) {
        if (uVar1 != 9) {
          (**(code **)(iVar10 + DAT_0200a758))(DAT_0200a764,param_1);
          return;
        }
        (**(code **)(iVar10 + DAT_0200a758))(10,param_1);
        *(undefined2 *)(iVar10 + DAT_0200a75c) = 0;
        *(undefined2 *)(iVar10 + DAT_0200a760) = 0;
        return;
      }
      *(ushort *)(iVar10 + DAT_0200a580) = param_1[5];
      (**(code **)(iVar10 + DAT_0200a538))(6,param_1);
      *(undefined2 *)(iVar10 + DAT_0200a578) = 1;
      iVar6 = func_0214358c(1,DAT_0200a584,0);
      if (iVar6 == 0) {
        uVar4 = func_02144230(DAT_0200a74c,*(undefined4 *)(iVar10 + DAT_0200a750),
                              *(undefined2 *)(iVar10 + DAT_0200a754),iVar10 + 0x40,
                              *(undefined2 *)(iVar10 + DAT_0200a58c),
                              *(short *)(iVar10 + DAT_0200a588) == 0,0,0,0,1,1);
        func_02009928(0xe,uVar4);
        return;
      }
      break;
    case 0xe:
      uVar1 = param_1[2];
      if (uVar1 == 10) {
        *(undefined2 *)(iVar10 + DAT_0200a760) = 1;
        iVar6 = func_0200ad4c();
        if (iVar6 != 0) {
          (**(code **)(iVar10 + DAT_0200a758))(0x19,0);
          return;
        }
      }
      else if ((uVar1 != 0xc) && (uVar1 != 0xd)) {
        (**(code **)(iVar10 + DAT_0200a758))(DAT_0200a764,param_1);
        return;
      }
      break;
    case 0xf:
      *(undefined1 *)(iVar10 + DAT_0200a768) = 0;
      if (param_1[1] == 0) {
        (**(code **)(iVar10 + DAT_0200a758))(8,param_1);
      }
      else if (param_1[1] == 9) {
        (**(code **)(iVar10 + DAT_0200a758))(0x29,param_1);
      }
      else {
        (**(code **)(iVar10 + DAT_0200a758))(0x12,param_1);
      }
      (**(code **)(iVar10 + DAT_0200a758))(0x19,0);
      return;
    case 0x15:
      iVar6 = func_0200ad4c();
      if (iVar6 != 0) {
        (**(code **)(iVar10 + DAT_0200a758))(0x19,0);
        return;
      }
    }
  }
  else {
    if (uVar1 == 0x80) {
      if (param_1[2] != 0x16) {
        return;
      }
      Os_Terminate();
      return;
    }
switchD_0200a1e2_caseD_3:
    (**(code **)(iVar10 + DAT_0200a758))(DAT_0200a764,param_1);
  }
  return;
LAB_0200a39e:
  iVar5 = iVar5 + DAT_0200a568;
  iVar11 = iVar11 + 1;
  if ((int)(uint)*(ushort *)(iVar10 + DAT_0200a564) <= iVar11) goto LAB_0200a3a8;
  goto LAB_0200a308;
}

