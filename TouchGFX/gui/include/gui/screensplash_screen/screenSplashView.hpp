#ifndef SCREENSPLASHVIEW_HPP
#define SCREENSPLASHVIEW_HPP

#include <gui_generated/screensplash_screen/screenSplashViewBase.hpp>
#include <gui/screensplash_screen/screenSplashPresenter.hpp>

class screenSplashView : public screenSplashViewBase
{
public:
    screenSplashView();
    virtual ~screenSplashView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SCREENSPLASHVIEW_HPP
