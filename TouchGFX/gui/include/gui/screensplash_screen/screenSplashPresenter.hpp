#ifndef SCREENSPLASHPRESENTER_HPP
#define SCREENSPLASHPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class screenSplashView;

class screenSplashPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    screenSplashPresenter(screenSplashView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~screenSplashPresenter() {};

    void EG_ChangeScreen(uint8_t key);

private:
    screenSplashPresenter();

    screenSplashView& view;
};

#endif // SCREENSPLASHPRESENTER_HPP
