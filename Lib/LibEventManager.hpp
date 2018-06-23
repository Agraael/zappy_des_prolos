//
// Created by Ludovica Pagliarani on 09/05/2018.
//

#ifndef LIBEVENTMANAGER_HPP
#define LIBEVENTMANAGER_HPP

#include <irrlicht/irrlicht.h>

struct	vec2d {
	int	x;
	int	y;
};

namespace graphic
{
	typedef struct s_contextRecEvnt
	{
		irr::IrrlichtDevice	*device;
		irr::s32		counter;
		irr::gui::IGUIListBox*	listbox;
	}             t_contextRecEvnt;
	enum controllerUser
	{
		OPEN_INVENTARY,
		CLOSE_INVENTARY,
		GUI_ID_NO_BUTTON,
		EXIT_MAINMENU,
	};

	class LibEventManager : public irr::IEventReceiver
	{
	public:
		explicit LibEventManager(t_contextRecEvnt const& context);
		~LibEventManager() override = default;
		bool OnEvent(const irr::SEvent& event) override;
		virtual bool IsKeyDown(irr::EKEY_CODE keyCode) const;
		bool IsButtonClicked(graphic::controllerUser) const;
		struct vec2d getInputMouse() const { return _inputMouse; }
	private:
		struct vec2d _inputMouse;
		bool KeyIsDown[irr::KEY_KEY_CODES_COUNT]{};
		mutable irr::s32 _pressedButton{GUI_ID_NO_BUTTON};
		t_contextRecEvnt _context;
    };
}

#endif //LIBEVENTMANAGER_HPP
