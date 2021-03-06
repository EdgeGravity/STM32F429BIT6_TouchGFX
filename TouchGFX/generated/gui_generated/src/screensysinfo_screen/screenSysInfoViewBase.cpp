/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screensysinfo_screen/screenSysInfoViewBase.hpp>
#include <touchgfx/Color.hpp>
#include "BitmapDatabase.hpp"
#include <texts/TextKeysAndLanguages.hpp>

screenSysInfoViewBase::screenSysInfoViewBase()
{

    boxImage_BG.setPosition(0, 0, 800, 480);
    boxImage_BG.setColor(touchgfx::Color::getColorFrom24BitRGB(24, 34, 41));

    tiledImage_Grid.setBitmap(touchgfx::Bitmap(BITMAP_GRID_50PX_ID));
    tiledImage_Grid.setPosition(0, 0, 800, 480);
    tiledImage_Grid.setOffset(0, 0);

    sensorContainer_CPU.setXY(20, 160);

    textCopyright.setXY(481, 462);
    textCopyright.setColor(touchgfx::Color::getColorFrom24BitRGB(228, 239, 237));
    textCopyright.setLinespacing(0);
    textCopyright.setTypedText(touchgfx::TypedText(T_SINGLEUSEID8));

    textProjectName.setXY(502, 439);
    textProjectName.setColor(touchgfx::Color::getColorFrom24BitRGB(228, 239, 237));
    textProjectName.setLinespacing(0);
    textProjectName.setTypedText(touchgfx::TypedText(T_SINGLEUSEID6));

    textQuotes.setXY(20, 6);
    textQuotes.setColor(touchgfx::Color::getColorFrom24BitRGB(248, 114, 12));
    textQuotes.setLinespacing(0);
    textQuotes.setTypedText(touchgfx::TypedText(T_SINGLEUSEID16));

    textProductName.setXY(244, 17);
    textProductName.setColor(touchgfx::Color::getColorFrom24BitRGB(228, 239, 237));
    textProductName.setLinespacing(0);
    textProductName.setTypedText(touchgfx::TypedText(T_SINGLEUSEID11));

    textSysInfoL.setXY(20, 17);
    textSysInfoL.setColor(touchgfx::Color::getColorFrom24BitRGB(228, 239, 237));
    textSysInfoL.setLinespacing(0);
    textSysInfoL.setTypedText(touchgfx::TypedText(T_SINGLEUSEID22));

    textSysInfoS.setXY(20, 20);
    textSysInfoS.setVisible(false);
    textSysInfoS.setColor(touchgfx::Color::getColorFrom24BitRGB(8, 238, 143));
    textSysInfoS.setLinespacing(5);
    textSysInfoS.setTypedText(touchgfx::TypedText(T_SINGLEUSEID13));

    slideMenu.setup(touchgfx::SlideMenu::WEST,
        touchgfx::Bitmap(BITMAP_TIC_TAC_TOE_ID),
        30, 30);
    slideMenu.setState(touchgfx::SlideMenu::COLLAPSED);
    slideMenu.setVisiblePixelsWhenCollapsed(30);
    slideMenu.setHiddenPixelsWhenExpanded(0);
    slideMenu.setAnimationEasingEquation(touchgfx::EasingEquations::cubicEaseInOut);
    slideMenu.setAnimationDuration(60);
    slideMenu.setExpandedStateTimeout(60);
    slideMenu.setXY(370, 50);

    textMenu.setXY(73, 71);
    textMenu.setColor(touchgfx::Color::getColorFrom24BitRGB(8, 238, 143));
    textMenu.setLinespacing(0);
    textMenu.setTypedText(touchgfx::TypedText(T_SINGLEUSEID9));
    slideMenu.add(textMenu);

    imageCherry.setXY(204, 76);
    imageCherry.setBitmap(touchgfx::Bitmap(BITMAP_CHERRYMX_ID));
    slideMenu.add(imageCherry);

    imageChiphell.setXY(336, 324);
    imageChiphell.setBitmap(touchgfx::Bitmap(BITMAP_CHIPHELL_ID));
    slideMenu.add(imageChiphell);

    textArea1.setXY(55, 346);
    textArea1.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID15));
    slideMenu.add(textArea1);

    add(boxImage_BG);
    add(tiledImage_Grid);
    add(sensorContainer_CPU);
    add(textCopyright);
    add(textProjectName);
    add(textQuotes);
    add(textProductName);
    add(textSysInfoL);
    add(textSysInfoS);
    add(slideMenu);
}

void screenSysInfoViewBase::setupScreen()
{
    sensorContainer_CPU.initialize();
}

//Handles when a key is pressed
void screenSysInfoViewBase::handleKeyEvent(uint8_t key)
{
    if(1 == key)
    {
        //Interaction_btn1_Clicked
        //When hardware button 1 clicked animateToState slideMenu
        //Set State on slideMenu to Expanded
        slideMenu.animateToState(SlideMenu::EXPANDED);
    }
}
