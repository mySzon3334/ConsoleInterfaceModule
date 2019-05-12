#pragma once
#include <iostream>
#include <Windows.h>		// system("")
#include <vector>			// vectors
#include <string>			// strings
#include <conio.h>			// _getch()
#include "ConsoleColor.h"	// coloring cout output

using namespace std;

// VARIABLE DECLARATION

vector<string> header;

int position, line, input, last_clicked;
vector<int> history;
vector<string> head_message;
bool running;

namespace sttg
{
	int logs = 2;							// logging to file, 0 - off,  1 - only init,  2 - on,  3 - full  ( view docs for more info )
	string deafult_string_value = "Null";	// don't touch it, if values aren't displayed correctly change it to some big number or random string
	int selection_mode = 0;					// 0 - w/s arrow, 1 - numbers
	int back_key = 32;						// ascii of key to move back, deafult is 32 (space), set to 0 to turn it off
	int up_key = 119;						// ascii of key to move up, default id 119 (w)
	int down_key = 115;						// ascii of key to move up, default id 115 (s)
	int select_key = 13;					// ascii of key to select, deafult is 13 (enter)
	string pointer_string = "--> ";			// string that will be used as an arrow to point in selection_mode = 0
	string true_string = "    True";		// string that will be used when bool varible object is true
	string false_string = "    False";		// string that will be used when bool varible object is false
	string pre_value = ":  ";				// string that will be displayed between obj name and obj value
	int color_true = 4;						// color for true_string
	int color_false = 3;					// color for false_string
	int color_header = 2;
}

class Submenu {
public:
	string name;
	string value = sttg::deafult_string_value;
	bool bool_value = false;
	vector<int> choices;
	int color = 0;											// 0 - white, 1 - blue, 2 - red, 3 - green, 4 - yellow
	int behavior = 0;	// what object do when selected: 0 - jump to submenu, 1 - nothing, 2 - open input box, 3 - change bool state
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
	void set_value(string a) { value = a; }
	void set_color(int a) { color = a; }
	void set_behavior(int a) { behavior = a; }
	void set_support_var(string a) { support_varible = a; }	// it will be displayed only in input box or at the top of submenu
};

vector<Submenu> all;

void log(int log_type, string log_msg)
{
	if (log_type <= sttg::logs)
	{
		string temp, temp2, temp3;
		temp = "echo ";
		temp2 = " >> cim_logs.txt";
		temp3 = temp + log_msg + temp2;
		const char * c = temp3.c_str();
		system(c);
	}
}

int clear_log()
{
	system("del cim_logs.txt");
	system("echo logs cleared >> cim_logs.txt");
}

int getPosition()
{
	return position;
}

void go_back()
{
	log(2, "moved back");
	history.pop_back();
	position = history[history.size() - 1];
}

void close()
{
	log(2, "closing.");
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

int displayHeader()
{
	int i;
	set_color(sttg::color_header);
	for (i = 0; i < header.size(); i++)
	{
		cout << header[i] << endl;
	}
	cout << white;
	return 0;
}

int input_handling(int inp)	// takes ascii input as argument
{
	log(3, "input recived");
	int temp;

	if (sttg::selection_mode == 0)
	{
		if (inp == sttg::up_key && line > 0)
			line--;
		if (inp == sttg::down_key && line < (all[position].choices.size() - 1))
			line++;
	}

	if (inp == sttg::select_key && sttg::selection_mode == 0 || 48 < inp && inp < 58 && sttg::selection_mode == 1)
	{
		if (sttg::selection_mode == 0)
			temp = line;
		if (sttg::selection_mode == 1)
			temp = inp - 48 - 1;

		last_clicked = all[position].choices[temp];

		switch (all[all[position].choices[temp]].behavior)
		{
		case 0:
			if (all[all[position].choices[temp]].choices.size() > 0)
			{
				string temp2;
				temp2 = to_string(position);
				log(2, "moved to " + temp2);
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
			log(2, "chaned bool state");
			if (all[all[position].choices[temp]].bool_value == false)
				all[all[position].choices[temp]].bool_value = true;
			else
				all[all[position].choices[temp]].bool_value = false;
			break;
		case 4:
			if(history.size() > 1)
				go_back();
			break;
		case 5:
			close();
			break;
		}
	}
	if (sttg::back_key != 0 && inp == sttg::back_key && history.size() > 1)
	{
		go_back();
	}
	return 0;
}

int display()
{
	cout << all[position].support_varible << endl << endl;
	int i;
	for (i = 0; i < head_message.size(); i++)
	{
		cout << head_message[i] << endl;
	}
	for (i = 0; i < all[position].choices.size(); i++)		// size of vector in class
	{
		if (i == line && sttg::selection_mode == 0)
			cout << sttg::pointer_string;

		set_color(all[all[position].choices[i]].color);

		if (sttg::selection_mode == 1)
			cout << i + 1 << ".  ";
		cout << all[all[position].choices[i]].name;
		if (all[all[position].choices[i]].value != sttg::deafult_string_value)	// check if value is != then deafult_string_value
			cout << sttg::pre_value << all[all[position].choices[i]].value << white << endl;
		else
		{
			if (all[all[position].choices[i]].behavior == 3)
			{
				if (all[all[position].choices[i]].bool_value == true)
				{
					set_color(sttg::color_true);
					cout << sttg::true_string << white << endl;
				}
				else
				{
					set_color(sttg::color_false);
					cout << sttg::false_string << white << endl;
				}
			}
			else
				cout << white << endl;
		}
	}
	return 0;
}

int module_init()				// run this at the top of your cpp source file
{
	string temp;
	temp = to_string(sttg::logs);
	log(1, "starting console_interface_module");
	log(1, "logs are set to " + temp);
	header.push_back("");
	position = 0;
	history.push_back(position);
	line = 0;
	running = true;
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