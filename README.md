# joint_control_base
Typedefs for motion generation and control

This software was initiated and is currently developed at the [Robotics Innovation Center](http://robotik.dfki-bremen.de/en/startpage.html)
of the [German Research Center for Artificial Intelligence (DFKI)](http://www.dfki.de) in Bremen.

<img src="https://github.com/rock-control/control-joint_control_base/blob/master/DFKI_Logo.jpg" width="450" height="100">

## Motivation

Defines data commonly used for motion generation and control in a separate library (Was moved here from [trajectory_generation](https://github.com/rock-control/control-orogen-trajectory_generation))

## Requirements / Dependencies

See [manifest.xml](https://github.com/rock-control/control-joint_control_base/blob/master/manifest.xml) 

## Installation

The easiest way to build and install this package is to use Rock's build system.
See [this page](https://www.rock-robotics.org/documentation/about/index.html)
on how to install Rock.

However, if you feel that it's too heavy for your needs, Rock aims at having
most of its "library" packages (such as this one) to follow best practices. See
[this page](https://www.rock-robotics.org/documentation/packages/outside_of_rock.html)
for installation instructions outside of Rock.

### Rock CMake Macros

This package uses a set of CMake helper shipped as the Rock CMake macros.
Documentations is available on [this page](http://rock-robotics.org/documentation/packages/cmake_macros.html).

## Documentation

The data types should be self-explaining. For Rock-Users: The typekits are created by the task libraries that use the data types. Currently, the data types are used by the [trajectory_generation](https://github.com/rock-control/control-orogen-trajectory_generation) task library.

## Testing

Unit tests are available in the test/ folder.

## Current State

Stable, but further data types or processing methods could be added in future. 

## Bug Reports

To search for bugs or report them, please use the [issue tracker](https://github.com/rock-control/control-joint_control_base/issues)

## Releases

Please use the master branch for now. If the library includes more functionality at some point, proper versioning will be introduced. 

### Semantic Versioning

Semantic versioning must be used, that is, the major version number will be
incremented when the API changes in a backwards incompatible way, the minor
version will be incremented when new functionality is added in a backwards
compatible manner, and the patch version is incremented for bugfixes,
documentation, etc.

## Maintainer / Authors / Contributers

See [manifest.xml](https://github.com/rock-control/control-joint_control_base/blob/master/manifest.xml) 

Copyright 2020, DFKI GmbH / Robotics Innovation Center, University of Bremen / Robotics Research Group

