#pragma once

void jn_ui_drawFormattedTextRect(const NNSG2dTextCanvas* canvas, int x, int y, int width, int height, int color,
                                 int alignFlags, int a8, const u16* text);
void jn_ui_drawFormattedTextRectMonospace(const NNSG2dTextCanvas* canvas, int x, int y, int width, int height,
                                          int color, int alignFlags, int a8, const u16* text, BOOL monospaceNumbers,
                                          int charWidth);
void jn_ui_drawFormattedTextRectSomething(const NNSG2dTextCanvas* canvas, int x, int y, int width, int height,
                                          int color, int alignFlags, int a8, const u16* text);
