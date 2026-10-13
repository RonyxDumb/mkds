/* Decompiled C draft; module arm9; ROM address 020aa89c. No matching claim. */
#include "types.h"
#include "deps/020aa89c_func_020aa89c.h"

void func_020aa89c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar1;
  short sVar2;
  ushort uVar3;
  undefined2 uVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  code *pcVar10;
  undefined1 auStack_20 [4];
  
  func_020ab660(param_1,param_2,param_3,auStack_20);
  func_020ab528();
  iVar5 = iRam020aab24;
  *(undefined2 *)(iRam020aab24 + 0x3c) = 0;
  *(undefined2 *)(iVar5 + 0x3e) = 0;
  if ((*(int *)(iVar5 + 0x2c) != 0) && (*(int *)(iVar5 + 0x30) != 0)) {
    iVar5 = func_020ab640(*puRam020aab28);
    if (iVar5 == 0) {
      iVar5 = func_020ab640(puRam020aab28[1]);
      if (iVar5 == 0) {
        *(undefined4 *)(iRam020aab24 + 0x18) = 0;
      }
      else {
        *(undefined4 *)(iRam020aab24 + 0x18) = **(undefined4 **)(iRam020aab24 + 0x2c);
      }
    }
    else {
      *(undefined4 *)(iRam020aab24 + 0x18) = *(undefined4 *)(iRam020aab24 + 0x44);
    }
    uVar1 = *puRam020aab28;
    uVar3 = func_020ab4d4();
    if ((uVar1 & uVar3) == 0) {
      uVar1 = puRam020aab28[1];
      uVar3 = func_020ab4d4();
      if ((uVar1 & uVar3) == 0) {
        uVar1 = puRam020aab28[2];
        uVar3 = func_020ab4d4();
        if ((uVar1 & uVar3) != 0) {
          iVar5 = *(int *)(*(int *)(iRam020aab24 + 0x2c) + 8);
          if (iVar5 == iRam020aab2c) {
            sVar2 = *(short *)(iRam020aab30 + 2);
            if (sVar2 == 0) {
              *(undefined2 *)(iRam020aab24 + 0x3c) = 4;
            }
            else if (sVar2 == 4) {
              *(undefined2 *)(iRam020aab24 + 0x3c) = 5;
            }
            else if (sVar2 == 5) {
              *(undefined2 *)(iRam020aab24 + 0x3c) = 5;
            }
            func_020ab650(uVar1);
            func_020ab028();
          }
          else if (iVar5 == iRam020aab34) {
            *(short *)(iRam020aab24 + 0x3c) = (short)uRam020aab38;
            func_020ab650(uVar1);
            func_020ab028();
          }
        }
      }
      else {
        *(undefined2 *)(iRam020aab24 + 0x3c) = 1;
        func_020ab650(uVar1);
        func_020ab028();
      }
    }
    else {
      *(undefined2 *)(iRam020aab24 + 0x3c) = *(undefined2 *)(*(int *)(iRam020aab24 + 0x44) + 6);
      func_020ab650(uVar1);
      func_020ab028();
    }
    uVar6 = func_020ab4d4();
    if ((uVar6 & 0x40) == 0) {
      uVar6 = func_020ab4d4();
      if ((uVar6 & 0x80) == 0) {
        uVar6 = func_020ab4d4();
        if ((uVar6 & 0x20) == 0) {
          uVar6 = func_020ab4d4();
          if ((uVar6 & 0x10) != 0) {
            uVar7 = func_020aa0ec(0x10,*(undefined4 *)(iRam020aab24 + 0x44),
                                  **(undefined4 **)(iRam020aab24 + 0x2c));
            *(undefined4 *)(iRam020aab24 + 0x44) = uVar7;
          }
        }
        else {
          uVar7 = func_020aa0ec(0x20,*(undefined4 *)(iRam020aab24 + 0x44),
                                **(undefined4 **)(iRam020aab24 + 0x2c));
          *(undefined4 *)(iRam020aab24 + 0x44) = uVar7;
        }
      }
      else {
        uVar7 = func_020aa0ec(0x80,*(undefined4 *)(iRam020aab24 + 0x44),
                              **(undefined4 **)(iRam020aab24 + 0x2c));
        *(undefined4 *)(iRam020aab24 + 0x44) = uVar7;
      }
    }
    else {
      uVar7 = func_020aa0ec(0x40,*(undefined4 *)(iRam020aab24 + 0x44),
                            **(undefined4 **)(iRam020aab24 + 0x2c));
      *(undefined4 *)(iRam020aab24 + 0x44) = uVar7;
    }
    iVar5 = func_020ab634();
    if (iVar5 != 0) {
      uVar7 = func_020ab61c();
      uVar8 = func_020ab610();
      uVar7 = func_020aaea0((byte *)(uintptr_t)(iRam020aab24),uVar7,uVar8);
      *(undefined4 *)(iRam020aab24 + 0x14) = uVar7;
    }
    iVar5 = func_020ab628();
    if (iVar5 == 1) {
      uVar7 = func_020ab61c();
      uVar8 = func_020ab610();
      iVar9 = func_020aaea0((byte *)(uintptr_t)(iRam020aab24),uVar7,uVar8);
      iVar5 = iRam020aab24;
      *(int *)(iRam020aab24 + 0x10) = iVar9;
      if (iVar9 != 0) {
        *(undefined2 *)(iVar5 + 0x3c) = *(undefined2 *)(iVar9 + 6);
        func_020ab028(1);
      }
    }
    else {
      iVar5 = func_020ab628();
      if (iVar5 == 3) {
        *(undefined4 *)(iRam020aab24 + 0x10) = 0;
      }
    }
    iVar5 = func_020aab40(iRam020aab24);
    if (iVar5 == 0) {
      func_020ab5b4((undefined2 *)(uintptr_t)(uRam020aab3c));
    }
    else {
      func_020ab5bc((ushort *)(uintptr_t)(uRam020aab3c));
      iVar5 = func_020ab59c((short *)(uintptr_t)(uRam020aab3c));
      if (iVar5 != 0) {
        *(undefined2 *)(iRam020aab24 + 0x3c) = *(undefined2 *)(*(int *)(iRam020aab24 + 0x10) + 6);
        func_020ab028(0);
      }
    }
    uVar4 = func_020ab1d0(*(undefined2 *)(iRam020aab24 + 0x3c));
    iVar5 = iRam020aab24;
    *(undefined2 *)(iRam020aab24 + 0x3e) = uVar4;
    if (0x1f < *(ushort *)(iVar5 + 0x3e)) {
      iVar5 = *(int *)(*(int *)(iVar5 + 0x2c) + 8);
      if (iVar5 == iRam020aab2c) {
        if (*(short *)(iRam020aab30 + 2) == 4) {
          *(undefined2 *)(iRam020aab30 + 2) = 0;
        }
      }
      else if (iVar5 == iRam020aab34) {
        *(undefined2 *)(iRam020aab30 + 2) = 0;
      }
    }
    if ((*(short *)(iRam020aab24 + 0x3c) != 0) &&
       (pcVar10 = *(code **)(*(int *)(iRam020aab24 + 0x2c) + 8), pcVar10 != (code *)0x0)) {
      (*pcVar10)();
    }
    func_020aad9c(iRam020aab24);
    func_020aab70(iRam020aab24);
  }
  return;
}

