#include "game_state.h"
#include "main_menu.h"



game_state corestate;
extern bool quitgame =false;
int main()
{

	sf::RenderWindow window(sf::VideoMode(1024,820 ), "pong");
	tine_state state = tine_state();
	corestate.Setwindow(&window);
	corestate.SetState(new main_menu());

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::Black);
		corestate.Update();
		corestate.Render();
		window.display();
		if (quitgame)
		{
			window.close();
		}
	}

	return 0;
}