/* Decompiled C draft; module arm9_ov000; ROM address 0219338c. No matching claim. */
#include "types.h"
#include "deps/0219338c_FUN_0219338c.h"

void FUN_0219338c(int *param_1,int param_2)

{
  if (*param_1 == 0) {
    *(undefined1 *)(param_2 + 8) = 0;
  }
  else {
    FUN_02196914(param_2 + 8,*param_1,0x1f);
  }
  if (param_1[1] == 0) {
    *(undefined1 *)(param_2 + 0x27) = 0;
  }
  else {
    FUN_02196914(param_2 + 0x27,param_1[1],0x15);
  }
  if (param_1[2] == 0) {
    *(undefined1 *)(param_2 + 0x3c) = 0;
  }
  else {
    FUN_02196914(param_2 + 0x3c,param_1[2],0x33);
  }
  if (param_1[3] == 0) {
    *(undefined1 *)(param_2 + 0x6f) = 0;
  }
  else {
    FUN_02196914(param_2 + 0x6f,param_1[3],0x1f);
  }
  if (param_1[4] == 0) {
    *(undefined1 *)(param_2 + 0x8e) = 0;
  }
  else {
    FUN_02196914(param_2 + 0x8e,param_1[4],0x1f);
  }
  if (param_1[5] == 0) {
    *(undefined1 *)(param_2 + 0xad) = 0;
  }
  else {
    FUN_02196914(param_2 + 0xad,param_1[5],0x4c);
  }
  *(int *)(param_2 + 0xfc) = param_1[6];
  FUN_02196914(param_2 + DAT_0219356c,(int)(uintptr_t)(param_1 + 7),0xb);
  FUN_02196914(param_2 + DAT_02193570,(int)param_1 + 0x27,3);
  *(int *)(param_2 + DAT_02193574) = param_1[0xb];
  *(int *)(param_2 + DAT_02193578) = param_1[0xc];
  if (param_1 + 0xd == (int *)0x0) {
    *(undefined1 *)(param_2 + DAT_0219357c) = 0;
  }
  else {
    FUN_02196914(param_2 + DAT_0219357c,(int)(uintptr_t)(param_1 + 0xd),0x80);
  }
  *(int *)(param_2 + DAT_02193580) = param_1[0x2d];
  *(int *)(param_2 + DAT_02193584) = param_1[0x2e];
  *(int *)(param_2 + DAT_02193588) = param_1[0x2f];
  *(int *)(param_2 + DAT_0219358c) = param_1[0x30];
  *(int *)(param_2 + DAT_02193590) = param_1[0x31];
  if (param_1[0x32] == 0) {
    *(undefined1 *)(param_2 + DAT_02193594) = 0;
  }
  else {
    FUN_02196914(param_2 + DAT_02193594,param_1[0x32],0x33);
  }
  *(int *)(param_2 + 0xfc) = param_1[6];
  *(int *)(param_2 + DAT_02193574) = param_1[0xb];
  *(int *)(param_2 + DAT_02193578) = param_1[0xc];
  *(int *)(param_2 + DAT_02193580) = param_1[0x2d];
  *(int *)(param_2 + DAT_02193584) = param_1[0x2e];
  *(int *)(param_2 + DAT_02193588) = param_1[0x2f];
  *(int *)(param_2 + DAT_0219358c) = param_1[0x30];
  *(int *)(param_2 + DAT_02193590) = param_1[0x31];
  *(int *)(param_2 + DAT_02193598) = param_1[0x33];
  *(int *)(param_2 + DAT_0219359c) = param_1[0x34];
  *(int *)(param_2 + DAT_021935a0) = param_1[0x35];
  *(int *)(param_2 + DAT_021935a4) = param_1[0x36];
  *(int *)(param_2 + DAT_021935a8) = param_1[0x37];
  *(int *)(param_2 + DAT_021935ac) = param_1[0x38];
  *(int *)(param_2 + DAT_021935b0) = param_1[0x39];
  *(int *)(param_2 + DAT_021935b4) = param_1[0x3a];
  *(int *)(param_2 + DAT_021935b8) = param_1[0x3b];
  return;
}

