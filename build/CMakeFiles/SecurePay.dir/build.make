# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/build"

# Include any dependencies generated for this target.
include CMakeFiles/SecurePay.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SecurePay.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SecurePay.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SecurePay.dir/flags.make

SecurePay_autogen/timestamp: /opt/homebrew/share/qt/libexec/moc
SecurePay_autogen/timestamp: /opt/homebrew/share/qt/libexec/uic
SecurePay_autogen/timestamp: CMakeFiles/SecurePay.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir="/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target SecurePay"
	/opt/homebrew/bin/cmake -E cmake_autogen "/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/build/CMakeFiles/SecurePay_autogen.dir/AutogenInfo.json" ""
	/opt/homebrew/bin/cmake -E touch "/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/build/SecurePay_autogen/timestamp"

CMakeFiles/SecurePay.dir/codegen:
.PHONY : CMakeFiles/SecurePay.dir/codegen

CMakeFiles/SecurePay.dir/SecurePay_autogen/mocs_compilation.cpp.o: CMakeFiles/SecurePay.dir/flags.make
CMakeFiles/SecurePay.dir/SecurePay_autogen/mocs_compilation.cpp.o: SecurePay_autogen/mocs_compilation.cpp
CMakeFiles/SecurePay.dir/SecurePay_autogen/mocs_compilation.cpp.o: CMakeFiles/SecurePay.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SecurePay.dir/SecurePay_autogen/mocs_compilation.cpp.o"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SecurePay.dir/SecurePay_autogen/mocs_compilation.cpp.o -MF CMakeFiles/SecurePay.dir/SecurePay_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/SecurePay.dir/SecurePay_autogen/mocs_compilation.cpp.o -c "/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/build/SecurePay_autogen/mocs_compilation.cpp"

CMakeFiles/SecurePay.dir/SecurePay_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SecurePay.dir/SecurePay_autogen/mocs_compilation.cpp.i"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/build/SecurePay_autogen/mocs_compilation.cpp" > CMakeFiles/SecurePay.dir/SecurePay_autogen/mocs_compilation.cpp.i

CMakeFiles/SecurePay.dir/SecurePay_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SecurePay.dir/SecurePay_autogen/mocs_compilation.cpp.s"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/build/SecurePay_autogen/mocs_compilation.cpp" -o CMakeFiles/SecurePay.dir/SecurePay_autogen/mocs_compilation.cpp.s

CMakeFiles/SecurePay.dir/src/main.cpp.o: CMakeFiles/SecurePay.dir/flags.make
CMakeFiles/SecurePay.dir/src/main.cpp.o: /Users/subhashpolisetti/Documents/Visual\ Studio\ Workspaces/Software\ System\ Engienering\ Assignment-5/src/main.cpp
CMakeFiles/SecurePay.dir/src/main.cpp.o: CMakeFiles/SecurePay.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SecurePay.dir/src/main.cpp.o"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SecurePay.dir/src/main.cpp.o -MF CMakeFiles/SecurePay.dir/src/main.cpp.o.d -o CMakeFiles/SecurePay.dir/src/main.cpp.o -c "/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/src/main.cpp"

CMakeFiles/SecurePay.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SecurePay.dir/src/main.cpp.i"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/src/main.cpp" > CMakeFiles/SecurePay.dir/src/main.cpp.i

CMakeFiles/SecurePay.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SecurePay.dir/src/main.cpp.s"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/src/main.cpp" -o CMakeFiles/SecurePay.dir/src/main.cpp.s

CMakeFiles/SecurePay.dir/src/core/customer.cpp.o: CMakeFiles/SecurePay.dir/flags.make
CMakeFiles/SecurePay.dir/src/core/customer.cpp.o: /Users/subhashpolisetti/Documents/Visual\ Studio\ Workspaces/Software\ System\ Engienering\ Assignment-5/src/core/customer.cpp
CMakeFiles/SecurePay.dir/src/core/customer.cpp.o: CMakeFiles/SecurePay.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SecurePay.dir/src/core/customer.cpp.o"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SecurePay.dir/src/core/customer.cpp.o -MF CMakeFiles/SecurePay.dir/src/core/customer.cpp.o.d -o CMakeFiles/SecurePay.dir/src/core/customer.cpp.o -c "/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/src/core/customer.cpp"

CMakeFiles/SecurePay.dir/src/core/customer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SecurePay.dir/src/core/customer.cpp.i"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/src/core/customer.cpp" > CMakeFiles/SecurePay.dir/src/core/customer.cpp.i

CMakeFiles/SecurePay.dir/src/core/customer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SecurePay.dir/src/core/customer.cpp.s"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/src/core/customer.cpp" -o CMakeFiles/SecurePay.dir/src/core/customer.cpp.s

