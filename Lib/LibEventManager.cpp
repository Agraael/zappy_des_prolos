//
// Created by Ludovica Pagliarani on 09/05/2018.
//

#include <iostream>
#include "LibEventManager.hpp"

graphic::LibEventManager::LibEventManager(t_contextRecEvnt const& context)
	: _context(context)
{
    for (bool& i : KeyIsDown)
	    i = false;
}

bool graphic::LibEventManager::OnEvent(const irr::SEvent& event)
{
	_pressedButton = GUI_ID_NO_BUTTON;
	if (event.EventType == irr::EET_KEY_INPUT_EVENT)
		KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
	if (event.EventType == irr::EET_GUI_EVENT)
	{
		irr::s32 id = event.GUIEvent.Caller->getID();
		switch(event.GUIEvent.EventType)
		{
		case irr::gui::EGET_BUTTON_CLICKED:
			_pressedButton = id;
			switch(id)
			{
				case graphic::EXIT_MAINMENU:
					_context.device->closeDevice();
					return true;
				default:
					return false;
			}
			break;
		default:
			break;
		}
	}
	return false;
}

bool graphic::LibEventManager::IsKeyDown(irr::EKEY_CODE keyCode) const
{
    return KeyIsDown[keyCode];
}

bool graphic::LibEventManager::IsButtonClicked(graphic::controllerUser id) const
{
	if (id == _pressedButton){
		_pressedButton = GUI_ID_NO_BUTTON;
		return true;
	}
	return false;
}
