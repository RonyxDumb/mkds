/* Decompiled C draft; module arm9_ov001; ROM address 02181860. No matching claim. */
#include "types.h"
#include "deps/02181860_func_ov001_02181860.h"

void func_ov001_02181860(void)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  code *pcVar4;
  undefined4 uVar5;
  int iVar6;
  
  iVar3 = func_0x0207a974((short)*(char *)(*piRam021819e4 + 0x62));
  piVar2 = piRam021819ec;
  if ((*(uint *)(iVar3 + 0x48) & uRam021819e8) == 0) {
    iVar6 = *piRam021819ec;
    *(undefined4 *)(iVar6 + 0x34) = *(undefined4 *)(iVar6 + 0x28);
    *(undefined4 *)(iVar6 + 0x38) = *(undefined4 *)(iVar6 + 0x2c);
    *(undefined4 *)(iVar6 + 0x3c) = *(undefined4 *)(iVar6 + 0x30);
    *(undefined2 *)(iVar6 + 0x42) = *(undefined2 *)(iVar6 + 0x40);
    iVar6 = *piVar2;
    uVar5 = *(undefined4 *)(iVar3 + 0x84);
    *(undefined4 *)(iVar6 + 0x28) = *(undefined4 *)(iVar3 + 0x80);
    *(undefined4 *)(iVar6 + 0x2c) = uVar5;
    *(undefined4 *)(iVar6 + 0x30) = *(undefined4 *)(iVar3 + 0x88);
    *(undefined2 *)(iVar6 + 0x40) = *(undefined2 *)(iVar3 + iRam021819f0);
  }
  if (*(int *)(*piRam021819e4 + 8) == 4) {
    iVar3 = func_0x020a126c();
  }
  else {
    iVar3 = 0;
  }
  if (iVar3 == 0) {
    if ((*(char *)(*piRam021819e4 + 0x2f) == '\x01') || (*(char *)(*piRam021819e4 + 0x2f) == '\x05')
       ) {
      iVar3 = func_0x02061f90();
      piVar2 = piRam021819ec;
      if (iVar3 == 0) {
        iVar3 = *piRam021819ec;
        if (*(short *)(iVar3 + 0xc) == 0) {
          if (*(short *)(iVar3 + 10) == 0) {
            if (*(short *)(iVar3 + 8) != 0) {
              *(short *)(iVar3 + 8) = *(short *)(iVar3 + 8) + -1;
              FUN_02181aa0();
              if (*(code **)(*piRam021819ec + 0x18) != (code *)0x0) {
                (**(code **)(*piRam021819ec + 0x18))();
              }
            }
          }
          else {
            *(short *)(iVar3 + 10) = *(short *)(iVar3 + 10) + -1;
            sVar1 = *(short *)(*piVar2 + 4);
            if (sVar1 != 0) {
              *(short *)(*piVar2 + 4) = sVar1 + -1;
            }
            if (*(code **)(*piRam021819ec + 0x1c) != (code *)0x0) {
              (**(code **)(*piRam021819ec + 0x1c))();
            }
            *(undefined2 *)(*piRam021819ec + 0xe) = 0;
          }
        }
        else {
          *(short *)(iVar3 + 0xc) = *(short *)(iVar3 + 0xc) + -1;
          sVar1 = *(short *)(*piVar2 + 4);
          if (sVar1 != 0) {
            *(short *)(*piVar2 + 4) = sVar1 + -1;
            *(short *)(*piVar2 + 6) = *(short *)(*piVar2 + 6) + 1;
          }
          if (*(code **)(*piRam021819ec + 0x20) != (code *)0x0) {
            (**(code **)(*piRam021819ec + 0x20))();
          }
          *(undefined2 *)(*piRam021819ec + 0xe) = 0;
        }
      }
      piVar2 = piRam021819ec;
      sVar1 = *(short *)(*piRam021819ec + 0xe);
      if (sVar1 != 0) {
        *(short *)(*piRam021819ec + 0xe) = sVar1 + -1;
        if ((*(short *)(*piVar2 + 0xe) == 0) &&
           (pcVar4 = *(code **)(*piVar2 + 0x24), pcVar4 != (code *)0x0)) {
          (*pcVar4)();
        }
      }
    }
  }
  else {
    if (*(int *)(*piRam021819e4 + 8) == 4) {
      iVar3 = func_0x020a1084((short)*(char *)(*piRam021819e4 + 0x62));
    }
    else {
      iVar3 = 0;
    }
    if ((iVar3 != 0) &&
       (iVar3 = func_0x020a1154((short)*(char *)(*piRam021819e4 + 0x62)), piVar2 = piRam021819ec,
       iVar3 != 0)) {
      *(int *)*piRam021819ec = *(int *)*piRam021819ec + 1;
      if (0xf < *(int *)*piVar2) {
        *(int *)*piVar2 = 0;
        func_0x020a1748((short)*(char *)(*piRam021819e4 + 0x62));
        return;
      }
    }
  }
  return;
}

