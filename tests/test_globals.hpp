#ifndef _TESTGLOBABLS_HPP_
#define _TESTGLOBABLS_HPP_

#include <SFML/Window.hpp>
#include <renderwure/engine/GTAEngine.hpp>

// Many tests require OpenGL be functional, seems like a reasonable solution.

class Global
{
public:
	sf::Window wnd;
	GTAEngine* e;
	
	Global() {
		wnd.create(sf::VideoMode(640, 360), "Testing");
		glewExperimental = GL_TRUE;
		glewInit();
		e = new GTAEngine("data");
	}

	~Global() {
		wnd.close();
	}
	
	static Global& get()
	{
		static Global g;
		return g;
	}
};

#endif 