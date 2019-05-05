#include "test_header.h"


int main()
{
	Submenu mainmenu;
	Submenu menu1;
	Submenu menu2;
	Submenu menu3;
	Submenu menu4;
	Submenu menu5;
	Submenu varbox;
	mainmenu.set_name("main");
	mainmenu.set_support_var("to nie dziala");
	menu1.set_name("temp1");
	menu1.set_support_var("tutaj bedzie opis");
	menu1.set_color(2);
	menu2.set_name("temp2");
	menu2.set_behavior(2);
	menu2.set_support_var("enter text here: ");
	menu3.set_name("temp3");
	menu3.set_behavior(3);
	menu4.set_name("submenu1");
	menu5.set_name("submenu2");
	varbox.set_name("varible: ");
	varbox.set_value(2);
	varbox.set_color(4);

	mainmenu.add_choice(1);
	mainmenu.add_choice(2);
	mainmenu.add_choice(3);
	menu1.add_choice(4);
	menu1.add_choice(5);
	menu1.add_choice(6);
	all.push_back(mainmenu);
	all.push_back(menu1);
	all.push_back(menu2);
	all.push_back(menu3);
	all.push_back(menu4);
	all.push_back(menu5);
	all.push_back(varbox);

	while (running)
	{
		test_header::tick();
	}

	return 0;
}