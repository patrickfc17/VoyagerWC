#include <iostream>
#include <chrono>
#include <gtkmm/application.h>
#include <gtkmm/frame.h>

#include "lib/dirmanager/traveller.hpp"
#include "gui/windows/voyager-startup-window.hpp"

using Gtk::Application;

using VoyagerGUI::StartupWindow;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::milliseconds;

using std::filesystem::path;


int main(int argc, char* argv[])
{
    auto app = Application::create("org.gtkmm.examples.base");

    high_resolution_clock::time_point start = high_resolution_clock::now();

    path root_path = ".";
    auto list = DirectoryManager::current_dirs();

    for (auto &&i : list)
        std::cout << i << std::endl;

    Gtk::Frame sidebar_frame;

    high_resolution_clock::time_point end = high_resolution_clock::now();

    std::cout << duration_cast<milliseconds>(end - start).count() << "ms" << std::endl;

    return app->make_window_and_run<StartupWindow>(argc, argv);
}
