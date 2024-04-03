project('VoyagerWC', 'cpp', version: '0.1')

subdir('lib/dirmanager')
subdir('gui/windows')

gtk = dependency('gtkmm-4.0', method: 'pkg-config')

executable('Voyager', sources: ['main.cpp'], dependencies: [gtk], link_with: [dirmanager_lib, components_lib])
