#include <gui/screen_screen/screenView.hpp>
#include <gui/screen_screen/screenPresenter.hpp>

screenPresenter::screenPresenter(screenView &v) :
        view(v) {

}

void screenPresenter::activate() {

}

void screenPresenter::deactivate() {

}

void screenPresenter::EG_ChangeScreen(uint8_t key) {
    view.handleKeyEvent(key);
}
