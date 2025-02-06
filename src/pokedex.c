#include "../include/gba/types.h"
#include "../include/text.h"

void __attribute__((long_call)) DexScreen_AddTextPrinterParameterized(u8 windowId, u8 fontId, const u8 *str, u8 x, u8 y, u8 colorIdx);

#if NATIONAL_DEX_COUNT < 999
#define NATIONAL_DEX_4_DIGITS
#endif

void DexScreen_PrintNumWLeadingZeroes(u8 windowId, u8 fontId, u16 num, u8 x, u8 y, u8 colorIdx) {
    u8 buff[5];
    buff[0] = (num / 1000) + CHAR_0;
    buff[1] = ((num %= 1000) / 100) + CHAR_0;
    buff[2] = ((num %= 100) / 10) + CHAR_0;
    buff[3] = (num % 10) + CHAR_0;
    buff[4] = EOS;
    DexScreen_AddTextPrinterParameterized(windowId, fontId, buff, x, y, colorIdx);
}