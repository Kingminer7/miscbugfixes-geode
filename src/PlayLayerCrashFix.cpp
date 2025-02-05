// fixes an android crash when hiding/showing the app with playlayer running

#ifdef GEODE_IS_ANDROID
#include <Geode/modify/GameManager.hpp>

class $modify (GameManager) {
    void applicationDidEnterBackground() {
        if (auto pl = PlayLayer::get()) {
            pl->pauseGame(true);
        }
        GameManager::applicationDidEnterBackground();
    }
};
#endif