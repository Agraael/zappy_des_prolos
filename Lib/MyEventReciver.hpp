//
// Created by Ludovica Pagliarani on 15/06/2018.
//

#ifndef MYEVENTRECIVER_HPP
#define MYEVENTRECIVER_HPP

#include <irrlicht/irrlicht.h>

using namespace irr;

namespace graphic {
    typedef struct SAppContext
    {
        IrrlichtDevice *device;
        //s32             counter;
        //IGUIListBox*    listbox;
    }  t_contextRecEvnt;
    class MyEventReceiver : public IEventReceiver {
        t_contextRecEvnt _context;
    public:
        MyEventReceiver(const t_contextRecEvnt &context) : _context(context) {}

        virtual bool OnEvent(const SEvent &event) {
            std::cout << "qui puo essere di no" << std::endl;
            // Remember whether each key is down or up
            if (event.EventType == irr::EET_KEY_INPUT_EVENT)
                KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
            if (event.EventType == irr::EET_GUI_EVENT) {
                irr::s32 id = event.GUIEvent.Caller->getID();
//              irr::gui::IGUIEnvironment* env = _context.device->getGUIEnvironment();
                switch (event.GUIEvent.EventType) {
                    case irr::gui::EGET_BUTTON_CLICKED:
                    std::cout << "entra qui " << std::endl;
                        switch (id) {
                            case 3:
                                std::cout << "printed" << std::endl;
                                return true;
                            default:
                                return false;
                        }
                    default:
                        break;
                }
            }

            return false;
        }

        // This is used to check whether a key is being held down
        virtual bool IsKeyDown(EKEY_CODE keyCode) const {
            return KeyIsDown[keyCode];
        }

        MyEventReceiver() {
            for (u32 i = 0; i < KEY_KEY_CODES_COUNT; ++i)
                KeyIsDown[i] = false;
        }

    private:
        // We use this array to store the current state of each key
        bool KeyIsDown[KEY_KEY_CODES_COUNT];
    };
}

#endif //MYEVENTRECIVER_HPP
