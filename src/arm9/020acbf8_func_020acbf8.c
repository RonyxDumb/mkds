/* Decompiled C draft; module arm9; ROM address 020acbf8. No matching claim. */
#include "types.h"
#include "deps/020acbf8_func_020acbf8.h"

void func_020acbf8(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  if (param_1 != 0) {
    uVar2 = func_020acef4();
    iVar3 = func_020acec4(uVar2,1);
    if (iVar3 == 0) {
      iVar3 = func_020ae408(uVar2,0x30);
      piVar1 = DAT_020acdbc;
      if (iVar3 == 0) {
        iVar3 = func_020ae408(uVar2,0x40);
        if (iVar3 == 0) {
          iVar3 = func_020ae408(uVar2,0x80);
          if (iVar3 == 0) {
            iVar3 = func_020ace14(uVar2);
            if (iVar3 == 0) {
              iVar3 = func_0210f738();
              piVar1 = DAT_020acdbc;
              *(int *)(*DAT_020acdbc + 0x4c) = *(int *)(*DAT_020acdbc + 0x4c) + 1;
              if ((iVar3 < *(int *)(*piVar1 + 0x4c)) && (iVar3 = func_0210f75c(0), iVar3 != 0)) {
                *(undefined2 *)(param_1 + 4) = 2;
                func_0203b6ac(*(undefined4 *)(*DAT_020acdbc + DAT_020acdc0));
              }
            }
            else {
              uVar4 = func_020acdec(uVar2);
              uVar2 = func_020acdc4(uVar2);
              iVar5 = *(int *)(*DAT_020acdbc + 0x54);
              iVar3 = func_020291c4(uVar4,uVar2,*(undefined4 *)(*DAT_020acdbc + 0x70));
              if (iVar3 != -1) {
                if (iVar5 == iVar3) {
                  *(undefined4 *)(*DAT_020acdbc + 0x58) = 1;
                }
                *(int *)(*DAT_020acdbc + 0x54) = iVar3;
                func_020adad0(4,8);
                func_020acf04();
              }
            }
          }
          else {
            iVar3 = *DAT_020acdbc;
            switch(*(undefined4 *)(iVar3 + 0x54)) {
            case 0:
              *(undefined4 *)(iVar3 + 0x54) = 1;
              break;
            case 1:
              *(undefined4 *)(iVar3 + 0x54) = 2;
              break;
            case 2:
              if (*(int *)(iVar3 + 0x5c) == 0) {
                *(undefined4 *)(iVar3 + 0x54) = 3;
              }
              else {
                *(undefined4 *)(iVar3 + 0x54) = 4;
              }
              break;
            case 3:
            case 4:
              *(undefined4 *)(iVar3 + 0x54) = 0;
            }
            MaybePlaySomeSseqFromSarc0(0);
            *(undefined4 *)(*DAT_020acdbc + 0x4c) = 0;
          }
        }
        else {
          iVar3 = *DAT_020acdbc;
          switch(*(undefined4 *)(iVar3 + 0x54)) {
          case 0:
            if (*(int *)(iVar3 + 0x5c) == 0) {
              *(undefined4 *)(iVar3 + 0x54) = 3;
            }
            else {
              *(undefined4 *)(iVar3 + 0x54) = 4;
            }
            break;
          case 1:
            *(undefined4 *)(iVar3 + 0x54) = 0;
            break;
          case 2:
            *(undefined4 *)(iVar3 + 0x54) = 1;
            break;
          case 3:
          case 4:
            *(undefined4 *)(iVar3 + 0x54) = 2;
          }
          MaybePlaySomeSseqFromSarc0(0);
          *(undefined4 *)(*DAT_020acdbc + 0x4c) = 0;
        }
      }
      else {
        iVar3 = *DAT_020acdbc;
        if (*(int *)(iVar3 + 0x54) == 3) {
          *(undefined4 *)(iVar3 + 0x54) = 4;
          *(undefined4 *)(*piVar1 + 0x5c) = 1;
          MaybePlaySomeSseqFromSarc0(0);
        }
        else if (*(int *)(iVar3 + 0x54) == 4) {
          *(undefined4 *)(iVar3 + 0x54) = 3;
          *(undefined4 *)(*piVar1 + 0x5c) = 0;
          MaybePlaySomeSseqFromSarc0();
        }
        *(undefined4 *)(*DAT_020acdbc + 0x4c) = 0;
      }
    }
    else {
      func_020adad0(4,8);
      func_020acf04();
      *(undefined4 *)(*DAT_020acdbc + 0x58) = 1;
    }
  }
  func_020acff4();
  return;
}

