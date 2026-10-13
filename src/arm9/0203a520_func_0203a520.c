/* Decompiled C draft; module arm9; ROM address 0203a520. No matching claim. */
#include "types.h"
#include "deps/0203a520_func_0203a520.h"

void func_0203a520(int param_1,undefined4 param_2)

{
  uint uVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  uVar4 = DAT_0203a8d0;
  bVar2 = false;
  *(undefined4 *)
   ((*(uint *)(DAT_0203a8d0 & 0xfffffffc) >> (DAT_0203a8d0 & 3) * 8 |
    *(uint *)(DAT_0203a8d0 & 0xfffffffc) << (DAT_0203a8d0 & 3) * -8 + 0x20) + 8) = 0;
  iVar5 = -1;
  switch(param_2) {
  case 0:
    break;
  case 1:
    goto LAB_0203a648;
  case 2:
    uVar4 = (*(uint *)(DAT_0203a8d4 & 0xfffffffc) >> (DAT_0203a8d4 & 3) * 8 |
            *(uint *)(DAT_0203a8d4 & 0xfffffffc) << (DAT_0203a8d4 & 3) * -8 + 0x20) + 8;
    uVar3 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    switch(uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) {
    case 0:
      PrepareForCourseIntro();
      iVar5 = 2;
      break;
    case 1:
      break;
    case 2:
      iVar5 = func_020458cc();
      if (iVar5 == 0) {
        uVar4 = (*(uint *)(DAT_0203a8d4 & 0xfffffffc) >> (DAT_0203a8d4 & 3) * 8 |
                *(uint *)(DAT_0203a8d4 & 0xfffffffc) << (DAT_0203a8d4 & 3) * -8 + 0x20) + 0x20;
        uVar3 = uVar4 & 3;
        uVar4 = *(uint *)(uVar4 & 0xfffffffc);
        if (uVar4 >> uVar3 * 8 == 0 && uVar4 << uVar3 * -8 + 0x20 == 0) {
          *(undefined4 *)
           ((*(uint *)(DAT_0203a8d0 & 0xfffffffc) >> (DAT_0203a8d0 & 3) * 8 |
            *(uint *)(DAT_0203a8d0 & 0xfffffffc) << (DAT_0203a8d0 & 3) * -8 + 0x20) + 8) = 2;
        }
        uVar4 = (*(uint *)(DAT_0203a8dc & 0xfffffffc) >> (DAT_0203a8dc & 3) * 8 |
                *(uint *)(DAT_0203a8dc & 0xfffffffc) << (DAT_0203a8dc & 3) * -8 + 0x20) + 0x1c;
        uVar3 = uVar4 & 3;
        uVar4 = *(uint *)(uVar4 & 0xfffffffc);
        if ((int)((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) << 0x1d) < 0) {
          iVar5 = 6;
          *(undefined4 *)
           ((*(uint *)(DAT_0203a8d0 & 0xfffffffc) >> (DAT_0203a8d0 & 3) * 8 |
            *(uint *)(DAT_0203a8d0 & 0xfffffffc) << (DAT_0203a8d0 & 3) * -8 + 0x20) + 0x74) = 3;
        }
        else {
          iVar5 = 1;
        }
      }
      else {
        uVar4 = (*(uint *)(DAT_0203a8dc & 0xfffffffc) >> (DAT_0203a8dc & 3) * 8 |
                *(uint *)(DAT_0203a8dc & 0xfffffffc) << (DAT_0203a8dc & 3) * -8 + 0x20) + 0x1c;
        uVar3 = uVar4 & 3;
        uVar4 = *(uint *)(uVar4 & 0xfffffffc);
        if ((int)((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) << 0x1d) < 0) {
          iVar5 = 6;
          *(undefined4 *)
           ((*(uint *)(DAT_0203a8d0 & 0xfffffffc) >> (DAT_0203a8d0 & 3) * 8 |
            *(uint *)(DAT_0203a8d0 & 0xfffffffc) << (DAT_0203a8d0 & 3) * -8 + 0x20) + 0x74) = 1;
        }
        else {
          iVar5 = 2;
        }
      }
      break;
    case 3:
      iVar5 = func_02045914();
      if (iVar5 == 0) {
        uVar4 = (*(uint *)(DAT_0203a8d4 & 0xfffffffc) >> (DAT_0203a8d4 & 3) * 8 |
                *(uint *)(DAT_0203a8d4 & 0xfffffffc) << (DAT_0203a8d4 & 3) * -8 + 0x20) + 0x20;
        uVar3 = uVar4 & 3;
        uVar4 = *(uint *)(uVar4 & 0xfffffffc);
        if (uVar4 >> uVar3 * 8 == 0 && uVar4 << uVar3 * -8 + 0x20 == 0) {
          *(undefined4 *)
           ((*(uint *)(DAT_0203a8d0 & 0xfffffffc) >> (DAT_0203a8d0 & 3) * 8 |
            *(uint *)(DAT_0203a8d0 & 0xfffffffc) << (DAT_0203a8d0 & 3) * -8 + 0x20) + 8) = 2;
        }
        uVar4 = (*(uint *)(DAT_0203a8dc & 0xfffffffc) >> (DAT_0203a8dc & 3) * 8 |
                *(uint *)(DAT_0203a8dc & 0xfffffffc) << (DAT_0203a8dc & 3) * -8 + 0x20) + 0x1c;
        uVar3 = uVar4 & 3;
        uVar4 = *(uint *)(uVar4 & 0xfffffffc);
        if ((int)((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) << 0x1d) < 0) {
          iVar5 = 6;
          *(undefined4 *)
           ((*(uint *)(DAT_0203a8d0 & 0xfffffffc) >> (DAT_0203a8d0 & 3) * 8 |
            *(uint *)(DAT_0203a8d0 & 0xfffffffc) << (DAT_0203a8d0 & 3) * -8 + 0x20) + 0x74) = 3;
        }
        else {
          iVar5 = 1;
        }
      }
      else {
        uVar4 = (*(uint *)(DAT_0203a8dc & 0xfffffffc) >> (DAT_0203a8dc & 3) * 8 |
                *(uint *)(DAT_0203a8dc & 0xfffffffc) << (DAT_0203a8dc & 3) * -8 + 0x20) + 0x1c;
        uVar3 = uVar4 & 3;
        uVar4 = *(uint *)(uVar4 & 0xfffffffc);
        if ((int)((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) << 0x1d) < 0) {
          iVar5 = 6;
          *(undefined4 *)
           ((*(uint *)(DAT_0203a8d0 & 0xfffffffc) >> (DAT_0203a8d0 & 3) * 8 |
            *(uint *)(DAT_0203a8d0 & 0xfffffffc) << (DAT_0203a8d0 & 3) * -8 + 0x20) + 0x74) = 1;
        }
        else {
          iVar5 = 2;
        }
      }
      break;
    case 4:
      break;
    case 5:
      iVar5 = func_02045874();
      if (iVar5 == 0) {
        iVar5 = 10;
        *(undefined4 *)
         ((*(uint *)(DAT_0203a8d0 & 0xfffffffc) >> (DAT_0203a8d0 & 3) * 8 |
          *(uint *)(DAT_0203a8d0 & 0xfffffffc) << (DAT_0203a8d0 & 3) * -8 + 0x20) + 0x1c) = 2;
      }
      else {
        iVar5 = 0xc;
        *(undefined4 *)
         ((*(uint *)(DAT_0203a8d0 & 0xfffffffc) >> (DAT_0203a8d0 & 3) * 8 |
          *(uint *)(DAT_0203a8d0 & 0xfffffffc) << (DAT_0203a8d0 & 3) * -8 + 0x20) + 0x1c) = 3;
      }
    }
    break;
  case 3:
LAB_0203a648:
    iVar5 = 2;
    *(undefined4 *)
     ((*(uint *)(DAT_0203a8d4 & 0xfffffffc) >> (DAT_0203a8d4 & 3) * 8 |
      *(uint *)(DAT_0203a8d4 & 0xfffffffc) << (DAT_0203a8d4 & 3) * -8 + 0x20) + 500) = 0;
    break;
  case 4:
    *(undefined4 *)
     ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
      *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 8) = 2;
    iVar5 = 1;
    break;
  case 5:
    iVar5 = 1;
    *(undefined4 *)
     ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
      *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 8) = 1;
    break;
  case 6:
    *(undefined4 *)
     ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
      *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 8) = 3;
    iVar5 = 1;
    break;
  case 7:
    uVar3 = (*(uint *)(DAT_0203a8d4 & 0xfffffffc) >> (DAT_0203a8d4 & 3) * 8 |
            *(uint *)(DAT_0203a8d4 & 0xfffffffc) << (DAT_0203a8d4 & 3) * -8 + 0x20) + 8;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    switch(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) {
    case 0:
      iVar5 = func_02045bd4();
      if (iVar5 == 0) {
        iVar5 = 10;
      }
      else {
        iVar5 = 2;
      }
      break;
    case 1:
      break;
    case 2:
      goto LAB_0203a858;
    case 3:
LAB_0203a858:
      uVar3 = (*(uint *)(DAT_0203a8dc & 0xfffffffc) >> (DAT_0203a8dc & 3) * 8 |
              *(uint *)(DAT_0203a8dc & 0xfffffffc) << (DAT_0203a8dc & 3) * -8 + 0x20) + 0x1c;
      uVar1 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      if ((int)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) << 0x1d) < 0) {
        iVar5 = 6;
        *(undefined4 *)
         ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
          *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x74) = 2;
      }
      else {
        iVar5 = 10;
      }
      break;
    case 4:
      iVar5 = 0;
    }
    break;
  case 8:
    iVar5 = 2;
    *(undefined4 *)
     ((*(uint *)(DAT_0203a8d4 & 0xfffffffc) >> (DAT_0203a8d4 & 3) * 8 |
      *(uint *)(DAT_0203a8d4 & 0xfffffffc) << (DAT_0203a8d4 & 3) * -8 + 0x20) + 500) = 2;
    break;
  case 9:
    uVar3 = (*(uint *)(DAT_0203a8d4 & 0xfffffffc) >> (DAT_0203a8d4 & 3) * 8 |
            *(uint *)(DAT_0203a8d4 & 0xfffffffc) << (DAT_0203a8d4 & 3) * -8 + 0x20) + 8;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    if ((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) == 5) {
      iVar5 = 0xc;
      *(undefined4 *)
       ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
        *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x1c) = 0;
    }
    else {
      uVar4 = *(uint *)(DAT_0203a8d8 & 0xfffffffc) >> (DAT_0203a8d8 & 3) * 8 |
              *(uint *)(DAT_0203a8d8 & 0xfffffffc) << (DAT_0203a8d8 & 3) * -8 + 0x20;
      if (uVar4 == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
      }
      if ((uVar3 != 0) &&
         (uVar3 = uVar4 + 4 & 3, uVar4 = *(uint *)(uVar4 + 4 & 0xfffffffc),
         (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) != 0xd)) {
        bVar2 = true;
      }
      if (bVar2) {
        uVar4 = (*(uint *)(DAT_0203a8dc & 0xfffffffc) >> (DAT_0203a8dc & 3) * 8 |
                *(uint *)(DAT_0203a8dc & 0xfffffffc) << (DAT_0203a8dc & 3) * -8 + 0x20) + 0x1c;
        uVar3 = uVar4 & 3;
        uVar4 = *(uint *)(uVar4 & 0xfffffffc);
        if ((int)((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) << 0x1d) < 0) {
          iVar5 = 6;
          *(undefined4 *)
           ((*(uint *)(DAT_0203a8d0 & 0xfffffffc) >> (DAT_0203a8d0 & 3) * 8 |
            *(uint *)(DAT_0203a8d0 & 0xfffffffc) << (DAT_0203a8d0 & 3) * -8 + 0x20) + 0x74) = 3;
        }
        else {
          iVar5 = 1;
        }
        uVar3 = DAT_0203a8d0;
        *(undefined4 *)
         ((*(uint *)(DAT_0203a8d0 & 0xfffffffc) >> (DAT_0203a8d0 & 3) * 8 |
          *(uint *)(DAT_0203a8d0 & 0xfffffffc) << (DAT_0203a8d0 & 3) * -8 + 0x20) + 8) = 4;
        uVar4 = uVar3 & 3;
        uVar3 = *(uint *)(uVar3 & 0xfffffffc);
        *(undefined4 *)((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 4) = 1;
      }
      else {
        iVar5 = 0;
      }
      uVar4 = (*(uint *)(DAT_0203a8d4 & 0xfffffffc) >> (DAT_0203a8d4 & 3) * 8 |
              *(uint *)(DAT_0203a8d4 & 0xfffffffc) << (DAT_0203a8d4 & 3) * -8 + 0x20) + 8;
      uVar3 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      if ((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) == 1) {
        func_0204673c();
      }
    }
    break;
  case 10:
    func_02045a2c();
    iVar5 = 2;
  }
  if (iVar5 != -1) {
    *(short *)(param_1 + 4) = (short)iVar5;
  }
  return;
}

