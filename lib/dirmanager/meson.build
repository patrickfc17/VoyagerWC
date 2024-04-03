sources = files('traveller.cpp')

gtk = dependency('gtkmm-4.0', method: 'pkg-config')

dirmanager_lib = shared_library('dirmanager', sources, dependencies: gtk)
