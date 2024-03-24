#include <iostream>
#include <gtkmm.h>
#include <gtkmm/window.h>

#include "lib/dirmanager/traveller.hpp"

using Gtk::Window;
using Gtk::Application;

class AppMainWindow : public Window
{
public:
    AppMainWindow();
};

AppMainWindow::AppMainWindow()
{
    set_title("File Explorer");
    set_default_size(1000, 750);
}

int main(int argc, char* argv[])
{
    auto app = Application::create("org.gtkmm.examples.base");

    path root_path = ".";
    auto list = DirectoryManager::travel_subpaths(root_path);

    for (auto &&i : list)
        std::cout << i << std::endl;

    return app->make_window_and_run<AppMainWindow>(argc, argv);
}
