#pragma once

#include "types.h"

typedef struct WBTPacketBitmap WBTPacketBitmap;

void MarkChunkReceived(WBTPacketBitmap *bitmap, u32 chunkIndex);
