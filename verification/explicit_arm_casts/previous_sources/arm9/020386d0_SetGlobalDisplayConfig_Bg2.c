/* Decompiled C draft; module arm9; ROM address 020386d0. No matching claim. */
#include "types.h"
#include "deps/020386d0_SetGlobalDisplayConfig_Bg2.h"

void SetGlobalDisplayConfig_Bg2(uint param_1,int param_2)

{
  ushort *puVar1;
  ushort *puVar2;
  ushort *puVar3;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  puVar2 = DAT_02038c88;
  puVar1 = DAT_02038c80;
  local_14 = 0;
  local_10 = 0;
  local_18 = 0x1000;
  local_c = 0x1000;
  puVar3 = (ushort *)(param_1 + 4);
  switch(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
         *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) {
  case 0:
    break;
  case 1:
    if (param_2 != 0) {
      *DAT_02038c7c = 0;
      *puVar1 = *puVar1 & 0xfffc | *puVar3;
      puVar2 = DAT_02038c80;
      if (*(short *)(param_1 + 6) == 0) {
        *puVar1 = *puVar1 & 0xffbf;
      }
      else {
        *puVar1 = *puVar1 | 0x40;
      }
      *puVar2 = *puVar2 & 0x43 | *(short *)(param_1 + 8) << 0xe | *(short *)(param_1 + 10) << 7 |
                *(short *)(param_1 + 0xc) << 8 | *(short *)(param_1 + 0xe) << 2;
      return;
    }
    *DAT_02038c84 = 0;
    *puVar2 = *puVar2 & 0xfffc | *puVar3;
    puVar1 = DAT_02038c88;
    if (*(short *)(param_1 + 6) == 0) {
      *puVar2 = *puVar2 & 0xffbf;
    }
    else {
      *puVar2 = *puVar2 | 0x40;
    }
    *puVar1 = *puVar1 & 0x43 | *(short *)(param_1 + 8) << 0xe | *(short *)(param_1 + 10) << 7 |
              *(short *)(param_1 + 0xc) << 8 | *(short *)(param_1 + 0xe) << 2;
    return;
  case 2:
    if (param_2 != 0) {
      func_0214a428(DAT_02038c8c,&local_18,0,0,0,0);
      puVar1 = DAT_02038c80;
      *DAT_02038c80 = *DAT_02038c80 & 0xfffc | *puVar3;
      puVar2 = DAT_02038c80;
      if (*(short *)(param_1 + 6) == 0) {
        *puVar1 = *puVar1 & 0xffbf;
      }
      else {
        *puVar1 = *puVar1 | 0x40;
      }
      *puVar2 = *puVar2 & 0x43 | *(short *)(param_1 + 8) << 0xe | *(short *)(param_1 + 0xc) << 8 |
                *(short *)(param_1 + 0xe) << 2 | *(short *)(param_1 + 10) << 0xd;
      return;
    }
    func_0214a428(DAT_02038c90,&local_18,0,0,0,0);
    puVar1 = DAT_02038c88;
    *DAT_02038c88 = *DAT_02038c88 & 0xfffc | *puVar3;
    puVar2 = DAT_02038c88;
    if (*(short *)(param_1 + 6) == 0) {
      *puVar1 = *puVar1 & 0xffbf;
    }
    else {
      *puVar1 = *puVar1 | 0x40;
    }
    *puVar2 = *puVar2 & 0x43 | *(short *)(param_1 + 8) << 0xe | *(short *)(param_1 + 0xc) << 8 |
              *(short *)(param_1 + 0xe) << 2 | *(short *)(param_1 + 10) << 0xd;
    return;
  case 3:
    if (param_2 != 0) {
      func_0214a428(DAT_02038c8c,&local_18,0,0,0,0);
      puVar1 = DAT_02038c80;
      *DAT_02038c80 = *DAT_02038c80 & 0xfffc | *puVar3;
      puVar2 = DAT_02038c80;
      if (*(short *)(param_1 + 6) == 0) {
        *puVar1 = *puVar1 & 0xffbf;
      }
      else {
        *puVar1 = *puVar1 | 0x40;
      }
      *puVar2 = *puVar2 & 0x43 | *(short *)(param_1 + 8) << 0xe | *(short *)(param_1 + 0xc) << 8 |
                *(short *)(param_1 + 10) << 0xd;
      return;
    }
    func_0214a428(DAT_02038c90,&local_18,0,0,0,0);
    puVar1 = DAT_02038c88;
    *DAT_02038c88 = *DAT_02038c88 & 0xfffc | *puVar3;
    puVar2 = DAT_02038c88;
    if (*(short *)(param_1 + 6) == 0) {
      *puVar1 = *puVar1 & 0xffbf;
    }
    else {
      *puVar1 = *puVar1 | 0x40;
    }
    *puVar2 = *puVar2 & 0x43 | *(short *)(param_1 + 8) << 0xe | *(short *)(param_1 + 0xc) << 8 |
              *(short *)(param_1 + 10) << 0xd;
    return;
  case 4:
    if (param_2 != 0) {
      func_0214a428(DAT_02038c8c,&local_18,0,0,0,0);
      puVar1 = DAT_02038c80;
      *DAT_02038c80 = *DAT_02038c80 & 0xfffc | *puVar3;
      puVar2 = DAT_02038c80;
      if (*(short *)(param_1 + 6) == 0) {
        *puVar1 = *puVar1 & 0xffbf;
      }
      else {
        *puVar1 = *puVar1 | 0x40;
      }
      *puVar2 = *puVar2 & 0x43 | *(short *)(param_1 + 8) << 0xe | 0x80 |
                *(short *)(param_1 + 0xc) << 8 | *(short *)(param_1 + 10) << 0xd;
      return;
    }
    func_0214a428(DAT_02038c90,&local_18,0,0,0,0);
    puVar1 = DAT_02038c88;
    *DAT_02038c88 = *DAT_02038c88 & 0xfffc | *puVar3;
    puVar2 = DAT_02038c88;
    if (*(short *)(param_1 + 6) == 0) {
      *puVar1 = *puVar1 & 0xffbf;
    }
    else {
      *puVar1 = *puVar1 | 0x40;
    }
    *puVar2 = *puVar2 & 0x43 | *(short *)(param_1 + 8) << 0xe | 0x80 |
              *(short *)(param_1 + 0xc) << 8 | *(short *)(param_1 + 10) << 0xd;
    return;
  case 5:
    if (param_2 != 0) {
      func_0214a428(DAT_02038c8c,&local_18,0,0,0,0);
      puVar1 = DAT_02038c80;
      *DAT_02038c80 = *DAT_02038c80 & 0xfffc | *puVar3;
      puVar2 = DAT_02038c80;
      if (*(short *)(param_1 + 6) == 0) {
        *puVar1 = *puVar1 & 0xffbf;
      }
      else {
        *puVar1 = *puVar1 | 0x40;
      }
      *puVar2 = *puVar2 & 0x43 | *(short *)(param_1 + 8) << 0xe | 0x84 |
                *(short *)(param_1 + 0xc) << 8 | *(short *)(param_1 + 10) << 0xd;
      return;
    }
    func_0214a428(DAT_02038c90,&local_18,0,0,0,0);
    puVar1 = DAT_02038c88;
    *DAT_02038c88 = *DAT_02038c88 & 0xfffc | *puVar3;
    puVar2 = DAT_02038c88;
    if (*(short *)(param_1 + 6) == 0) {
      *puVar1 = *puVar1 & 0xffbf;
    }
    else {
      *puVar1 = *puVar1 | 0x40;
    }
    *puVar2 = *puVar2 & 0x43 | *(short *)(param_1 + 8) << 0xe | 0x84 |
              *(short *)(param_1 + 0xc) << 8 | *(short *)(param_1 + 10) << 0xd;
  }
  return;
}

