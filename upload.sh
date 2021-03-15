FQBN=arduino:avr:nano
PORT=/dev/ttyUSB0

arduino-cli compile --fqbn $FQBN src
arduino-cli upload --verbose -p $PORT --fqbn $FQBN src
