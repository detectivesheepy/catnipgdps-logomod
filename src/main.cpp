#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) {
            return false;
        }

        // 1. Find the original main menu title sprite
        // In GD 2.2, the title is typically a CCNode named "main-title"
        auto mainTitle = this->getChildByID("main-title");
        
        if (mainTitle) {
            // Get the position of the old logo so the new one matches perfectly
            auto position = mainTitle->getPosition();
            
            // Remove the original logo
            mainTitle->removeFromParent();

            // 2. Create your custom logo sprite
            // "my-custom-logo.png" must be included in your mod's resources
            auto newTitle = CCSprite::create("my-custom-logo.png");
            
            if (newTitle) {
                newTitle->setPosition(position);
                newTitle->setID("main-title"); // Keep the ID for compatibility
                
                // Add the new logo to the menu layer
                this->addChild(newTitle);
            }
        }

        return true;
    }
};
