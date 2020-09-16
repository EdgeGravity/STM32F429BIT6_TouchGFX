#ifndef SCREENSYSINFOVIEW_HPP
#define SCREENSYSINFOVIEW_HPP

#include <gui_generated/screensysinfo_screen/screenSysInfoViewBase.hpp>
#include <gui/screensysinfo_screen/screenSysInfoPresenter.hpp>

class screenSysInfoView : public screenSysInfoViewBase
{
public:
    screenSysInfoView();
    virtual ~screenSysInfoView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SCREENSYSINFOVIEW_HPP
