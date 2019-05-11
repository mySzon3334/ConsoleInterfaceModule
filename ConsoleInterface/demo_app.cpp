#include "pch.h"
#include "ConsoleInterfaceModule.h"

using namespace std;

int main()
{	
	module_init();		// init of module

	Submenu mainmenu;
	Submenu menu1;
	Submenu menu2;
	Submenu menu3;
	Submenu menu4;
	Submenu menu5;
	Submenu varbox;
	Submenu backbox;
	Submenu exitbox;
	mainmenu.set_name("main");
	mainmenu.set_support_var("Move up with W and down with S, select using Enter");
	menu1.set_name("I'am submenu");
	menu1.set_support_var("Press Space to move back");
	menu1.set_color(2);
	menu2.set_name("I'am input box");
	menu2.set_behavior(2);
	menu2.set_support_var("Enter your text here: ");
	menu3.set_name("I'am true/false tick box");
	menu3.set_behavior(3);
	menu4.set_name("I'am empty");
	menu5.set_name("I'am empty 2");
	varbox.set_name("I can display varible: ");
	varbox.set_value("56");
	varbox.set_color(4);
	backbox.set_name("Back");
	backbox.set_behavior(4);
	exitbox.set_name("Exit");
	exitbox.set_behavior(5);

	mainmenu.add_choice(1);
	mainmenu.add_choice(2);
	mainmenu.add_choice(3);
	mainmenu.add_choice(8);
	menu1.add_choice(4);
	menu1.add_choice(5);
	menu1.add_choice(6);
	menu1.add_choice(7);
	all.push_back(mainmenu);
	all.push_back(menu1);	
	all.push_back(menu2);
	all.push_back(menu3);
	all.push_back(menu4);
	all.push_back(menu5);
	all.push_back(varbox);
	all.push_back(backbox);
	all.push_back(exitbox);
	
	
	while (running)
	{
		tick();
	}
 

}




