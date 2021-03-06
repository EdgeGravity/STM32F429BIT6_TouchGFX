/* DO NOT EDIT THIS FILE */
/* This file is autogenerated by the text-database code generator */

#include <fonts/ApplicationFontProvider.hpp>
#include <fonts/GeneratedFont.hpp>
#include <texts/TypedTextDatabase.hpp>

touchgfx::Font* ApplicationFontProvider::getFont(touchgfx::FontId typography)
{
    switch (typography)
    {
    case Typography::DEFAULT:
        // verdana_20_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[0]);
    case Typography::LARGE:
        // verdana_40_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[1]);
    case Typography::SMALL:
        // verdana_10_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[2]);
    case Typography::BENDER_46PX:
        // Bender_otf_46_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[3]);
    case Typography::BENDER_34PX:
        // Bender_otf_34_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[4]);
    case Typography::COURIERNEW_14PX:
        // cour_14_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[5]);
    case Typography::APEXLOGO_SOCIALNETWORK:
        // ApexLogo_SocialNetwork_64_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[6]);
    case Typography::APEXLOGO_GUI:
        // ApexLogo_GUI_32_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[7]);
    case Typography::APEXLOGO_BATTERY:
        // ApexLogo_Battery_32_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[8]);
    case Typography::APEXLOGO:
        // ApexLogo_64_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[9]);
    case Typography::ROBOTO_24PX:
        // Roboto_Regular_24_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[10]);
    case Typography::BENDER_24PX:
        // Bender_otf_24_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[11]);
    case Typography::ROBOTO_THIN_100PX:
        // Roboto_Thin_100_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[12]);
    case Typography::ROBOTO_14PX:
        // Roboto_Regular_14_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[13]);
    default:
        return 0;
    }
}
