#include <gui/screen_screen/screenView.hpp>

screenView::screenView()
{
    screenViewBase::handleKeyEvent(1);
}

void screenView::setupScreen()
{
    screenViewBase::setupScreen();
}

void screenView::tearDownScreen()
{
    screenViewBase::tearDownScreen();
}
