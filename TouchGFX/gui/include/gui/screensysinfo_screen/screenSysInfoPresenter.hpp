#ifndef SCREENSYSINFOPRESENTER_HPP
#define SCREENSYSINFOPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class screenSysInfoView;

class screenSysInfoPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    screenSysInfoPresenter(screenSysInfoView& v);

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

    virtual ~screenSysInfoPresenter() {};

    void EG_ChangeScreen(uint8_t key);

private:
    screenSysInfoPresenter();

    screenSysInfoView& view;
};

#endif // SCREENSYSINFOPRESENTER_HPP