CMakeFiles/SecurePay.dir/src/core/transaction.cpp.o: CMakeFiles/SecurePay.dir/flags.make
CMakeFiles/SecurePay.dir/src/core/transaction.cpp.o: /Users/subhashpolisetti/Documents/Visual\ Studio\ Workspaces/Software\ System\ Engienering\ Assignment-5/src/core/transaction.cpp
CMakeFiles/SecurePay.dir/src/core/transaction.cpp.o: CMakeFiles/SecurePay.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/SecurePay.dir/src/core/transaction.cpp.o"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SecurePay.dir/src/core/transaction.cpp.o -MF CMakeFiles/SecurePay.dir/src/core/transaction.cpp.o.d -o CMakeFiles/SecurePay.dir/src/core/transaction.cpp.o -c "/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/src/core/transaction.cpp"

CMakeFiles/SecurePay.dir/src/core/transaction.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SecurePay.dir/src/core/transaction.cpp.i"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/src/core/transaction.cpp" > CMakeFiles/SecurePay.dir/src/core/transaction.cpp.i

CMakeFiles/SecurePay.dir/src/core/transaction.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SecurePay.dir/src/core/transaction.cpp.s"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/src/core/transaction.cpp" -o CMakeFiles/SecurePay.dir/src/core/transaction.cpp.s

CMakeFiles/SecurePay.dir/src/core/paymentmethod.cpp.o: CMakeFiles/SecurePay.dir/flags.make
CMakeFiles/SecurePay.dir/src/core/paymentmethod.cpp.o: /Users/subhashpolisetti/Documents/Visual\ Studio\ Workspaces/Software\ System\ Engienering\ Assignment-5/src/core/paymentmethod.cpp
CMakeFiles/SecurePay.dir/src/core/paymentmethod.cpp.o: CMakeFiles/SecurePay.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/SecurePay.dir/src/core/paymentmethod.cpp.o"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SecurePay.dir/src/core/paymentmethod.cpp.o -MF CMakeFiles/SecurePay.dir/src/core/paymentmethod.cpp.o.d -o CMakeFiles/SecurePay.dir/src/core/paymentmethod.cpp.o -c "/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/src/core/paymentmethod.cpp"

CMakeFiles/SecurePay.dir/src/core/paymentmethod.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SecurePay.dir/src/core/paymentmethod.cpp.i"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/src/core/paymentmethod.cpp" > CMakeFiles/SecurePay.dir/src/core/paymentmethod.cpp.i

CMakeFiles/SecurePay.dir/src/core/paymentmethod.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SecurePay.dir/src/core/paymentmethod.cpp.s"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/src/core/paymentmethod.cpp" -o CMakeFiles/SecurePay.dir/src/core/paymentmethod.cpp.s

CMakeFiles/SecurePay.dir/src/core/paymentgateway.cpp.o: CMakeFiles/SecurePay.dir/flags.make
CMakeFiles/SecurePay.dir/src/core/paymentgateway.cpp.o: /Users/subhashpolisetti/Documents/Visual\ Studio\ Workspaces/Software\ System\ Engienering\ Assignment-5/src/core/paymentgateway.cpp
CMakeFiles/SecurePay.dir/src/core/paymentgateway.cpp.o: CMakeFiles/SecurePay.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/SecurePay.dir/src/core/paymentgateway.cpp.o"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SecurePay.dir/src/core/paymentgateway.cpp.o -MF CMakeFiles/SecurePay.dir/src/core/paymentgateway.cpp.o.d -o CMakeFiles/SecurePay.dir/src/core/paymentgateway.cpp.o -c "/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/src/core/paymentgateway.cpp"

CMakeFiles/SecurePay.dir/src/core/paymentgateway.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SecurePay.dir/src/core/paymentgateway.cpp.i"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/src/core/paymentgateway.cpp" > CMakeFiles/SecurePay.dir/src/core/paymentgateway.cpp.i

CMakeFiles/SecurePay.dir/src/core/paymentgateway.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SecurePay.dir/src/core/paymentgateway.cpp.s"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/src/core/paymentgateway.cpp" -o CMakeFiles/SecurePay.dir/src/core/paymentgateway.cpp.s

CMakeFiles/SecurePay.dir/src/core/fraudsystem.cpp.o: CMakeFiles/SecurePay.dir/flags.make
CMakeFiles/SecurePay.dir/src/core/fraudsystem.cpp.o: /Users/subhashpolisetti/Documents/Visual\ Studio\ Workspaces/Software\ System\ Engienering\ Assignment-5/src/core/fraudsystem.cpp
CMakeFiles/SecurePay.dir/src/core/fraudsystem.cpp.o: CMakeFiles/SecurePay.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/SecurePay.dir/src/core/fraudsystem.cpp.o"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SecurePay.dir/src/core/fraudsystem.cpp.o -MF CMakeFiles/SecurePay.dir/src/core/fraudsystem.cpp.o.d -o CMakeFiles/SecurePay.dir/src/core/fraudsystem.cpp.o -c "/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/src/core/fraudsystem.cpp"

