#pragma once

#include "types.h"

void m2d_initFont(void *font, void *fontData);
void m2d_copyTiles2d(void *source, s32 sourceTileX, s32 sourceTileY, s32 tileWidth, s32 tileHeight, void *destination,
                    s32 destinationTileX, s32 destinationTileY);
void m2d_copyTiles2dVFlip(u16 *source, s32 sourceTileX, s32 sourceTileY, s32 tileWidth, s32 tileHeight,
                                     u16 *destination, s32 destinationTileX, s32 destinationTileY);
void m2d_copyCharMapTiles2d(u16 *source, s32 sourceColumn, s32 sourceRow, s32 columnCount, s32 rowCount, u16 *destination,
                        s32 destinationColumn, s32 destinationRow);
void m2d_setCharMapPalette2d(u16 *screenMap, s32 column, s32 row, s32 columnCount, s32 rowCount, u16 topBits);
void m2d_setCharMapCharName2d(u16 *screenMap, s32 column, s32 row, s32 columnCount, s32 rowCount, s32 lowBits);
void m2d_getPlayerPortrait(u16 *paletteDestination, s32 paletteRow, u16 *charsDestination, s32 column,
                                        s32 row);
