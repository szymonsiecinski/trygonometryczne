/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * main.cc
 * Copyright (C) Szymon Sieciński 2012 <szymon.siecinski@gmail.com>
 * 
 * Trygonometryczne is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Trygonometryczne is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <gtkmm.h>
#include <iostream>
#include<cmath>
#include "config.h"


#ifdef ENABLE_NLS
#  include <libintl.h>
#endif

/* For testing propose use the local (not installed) ui file */
/* #define UI_FILE PACKAGE_DATA_DIR"/trygonometryczne/ui/trygonometryczne.ui" */
#define UI_FILE "src/trygonometryczne.ui"
#define _USE_MATH_DEFINES

Gtk::ComboBoxText* jednostka=0;
Gtk::ComboBoxText* funkcja=0;
Gtk::Button* abprog=0;
Gtk::Button* closing=0;
Gtk::Entry* wej=0;
Gtk::Entry* wyj=0;

void zamknij()
{
	Gtk::Main::quit(); //zamykanie programu
}

void oprog()
{
	Gtk::AboutDialog a;
	std::vector<Glib::ustring> autorzy;
	autorzy.push_back("Szymon Sieciński <szymon.siecinski@gmail.com>");
	a.set_copyright("© 2012 Szymon Sieciński");
	a.set_program_name("Funkcje trygonometryczne");
	a.set_comments("Program wyznaczający wartości wybranych funkcji trygonometrycznych");
	a.set_license_type(Gtk::LICENSE_GPL_3_0);
	a.set_wrap_license(true);
	a.set_version ("Wersja 0.1");
	a.set_authors (autorzy);
	a.run();
}