CMakeFiles/SecurePay.dir/src/core/fraudsystem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SecurePay.dir/src/core/fraudsystem.cpp.i"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/src/core/fraudsystem.cpp" > CMakeFiles/SecurePay.dir/src/core/fraudsystem.cpp.i

CMakeFiles/SecurePay.dir/src/core/fraudsystem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SecurePay.dir/src/core/fraudsystem.cpp.s"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/src/core/fraudsystem.cpp" -o CMakeFiles/SecurePay.dir/src/core/fraudsystem.cpp.s

CMakeFiles/SecurePay.dir/src/core/bank.cpp.o: CMakeFiles/SecurePay.dir/flags.make
CMakeFiles/SecurePay.dir/src/core/bank.cpp.o: /Users/subhashpolisetti/Documents/Visual\ Studio\ Workspaces/Software\ System\ Engienering\ Assignment-5/src/core/bank.cpp
CMakeFiles/SecurePay.dir/src/core/bank.cpp.o: CMakeFiles/SecurePay.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/SecurePay.dir/src/core/bank.cpp.o"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SecurePay.dir/src/core/bank.cpp.o -MF CMakeFiles/SecurePay.dir/src/core/bank.cpp.o.d -o CMakeFiles/SecurePay.dir/src/core/bank.cpp.o -c "/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/src/core/bank.cpp"

CMakeFiles/SecurePay.dir/src/core/bank.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SecurePay.dir/src/core/bank.cpp.i"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/src/core/bank.cpp" > CMakeFiles/SecurePay.dir/src/core/bank.cpp.i

CMakeFiles/SecurePay.dir/src/core/bank.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SecurePay.dir/src/core/bank.cpp.s"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/src/core/bank.cpp" -o CMakeFiles/SecurePay.dir/src/core/bank.cpp.s

CMakeFiles/SecurePay.dir/src/core/appcontroller.cpp.o: CMakeFiles/SecurePay.dir/flags.make
CMakeFiles/SecurePay.dir/src/core/appcontroller.cpp.o: /Users/subhashpolisetti/Documents/Visual\ Studio\ Workspaces/Software\ System\ Engienering\ Assignment-5/src/core/appcontroller.cpp
CMakeFiles/SecurePay.dir/src/core/appcontroller.cpp.o: CMakeFiles/SecurePay.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/SecurePay.dir/src/core/appcontroller.cpp.o"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SecurePay.dir/src/core/appcontroller.cpp.o -MF CMakeFiles/SecurePay.dir/src/core/appcontroller.cpp.o.d -o CMakeFiles/SecurePay.dir/src/core/appcontroller.cpp.o -c "/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/src/core/appcontroller.cpp"

CMakeFiles/SecurePay.dir/src/core/appcontroller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SecurePay.dir/src/core/appcontroller.cpp.i"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/src/core/appcontroller.cpp" > CMakeFiles/SecurePay.dir/src/core/appcontroller.cpp.i

CMakeFiles/SecurePay.dir/src/core/appcontroller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SecurePay.dir/src/core/appcontroller.cpp.s"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/src/core/appcontroller.cpp" -o CMakeFiles/SecurePay.dir/src/core/appcontroller.cpp.s

CMakeFiles/SecurePay.dir/src/gui/mainwindow.cpp.o: CMakeFiles/SecurePay.dir/flags.make
CMakeFiles/SecurePay.dir/src/gui/mainwindow.cpp.o: /Users/subhashpolisetti/Documents/Visual\ Studio\ Workspaces/Software\ System\ Engienering\ Assignment-5/src/gui/mainwindow.cpp
CMakeFiles/SecurePay.dir/src/gui/mainwindow.cpp.o: CMakeFiles/SecurePay.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/SecurePay.dir/src/gui/mainwindow.cpp.o"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SecurePay.dir/src/gui/mainwindow.cpp.o -MF CMakeFiles/SecurePay.dir/src/gui/mainwindow.cpp.o.d -o CMakeFiles/SecurePay.dir/src/gui/mainwindow.cpp.o -c "/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/src/gui/mainwindow.cpp"

CMakeFiles/SecurePay.dir/src/gui/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SecurePay.dir/src/gui/mainwindow.cpp.i"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/src/gui/mainwindow.cpp" > CMakeFiles/SecurePay.dir/src/gui/mainwindow.cpp.i

CMakeFiles/SecurePay.dir/src/gui/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SecurePay.dir/src/gui/mainwindow.cpp.s"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/src/gui/mainwindow.cpp" -o CMakeFiles/SecurePay.dir/src/gui/mainwindow.cpp.s

