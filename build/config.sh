#####
# Description:  File used to create a build for the Raspberry pi pico


# Remove all of the old build files
rm -r build_rpi_servo

# Create the new build folder
mkdir build_rpi_servo

# Create all of the build artifacts in the folder
cmake -S  .. -B ./build_rpi_servo
