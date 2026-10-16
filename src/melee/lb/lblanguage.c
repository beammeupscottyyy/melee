#include "lblanguage.h"

#include <melee/gm/gmmain_lib.h>
#include <melee/gm/types.h>

LbLanguage lbLang_GetLanguageSetting(void)
{
    return gmMainLib_804D3EE0->language;
}

LbLanguage lbLang_SetLanguageSetting(LbLanguage language)
{
    if (language >= 0 && language < LANG_COUNT) {
        gmMainLib_804D3EE0->language = language;
    }

    return language;
}

bool lbLang_IsSettingJP(void)
{
    return gmMainLib_804D3EE0->language == LANG_JP ? true : false;
}

bool lbLang_IsSettingUS(void)
{
    return gmMainLib_804D3EE0->language == LANG_US ? true : false;
}

LbLanguage lbLang_GetSavedLanguage(void)
{
    return gmMainLib_GetGamePrefs()->saved_language;
}

void lbLang_SetSavedLanguage(LbLanguage language)
{
    if (language >= 0 && language < LANG_COUNT) {
        gmMainLib_GetGamePrefs()->saved_language = language;
    }
}

bool lbLang_IsSavedLanguageJP(void)
{
    return gmMainLib_GetGamePrefs()->saved_language == LANG_JP ? true : false;
}

bool lbLang_IsSavedLanguageUS(void)
{
    return gmMainLib_GetGamePrefs()->saved_language == LANG_US ? true : false;
}
