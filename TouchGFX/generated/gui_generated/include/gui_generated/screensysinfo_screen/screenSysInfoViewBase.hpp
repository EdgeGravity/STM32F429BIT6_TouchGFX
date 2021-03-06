/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SCREENSYSINFOVIEWBASE_HPP
#define SCREENSYSINFOVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/screensysinfo_screen/screenSysInfoPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/TiledImage.hpp>
#include <gui/containers/SensorContainer.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/containers/SlideMenu.hpp>
#include <touchgfx/widgets/Image.hpp>

class screenSysInfoViewBase : public touchgfx::View<screenSysInfoPresenter>
{
public:
    screenSysInfoViewBase();
    virtual ~screenSysInfoViewBase() {}
    virtual void setupScreen();
    virtual void handleKeyEvent(uint8_t key);

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box boxImage_BG;
    touchgfx::TiledImage tiledImage_Grid;
    SensorContainer sensorContainer_CPU;
    touchgfx::TextArea textCopyright;
    touchgfx::TextArea textProjectName;
    touchgfx::TextArea textQuotes;
    touchgfx::TextArea textProductName;
    touchgfx::TextArea textSysInfoL;
    touchgfx::TextArea textSysInfoS;
    touchgfx::SlideMenu slideMenu;
    touchgfx::TextArea textMenu;
    touchgfx::Image imageCherry;
    touchgfx::Image imageChiphell;
    touchgfx::TextArea textArea1;

private:

};

#endif // SCREENSYSINFOVIEWBASE_HPP
