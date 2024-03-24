project('VoyagerWC', 'cpp', version: '0.1')

subdir('lib/dirmanager')

dirmanager_sources = [
    'lib/dirmanager/traveller.cpp'
]

gtk = dependency('gtkmm-4.0', method: 'pkg-config')

executable('Explorer', ['main.cpp'] + dirmanager_sources, dependencies : [gtk], include_directories: ['.', './lib/'])
