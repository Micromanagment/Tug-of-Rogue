#!/bin/bash
./vendor/premake/premake5 gmake

# Create logs directory
mkdir -p logs

# Makes
make

# check if file is created
if [ -f ./bin/Debug-linux-x86_64/App/App ]; then

    # Run main app
    alacritty -e bash -c "./bin/Debug-linux-x86_64/App/App; exec bash" &

    sleep 0.1

    # Runs logging
    alacritty -e bash -c "tail -f logs/app.log; exec bash" &
else
    echo "Build failed, App not found."
fi
