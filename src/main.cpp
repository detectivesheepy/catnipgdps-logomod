#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) {
            return false;
        }

        // Find the original main menu title sprite
        auto mainTitle = this->getChildByID("main-title");
        
        if (mainTitle) {
            // Match the position coordinates 
            auto position = mainTitle->getPosition();
            
            // Remove the original layout logo
            mainTitle->removeFromParent();

            // Create your replacement custom logo sprite asset
            auto newTitle = CCSprite::create("my-custom-logo.png");
            
            if (newTitle) {
                newTitle->setPosition(position);
                newTitle->setID("main-title"); 
                
                // Mount to the active scene layout
                this->addChild(newTitle);
            }
        }

        return true;
    }
};