CMakeFiles/SecurePay.dir/src/gui/addcustomerdialog.cpp.o: CMakeFiles/SecurePay.dir/flags.make
CMakeFiles/SecurePay.dir/src/gui/addcustomerdialog.cpp.o: /Users/subhashpolisetti/Documents/Visual\ Studio\ Workspaces/Software\ System\ Engienering\ Assignment-5/src/gui/addcustomerdialog.cpp
CMakeFiles/SecurePay.dir/src/gui/addcustomerdialog.cpp.o: CMakeFiles/SecurePay.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/SecurePay.dir/src/gui/addcustomerdialog.cpp.o"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SecurePay.dir/src/gui/addcustomerdialog.cpp.o -MF CMakeFiles/SecurePay.dir/src/gui/addcustomerdialog.cpp.o.d -o CMakeFiles/SecurePay.dir/src/gui/addcustomerdialog.cpp.o -c "/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/src/gui/addcustomerdialog.cpp"

CMakeFiles/SecurePay.dir/src/gui/addcustomerdialog.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SecurePay.dir/src/gui/addcustomerdialog.cpp.i"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/src/gui/addcustomerdialog.cpp" > CMakeFiles/SecurePay.dir/src/gui/addcustomerdialog.cpp.i

CMakeFiles/SecurePay.dir/src/gui/addcustomerdialog.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SecurePay.dir/src/gui/addcustomerdialog.cpp.s"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/src/gui/addcustomerdialog.cpp" -o CMakeFiles/SecurePay.dir/src/gui/addcustomerdialog.cpp.s

# Object files for target SecurePay
SecurePay_OBJECTS = \
"CMakeFiles/SecurePay.dir/SecurePay_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/SecurePay.dir/src/main.cpp.o" \
"CMakeFiles/SecurePay.dir/src/core/customer.cpp.o" \
"CMakeFiles/SecurePay.dir/src/core/transaction.cpp.o" \
"CMakeFiles/SecurePay.dir/src/core/paymentmethod.cpp.o" \
"CMakeFiles/SecurePay.dir/src/core/paymentgateway.cpp.o" \
"CMakeFiles/SecurePay.dir/src/core/fraudsystem.cpp.o" \
"CMakeFiles/SecurePay.dir/src/core/bank.cpp.o" \
"CMakeFiles/SecurePay.dir/src/core/appcontroller.cpp.o" \
"CMakeFiles/SecurePay.dir/src/gui/mainwindow.cpp.o" \
"CMakeFiles/SecurePay.dir/src/gui/addcustomerdialog.cpp.o"

# External object files for target SecurePay
SecurePay_EXTERNAL_OBJECTS =

SecurePay: CMakeFiles/SecurePay.dir/SecurePay_autogen/mocs_compilation.cpp.o
SecurePay: CMakeFiles/SecurePay.dir/src/main.cpp.o
SecurePay: CMakeFiles/SecurePay.dir/src/core/customer.cpp.o
SecurePay: CMakeFiles/SecurePay.dir/src/core/transaction.cpp.o
SecurePay: CMakeFiles/SecurePay.dir/src/core/paymentmethod.cpp.o
SecurePay: CMakeFiles/SecurePay.dir/src/core/paymentgateway.cpp.o
SecurePay: CMakeFiles/SecurePay.dir/src/core/fraudsystem.cpp.o
SecurePay: CMakeFiles/SecurePay.dir/src/core/bank.cpp.o
SecurePay: CMakeFiles/SecurePay.dir/src/core/appcontroller.cpp.o
SecurePay: CMakeFiles/SecurePay.dir/src/gui/mainwindow.cpp.o
SecurePay: CMakeFiles/SecurePay.dir/src/gui/addcustomerdialog.cpp.o
SecurePay: CMakeFiles/SecurePay.dir/build.make
SecurePay: /opt/homebrew/lib/QtWidgets.framework/Versions/A/QtWidgets
SecurePay: /opt/homebrew/lib/QtGui.framework/Versions/A/QtGui
SecurePay: /opt/homebrew/lib/QtCore.framework/Versions/A/QtCore
SecurePay: CMakeFiles/SecurePay.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable SecurePay"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SecurePay.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SecurePay.dir/build: SecurePay
.PHONY : CMakeFiles/SecurePay.dir/build

CMakeFiles/SecurePay.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SecurePay.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SecurePay.dir/clean

CMakeFiles/SecurePay.dir/depend: SecurePay_autogen/timestamp
	cd "/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5" "/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5" "/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/build" "/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/build" "/Users/subhashpolisetti/Documents/Visual Studio Workspaces/Software System Engienering Assignment-5/build/CMakeFiles/SecurePay.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/SecurePay.dir/depend

