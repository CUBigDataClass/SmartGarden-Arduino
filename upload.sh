FQBN=arduino:avr:nano
PORT=/dev/ttyUSB0

echo 'compiling...'
arduino-cli compile --fqbn $FQBN src
echo 'uploading...'
arduino-cli upload --verbose -p $PORT --fqbn $FQBN src
