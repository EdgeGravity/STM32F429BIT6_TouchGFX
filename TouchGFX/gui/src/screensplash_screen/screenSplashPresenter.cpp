#include <gui/screensplash_screen/screenSplashView.hpp>
#include <gui/screensplash_screen/screenSplashPresenter.hpp>

screenSplashPresenter::screenSplashPresenter(screenSplashView& v)
    : view(v)
{

}

void screenSplashPresenter::activate()
{

}

void screenSplashPresenter::deactivate()
{

}

void screenSplashPresenter::EG_ChangeScreen(uint8_t key) {
    view.handleKeyEvent(key);
}
