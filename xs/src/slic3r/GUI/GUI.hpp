#ifndef slic3r_GUI_hpp_
#define slic3r_GUI_hpp_

#include <string>
#include <vector>
#include "Config.hpp"

class wxApp;
class wxFrame;
class wxWindow;
class wxMenuBar;
class wxNotebook;

namespace Slic3r { 

class PresetBundle;
class PresetCollection;
class AppConfig;
class DynamicPrintConfig;
class TabIface;

namespace GUI {

class Tab;

void disable_screensaver();
void enable_screensaver();
std::vector<std::string> scan_serial_ports();
bool debugged();
void break_to_debugger();

// Passing the wxWidgets GUI classes instantiated by the Perl part to C++.
void set_wxapp(wxApp *app);
void set_main_frame(wxFrame *main_frame);
void set_tab_panel(wxNotebook *tab_panel);

void add_debug_menu(wxMenuBar *menu);
// Create a new preset tab (print, filament and printer),
void create_preset_tabs(PresetBundle *preset_bundle, AppConfig *app_config, 
						bool no_controller, bool is_disabled_button_browse,	bool is_user_agent,
						int event_value_change, int event_presets_changed,
						int event_button_browse, int event_button_test);
TabIface* get_preset_tab_iface(char *name);

// add it at the end of the tab panel.
void add_created_tab(Tab* panel, PresetBundle *preset_bundle, AppConfig *app_config);
// Change option value in config
void change_opt_value(DynamicPrintConfig& config, t_config_option_key opt_key, boost::any value);

void show_error(wxWindow* parent, std::string message);
void show_info(wxWindow* parent, std::string message, std::string title);


} }

#endif
