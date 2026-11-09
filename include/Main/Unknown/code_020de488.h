#pragma once

#include "types.h"

typedef struct PushedObject PushedObject;

u8 CollideKartWithEarthenPipe(PushedObject *pipe, void *kart, u8 *firstResponsePtr, u8 *secondResponsePtr);
u8 CollideItemObjectWithEarthenPipe(PushedObject *pipe, void *itemObject, u8 *firstResponsePtr, u8 *secondResponsePtr);
