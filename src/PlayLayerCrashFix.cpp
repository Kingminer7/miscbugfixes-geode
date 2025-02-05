// fixes an android crash when hiding/showing the app with playlayer running
#ifdef GEODE_IS_ANDROID
#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/CCApplication.hpp>
class $modify (CCApplication) {
    // Game saves on app hide (last i checked)
    void gameDidSave() {
        CCApplication::gameDidSave();
        if (auto pl = PlayLayer::get()) {
            pl->pauseGame(true);
        }
    }
};
#endif