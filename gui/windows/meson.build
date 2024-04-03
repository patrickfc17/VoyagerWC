sources = files('voyager-startup-window.cpp')

gtk = dependency('gtkmm-4.0', method: 'pkg-config')

windows_lib = shared_library('components', sources, dependencies: gtk)