void zamiana()
{
	std::locale::global(std::locale(""));
	double radianow=0;
	
	if(funkcja->get_active_text()=="Sinus")
	{
				if(jednostka->get_active_text()=="Stopnie")
				{
					radianow = strtod(wej->get_text().c_str(), NULL) * M_PI / 180;
					wyj->set_text(Glib::ustring::compose("sin(%1°)=%2", Glib::ustring::format(strtod(wej->get_text().c_str(), NULL)), Glib::ustring::format(sin(radianow))));
				}
				else
				{
					radianow = strtod(wej->get_text().c_str(), NULL);
					wyj->set_text(Glib::ustring::compose("sin(%1)=%2", Glib::ustring::format(radianow), Glib::ustring::format(sin(radianow))));
				}
		}
		if(funkcja->get_active_text()=="Cosinus")
		{
				if(jednostka->get_active_text()=="Stopnie")
				{
					radianow = strtod(wej->get_text().c_str(), NULL) * M_PI / 180;
					wyj->set_text(Glib::ustring::compose("cos(%1°)=%2", Glib::ustring::format(strtod(wej->get_text().c_str(), NULL)), Glib::ustring::format(cos(radianow))));
				}
				else
				{
					radianow = strtod(wej->get_text().c_str(), NULL);
					wyj->set_text(Glib::ustring::compose("cos(%1)=%2", Glib::ustring::format(radianow), Glib::ustring::format(cos(radianow))));
				}		
		}
		if(funkcja->get_active_text()=="Tangens")
		{
				if(jednostka->get_active_text()=="Stopnie")
				{
					radianow = strtod(wej->get_text().c_str(), NULL) * M_PI / 180;
					if(cos(radianow)!=0)
					wyj->set_text(Glib::ustring::compose("tg(%1°)=%2", Glib::ustring::format(strtod(wej->get_text().c_str(), NULL)), Glib::ustring::format(tan(radianow))));
					else
					{
						Gtk::MessageDialog err("Nieokreślona wartość funkcji", false, Gtk::MESSAGE_ERROR, Gtk::BUTTONS_OK, true);
						err.run();
					}
				}
				else
				{
					radianow = strtod(wej->get_text().c_str(), NULL);
					if(cos(radianow)!=0)
					wyj->set_text(Glib::ustring::compose("tg(%1)=%2", Glib::ustring::format(radianow), Glib::ustring::format(tan(radianow))));
					else
					{
						Gtk::MessageDialog err("Nieokreślona wartość funkcji", false, Gtk::MESSAGE_ERROR, Gtk::BUTTONS_OK, true);
						err.run();
					}
				}
		}
		if(funkcja->get_active_text()=="Cotangens")
		{
				if(jednostka->get_active_text()=="Stopnie")
				{
					radianow = strtod(wej->get_text().c_str(), NULL) * M_PI / 180;
					if(sin(radianow)!=0)
					wyj->set_text(Glib::ustring::compose("ctg(%1°)=%2", Glib::ustring::format(strtod(wej->get_text().c_str(), NULL)), Glib::ustring::format(1/tan(radianow))));
					else
					{
						Gtk::MessageDialog err("Nieokreślona wartość funkcji", false, Gtk::MESSAGE_ERROR, Gtk::BUTTONS_OK, true);
						err.run();
					}
				}
				else
				{
					radianow = strtod(wej->get_text().c_str(), NULL);
					if(sin(radianow)!=0)
					wyj->set_text(Glib::ustring::compose("ctg(%1)=%2", Glib::ustring::format(radianow), Glib::ustring::format(1/tan(radianow))));
					else
					{
						Gtk::MessageDialog err("Nieokreślona wartość funkcji", false, Gtk::MESSAGE_ERROR, Gtk::BUTTONS_OK, true);
						err.run();
					}
				}	
		}
		if(funkcja->get_active_text()=="Secans")
		{
				if(jednostka->get_active_text()=="Stopnie")
				{
					radianow = strtod(wej->get_text().c_str(), NULL) * M_PI / 180;
					if(cos(radianow)!=0)
					wyj->set_text(Glib::ustring::compose("sec(%1°)=%2", Glib::ustring::format(strtod(wej->get_text().c_str(), NULL)), Glib::ustring::format(1/cos(radianow))));
					else
					{
						Gtk::MessageDialog err("Nieokreślona wartość funkcji", false, Gtk::MESSAGE_ERROR, Gtk::BUTTONS_OK, true);
						err.run();
					}
				}
				else
				{
					radianow = strtod(wej->get_text().c_str(), NULL);
					if(cos(radianow)!=0)
					wyj->set_text(Glib::ustring::compose("sec(%1)=%2", Glib::ustring::format(radianow), Glib::ustring::format(1/cos(radianow))));
					else
					{
						Gtk::MessageDialog err("Nieokreślona wartość funkcji", false, Gtk::MESSAGE_ERROR, Gtk::BUTTONS_OK, true);
						err.run();
					}
				}
		}
		if(funkcja->get_active_text()=="Cosecans")
		{
				if(jednostka->get_active_text()=="Stopnie")
				{
					radianow = strtod(wej->get_text().c_str(), NULL) * M_PI / 180;
					if(sin(radianow)!=0)
					wyj->set_text(Glib::ustring::compose("csc(%1°)=%2", Glib::ustring::format(strtod(wej->get_text().c_str(), NULL)), Glib::ustring::format(1/sin(radianow))));
					else
					{
						Gtk::MessageDialog err("Nieokreślona wartość funkcji", false, Gtk::MESSAGE_ERROR, Gtk::BUTTONS_OK, true);
						err.run();
					}
				}
				else
				{
					radianow = strtod(wej->get_text().c_str(), NULL);
					if(sin(radianow)!=0)
					wyj->set_text(Glib::ustring::compose("csc(%1)=%2", Glib::ustring::format(radianow), Glib::ustring::format(1/sin(radianow))));
					else
					{
						Gtk::MessageDialog err("Nieokreślona wartość funkcji", false, Gtk::MESSAGE_ERROR, Gtk::BUTTONS_OK, true);
						err.run();
					}
				}	
		}
	}
   
int
main (int argc, char *argv[])
{
	Gtk::Main kit(argc, argv);
	//Load the Glade file and instiate its widgets:
	Glib::RefPtr<Gtk::Builder> builder;
	try
	{
		builder = Gtk::Builder::create_from_file(UI_FILE);
	}
	catch (const Glib::FileError & ex)
	{
		std::cerr << ex.what() << std::endl;
		return 1;
	}
	Gtk::Window* main_win = 0;
	builder->get_widget("main_window", main_win);
	builder->get_widget("oprogramie", abprog);
	builder->get_widget("zamknij", closing);
	builder->get_widget("entry2", wej);
	builder->get_widget("entry1", wyj);
	builder->get_widget("comboboxtext1", jednostka);
	builder->get_widget("comboboxtext2", funkcja);

	if(wej)
	{
		if(wyj)
		{
			if(jednostka)
			{
				jednostka->set_active_text("Stopnie");
				jednostka->signal_changed().connect(sigc::ptr_fun(&zamiana));
				if(funkcja)
				{
					funkcja->set_active_text("Sinus");
					funkcja->signal_changed().connect(sigc::ptr_fun(&zamiana));
					wej->signal_changed().connect(sigc::ptr_fun(&zamiana));
				}
			}
		}
	}

	if(abprog)
	{
		abprog->signal_clicked().connect(sigc::ptr_fun(&oprog));
	}

	if(closing)
	{
		closing->signal_clicked().connect(sigc::ptr_fun(&zamknij));
	}

	if (main_win)
	{
		kit.run(*main_win);
	}
	return 0;
}
