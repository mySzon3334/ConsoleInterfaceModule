﻿#include <iostream>
/*#include <Windows.h>		// system("")
#include <vector>			// vectors
#include <string>			// strings*/
#include "test_header.h"
#include "pch.h"
using namespace std;
/*
using namespace std;

// VARIABLE DECLARATION

string header[5] = { "	               .__                               ",
					 "	__  _  __ ____ |  |   ____  ____   _____   ____  ",
					 "	\\ \\/ \\/ // __ \\|  | _/ ___\\/  _ \\ /     \\_/ __ \\ ",
					 "	 \\     /\\  ___/|  |_\\  \\__(  <_> )  Y Y  \\  ___/ ",
					 "	  \\/\\_/  \\_____>____/\\_____>____/|__|_|__/\\_____>" };
				//	 "	             \/          \/            \/     \/ "}
int position, line, input;
vector<int> history;
bool running;

namespace cst
{
	string deafult_string_value = "Null";
	int selection_mode = 0;					// 0 - w/s arrow, 1 - numbers
	int back_key = 32;						// ascii of key to move back, deafult is 32 (space), set to 0 to turn it off
	int up_key = 119;
	int down_key = 115;
	int select_key = 13;					// ascii of key to select, deafult is 13 (enter)
	string pointer_string = "--> ";			// string that will be used as an arrow to point in selection_mode = 0
	string true_string = "    True";		// string that will be used when bool varible object is true
	string false_string = "    False";		// string that will be used when bool varible object is false
	string pre_value = ":  ";				// string that will be displayed between obj name and obj value
	int color_true = 4;						// color for true_string
	int color_false = 3;					// color for false_string
}

class Submenu {
public:
	string name;
	string value = cst::deafult_string_value;
	bool bool_value = false;
	vector<int> choices;
	int color = 0;											// 0 - white, 1 - blue, 2 - red, 3 - green, 4 - yellow
	int behavior = 0;	// what object do when selected: 0 - jump to submenu, 1 - nothing, 2 - open input box, 3 - change bool state;
						// 4 - go back, 5 - exit app
	string support_varible; // varible that sometimes class use, used to hold additional class information

	void add_choice(int ch)
	{
		choices.push_back(ch);
	}
	int get_choice(int index)
	{
		return choices[index];
	}
	void set_name(string a) { name = a; }
	void set_value(int a) { value = a; }
	void set_color(int a) { color = a; }
	void set_behavior(int a) { behavior = a; }
	void set_support_var(string a) { support_varible = a; }	// it will be displayed only in input box or at the top of submenu
};

class VaribleBox {
public:
	string name, value;
	void set_name(string varible) { name = varible; }
	void set_value(string varible) { value = varible; }*/

/*class Header {// for every new line in header write "endl" in single cell and "color_blue" for colored text.
public:
	vector<string>;
};


vector<Submenu> all;
//vector<VaribleBox> varbox;


int displayHeader()
{
	int i;
	for (i = 0; i < 5; i++)
	{
		cout << yellow << header[i] << white << endl;
	}
	return 0;
}

int getPosition()
{
	return position;
}

void go_back()
{
	history.pop_back();
	position = history[history.size() - 1];
}

void close()
{
	running = false;
}

int set_color(int color)
{
	switch (color)
	{
	case 0:
		cout << white;
		break;
	case 2:
		cout << blue;
		break;
	case 3:
		cout << red;
		break;
	case 4:
		cout << green;
		break;
	case 5:
		cout << yellow;
		break;
	default:
		return -1;
	}
	return 0;
}

int input_handling(int inp)	// takes ascii input as argument
{
	int temp;

	if (cst::selection_mode == 0)
	{
		if (inp == cst::up_key && line > 0)
			line--;
		if (inp == cst::down_key && line < (all[position].choices.size() - 1))
			line++;
	}

	if (inp == cst::select_key && cst::selection_mode == 0 || 48 < inp && inp < 58 && cst::selection_mode == 1)
	{
		if (cst::selection_mode == 0)
			temp = line;
		if (cst::selection_mode == 1)
			temp = inp - 48 - 1;

		switch (all[all[position].choices[temp]].behavior)
		{
		case 0:
			if (all[all[position].choices[temp]].choices.size() > 0)
			{
				position = all[position].choices[temp];
				history.push_back(position);
			}
			break;
		case 1:
			// do nothing
			break;
		case 2:
			system("cls");
			cout << all[all[position].choices[temp]].support_varible;
			cin >> all[all[position].choices[temp]].value;
			system("cls");
			break;
		case 3:
			if (all[all[position].choices[temp]].bool_value == false)
				all[all[position].choices[temp]].bool_value = true;
			else
				all[all[position].choices[temp]].bool_value = false;
			break;
		case 4:
			go_back();
			break;
		}
	}
	if (cst::back_key != 0 && inp == cst::back_key && history.size() > 1)
	{
		go_back();
	}
	return 0;
}

int display()
{
	int i;
	for (i = 0; i < all[position].choices.size(); i++)		// size of vector in class
			//if (all[position][i] != -1)
			//if(1000 <= all[position].choices[i] && all[position].choices[i] < 2000 )
										// if for clickable - for later use
	{
		if (i == line && cst::selection_mode == 0)
			cout << cst::pointer_string;

		set_color(all[all[position].choices[i]].color);

		if (cst::selection_mode == 1)
			cout << i + 1 << ".  ";
		cout << all[all[position].choices[i]].name;
		if (all[all[position].choices[i]].value != cst::deafult_string_value)	// check if value is != then deafult_string_value
			cout << cst::pre_value << all[all[position].choices[i]].value << white << endl;
		else
		{
			if (all[all[position].choices[i]].behavior == 3)
			{
				if (all[all[position].choices[i]].bool_value == true)
				{
					set_color(cst::color_true);
					cout << cst::true_string << white << endl;
				}
				else
				{
					set_color(cst::color_false);
					cout << cst::false_string << white << endl;
				}
			}
			else
				cout << white << endl;
		}
	}
	return 0;
}

int tick()
{
	system("cls");
	displayHeader();
	display();
		input = _getch();
		input_handling(input);
	return 0;
}
int create_obj(string name, string value = "Null", int color = 0, int behavior = 0, string description = "")
{	// this function will create object of Submenu and add it to 'all' vector | function returns index in 'all' of new object
	string temp, temp2;
	temp2 = to_string(all.size());
	temp = "obj" + temp2;
	Submenu temp;
	temp.set_name(name)
	return 0;
}*/

int main()
{	
	cout << "11" << endl;
	/*Submenu mainmenu;
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
	
	//string inp2;

	/*for (int i = 0; i < 4; i++)
	{
		cout << all[i].name << endl;
		for (auto m : all[i].choices)
		{
			cout << all[m].name << endl;
		}
	}
	cout << mainmenu.choices[0];
	int inp;
	inp = 0;
	int max_rows, i, j;
	string err_note;
	err_note = "";
	
	history.push_back(0);
	int inp;
	position = 0;
	line = 0;
	running = true;
	while (running)
	{
		tick();
	}
 
 */
}




