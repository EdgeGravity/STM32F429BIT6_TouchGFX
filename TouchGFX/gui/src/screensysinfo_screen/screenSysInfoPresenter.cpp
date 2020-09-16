#include <gui/screensysinfo_screen/screenSysInfoView.hpp>
#include <gui/screensysinfo_screen/screenSysInfoPresenter.hpp>

screenSysInfoPresenter::screenSysInfoPresenter(screenSysInfoView& v)
    : view(v)
{

}

void screenSysInfoPresenter::activate()
{

}

void screenSysInfoPresenter::deactivate()
{

}

void screenSysInfoPresenter::EG_ChangeScreen(uint8_t key) {
    view.handleKeyEvent(key);
}
