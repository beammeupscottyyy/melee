#ifndef _lblanguage_h_
#define _lblanguage_h_

#include <Runtime/platform.h>

typedef enum {
    LANG_JP,
    LANG_US,
    LANG_COUNT,
} LbLanguage;

LbLanguage lbLang_GetLanguageSetting(void);
LbLanguage lbLang_SetLanguageSetting(LbLanguage language);
bool lbLang_IsSettingJP(void);
bool lbLang_IsSettingUS(void);
LbLanguage lbLang_GetSavedLanguage(void);
void lbLang_SetSavedLanguage(LbLanguage language);
bool lbLang_IsSavedLanguageJP(void);
bool lbLang_IsSavedLanguageUS(void);

#endif
